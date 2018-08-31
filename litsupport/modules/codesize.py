"""Test module to collect code size metrics of the benchmark executable."""
from litsupport import testplan
import logging
import os.path


def _getCodeSize(context):
    # First get the filesize: This should always work.
    metrics = {}
    metrics['size'] = os.path.getsize(context.executable)

    # If we have the llvm-size tool available get the size per segment.
    llvm_size = context.config.llvm_size
    if llvm_size:
        # -format=sysv is easier to parse than darwin/berkeley.
        cmdline = [llvm_size, '-format=sysv', context.executable]
        out = testplan.check_output(cmdline).decode('utf-8', errors='ignore')
        lines = out.splitlines()
        # First line contains executable name, second line should be a
        # "section   size    addr" header, numbers start after that.
        if "section" not in lines[1] or "size" not in lines[1]:
            logging.warning("Unexpected output from llvm-size on '%s'",
                            context.executable)
        else:
            for line in lines[2:]:
                line = line.strip()
                if line == "":
                    continue
                values = line.split()
                if len(values) < 2:
                    logging.info("Ignoring malformed output line: %s", line)
                    continue
                if values[0] == 'Total':
                    continue
                try:
                    name = values[0]
                    val = int(values[1])
                    metrics['size.%s' % name] = val
                except ValueError:
                    logging.info("Ignoring malformed output line: %s", line)

    return metrics


def mutatePlan(context, plan):
    plan.metric_collectors.append(_getCodeSize)
