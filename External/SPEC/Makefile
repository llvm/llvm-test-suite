LEVEL = ../../../..
DIRS := CFP2000 CINT2000
include ${LEVEL}/Makefile.config

#
# Add SPEC95 if we've got it.
#
ifeq ($(USE_SPEC95),1)
DIRS += CINT95
endif

include ${LEVEL}/test/Programs/Makefile.programs
