LEVEL = ../../../..
RUN_OPTIONS     = 
STDIN_FILENAME  = ammp.in
STDOUT_FILENAME = ammp.out
CPPFLAGS =
# override RUN_TYPE (this is a long running test):
ifndef RUN_TYPE
ifdef LARGE_PROBLEM_SIZE
RUN_TYPE  := ref
else
RUN_TYPE  := train
endif
endif
include ../../Makefile.spec2000
