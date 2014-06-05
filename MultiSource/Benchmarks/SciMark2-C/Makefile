LEVEL = ../../..
PROG       = scimark2
CPPFLAGS   = 
LDFLAGS    = -lm

ifeq ($(ARCH),XCore)
ifndef SMALL_PROBLEM_SIZE
# XCore target takes over 9hours to complete a medium sized problem.
RUNTIMELIMIT := 50000
# Ignore 'LARGE_PROBLEM_SIZE' requests
endif
else
ifeq ($(ARCH),Mips)
# Mips takes ~50 minutes.
RUNTIMELIMIT := 3000
endif
ifdef LARGE_PROBLEM_SIZE
RUN_OPTIONS = -large
endif
endif

include	../../Makefile.multisrc
