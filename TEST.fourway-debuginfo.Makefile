##===- TEST.fourway.Makefile -------------------------------*- Makefile -*-===##
#
# This test tries running the gcc and llvm-gcc compilers on all of the programs
# with and without debuginfo and reports on resulting sizes.
#
##===----------------------------------------------------------------------===##

include $(LEVEL)/fourway.Makefile

$(PROGRAMS_TO_TEST:%=test.$(TEST).%): \
test.$(TEST).%: $(LLVMGCC) $(LLVMGXX) \
Output/%.report.$(TEST).txt \
Output/%.gcc.nodebug.size \
Output/%.gcc.debug.size \
Output/%.llvmgcc.nodebug.size \
Output/%.llvmgcc.debug.size
	@-cat Output/$*.gcc.nodebug.size
	@-cat Output/$*.gcc.debug.size
	@-cat Output/$*.llvmgcc.nodebug.size
	@-cat Output/$*.llvmgcc.debug.size


