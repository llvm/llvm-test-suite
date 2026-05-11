"""Test that timeit -arch correctly selects Mach-O slices on macOS.

Usage: test_arch.py <timeit> <exe>
"""
import subprocess
import sys

# Must match EXITCODE_EXEC_BADARCH in tools/timeit.c
_EXITCODE_EXEC_BADARCH = 70


def test_valid_arches(timeit, exe):
    """Check that timeit -arch <slice> runs the correct slice of exe."""

    lipo = subprocess.run(["lipo", "-archs", exe], capture_output=True, text=True)
    if lipo.returncode != 0:
        print(f"lipo failed: {lipo.stderr.strip()}")
        sys.exit(1)

    for arch in lipo.stdout.split():
        cmd = [timeit, "-arch", arch, exe]
        print(" ".join(cmd))
        result = subprocess.run(cmd, capture_output=True, text=True)
        if result.returncode == _EXITCODE_EXEC_BADARCH:
            print(f"skipping {arch}: not supported on this machine")
            continue
        if result.returncode != 0:
            print(f"timeit -arch {arch} exited with {result.returncode}")
            print(result.stderr)
            sys.exit(1)
        got = result.stdout.strip()
        if got != arch:
            print(f"timeit -arch {arch}: expected '{arch}', got '{got}'")
            sys.exit(1)


def test_invalid_arch(timeit, exe):
    """Check that timeit rejects unrecognized arch names."""

    cmd = [timeit, "-arch", "obviouslyfake", exe]
    print(" ".join(cmd))
    result = subprocess.run(cmd, capture_output=True)
    if result.returncode == 0:
        print("timeit -arch obviouslyfake should have failed but succeeded")
        sys.exit(1)


if __name__ == "__main__":
    timeit = sys.argv[1]
    exe = sys.argv[2]

    test_valid_arches(timeit, exe)
    test_invalid_arch(timeit, exe)
