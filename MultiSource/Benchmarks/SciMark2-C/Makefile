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
else
ifeq ($(ARCH),AArch64)
# On AArch64 at -O0 we get very close to 500s and sometimes we go over the
# threshold. Set it to a more comfortable value.
RUNTIMELIMIT := 750
endif
endif
ifdef LARGE_PROBLEM_SIZE
RUN_OPTIONS = -large
endif
endif

include	../../Makefile.multisrc
