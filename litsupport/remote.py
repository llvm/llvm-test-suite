from litsupport import testplan
import logging


def mutateCommandline(context, commandline, suffix=""):
    shfilename = context.tmpBase + suffix + ".sh"
    shfile = open(shfilename, "w")
    shfile.write(commandline + "\n")
    logging.info("Created shfile '%s'", shfilename)
    shfile.close()

    config = context.config
    remote_commandline = config.remote_client
    if config.remote_user:
        remote_commandline += " -l %s" % config.remote_user
    if config.remote_port:
        remote_commandline += " -p %s" % config.remote_port
    if config.remote_flags:
        remote_commandline += config.remote_flags
    remote_commandline += " %s" % config.remote_host
    remote_commandline += " /bin/sh %s" % shfilename
    return remote_commandline


def mutateScript(context, script, suffix=""):
    mutate = lambda c, cmd: mutateCommandline(c, cmd, suffix)
    return testplan.mutateScript(context, script, mutate)


def mutatePlan(context, plan):
    plan.preparescript = mutateScript(context, plan.preparescript, "-prepare")
    plan.runscript = mutateScript(context, plan.runscript)
