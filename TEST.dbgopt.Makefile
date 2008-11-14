##===- TEST.dbgopt.Makefile --------------------------------*- Makefile -*-===##
#
# This test checks whether presense of debugging information influences
# the optimizer or not. 
#
# If input.bc includes llvm.dbg intrinsics and llvm.dbg variables then
# first.bc and second.bc should match. Otherwise debugging information
# is influencing the optimizer.
#
# $ opt input.bc -strip -std-compile-output -o first.bc
# $ opt input.bc -std-compile-output -strip -o second.bc
#
##===----------------------------------------------------------------------===##

TESTNAME = $*

$(PROGRAMS_TO_TEST:%=test.$(TEST).%): \
test.$(TEST).%: Output/%.diff

Output/%.diff: %.cpp Output/.dir $(LLVMGXX) $(LOPT) $(LDIS)
	$(LLVMGXX) $*.cpp -g --emit-llvm -c -o Output/$*.bc 
	$(LOPT) Output/$*.bc -strip -std-compile-opts -f -o Output/$*.bc 
	$(LDIS) Output/$*.bc -f -o Output/$*.first.ll 
	$(LOPT) Output/$*.bc -std-compile-opts -strip -f -o Output/$*.bc 
	$(LDIS) Output/$*.bc -f -o Output/$*.second.ll 
	@-if diff Output/$*.first.ll Output/$*.second.ll > Output/$*.diff; then \
	 echo "--------- TEST-PASS: $*"; \
	else \
	 echo "--------- TEST-FAIL: $*"; \
	fi


Output/%.diff: %.c Output/.dir $(LLVMGCC) $(LOPT) $(LDIS)
	$(LLVMGCC) $*.c -g --emit-llvm -c -o Output/$*.bc 
	$(LOPT) Output/$*.bc -strip -std-compile-opts -f -o Output/$*.bc 
	$(LDIS) Output/$*.bc -f -o Output/$*.first.ll 
	$(LOPT) Output/$*.bc -std-compile-opts -strip -f -o Output/$*.bc 
	$(LDIS) Output/$*.bc -f -o Output/$*.second.ll 
	@-if diff Output/$*.first.ll Output/$*.second.ll > Output/$*.diff; then \
	 echo "--------- TEST-PASS: $*"; \
	else \
	 echo "--------- TEST-FAIL: $*"; \
	fi
