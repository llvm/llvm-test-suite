LEVEL = ../../../../../..
RUN_OPTIONS     = 2.1.dict -batch
STDIN_FILENAME  = $(RUN_TYPE).in
STDOUT_FILENAME = $(RUN_TYPE).out
CPPFLAGS =

SPEC_BENCH_DIR := /home/vadve/shared/benchmarks/speccpu2000/benchspec/CINT2000/197.parser/

Source = $(addprefix $(SPEC_BENCH_DIR)/src/, \
analyze-linkage.c and.c build-disjuncts.c extract-links.c fast-match.c idiom.c main.c massage.c parse.c post-process.c print.c prune.c read-dict.c strncasecmp.c utilities.c word-file.c )  \
   xa.c

include ../../Makefile.spec2000
