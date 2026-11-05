#!/usr/bin/env python3
"""Run the LLVM test-suite and write a report that LNT can import.

See README.md in this directory for how to use it.
"""
from test_suite_runner import cli_action

# Profiles are imported with multiprocessing, which may import this script
# again in each worker process.
if __name__ == "__main__":
    cli_action()
