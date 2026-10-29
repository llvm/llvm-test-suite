"""Test that timeit --report-maxrss reports a valid max RSS value.

Usage: test_maxrss.py <timeit> <alloc_mem>
"""
import os
import subprocess
import sys
import tempfile

ALLOC_MiB = 128

timeit = sys.argv[1]
alloc_mem = sys.argv[2]

with tempfile.NamedTemporaryFile(suffix=".time", delete=False) as f:
    summary = f.name

try:
    result = subprocess.run(
        [timeit, "--report-maxrss", "--summary", summary, alloc_mem, str(ALLOC_MiB)]
    )
    if result.returncode != 0:
        print("timeit exited with %d" % result.returncode)
        sys.exit(1)

    with open(summary) as f:
        contents = f.read()

    maxrss = None
    for line in contents.splitlines():
        if line.startswith("maxrss"):
            maxrss = int(line.split()[1])
            break

    if not maxrss:
        print("maxrss line not found in summary:\n%s" % contents)
        sys.exit(1)

    # The absolute value of maxrss reported by the OS is not strictly reliable,
    # thus we conservatively just check we could capture any number > 0, and not
    # a number that is strictly larger than ALLOC_MiB * 1024 * 1024, for example.
    # See: https://github.com/llvm/llvm-test-suite/pull/373
    if not maxrss > 0:
        print("maxrss is zero")
        sys.exit(1)

finally:
    os.unlink(summary)
