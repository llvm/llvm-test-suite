LEVEL = ../..
PARALLEL_DIRS  = SingleSource MultiSource

include ${LEVEL}/test/Makefile.tests

# Include all makefiles which define tests... These makefiles must define
# test.<testname>.%  given input from Output/%.llvm.bc
#
ifdef TEST
TestMakefile := $(wildcard $(LEVEL)/test/Programs/Makefile.TEST.$(TEST))
ifneq ($(TestMakefile),)
-include $(TestMakefile)
endif
endif

