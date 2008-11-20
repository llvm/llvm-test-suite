##===- TEST.dbgopt.Makefile --------------------------------*- Makefile -*-===##
#
# This test checks whether presense of debugging information influences
# the optimizer or not. 
#
# If input.bc includes llvm.dbg intrinsics and llvm.dbg variables then
# first.bc and second.bc should match. Otherwise debugging information
# is influencing the optimizer.
#
# $ opt input.bc -strip-nondebug -strip-debug -std-compile-output -strip -o first.bc
# $ opt input.bc -strip-nondebug -std-compile-output -strip-debug -strip -o second.bc
#
##===----------------------------------------------------------------------===##

TESTNAME = $*

$(PROGRAMS_TO_TEST:%=test.$(TEST).%): \
test.$(TEST).%: Output/%.diff

Output/%.diff: %.cpp Output/.dir $(LLVMGXX) $(LOPT) $(LDIS)
	$(LLVMGXX) $*.cpp -g --emit-llvm -c -o Output/$*.bc 
	$(LOPT) Output/$*.bc -strip-nondebug -strip-debug -std-compile-opts -strip -f -o Output/$*.t.bc 
	$(LDIS) Output/$*.t.bc -f -o Output/$*.first.ll 
	$(LOPT) Output/$*.bc -strip-nondebug -std-compile-opts -strip-debug -strip -f -o Output/$*.t.bc 
	$(LDIS) Output/$*.t.bc -f -o Output/$*.second.ll 
	@-if diff Output/$*.first.ll Output/$*.second.ll > Output/$*.diff; then \
	 echo "--------- TEST-PASS: $*"; \
	else \
	 echo "--------- TEST-FAIL: $*"; \
	fi


Output/%.diff: %.c Output/.dir $(LLVMGCC) $(LOPT) $(LDIS)
	$(LLVMGCC) $*.c -g --emit-llvm -c -o Output/$*.bc 
	$(LOPT) Output/$*.bc -strip-nondebug -strip-debug -std-compile-opts -strip -f -o Output/$*.t.bc 
	$(LDIS) Output/$*.t.bc -f -o Output/$*.first.ll 
	$(LOPT) Output/$*.bc -strip-nondebug -std-compile-opts -strip-debug -strip -f -o Output/$*.t.bc 
	$(LDIS) Output/$*.t.bc -f -o Output/$*.second.ll 
	@-if diff Output/$*.first.ll Output/$*.second.ll > Output/$*.diff; then \
	 echo "--------- TEST-PASS: $*"; \
	else \
	 echo "--------- TEST-FAIL: $*"; \
	fi

