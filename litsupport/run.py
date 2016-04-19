def mutatePlan(context, plan):
    """The most basic test module: Execute the RUN:, VERIFY: and METRIC:
    scripts"""
    plan.runscript = context.parsed_runscript
    plan.verifyscript = context.parsed_verifyscript
    plan.metricscripts = context.parsed_metricscripts
