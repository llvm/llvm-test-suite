#!/bin/python3

# CMake compiler wrapper which collects DebugLoc coverage tracking stats.
# Runs a DebugLoc Coverage-Tracking compiler command first, checking to see
# whether there is any missing coverage. If at least one missing location is
# found, repeat the build with Origin-Tracking enabled and accumulate the
# results into a single report file, shared across all compiler commands.

import json
import os
import shlex
import subprocess
import sys
from typing import List, Set


def get_source_and_output_files(args: List[str]):
    source_file = None
    output_file = None
    for idx, arg in enumerate(args):
        if arg == "-c" and idx + 1 < len(args):
            source_file = args[idx + 1]
        if arg == "-o" and idx + 1 < len(args):
            output_file = args[idx + 1]
    return (source_file, output_file)


def run_command(args: List[str]):
    """Runs the command with the given args, raising if the process returns a non-zero exit code."""
    subprocess.run(args).check_returncode()


def main():
    if len(sys.argv) <= 2:
        print(
            "usage: DebugifyCompilerWrapper.py <output-path> <compiler-command...>",
            file=sys.stderr,
        )
        return 1
    debugify_origin_file = sys.argv[1]
    compile_args = sys.argv[2:]

    source, output = get_source_and_output_files(compile_args)
    if source is None or output is None:
        # Assumed non-compile command, run unmodified and exit.
        print(
            f"warning: using debugify wrapper to run non-compiler-command: {shlex.join(compile_args)}",
            file=sys.stderr,
        )
        run_command(compile_args)
        return 0
    # At this point we assume we're running a valid compile command, so prepare the build args.
    debugify_coverage_file = output + ".cov.json"
    if os.path.exists(debugify_coverage_file):
        # If there's an old file lingering, remove it.
        os.remove(debugify_coverage_file)
    coverage_build_extra_args = [
        "-Xclang",
        "-fverify-debuginfo-preserve",
        "-Xclang",
        f"-fverify-debuginfo-preserve-export={debugify_coverage_file}",
        "-mllvm",
        "--debugify-quiet",
        "-mllvm",
        "-debugify-level=locations",
    ]
    run_command(compile_args + coverage_build_extra_args)

    # Now we check to see whether any coverage errors appeared; if the coverage report wasn't created, then there were
    # no errors and there is nothing more for us to do.
    if not os.path.exists(debugify_coverage_file):
        return 0

    # Coverage errors were found; determine which passes they occurred in, and re-run with origin tracking enabled for those passes.
    coverage_error_pass_set: Set[str] = set()
    with open(debugify_coverage_file) as cov_fp:
        for line in cov_fp.readlines():
            bug_report = json.loads(line.strip())
            assert (
                isinstance(bug_report, dict) and "pass" in bug_report
            ), "error: invalid bug format in coverage report"
            coverage_error_pass_set.add(bug_report["pass"])

    enable_origin_tracking_passes = ",".join(sorted(coverage_error_pass_set))
    origin_build_extra_args = [
        "-Xclang",
        "-fverify-debuginfo-preserve",
        "-Xclang",
        f"-fverify-debuginfo-preserve-export={debugify_origin_file}",
        "-mllvm",
        "--debugify-quiet",
        "-mllvm",
        "-debugify-level=locations",
        "-mllvm",
        f"-enable-origin-stacktraces={enable_origin_tracking_passes}",
    ]
    run_command(compile_args + origin_build_extra_args)
    assert os.path.exists(
        debugify_origin_file
    ), "error: missing coverage did not appear in second run?"
    return 0


if __name__ == "__main__":
    sys.exit(main())
