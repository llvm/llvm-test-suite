##===- Makefile --------------------------------------------*- Makefile -*-===##
#
# This makefile contains information for building the SPEC2006 bzip2 test.
#
##===----------------------------------------------------------------------===##

LEVEL = ../../../..

RUN_OPTIONS = `head -n 1 $(REF_IN_DIR)control`

ifeq ($(RUN_TYPE),test)
  STDOUT_FILENAME := input.compressed.out
else
  STDOUT_FILENAME := input.combined.out
endif

include ../../Makefile.spec2006
