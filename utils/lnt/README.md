# Running the test-suite for LNT

`run-test-suite.py` configures the LLVM test-suite with CMake, builds it, runs
it with lit, and writes the results as a report that [LNT](https://llvm.org/docs/lnt/)
can import. It can also submit the report to an LNT instance.

## Setup

The script needs Python 3, with the packages listed in `requirements.txt`:

    pip install -r utils/lnt/requirements.txt

It also needs CMake, a build tool, and lit (`pip install lit`, or `llvm-lit`
from an LLVM build).

## Running the test-suite

    utils/lnt/run-test-suite.py --sandbox /tmp/sandbox \
                                --cc /path/to/clang \
                                --test-suite /path/to/llvm-test-suite \
                                --use-lit lit \
                                --cmake-cache Release

`--sandbox` is the directory where the test-suite is built and run, inside a
timestamped subdirectory by default. `--test-suite` is the checkout of the
test-suite to build, normally this checkout. The report is written to `report.json`
in the build directory.

See `run-test-suite.py --help` for all of the options, and [LNT's documentation](https://llvm.org/docs/lnt/tests.html)
for more details on running the test-suite with LNT.
