LEVEL = ../../../../../..

RUN_OPTIONS     = `cat $(REF_IN_DIR)control`
ifeq ($(RUN_TYPE),test)
STDOUT_FILENAME := input.random.out
else
STDOUT_FILENAME := input.compressed.out
endif

include ../../Makefile.spec2000
