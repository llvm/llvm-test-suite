##===- test/Programs/Makefile.TEST.example -----------------*- Makefile -*-===##
#
# Example to show a custom test.  This test just prints the size of the bytecode
# file for each program.
#
##===----------------------------------------------------------------------===##

TESTNAME = $(subst test.example.,,$@)

test.example.%: Output/%.llvm.bc
	@echo "========================================="
	@echo "Running 'example' test on '$(TESTNAME)' program"
	wc $<
