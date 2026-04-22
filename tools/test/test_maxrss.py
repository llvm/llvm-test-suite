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

    expected_min = ALLOC_MiB * 1024 * 1024
    if maxrss < expected_min:
        print("maxrss too low: %d < %d" % (maxrss, expected_min))
        sys.exit(1)

finally:
    os.unlink(summary)
