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

## Reports for LNT v5

With `--report-format v5`, the script writes a report for [LNT v5](https://lnt.llvm.org)
to `report.v5.json` in the build directory. These reports follow the schema in [`schema.json`](schema.json).
The `--report-format` argument can be passed twice to write reports in both formats.

Since LNT v5 does not infer the commit that a run is associated to, it must be passed
with `--commit` (e.g. the git SHA of the compiler under test). If the commit should be
ordered with other commits (e.g. it is a commit on `main`, as opposed to a throwaway
commit like a PR), its position should be passed with `--commit-ordinal`:

    utils/lnt/run-test-suite.py ... --report-format v5 \
                                    --commit 0123abc --commit-ordinal 598181

`run-test-suite.py` doesn't submit v5 reports itself. Submit them with `lnt v5 submit`,
which reads its token from `LNT_TOKEN`:

    lnt v5 submit https://lnt.example.com --suite llvm_test_suite report.v5.json
