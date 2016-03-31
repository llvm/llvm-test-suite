from litsupport import testplan
import logging


def mutateCommandline(context, commandline):
    shfilename = context.tmpBase + ".sh"
    shfile = open(shfilename, "w")
    shfile.write(commandline + "\n")
    logging.info("Created shfile '%s'", shfilename)
    shfile.close()

    config = context.config
    remote_commandline = config.remote_client
    if config.remote_user:
        remote_commandline += " -l %s" % config.remote_user
    if config.remote_port:
        remote_commandline += " -rp %s" % config.remote_port
    if config.remote_flags:
        remote_commandline += config.remote_flags
    remote_commandline += " %s" % config.remote_host
    remote_commandline += " /bin/sh %s" % shfilename
    return remote_commandline


def mutateScript(context, script):
    return testplan.mutateScript(context, script, mutateCommandline)


def mutatePlan(context, plan):
    plan.runscript = mutateScript(context, plan.runscript)
