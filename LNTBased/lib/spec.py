#!/usr/bin/env python
# -*- Python -*-

import os
import shutil

# We import test functionity from LNT.
from lnt.tests import nt
from lnt.testing import TestSamples, PASS, FAIL, XFAIL
from lnt.testing.util import commands

# Implement cp -rf such that src can be both a file or a directory and if
# the dst exists create the file/dir under dst rather than rename on the
# fly.
def cp_rf(src, dst):
    if os.path.isfile(src):
        shutil.copy(src, dst)
    else:
        newdst = dst
        if os.path.exists(dst):
            newdst = os.path.join(dst, os.path.basename(src))
        shutil.copytree(src, newdst)

# Test module classes are currently required to subclass 'nt.TestModule'.
class TestModule(nt.TestModule):
    def __init__(self):
        # The subdirectory name under externals E.g. CINT2006
        self.suite = 'C' + self.category.upper() + str(self.year)

        # Name to identify this LNT test, e.g. nts.LNT/CINT2006_ref/456.hmmer
        self.testname = "nts.LNT/%s_ref/%s" % (self.suite, self.benchmark)

        # Executable name, e.g. 456.hmmer.simple
        self.exe = self.benchmark + '.simple'

    def configure_test_suite(self, config, working_dir):
        args = [os.path.realpath(os.path.join(config.test_suite_root,
                                              'configure'))]
        if config.without_llvm:
            args.extend(['--without-llvmsrc', '--without-llvmobj'])
        else:
            args.extend(['--with-llvmsrc=%s' % config.llvm_src_root,
                         '--with-llvmobj=%s' % config.llvm_obj_root])

        if config.test_suite_externals:
            args.append('--with-externals=%s' %
                        os.path.realpath(config.test_suite_externals))

        res = self.call(args, cwd=working_dir)
        if res != 0:
            return res
        # RunSafely requires timeit, build it.
        return self.call(['make', 'tools'], cwd=working_dir)

    def fail(self):
        return [TestSamples(self.testname + '.compile.status', [FAIL])]

    def copy_input_set(self, dest_dir, size):
        if size == 'train':
            input_set = self.train_input_set
        elif size == 'ref':
            input_set = self.ref_input_set
        else:
            fatal('only train and ref are supported for now')

        for f in input_set:
            cp_rf(os.path.join(self.datadir, f), dest_dir)

    def copy_output_set(self, dest_dir, size):
        if size == 'train':
            output_set = self.train_output_set
        else:
            output_set = self.ref_output_set

        for f in output_set:
            cp_rf(os.path.join(self.datadir, f), dest_dir)

    def execute_test(self, options, make_variables, config):
        MODULENAME = options['MODULENAME']
        self.SRCROOT = options['SRCROOT']
        OBJROOT = options['OBJROOT']
        CC = options['CC']
        CFLAGS = options['CFLAGS']
        TEST_SUITE_EXTERNALS = config.test_suite_externals

        # test-suite-externals//speccpu2006/benchspec/CPU2006/400.perlbench vs
        # test-suite-externals//speccpu2000/benchspec/CINT2000/164.gzip
        suitedir = os.path.join(TEST_SUITE_EXTERNALS, 'speccpu' + str(self.year), 'benchspec')
        if self.year == '2000':
            suitedir = os.path.join(suitedir, 'C%s2000' % self.category.upper())
        else:
            suitedir = os.path.join(suitedir, 'CPU' + self.year)

        self.datadir = os.path.join(suitedir, self.benchmark, 'data')
        print >>self.log, "%s\n  options: %s\n\nmake variables: %s\n\n" % (self.testname, str(options), str(make_variables))

        if not os.path.exists(self.datadir):
            print >>self.log, "skipping, no source under externals"
            return []

        res = self.configure_test_suite(config, OBJROOT)
        if res != 0:
            return fail()

        make_cmd = ['make', '-k']
        make_cmd.extend('%s=%s' % (k,v) for k,v in make_variables.items())
        make_cmd.append('USE_SPEC_TEST_MODULE=1')

        # Run make clean to create the benchmark directories.
        external_obj = os.path.join(OBJROOT, 'External', 'SPEC', self.suite, self.benchmark)
        clean_cmd = make_cmd
        external_spec_obj = os.path.split(external_obj)[0]
        result = self.call(make_cmd + ['-C', external_spec_obj, 'clean'])
        if result != 0:
            return self.fail()

        # From this on, we are operating in the 456.hmmer directory.
        make_cmd.extend(['-C', external_obj])
        exe_file = os.path.join('Output', self.exe)

        if config.spec_with_pgo:
            pgo_dir = os.path.join(OBJROOT, 'pgo')
            os.mkdir(pgo_dir)

            target_flags = make_variables['TARGET_FLAGS'] + ' -fprofile-instr-generate'
            pgo_make_cmd = make_cmd[:]
            pgo_make_cmd.append("TARGET_FLAGS=%s" % target_flags)
            result = self.call(pgo_make_cmd + [ exe_file ])

            exe = os.path.join(external_obj, exe_file)
            if result != 0 or not os.path.exists(exe):
                return self.fail()
            shutil.copy(exe, pgo_dir)

            self.copy_input_set(pgo_dir, 'train')

            pgo_cmd = './%s %s' % (self.exe, self.train_args)
            result = self.call(pgo_cmd, cwd=pgo_dir, shell=True)
            if result != 0:
                return self.fail()

            llvm_profdata = os.path.join(os.path.dirname(CC), 'llvm-profdata')
            result = self.call(llvm_profdata + ' merge -output=code.profdata pgo/default.profraw', shell=True, cwd=OBJROOT)
            if result != 0:
                return self.fail()

            target_flags = make_variables['TARGET_FLAGS'] + ' -fprofile-instr-use=' + os.path.join(OBJROOT, 'code.profdata')
            make_cmd.append("TARGET_FLAGS=%s" % target_flags)

            result = self.call(make_cmd + ['-C', external_spec_obj, 'clean'])
            if result != 0:
                return self.fail()

        start_time = self.get_time()
        result = self.call(make_cmd + [ exe_file ])
        compile_time = self.get_time() - start_time

        exe = os.path.join(external_obj, exe_file)
        if result != 0 or not os.path.exists(exe):
            return self.fail()

        shutil.copy(exe, OBJROOT)

        self.copy_input_set(OBJROOT, 'ref')
        self.copy_output_set(OBJROOT, 'ref')

        run_cmds = ['./%s %s' % (self.exe, args) for args in self.ref_args]
        status = PASS

        start_time = self.get_time()
        for cmd in run_cmds:
            result = self.call(cmd, cwd=OBJROOT, shell=True)
            if result != 0:
                status = FAIL
        exec_time = self.get_time() - start_time

        os.environ['PATH'] += ':' + os.path.join(OBJROOT, 'tools')
        for cmd in self.ref_cmp_cmds:
            if self.call(cmd, cwd=OBJROOT, shell=True, env=os.environ) != 0:
                status = FAIL

        return [
            TestSamples(self.testname + '.compile', [compile_time]),
            TestSamples(self.testname + '.exec', [exec_time]),
            TestSamples(self.testname + '.exec.status', [status])]
