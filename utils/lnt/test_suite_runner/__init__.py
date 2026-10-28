"""LLVM test-suite"""
import base64
import subprocess
import tempfile
import json
import os
import shlex
import platform
import sys
import shutil
import glob
import re
import multiprocessing
import getpass
import types
import uuid

import datetime
from collections import defaultdict
from functools import partial
import jinja2
import click

from . import report_v5
from .compilers import get_cc_info, infer_cxx_compiler
from .report import FAIL, PASS, XFAIL, Machine, Report, Run, TestSamples
from .util import (fatal, init_logging, isexecfile, logger, mkdir_p,
                   resolve_command_path, timestamp)

KNOWN_SAMPLE_KEYS = ['compile', 'exec', 'hash', 'score']

# Options that only apply when generating a specific version of the
# reports. This can be removed once we eventually remove support for
# generating v1 reports.
FORMAT_OPTIONS = [
    ('output', '--output', 'v1'),
    ('submit_url', '--submit', 'v1'),
    ('run_order', '--run-order', 'v1'),
    ('exclude_stat_from_submission', '--exclude-stat-from-submission', 'v1'),
    ('output_v5', '--output-v5', 'v5'),
    ('commit', '--commit', 'v5'),
    ('commit_ordinal', '--commit-ordinal', 'v5'),
]

XML_REPORT_TEMPLATE = """<?xml version="1.0" encoding="UTF-8"?>
<testsuites>
{%  for suite in suites %}
<testsuite name="{{ suite.name }}"
           tests="{{ suite.num_tests }}"
           errors="{{ suite.num_errors }}"
           failures="{{ suite.num_failures }}"
           timestamp="{{suite.timestamp}}"
           hostname="localhost"
           time="0"
           package="{{suite.name}}"
           id="{{suite.id}}">
    <properties></properties>
    {% for test in suite.tests %}
    <testcase classname="{{ test.path }}"
              name="{{ test.name }}" time="{{ test.time }}">
        {% if test.code == "NOEXE"%}
            <error type="{{test.code}}">
            {{ test.output }}
            </error>
        {% endif %}
        {% if test.code == "FAIL"%}
            <failure type="{{test.code}}">
            {{ test.output }}
            </failure>
        {% endif %}
    </testcase>
    {% endfor %}
    <system-out></system-out>
    <system-err></system-err>
</testsuite>
{% endfor %}
</testsuites>
"""

CSV_REPORT_TEMPLATE = """\
Program;CC;CC_Time;Code_Size;CC_Hash;Exec;Exec_Time;Score
{%- for suite in suites -%}
    {%- for test in suite.tests %}
{{ suite.name }}/{{ test.path }}/{{ test.name }};
        {%- if test.code == "NOEXE" -%}
            fail;*;*;*;
        {%- else -%}
            pass;{{ test.metrics.compile_time if test.metrics }};\
{{ test.metrics.get('size..text') or test.metrics.get('size.__text') if test.metrics }};\
{{ test.metrics.hash if test.metrics }};
        {%- endif -%}
        {%- if test.code == "FAIL" or test.code == "NOEXE" -%}
            fail;*;*;
        {%- else -%}
            pass;{{ test.metrics.exec_time if test.metrics }};\
{{ test.metrics.score if test.metrics }};
        {%- endif -%}
    {% endfor %}
{%- endfor -%}
"""


def _importProfile(lnt, objdump, name_filename):
    """_importProfile imports a single profile, converted to the latest version
    of LNT's profile format by `lnt profile upgrade`. It must be at the top
    level (and not within TestSuiteTest) so that multiprocessing can import it
    correctly."""
    name, filename = name_filename

    if not os.path.exists(filename):
        logger.warning('Profile %s does not exist' % filename)
        return None

    with tempfile.TemporaryDirectory() as tmpdir:
        upgraded = os.path.join(tmpdir, 'profile')
        # `lnt profile upgrade` reads perf profiles with $CMAKE_OBJDUMP.
        env = dict(os.environ, CMAKE_OBJDUMP=objdump)
        cmd = [lnt, 'profile', 'upgrade', filename, upgraded]
        result = subprocess.run(cmd, env=env, capture_output=True,
                                encoding='utf-8', errors='replace')
        if result.returncode != 0:
            logger.warning('Profile %s could not be imported:\n%s' %
                           (filename, result.stderr))
            return None
        with open(upgraded, 'rb') as f:
            profilefile = base64.b64encode(f.read()).decode('ascii')
    return TestSamples(name + '.profile', [profilefile], str)


def _lit_json_to_template(json_reports, template_engine):
    # For now, only show first runs report.
    json_report = json_reports[0]
    tests_by_suite = defaultdict(list)
    for tests in json_report['tests']:
        name = tests['name']
        code = tests['code']
        time = tests['elapsed']
        output = tests.get('output', 'No output collected for this test.')

        x = name.split("::")
        suite_name = x[1].strip().split("/")[0]
        test_name = x[1].strip().split("/")[-1]
        path = x[1].strip().split("/")[:-1]

        entry = {'name': test_name,
                 'path': '.'.join(path),
                 'time': time,
                 'code': code,
                 'metrics': tests.get('metrics', None)}
        if code != "PASS":
            entry['output'] = output

        tests_by_suite[suite_name].append(entry)
    suites = []
    for i, suite in enumerate(tests_by_suite):
        tests = tests_by_suite[suite]
        entry = {'name': suite,
                 'id': i,
                 'tests': tests,
                 'timestamp': datetime.datetime.now().replace(microsecond=0)
                                      .isoformat(),
                 'num_tests': len(tests),
                 'num_failures': len(
                     [test for test in tests if test['code'] == 'FAIL']),
                 'num_errors': len(
                     [test for test in tests if test['code'] == 'NOEXE'])}
        suites.append(entry)
    str_template = template_engine.render(suites=suites)
    return str_template


def _lit_json_to_xunit_xml(json_reports):
    # type: (list) -> str
    """Take the lit report jason dicts and convert them
    to an xunit xml report for CI to digest."""
    template_engine = jinja2.Template(XML_REPORT_TEMPLATE, autoescape=True)
    return _lit_json_to_template(json_reports, template_engine)


def _lit_json_to_csv(json_reports):
    # type: (list) -> str
    """Take the lit report json dicts and convert them
    to a csv report, similar to the old test-suite make-based
    *.report.simple.csv files."""
    template_engine = jinja2.Template(CSV_REPORT_TEMPLATE, autoescape=True)
    return _lit_json_to_template(json_reports, template_engine)


class TestSuiteTest(object):
    def __init__(self, opts):
        self.opts = opts
        self.configured = False
        self.compiled = False
        self.trained = False
        self.remote_run = False
        # The number of times the tests were built, which identifies the build
        # each lit run tests.
        self.build_count = 0

    def _fatal(self, msg):
        """Exit with an error, as OptionParser.error does."""
        prog_name = os.path.basename(sys.argv[0])
        sys.stderr.write("%s error: %s\n" % (prog_name, msg))
        sys.exit(2)

    def run_test(self):
        opts = self.opts

        # Validate the report options
        v1 = 'v1' in opts.report_formats
        v5 = 'v5' in opts.report_formats
        for attribute, option, report_format in FORMAT_OPTIONS:
            if report_format not in opts.report_formats and \
                    getattr(opts, attribute) not in (None, ()):
                self._fatal("%s requires --report-format %s" %
                            (option, report_format))
        if v5:
            if opts.commit is None:
                self._fatal("--report-format v5 requires --commit")
            problem = report_v5.check_name(opts.commit, "--commit")
            if problem:
                self._fatal(problem)
            if opts.exec_interleaved_builds:
                self._fatal("--report-format v5 cannot be used with "
                            "--exec-interleaved-builds")
        # Validate build/exec mode options
        if opts.build and opts.exec_mode:
            self._fatal("--build and --exec are mutually exclusive")

        if opts.exec_mode and opts.build_dir is None and not opts.exec_interleaved_builds:
            self._fatal("--exec requires --build-dir (or use --exec-interleaved-builds)")

        if opts.exec_interleaved_builds:
            # --exec-interleaved-builds implies --exec
            opts.exec_mode = True
            # Parse and validate build directories
            opts.exec_interleaved_builds_list = [
                os.path.abspath(d.strip())
                for d in opts.exec_interleaved_builds.split(',')
            ]
            for build_dir in opts.exec_interleaved_builds_list:
                if not os.path.exists(build_dir):
                    self._fatal(
                        "--exec-interleaved-builds directory does not exist: %r" %
                        build_dir)
                cmakecache = os.path.join(build_dir, 'CMakeCache.txt')
                if not os.path.exists(cmakecache):
                    self._fatal(
                        "--exec-interleaved-builds directory is not a configured build: %r" %
                        build_dir)

        if opts.build_dir:
            opts.build_dir = os.path.abspath(opts.build_dir)
            # In --exec mode, validate that build_dir already exists and is configured
            # In --build mode, we'll create the directory if needed
            if opts.exec_mode:
                if not os.path.exists(opts.build_dir):
                    self._fatal("--build-dir does not exist: %r" % opts.build_dir)
                cmakecache = os.path.join(opts.build_dir, 'CMakeCache.txt')
                if not os.path.exists(cmakecache):
                    self._fatal("--build-dir is not a configured build: %r" % opts.build_dir)

        if opts.cc is not None:
            opts.cc = resolve_command_path(opts.cc)

            if not isexecfile(opts.cc):
                self._fatal('--cc does not point to a valid executable.')

            # If there was no --cxx given, attempt to infer it from the --cc.
            if opts.cxx is None:
                opts.cxx = infer_cxx_compiler(opts.cc)
                if opts.cxx is not None:
                    logger.info("Inferred C++ compiler under test as: %r"
                                % (opts.cxx,))
                else:
                    self._fatal("unable to infer --cxx - set it manually.")
            else:
                opts.cxx = resolve_command_path(opts.cxx)

            if not os.path.exists(opts.cxx):
                self._fatal("invalid --cxx argument %r, does not exist"
                            % (opts.cxx))
        else:
            # If --cc not specified, CMake will use its default compiler discovery
            # We'll validate that a compiler was found after configuration
            if opts.cc is None and not opts.exec_mode:
                logger.info("No --cc specified, will use CMake's default compiler discovery")

        if not opts.exec_mode:
            # These are only required when building
            if opts.test_suite_root is None:
                self._fatal('--test-suite is required')
            if not os.path.exists(opts.test_suite_root):
                self._fatal("invalid --test-suite argument, does not exist: %r" % (
                    opts.test_suite_root))
            opts.test_suite_root = os.path.abspath(opts.test_suite_root)

        if opts.test_suite_externals:
            if not os.path.exists(opts.test_suite_externals):
                self._fatal(
                    "invalid --test-externals argument, does not exist: %r" % (
                        opts.test_suite_externals,))
            opts.test_suite_externals = os.path.abspath(
                opts.test_suite_externals)

        opts.cmake = resolve_command_path(opts.cmake)
        if not isexecfile(opts.cmake):
            self._fatal("CMake tool not found (looked for %s)" % opts.cmake)
        opts.lit = resolve_command_path(opts.lit)
        if not isexecfile(opts.lit):
            self._fatal("LIT tool not found (looked for %s)" % opts.lit)
        # `lnt` submits the report, and imports the profiles gathered with
        # perf.
        if opts.submit_url is not None or \
                opts.use_perf in ('profile', 'all'):
            if opts.lnt is None:
                # The `lnt` installed along with the Python running us, if
                # any, so that a virtualenv works without being activated.
                opts.lnt = os.path.join(os.path.dirname(sys.executable), 'lnt')
                if not isexecfile(opts.lnt):
                    opts.lnt = 'lnt'
            opts.lnt = resolve_command_path(opts.lnt)
            if not isexecfile(opts.lnt):
                self._fatal("LNT tool not found (looked for %s); use "
                            "--use-lnt to name it" % opts.lnt)
        if opts.run_under:
            split = shlex.split(opts.run_under)
            split[0] = resolve_command_path(split[0])
            if not isexecfile(split[0]):
                self._fatal("Run under wrapper not found (looked for %s)" %
                            opts.run_under)

        if opts.single_result:
            # --single-result implies --only-test
            opts.only_test = opts.single_result

        if opts.only_test:
            # Convert --only-test to tuple format: (directory, test_name or None)
            # In non-exec mode, validate against test_suite_root
            # In exec mode, validate against build_dir if available
            base_path = opts.build_dir if opts.exec_mode and opts.build_dir else opts.test_suite_root

            if base_path:
                full_path = os.path.join(base_path, opts.only_test)
                parent_path = os.path.dirname(full_path)

                if os.path.isdir(full_path):
                    opts.only_test = (opts.only_test, None)
                elif os.path.isdir(parent_path):
                    opts.only_test = (os.path.dirname(opts.only_test),
                                      os.path.basename(opts.only_test))
                elif not opts.exec_mode:
                    # In normal mode, path must exist
                    self._fatal("--only-test argument not understood (must be a " +
                                "test or directory name)")
                else:
                    # In exec mode, path may not exist yet, assume it's a directory
                    opts.only_test = (opts.only_test, None)
            else:
                # No base_path available (e.g., exec_interleaved_builds), assume directory
                opts.only_test = (opts.only_test, None)

        if opts.single_result and not opts.only_test[1]:
            self._fatal("--single-result must be given a single test name, "
                        "not a directory name")

        # Parse and validate --drop-exec option
        if opts.drop_exec is not None:
            # Check for incompatible options
            if opts.only_compile:
                self._fatal("--drop-exec cannot be used with --only-compile")
            if opts.build:
                self._fatal("--drop-exec cannot be used with --build")
            if opts.exec_multisample <= 1:
                self._fatal("--drop-exec requires --exec-multisample > 1")

            # opts.drop_exec is already an integer from click
            if opts.drop_exec < 1:
                self._fatal("--drop-exec must be at least 1")

            if opts.drop_exec >= opts.exec_multisample:
                self._fatal("--drop-exec would drop all %d samples" % opts.exec_multisample)

        opts.cppflags = ' '.join(opts.cppflags)
        opts.cflags = ' '.join(opts.cflags)
        opts.cxxflags = ' '.join(opts.cxxflags)

        if opts.diagnose:
            if not opts.only_test:
                self._fatal("--diagnose requires --only-test")

        self.start_time = timestamp()

        # Work out where to put our build stuff
        if opts.build_dir and (opts.exec_mode or opts.build):
            # With --build-dir, use the specified build directory (for both --build and --exec modes)
            basedir = opts.build_dir
        elif opts.exec_interleaved_builds:
            # For exec-interleaved-builds, each build uses its own directory
            # We'll return early from _run_interleaved_builds(), so basedir doesn't matter
            basedir = opts.sandbox_path
        else:
            # Normal mode: use sandbox/build or sandbox/test-<timestamp>
            if opts.timestamp_build:
                ts = self.start_time.replace(' ', '_').replace(':', '-')
                build_dir_name = "test-%s" % ts
            else:
                build_dir_name = "build"
            basedir = os.path.join(opts.sandbox_path, build_dir_name)

        self._base_path = basedir

        cmakecache = os.path.join(self._base_path, 'CMakeCache.txt')
        if opts.exec_mode:
            # In exec mode, the build is already configured and compiled
            self.configured = True
            self.compiled = True
        else:
            # In normal/build mode, check if we should skip reconfiguration
            self.configured = not opts.run_configure and \
                os.path.exists(cmakecache)

        # No additional validation needed - CMake will find default compiler if needed
        # The validation after _configure_if_needed() will catch if no compiler found

        #  If we are doing diagnostics, skip the usual run and do them now.
        if opts.diagnose:
            self.diagnose()
            return

        # Handle exec-interleaved-builds mode separately
        if opts.exec_interleaved_builds:
            self._run_interleaved_builds(opts)
            return

        # Configure if needed (skip in exec mode)
        if not opts.exec_mode:
            # configure, so we can extract toolchain information from the cmake
            # output.
            self._configure_if_needed()

        # Verify that we can actually find a compiler before continuing
        cmake_vars = self._extract_cmake_vars_from_cache()
        if "CMAKE_C_COMPILER" not in cmake_vars or \
                not os.path.exists(cmake_vars["CMAKE_C_COMPILER"]):
            self._fatal(
                "Couldn't find C compiler (%s). Maybe you should specify --cc?"
                % cmake_vars.get("CMAKE_C_COMPILER"))

        # We don't support compiling without testing as we can't get compile-
        # time numbers from LIT without running the tests.
        if opts.compile_multisample > opts.exec_multisample:
            logger.info("Increasing number of execution samples to %d" %
                        opts.compile_multisample)
            opts.exec_multisample = opts.compile_multisample

        if opts.auto_name:
            # Construct the nickname from a few key parameters.
            cc_info = self._get_cc_info(cmake_vars)
            cc_nick = '%s_%s' % (cc_info['cc_name'], cc_info['cc_build'])
            opts.label += "__%s__%s" %\
                (cc_nick, cc_info['cc_target'].split('-')[0])
        logger.info('Using nickname: %r' % opts.label)
        if v5:
            problem = report_v5.check_name(opts.label, "The machine name")
            if problem:
                self._fatal("%s: %r" % (problem, opts.label))

        #  When we can't detect the clang version we use 0 instead. That
        # is a horrible failure mode because all of our data ends up going
        # to order 0.  The user needs to give an order if we can't detect!
        if v1 and opts.run_order is None:
            cc_info = self._get_cc_info(cmake_vars)
            if cc_info['inferred_run_order'] == 0:
                fatal("Cannot detect compiler version. Specify --run-order"
                      " to manually define it.")

        # Handle --build mode
        if opts.build:
            logger.info("Building tests (--build mode)...")
            self.run(cmake_vars, compile=True, test=False, skip_lit=True)
            logger.info("Build complete. Build directory: %s" % self._base_path)
            logger.info("Use --exec --build-dir %s to run tests." % self._base_path)
            return

        # Now do the actual run.
        reports = []
        json_reports = []
        builds = []
        # In exec mode, we only run tests, no compilation
        if opts.exec_mode:
            for i in range(opts.exec_multisample):
                # only gather perf profiles on a single run.
                p = i == 0 and opts.use_perf in ('profile', 'all')
                run_report, json_data = self.run(cmake_vars, compile=False, test=True,
                                                 profile=p)
                reports.append(run_report)
                json_reports.append(json_data)
                builds.append(self.build_count)
        else:
            # Normal mode: build and test
            for i in range(max(opts.exec_multisample, opts.compile_multisample)):
                c = i < opts.compile_multisample
                e = i < opts.exec_multisample
                # only gather perf profiles on a single run.
                p = i == 0 and opts.use_perf in ('profile', 'all')
                run_report, json_data = self.run(cmake_vars, compile=c, test=e,
                                                 profile=p)
                reports.append(run_report)
                json_reports.append(json_data)
                builds.append(self.build_count)

        # Filter execution samples if --drop-exec was specified
        reports, json_reports, builds = self._filter_exec_samples(
            reports, json_reports, builds)

        if v1:
            rendered = self._create_merged_report(reports).render()

            # Write the report out so it can be read by the submission tool.
            report_path = os.path.join(self._base_path, 'report.json')
            with open(report_path, 'w') as fd:
                fd.write(rendered)

            if opts.output:
                with open(opts.output, 'w') as fd:
                    fd.write(rendered)

        if v5:
            submission = report_v5.build_submission(
                str(uuid.uuid4()), datetime.datetime.now(datetime.timezone.utc),
                opts.label, opts.commit, opts.commit_ordinal,
                self._get_cc_info(cmake_vars), list(zip(json_reports, builds)))
            rendered = report_v5.render(submission)
            for path in (os.path.join(self._base_path, 'report.v5.json'),
                         opts.output_v5):
                if path:
                    with open(path, 'w') as fd:
                        fd.write(rendered)

        xml_report_path = os.path.join(self._base_path,
                                       'test-results.xunit.xml')

        str_template = _lit_json_to_xunit_xml(json_reports)
        with open(xml_report_path, 'w') as fd:
            fd.write(str_template)

        csv_report_path = os.path.join(self._base_path,
                                       'test-results.csv')
        str_template = _lit_json_to_csv(json_reports)
        with open(csv_report_path, 'w') as fd:
            fd.write(str_template)

        if opts.submit_url is not None:
            self._submit(report_path)

    def _submit(self, report_path):
        """Submit the report at report_path with `lnt submit`, and exit with
        an error if that fails."""
        cmd = [self.opts.lnt, 'submit', self.opts.submit_url, report_path,
               '--select-machine', self.opts.select_machine,
               '--merge', self.opts.merge]
        if self.opts.verbose:
            cmd.append('--verbose')
        # So that what we printed so far comes before what `lnt submit` prints.
        sys.stdout.flush()
        try:
            self._check_call(cmd)
        except subprocess.CalledProcessError:
            fatal("Submitting the report failed. It can be submitted again "
                  "with: %s" % shlex.join(cmd))

    def _run_interleaved_builds(self, opts):
        """Run tests from multiple builds in an interleaved fashion."""
        logger.info("Running interleaved builds mode with %d builds" %
                    len(opts.exec_interleaved_builds_list))

        # Collect information about each build
        build_infos = []
        for build_dir in opts.exec_interleaved_builds_list:
            logger.info("Loading build from: %s" % build_dir)

            # Temporarily set _base_path and configured to this build directory
            saved_base_path = self._base_path
            saved_configured = self.configured
            self._base_path = build_dir
            self.configured = True  # Build directories are already configured

            # Extract cmake vars from this build
            cmake_vars = self._extract_cmake_vars_from_cache()
            if "CMAKE_C_COMPILER" not in cmake_vars or \
                    not os.path.exists(cmake_vars["CMAKE_C_COMPILER"]):
                self._fatal(
                    "Couldn't find C compiler in build %s (%s)." %
                    (build_dir, cmake_vars.get("CMAKE_C_COMPILER")))

            cc_info = self._get_cc_info(cmake_vars)
            logger.info("  Compiler: %s %s" % (cc_info['cc_name'], cc_info['cc_build']))

            build_infos.append({
                'build_dir': build_dir,
                'cmake_vars': cmake_vars,
                'cc_info': cc_info
            })

            # Restore _base_path and configured
            self._base_path = saved_base_path
            self.configured = saved_configured

        # Now run tests in interleaved fashion
        all_reports = []
        all_json_reports = []

        for sample_idx in range(opts.exec_multisample):
            logger.info("Running sample %d of %d" % (sample_idx + 1, opts.exec_multisample))

            for build_idx, build_info in enumerate(build_infos):
                logger.info("  Testing build %d/%d: %s" %
                            (build_idx + 1, len(build_infos), build_info['build_dir']))

                # Set _base_path and configured to this build directory
                self._base_path = build_info['build_dir']
                self.configured = True  # Build is already configured, skip reconfiguration

                # Run tests (no compilation)
                p = sample_idx == 0 and opts.use_perf in ('profile', 'all')
                run_report, json_data = self.run(
                    build_info['cmake_vars'],
                    compile=False,
                    test=True,
                    profile=p
                )

                all_reports.append(run_report)
                all_json_reports.append(json_data)

        logger.info("Interleaved testing complete. Generating reports...")

        # For now, we'll create separate reports for each build
        # Group reports by build
        reports_by_build = {}
        json_by_build = {}
        for i, (report, json_data) in enumerate(zip(all_reports, all_json_reports)):
            build_idx = i % len(build_infos)
            if build_idx not in reports_by_build:
                reports_by_build[build_idx] = []
                json_by_build[build_idx] = []
            reports_by_build[build_idx].append(report)
            json_by_build[build_idx].append(json_data)

        # Write reports for each build to its own directory
        for build_idx, build_info in enumerate(build_infos):
            build_dir = build_info['build_dir']
            logger.info("Writing report for build: %s" % build_dir)

            # Filter execution samples if --drop-exec was specified
            build_reports, build_json_reports = self._filter_exec_samples(
                reports_by_build[build_idx],
                json_by_build[build_idx]
            )

            # Merge reports for this build
            merged_report = self._create_merged_report(build_reports)

            # Write JSON report to build directory
            report_path = os.path.join(build_dir, 'report.json')
            with open(report_path, 'w') as fd:
                fd.write(merged_report.render())
            logger.info("  Report: %s" % report_path)

            # Write xUnit XML to build directory
            xml_path = os.path.join(build_dir, 'test-results.xunit.xml')
            str_template = _lit_json_to_xunit_xml(build_json_reports)
            with open(xml_path, 'w') as fd:
                fd.write(str_template)

            # Write CSV to build directory
            csv_path = os.path.join(build_dir, 'test-results.csv')
            str_template = _lit_json_to_csv(build_json_reports)
            with open(csv_path, 'w') as fd:
                fd.write(str_template)

        logger.info("Reports written to each build directory.")
        logger.info("To submit results, use 'lnt submit' with each report file.")

    def _configure_if_needed(self):
        mkdir_p(self._base_path)
        if not self.configured:
            self._configure(self._base_path)
            self._clean(self._base_path)
            self.configured = True

    def run(self, cmake_vars, compile=True, test=True, profile=False, skip_lit=False):
        mkdir_p(self._base_path)

        # FIXME: should we only run PGO collection once, even when
        # multisampling? We could do so be adding "and not self.trained"
        # below.
        if self.opts.pgo:
            self._collect_pgo(self._base_path)
            self.trained = True
            self.configured = False

        if compile or self.opts.pgo:
            self._configure_if_needed()

            if self.compiled:
                self._clean(self._base_path)
            self._build(self._base_path)
            self._install_benchmark(self._base_path)
            self.compiled = True
            self.build_count += 1

        if skip_lit:
            return None, None

        data = self._lit(self._base_path, test, profile)
        return self._parse_lit_output(self._base_path, data, cmake_vars), data

    def _create_merged_report(self, reports):
        if len(reports) == 1:
            return reports[0]

        machine = reports[0].machine
        run = reports[0].run
        run.end_time = reports[-1].run.end_time
        test_samples = sum([r.tests for r in reports], [])
        return Report(machine, run, test_samples)

    def _filter_exec_samples(self, reports, *per_sample):
        """Filter out execution samples based on --drop-exec option.

        Returns the filtered reports, followed by each list of per_sample,
        which has one item per report, filtered the same way.
        """
        drop_exec_count = self.opts.drop_exec

        if drop_exec_count is None or drop_exec_count == 0 or len(reports) == 0:
            return (reports,) + per_sample

        # Drop the first N samples
        filtered_reports = reports[drop_exec_count:]

        # Log what we're dropping
        if drop_exec_count == 1:
            logger.info("Dropping first execution sample (iteration 0)")
        else:
            logger.info("Dropping first %d execution samples (iterations 0-%d)" %
                        (drop_exec_count, drop_exec_count - 1))

        logger.info("Kept %d of %d execution samples after --drop-exec filtering" %
                    (len(filtered_reports), len(reports)))

        return (filtered_reports,) + tuple(items[drop_exec_count:]
                                           for items in per_sample)

    def _test_suite_dir(self):
        return self.opts.test_suite_root

    def _build_threads(self):
        return self.opts.build_threads or self.opts.threads

    def _test_threads(self):
        return self.opts.threads

    def _check_call(self, *args, **kwargs):
        logger.info('Execute: %s' % ' '.join(args[0]))
        if 'cwd' in kwargs:
            logger.info('          (In %s)' % kwargs['cwd'])
        return subprocess.check_call(*args, **kwargs)

    def _check_output(self, *args, **kwargs):
        logger.info('Execute: %s' % ' '.join(args[0]))
        if 'cwd' in kwargs:
            logger.info('          (In %s)' % kwargs['cwd'])
        output = subprocess.check_output(*args, **kwargs)
        if kwargs.get('universal_newlines', False):
            sys.stdout.write(output)
        else:
            sys.stdout.buffer.write(output)
        return output

    def _clean(self, path):
        cmake_cmd = self.opts.cmake

        subdir = path
        if self.opts.only_test:
            components = [path] + [self.opts.only_test[0]]
            subdir = os.path.join(*components)

        self._check_call([cmake_cmd, '--build', '.', '-t', 'clean'],
                         cwd=subdir)

    def _configure(self, path, extra_cmake_defs=[], execute=True):
        cmake_cmd = self.opts.cmake

        defs = {}
        if self.opts.cc:
            defs['CMAKE_C_COMPILER'] = self.opts.cc
        if self.opts.cxx:
            defs['CMAKE_CXX_COMPILER'] = self.opts.cxx
        if self.opts.make:
            defs['CMAKE_MAKE_PROGRAM'] = self.opts.make
        if self.opts.make and (self.opts.make.endswith('ninja') or
                               self.opts.make.endswith('ninja.exe')):
            cmake_flags = ['-G', 'Ninja']
        else:
            cmake_flags = []

        if self.opts.cmake_toolchain:
            cmake_flags += ['--toolchain', self.opts.cmake_toolchain]

        cmake_build_types = ('DEBUG', 'MINSIZEREL', 'RELEASE',
                             'RELWITHDEBINFO')
        if self.opts.cppflags or self.opts.cflags:
            all_cflags = ' '.join([self.opts.cppflags, self.opts.cflags])
            defs['CMAKE_C_FLAGS'] = self._unix_quote_args(all_cflags)
            # Ensure that no flags get added based on build type when the user
            # explicitly specifies flags to use.
            for build_type in cmake_build_types:
                defs['CMAKE_C_FLAGS_'+build_type] = ""

        if self.opts.cppflags or self.opts.cxxflags:
            all_cxx_flags = ' '.join([self.opts.cppflags, self.opts.cxxflags])
            defs['CMAKE_CXX_FLAGS'] = self._unix_quote_args(all_cxx_flags)
            # Ensure that no flags get added based on build type when the user
            # explicitly specifies flags to use.
            for build_type in cmake_build_types:
                defs['CMAKE_CXX_FLAGS_'+build_type] = ""

        if self.opts.run_under:
            defs['TEST_SUITE_RUN_UNDER'] = \
                self._unix_quote_args(self.opts.run_under)
        if self.opts.benchmarking_only:
            defs['TEST_SUITE_BENCHMARKING_ONLY'] = 'ON'
        if self.opts.test_size:
            if self.opts.test_size == 'large':
                defs['LARGE_PROBLEM_SIZE'] = 'ON'
            elif self.opts.test_size == 'small':
                defs['SMALL_PROBLEM_SIZE'] = 'ON'
        if self.opts.only_compile:
            defs['TEST_SUITE_RUN_BENCHMARKS'] = 'Off'
        if self.opts.use_perf in ('time', 'all'):
            defs['TEST_SUITE_USE_PERF'] = 'ON'
        if self.opts.test_suite_externals:
            defs['TEST_SUITE_EXTERNALS_DIR'] = self.opts.test_suite_externals
        if self.opts.pgo and self.trained:
            defs['TEST_SUITE_PROFILE_USE'] = "On"
            defs['TEST_SUITE_PROFILE_GENERATE'] = "Off"
            if 'TEST_SUITE_RUN_TYPE' not in defs:
                defs['TEST_SUITE_RUN_TYPE'] = 'ref'
        if self.opts.remote_host:
            defs['TEST_SUITE_REMOTE_HOST'] = self.opts.remote_host

        for item in tuple(self.opts.cmake_defines) + tuple(extra_cmake_defs):
            k, v = item.split('=', 1)
            # make sure the overriding of the settings above also works
            # when the cmake-define-defined variable has a datatype
            # specified.
            key_no_datatype = k.split(':', 1)[0]
            if key_no_datatype in defs:
                del defs[key_no_datatype]
            defs[k] = v

        # We use 'cmake -LAH -N' later to find out the value of the
        # CMAKE_C_COMPILER and CMAKE_CXX_COMPILER variables.
        # 'cmake -LAH -N' will only return variables in the cache that have
        # a cmake type set. Therefore, explicitly set a 'FILEPATH' type on
        # these variables here, if they were untyped so far.
        if 'CMAKE_C_COMPILER' in defs:
            defs['CMAKE_C_COMPILER:FILEPATH'] = defs['CMAKE_C_COMPILER']
            del defs['CMAKE_C_COMPILER']
        if 'CMAKE_CXX_COMPILER' in defs:
            defs['CMAKE_CXX_COMPILER:FILEPATH'] = defs['CMAKE_CXX_COMPILER']
            del defs['CMAKE_CXX_COMPILER']

        lines = ['Configuring with {']
        for k, v in sorted(defs.items()):
            lines.append("  %s: '%s'" % (k, v))
        lines.append('}')

        if 'TEST_SUITE_REMOTE_HOST' in defs:
            self.remote_run = True

        # Prepare cmake cache if requested:
        for cache in self.opts.cmake_cache:
            if cache == "":
                continue
            # Shortcut for the common case.
            if not cache.endswith(".cmake") and "/" not in cache:
                cache = os.path.join(self._test_suite_dir(),
                                     "cmake/caches", cache + ".cmake")
            cache = os.path.abspath(cache)
            if not os.path.exists(cache):
                fatal("Could not find CMake cache file: " + cache)
            cmake_flags += ['-C', cache]

        for line in lines:
            logger.info(line)

        # Define compilers before specifying the cache files.
        early_defs = {}
        for key in ['CMAKE_C_COMPILER:FILEPATH',
                    'CMAKE_CXX_COMPILER:FILEPATH']:
            value = defs.pop(key, None)
            if value is not None:
                early_defs[key] = value

        cmake_cmd = ([cmake_cmd] +
                     ['-D%s=%s' % (k, v) for k, v in early_defs.items()] +
                     cmake_flags + [self._test_suite_dir()] +
                     ['-D%s=%s' % (k, v) for k, v in defs.items()])
        if execute:
            self._check_call(cmake_cmd, cwd=path)

        return cmake_cmd

    def _collect_pgo(self, path):
        extra_defs = ["TEST_SUITE_PROFILE_GENERATE=On",
                      "TEST_SUITE_PROFILE_USE=Off",
                      "TEST_SUITE_RUN_TYPE=train"]
        self._configure(path, extra_cmake_defs=extra_defs)
        self._clean(self._base_path)
        self._build(path)
        self._install_benchmark(path)
        self._lit(path, True, False)

    def _build(self, path):
        cmake_cmd = self.opts.cmake

        subdir = path
        target = 'all'
        if self.opts.only_test:
            components = [path] + [self.opts.only_test[0]]
            if self.opts.only_test[1]:
                target = self.opts.only_test[1]
            subdir = os.path.join(*components)

        logger.info('Building...')
        try:
            self._check_call([cmake_cmd,
                              '--build', '.',
                              '-t', target,
                              '-j', str(self._build_threads())] +
                             ([] if self.opts.succinct else ["-v"]) +
                             ["--"] + shlex.split(self.opts.build_tool_options),
                             cwd=subdir)
        except subprocess.CalledProcessError:
            # cmake is expected to exit with code 1 if there was any build
            # failure. Build failures are not unexpected when testing an
            # experimental compiler.
            pass

    def _install_benchmark(self, path):
        if self.remote_run:
            cmake_cmd = self.opts.cmake
            self._check_call([cmake_cmd, '--build', '.', '-t', 'rsync'], cwd=path)

    def _lit(self, path, test, profile):
        lit_cmd = self.opts.lit

        output_json_path = tempfile.NamedTemporaryFile(prefix='output',
                                                       suffix='.json',
                                                       dir=path,
                                                       delete=False)
        output_json_path.close()

        subdir = path
        if self.opts.only_test:
            components = [path] + [self.opts.only_test[0]]
            subdir = os.path.join(*components)

        extra_args = []
        if not test:
            extra_args = ['--no-execute']

        nr_threads = self._test_threads()
        if profile:
            if nr_threads != 1:
                logger.warning('Gathering profiles with perf requires -j 1 ' +
                               'as perf record cannot be run multiple times ' +
                               'simultaneously. Overriding -j %s to -j 1' %
                               nr_threads)
                nr_threads = 1
            extra_args += ['--param', 'profile=perf']
            if self.opts.perf_events:
                extra_args += ['--param',
                               'perf_profile_events=%s' %
                               self.opts.perf_events]

        if self.opts.filter:
            extra_args += ['--filter', self.opts.filter]
        if self.opts.filter_out:
            extra_args += ['--filter-out', self.opts.filter_out]

        logger.info('Testing...')
        try:
            self._check_call([lit_cmd,
                              '-v',
                              '-j', str(nr_threads),
                              '--order=lexical',
                              subdir,
                              '-o', output_json_path.name] + extra_args)
        except subprocess.CalledProcessError:
            # LIT is expected to exit with code 1 if there were test
            # failures!
            pass
        try:
            with open(output_json_path.name) as f:
                return json.loads(f.read())
        except ValueError as e:
            fatal("Running test-suite did not create valid json report "
                  "in {}: {}".format(output_json_path.name, e))

    def _is_pass_code(self, code):
        return code in ('PASS', 'XPASS', 'XFAIL')

    def _get_lnt_code(self, code):
        return {
            'FAIL': FAIL,
            'NOEXE': FAIL,
            'PASS': PASS,
            'UNRESOLVED': FAIL,
            'XFAIL': XFAIL,
            'XPASS': FAIL,
        }[code]

    def _extract_cmake_vars_from_cache(self):
        assert self.configured is True
        cmake_lah_output = self._check_output(
            [self.opts.cmake] + ['-LAH', '-N'] + [self._base_path],
            universal_newlines=True)
        pattern2var = [
            (re.compile("^%s:[^=]*=(.*)$" % cmakevar), cmakevar)
            for cmakevar in (
                "CMAKE_C_COMPILER",
                "CMAKE_BUILD_TYPE",
                "CMAKE_CXX_FLAGS",
                "CMAKE_CXX_FLAGS_DEBUG",
                "CMAKE_CXX_FLAGS_MINSIZEREL",
                "CMAKE_CXX_FLAGS_RELEASE",
                "CMAKE_CXX_FLAGS_RELWITHDEBINFO",
                "CMAKE_C_FLAGS",
                "CMAKE_C_FLAGS_DEBUG",
                "CMAKE_C_FLAGS_MINSIZEREL",
                "CMAKE_C_FLAGS_RELEASE",
                "CMAKE_C_FLAGS_RELWITHDEBINFO",
                "CMAKE_C_COMPILER_TARGET",
                "CMAKE_CXX_COMPILER_TARGET",
                "CMAKE_OBJDUMP")]
        cmake_vars = {}
        for line in cmake_lah_output.split("\n"):
            for pattern, varname in pattern2var:
                m = re.match(pattern, line)
                if m:
                    cmake_vars[varname] = m.group(1)
        return cmake_vars

    def _get_cc_info(self, cmake_vars):
        build_type = cmake_vars["CMAKE_BUILD_TYPE"]
        cflags = cmake_vars["CMAKE_C_FLAGS"]
        if build_type != "":
            cflags = \
                " ".join(cflags.split(" ") +
                         cmake_vars["CMAKE_C_FLAGS_" + build_type.upper()]
                         .split(" "))
        # FIXME: this probably needs to be conditionalized on the compiler
        # being clang. Or maybe we need a get_cc_info that uses cmake somehow?
        if "CMAKE_C_COMPILER_TARGET" in cmake_vars:
            cflags += " --target=" + cmake_vars["CMAKE_C_COMPILER_TARGET"]
        target_flags = shlex.split(cflags)

        return get_cc_info(
            cmake_vars["CMAKE_C_COMPILER"], target_flags)

    def _parse_lit_output(self, path, data, cmake_vars, only_test=False):
        LIT_METRIC_TO_LNT = {
            'compile_time': 'compile',
            'exec_time': 'exec',
            'score': 'score',
            'hash': 'hash',
            'link_time': 'compile',
            'size..text': 'code_size',
            # On Darwin, the section name is reported as `__text`.
            'size.__text': 'code_size',
            'mem_bytes': 'mem',
            'link_mem_bytes': 'mem'
        }
        LIT_METRIC_CONV_FN = {
            'compile_time': float,
            'exec_time': float,
            'score': float,
            'hash': str,
            'link_time': float,
            'size..text': float,
            # On Darwin, the section name is reported as `__text`.
            'size.__text': float,
            'mem_bytes': float,
            'link_mem_bytes': float
        }

        test_samples = []

        # FIXME: Populate with keys not to upload
        ignore = self.opts.exclude_stat_from_submission
        if only_test:
            ignore.append('compile')

        profiles_to_import = []
        no_errors = True

        for test_data in data['tests']:
            code = test_data['code']
            raw_name = test_data['name']

            split_name = raw_name.split(' :: ', 1)
            if len(split_name) > 1:
                name = split_name[1]
            else:
                name = split_name[0]

            if name.endswith('.test'):
                name = name[:-5]
            name = 'nts.' + name

            # If --single-result is given, exit based on
            # --single-result-predicate
            is_pass = self._is_pass_code(code)
            if self.opts.single_result and \
               raw_name == self.opts.single_result + '.test':
                env = {'status': is_pass}
                if 'metrics' in test_data:
                    for k, v in test_data['metrics'].items():
                        env[k] = v
                        if k in LIT_METRIC_TO_LNT:
                            env[LIT_METRIC_TO_LNT[k]] = v
                status = eval(self.opts.single_result_predicate, {}, env)
                sys.exit(0 if status else 1)

            if 'metrics' in test_data:
                for k, v in sorted(test_data['metrics'].items()):
                    if k == 'profile':
                        profiles_to_import.append((name, v))
                        continue

                    if k not in LIT_METRIC_TO_LNT or \
                       LIT_METRIC_TO_LNT[k] in ignore:
                        continue
                    server_name = name + '.' + LIT_METRIC_TO_LNT[k]

                    if k == 'link_time' or k == 'link_mem_bytes':
                        # Move link time into a second benchmark's
                        # compile-time.
                        server_name = name + '-link.' + LIT_METRIC_TO_LNT[k]

                    test_samples.append(
                        TestSamples(server_name, [v], LIT_METRIC_CONV_FN[k]))

            if code == 'NOEXE':
                test_samples.append(
                    TestSamples(name + '.compile.status', [FAIL]))
                no_errors = False

            elif not is_pass:
                lnt_code = self._get_lnt_code(test_data['code'])
                test_samples.append(
                    TestSamples(name + '.exec.status', [lnt_code]))
                no_errors = False

        # Now import the profiles in parallel.
        if profiles_to_import:
            logger.info('Importing %d profiles with %d threads...' %
                        (len(profiles_to_import), multiprocessing.cpu_count()))
            TIMEOUT = 800
            try:
                pool = multiprocessing.Pool()
                func = partial(_importProfile, self.opts.lnt,
                               cmake_vars["CMAKE_OBJDUMP"])
                waiter = pool.map_async(func, profiles_to_import)
                samples = waiter.get(TIMEOUT)
                test_samples.extend([sample
                                     for sample in samples
                                     if sample is not None])
            except multiprocessing.TimeoutError:
                logger.warning('Profiles had not completed importing after ' +
                               '%s seconds.' % TIMEOUT)
                logger.info('Aborting profile import and continuing')

        if self.opts.single_result:
            # If we got this far, the result we were looking for didn't exist.
            raise RuntimeError("Result %s did not exist!" %
                               self.opts.single_result)

        # FIXME: Add more machine info!
        run_info = {
            'tag': 'nts',
            'no_errors': no_errors,
        }
        run_info.update(self._get_cc_info(cmake_vars))
        run_info['run_order'] = run_info['inferred_run_order']
        if self.opts.run_order:
            run_info['run_order'] = self.opts.run_order

        machine = Machine(self.opts.label)
        run = Run(self.start_time, timestamp(), info=run_info)
        report = Report(machine, run, test_samples)
        return report

    def _unix_quote_args(self, s):
        return ' '.join(map(shlex.quote, shlex.split(s)))

    def _cp_artifacts(self, src, dest, patts):
        """Copy artifacts out of the build """
        for patt in patts:
            for file in glob.glob(src + patt):
                shutil.copy(file, dest)
                logger.info(file + " --> " + dest)

    def diagnose(self):
        """Build a triage report that contains information about a test.

        This is an alternate top level target for running the test-suite.  It
        will produce a triage report for a benchmark instead of running the
        test-suite normally. The report has stuff in it that will be useful
        for reproducing and diagnosing a performance change.
        """
        assert self.opts.only_test, "We don't have a benchmark to diagnose."
        bm_path, short_name = self.opts.only_test
        assert bm_path, "The benchmark path is empty?"

        report_name = "{}.report".format(short_name)
        # Make a place for the report.
        report_path = os.path.abspath(report_name)

        # Overwrite the report.
        if os.path.exists(report_path):
            shutil.rmtree(report_path)
        os.mkdir(report_path)

        path = self._base_path
        mkdir_p(path)
        os.chdir(path)

        # Run with -save-temps
        cmd = self._configure(path, execute=False)
        cmd_temps = cmd + ['-DTEST_SUITE_DIAGNOSE_FLAGS=-save-temps']

        logger.info(' '.join(cmd_temps))

        out = subprocess.check_output(cmd_temps, universal_newlines=True)
        logger.info(out)

        # Figure out our test's target.
        cmake_cmd = [self.opts.cmake, '--build', '.', '-t', 'help']

        cmake_targets = subprocess.check_output(cmake_cmd,
                                                universal_newlines=True)
        matcher = re.compile(r"^\.\.\.\s{}$".format(short_name),
                             re.MULTILINE | re.IGNORECASE)
        if not matcher.search(cmake_targets):
            assert False, "did not find benchmark, nestsed? Unimplemented."

        local_path = os.path.join(path, bm_path)

        cmake_deps = [self.opts.cmake, "--build", '.', "-t", "timeit-target",
                      "timeit-host", "fpcmp-host"]
        logger.info(" ".join(cmake_deps))
        p = subprocess.Popen(cmake_deps,
                             stdout=subprocess.PIPE,
                             stderr=subprocess.STDOUT,
                             universal_newlines=True)
        std_out, std_err = p.communicate()
        logger.info(std_out)

        cmake_save_temps = [self.opts.cmake, "--build", '.', "-t", short_name]
        logger.info(" ".join(cmake_save_temps))
        p = subprocess.Popen(cmake_save_temps,
                             stdout=subprocess.PIPE,
                             stderr=subprocess.STDOUT,
                             universal_newlines=True)
        std_out, std_err = p.communicate()
        logger.info(std_out)
        with open(report_path + "/build.log", 'w') as f:
            f.write(std_out)
        # Executable(s) and test file:
        shutil.copy(os.path.join(local_path, short_name), report_path)
        shutil.copy(os.path.join(local_path, short_name + ".test"),
                    report_path)
        # Temp files are in:
        temp_files = os.path.join(local_path, "CMakeFiles",
                                  short_name + ".dir")

        save_temps_file = ["/*.s", "/*.ii", "/*.i", "/*.bc"]
        build_files = ["/*.o", "/*.time", "/*.cmake", "/*.make",
                       "/*.includecache", "/*.txt"]
        self._cp_artifacts(local_path, report_path, save_temps_file)
        self._cp_artifacts(temp_files, report_path, build_files)

        # Now lets do -ftime-report.
        cmd_time_report = cmd + ['-DTEST_SUITE_DIAGNOSE_FLAGS=-ftime-report']

        logger.info(' '.join(cmd_time_report))

        out = subprocess.check_output(cmd_time_report, universal_newlines=True)
        logger.info(out)

        cmake_time_report = [self.opts.cmake, "--build", '.', "-t", short_name]
        p = subprocess.Popen(cmake_time_report,
                             stdout=subprocess.PIPE,
                             stderr=subprocess.PIPE,
                             universal_newlines=True)
        std_out, std_err = p.communicate()

        with open(report_path + "/time-report.txt", 'w') as f:
            f.write(std_err)
        logger.info("Wrote: " + report_path + "/time-report.txt")

        # Now lets do -llvm -stats.
        cmd_stats_report = cmd + ['-DTEST_SUITE_DIAGNOSE_FLAGS=-mllvm -stats']

        logger.info(' '.join(cmd_stats_report))

        out = subprocess.check_output(cmd_stats_report,
                                      universal_newlines=True)
        logger.info(out)

        cmake_stats_report = [self.opts.cmake, "--build", '.', "-t", short_name]
        p = subprocess.Popen(cmake_stats_report,
                             stdout=subprocess.PIPE,
                             stderr=subprocess.PIPE,
                             universal_newlines=True)
        std_out, std_err = p.communicate()

        with open(report_path + "/stats-report.txt", 'w') as f:
            f.write(std_err)
        logger.info("Wrote: " + report_path + "/stats-report.txt")

        #  Collect Profile:
        if "Darwin" in platform.platform():
            # For testing and power users, lets allow overrides of how sudo
            # and iprofiler are called.
            sudo = os.getenv("SUDO_CMD", "sudo")
            if " " in sudo:
                sudo = sudo.split(" ")
            if not sudo:
                sudo = []
            else:
                sudo = [sudo]
            iprofiler = os.getenv("IPROFILER_CMD",
                                  "iprofiler -timeprofiler -I 40u")

            cmd_iprofiler = cmd + ['-DTEST_SUITE_RUN_UNDER=' + iprofiler]
            print(' '.join(cmd_iprofiler))

            subprocess.check_output(cmd_iprofiler, universal_newlines=True)

            os.chdir(local_path)
            cmake_iprofiler_temps = [self.opts.cmake, "--build", '.', "-t", short_name]
            p = subprocess.Popen(cmake_iprofiler_temps,
                                 stdout=subprocess.PIPE,
                                 stderr=subprocess.PIPE)
            p.communicate()
            logger.warning("Using sudo to collect execution trace.")
            make_save_temps = sudo + [self.opts.lit, short_name + ".test"]
            p = subprocess.Popen(make_save_temps,
                                 stdout=subprocess.PIPE,
                                 stderr=subprocess.PIPE,
                                 universal_newlines=True)
            std_out, std_err = p.communicate()
            sys.stdout.write(std_out)
            sys.stderr.write(std_err)
            logger.warning("Tests may fail because of iprofiler's output.")
            # The dtps file will be saved as root, make it so
            # that we can read it.
            chmod = sudo + ["chown", "-R", getpass.getuser(),
                            short_name + ".dtps"]
            subprocess.call(chmod)
            profile = local_path + "/" + short_name + ".dtps"
            shutil.copytree(profile, report_path + "/" + short_name + ".dtps")
            logger.info(profile + "-->" + report_path)
        else:
            logger.warning("Skipping execution profiling because " +
                           "this is not Darwin.")
        logger.info("Report produced in: " + report_path)


@click.command("run-test-suite.py", short_help=str(__doc__))
@click.argument("label", default=platform.uname()[1], required=False,
                type=click.UNPROCESSED)
# Sandbox options
@click.option("-S", "--sandbox", "sandbox_path", required=True,
              help="Parent directory to build and run tests in",
              type=click.UNPROCESSED, metavar="PATH")
@click.option("--timestamp/--no-timestamp", "timestamp_build", default=True, show_default=True,
              help="Whether to timestamp the build directory (for testing)")
@click.option("--configure/--no-configure", "run_configure", default=True, show_default=True,
              help="Whether to run CMake if CMakeCache.txt is present (--no-configure is only "
                   "useful with --no-timestamp)")
# Inputs
@click.option("--test-suite", "test_suite_root",
              type=click.UNPROCESSED, metavar="PATH",
              help="Path to the LLVM test-suite sources")
@click.option("--test-externals", "test_suite_externals",
              type=click.UNPROCESSED, metavar="PATH",
              help="Path to the LLVM test-suite externals")
@click.option("-D", "--cmake-define", "cmake_defines",
              multiple=True,
              help="Defines to pass to cmake. These do not require the "
                   "-D prefix and can be given multiple times. e.g.: "
                   "--cmake-define A=B => -DA=B")
@click.option("-C", "--cmake-cache", "cmake_cache", multiple=True,
              default=[],
              help="Use one of the test-suite's cmake configurations."
                   " Ex: Release, Debug")
@click.option("--cmake-toolchain", metavar="PATH", type=click.UNPROCESSED,
              default=None,
              help="Path to a CMake toolchain file to use")
# Test compiler
@click.option("--cc", "cc", metavar="CC", type=click.UNPROCESSED,
              default=None,
              help="Path to the C compiler to test")
@click.option("--cxx", "cxx", metavar="CXX", type=click.UNPROCESSED,
              default=None,
              help="Path to the C++ compiler to test (inferred from"
                   " --cc where possible")
@click.option("--cppflags", "cppflags", type=click.UNPROCESSED,
              multiple=True, default=[],
              help="Extra flags to pass the compiler in C or C++ mode. "
                   "Can be given multiple times")
@click.option("--cflags", "--cflag", "cflags", type=click.UNPROCESSED,
              multiple=True, default=[],
              help="Extra CFLAGS to pass to the compiler. Can be "
                   "given multiple times")
@click.option("--cxxflags", "cxxflags", type=click.UNPROCESSED,
              multiple=True, default=[],
              help="Extra CXXFLAGS to pass to the compiler. Can be "
                   "given multiple times")
# Test selection
@click.option("--test-size", "test_size",
              type=click.Choice(['small', 'regular', 'large']),
              default='regular', help="The size of test inputs to use")
@click.option("--benchmarking-only", "benchmarking_only", is_flag=True,
              help="Benchmarking-only mode. Disable unit tests and "
                   "other flaky or short-running tests")
@click.option("--only-test", "only_test", metavar="PATH",
              type=click.UNPROCESSED, default=None,
              help="Only run tests under PATH")
@click.option("--filter", metavar="REGEX",
              help="Only run tests with paths matching the given regular "
                   "expression")
@click.option("--filter-out", metavar="REGEX",
              help="Filter out tests with paths matching the given regular "
                   "expression")
# Test Execution
@click.option("--only-compile", "only_compile",
              help="Don't run the tests, just compile them.", is_flag=True)
@click.option("-j", "--threads", "threads",
              help="Number of testing (and optionally build) "
              "threads", type=int, default=1, metavar="N")
@click.option("--build-threads", "build_threads",
              help="Number of compilation threads, defaults to --threads",
              type=int, default=0, metavar="N")
@click.option("--use-perf", "use_perf",
              help="Use Linux perf for high accuracy timing, profile "
                   "information or both",
              type=click.Choice(['none', 'time', 'profile', 'all']),
              default='none')
@click.option("--perf-events", "perf_events",
              help=("Define which linux perf events to measure"),
              type=click.UNPROCESSED, default=None)
@click.option("--run-under", "run_under", default="",
              help="Wrapper to run tests under", type=click.UNPROCESSED)
@click.option("--exec-multisample", "exec_multisample",
              help="Accumulate execution test data from multiple runs",
              type=int, default=1, metavar="N")
@click.option("--compile-multisample", "compile_multisample",
              help="Accumulate compile test data from multiple runs",
              type=int, default=1, metavar="N")
@click.option("--drop-exec", "drop_exec",
              help="Drop the first N execution samples to mitigate warmup effects. "
                   "Used with --exec-multisample.",
              type=int, default=None, metavar="N")
@click.option("-d", "--diagnose", "diagnose",
              help="Produce a diagnostic report for a particular "
                   "test, this will not run all the tests.  Must be"
                   " used in conjunction with --only-test.",
              is_flag=True, default=False,)
@click.option("--pgo", "pgo",
              help="Run the test-suite in training mode first and"
                   " collect PGO data, then rerun with that training "
                   "data.",
              is_flag=True, default=False,)
@click.option("--remote-host", metavar="HOST",
              help="Run tests on a remote machine")
@click.option("--build", "build",
              help="Only build the tests, don't execute them. Useful for "
                   "preparing builds for later interleaved execution.",
              is_flag=True, default=False)
@click.option("--exec", "exec_mode",
              help="Only execute tests from pre-built directory, skip configure "
                   "and build steps. Requires --build-dir to specify the "
                   "build directory. Default behavior is to both build and execute.",
              is_flag=True, default=False)
@click.option("--build-dir", "build_dir",
              metavar="PATH",
              help="Path to pre-built test directory (used with --exec). "
                   "This is the actual build directory (e.g., sandbox/build), "
                   "not the sandbox parent directory.",
              type=click.UNPROCESSED, default=None)
@click.option("--exec-interleaved-builds", "exec_interleaved_builds",
              metavar="BUILD1,BUILD2,...",
              help="Comma-separated list of build directories to interleave "
                   "execution from. Implies --exec. Each path should be "
                   "a build directory (e.g., sandbox/build). For each multisample, "
                   "runs all tests from each build in sequence to control for "
                   "environmental changes.",
              type=click.UNPROCESSED, default=None)
# Output Options
@click.option("--auto-name/--no-auto-name", "auto_name", default=True, show_default=True,
              help="Whether to automatically derive the submission name")
@click.option("--run-order", "run_order", metavar="STR",
              help="String to use to identify and order this run")
@click.option("--submit", "submit_url", metavar="URLORPATH",
              help="autosubmit the test result to the given server"
                   " (or local instance)",
              type=click.UNPROCESSED, default=None)
@click.option("--output", "output", metavar="PATH",
              help="write raw report data to PATH (or stdout if '-')",
              default=None)
@click.option("--report-format", "report_formats", multiple=True,
              type=click.Choice(['v1', 'v5']), default=['v1'],
              show_default=True,
              help="The format of the report: v1 for LNT v4 (report.json), "
                   "v5 for LNT v5 (report.v5.json). Can be given twice to "
                   "write both")
@click.option("--output-v5", "output_v5", metavar="PATH", default=None,
              help="also write the v5 report to PATH")
@click.option("--commit", "commit", metavar="VALUE", default=None,
              help="The commit the v5 report is for, e.g. the git SHA the "
                   "compiler was built from (required for v5)")
@click.option("--commit-ordinal", "commit_ordinal", metavar="N",
              type=click.IntRange(-2**31, 2**31 - 1), default=None,
              help="The commit's position in the order of commits, in the v5 "
                   "report. Without it, the commit has no ordinal")
@click.option("--succinct-compile-output", "succinct",
              help="run CMake without -v", is_flag=True)
@click.option("-v", "--verbose", "verbose", is_flag=True, default=False,
              help="show verbose test results")
@click.option("--exclude-stat-from-submission",
              "exclude_stat_from_submission",
              help="Do not submit the stat of this type (v1 only)",
              multiple=True, default=[],
              type=click.Choice(KNOWN_SAMPLE_KEYS))
@click.option("--single-result", "single_result",
              help="only execute this single test and apply "
                   "--single-result-predicate to calculate the exit "
                   "status")
@click.option("--single-result-predicate", "single_result_predicate",
              help="the predicate to apply to calculate the exit "
                   "status (with --single-result)", default="status")
# Test tools
@click.option("--use-cmake", "cmake", metavar="PATH",
              type=click.UNPROCESSED, default="cmake",
              help="Path to CMake [cmake]")
@click.option("--use-make", "make", metavar="PATH",
              type=click.UNPROCESSED,
              help="Path to the build system tool [make/ninja/...]")
@click.option("--build-tool-options", default="",
              help="Options to pass to the build system tool",
              type=click.UNPROCESSED)
@click.option("--use-lit", "lit", metavar="PATH", type=click.UNPROCESSED,
              default="llvm-lit",
              help="Path to the LIT test runner [llvm-lit]")
@click.option("--use-lnt", "lnt", metavar="PATH", type=click.UNPROCESSED,
              default=None,
              help="Path to the LNT command line tool [the lnt installed "
                   "along with this Python, or else lnt]")
# Submission
@click.option("--merge", default="replace", show_default=True,
              type=click.Choice(['reject', 'replace', 'append']),
              help="Merge strategy when run already exists")
@click.option("--select-machine", default='match',
              type=click.Choice(['match', 'update', 'split']),
              help="How to select and create missing machine")
def cli_action(*args, **kwargs):
    """Build and run the LLVM test-suite, and write a report for LNT."""
    init_logging()
    opts = types.SimpleNamespace(**kwargs)
    TestSuiteTest(opts).run_test()
