import lit.Test
import logging
import os.path


def _getCodeSize(context):
    size = os.path.getsize(context.executable)
    return {'size': lit.Test.toMetricValue(size)}


def mutatePlan(context, plan):
    plan.metric_collectors.append(_getCodeSize)
