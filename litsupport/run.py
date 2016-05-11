def mutatePlan(context, plan):
    """The most basic test module: Execute the RUN:, VERIFY: and METRIC:
    scripts"""
    plan.preparescript = context.parsed_preparescript
    plan.runscript = context.parsed_runscript
    plan.verifyscript = context.parsed_verifyscript
    plan.metricscripts = context.parsed_metricscripts
