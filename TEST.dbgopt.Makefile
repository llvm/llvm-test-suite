##===- TEST.dbgopt.Makefile --------------------------------*- Makefile -*-===##
#
# This test checks whether presense of debugging information influences
# the optimizer or not. 
#
# $ llvm-gcc -g -fdebug-disable-debug-info-print -Os -S foo.c -o foo.first.s
# $ llvm-gcc -Os -S foo.c -o foo.second.s
# $ diff foo.first.s foo.second.s
#
##===----------------------------------------------------------------------===##

TESTNAME = $*
.PRECIOUS: Output/%.first.s Output/%.second.s 

$(PROGRAMS_TO_TEST:%=test.$(TEST).%): \
test.$(TEST).%: Output/%.diff

Output/%.s: %.c Output/.dir $(INCLUDES)
	-$(LLVMGCC) $(CPPFLAGS) $(CFLAGS) $(LOPTFLAGS) $(X_TARGET_FLAGS) -g -Os -fdebug-disable-debug-info-print -S ${PROJ_SRC_DIR}/$*.c -o Output/$*.first.s
	-$(LLVMGCC) $(CPPFLAGS) $(CFLAGS) $(LOPTFLAGS) $(X_TARGET_FLAGS) -Os -S ${PROJ_SRC_DIR}/$*.c -o Output/$*.second.s
	@-if diff Output/$*.first.s Output/$*.second.s > $@; then \
	 echo "--------- TEST-PASS: $*"; \
	else \
	 echo "--------- TEST-FAIL: $*"; \
	fi

Output/%.s: %.cpp Output/.dir $(INCLUDES)
	-$(LLVMGCC) $(CPPFLAGS) $(CFLAGS) $(LOPTFLAGS) $(X_TARGET_FLAGS) -g -Os -fdebug-disable-debug-info-print -S ${PROJ_SRC_DIR}/$*.cpp -o Output/$*.first.s
	-$(LLVMGCC) $(CPPFLAGS) $(CFLAGS) $(LOPTFLAGS) $(X_TARGET_FLAGS) -Os -S ${PROJ_SRC_DIR}/$*.cpp -o Output/$*.second.s
	@-if diff Output/$*.first.s Output/$*.second.s > $@; then \
	 echo "--------- TEST-PASS: $*"; \
	else \
	 echo "--------- TEST-FAIL: $*"; \
	fi

Output/%.s: %.cc Output/.dir $(INCLUDES)
	-$(LLVMGCC) $(CPPFLAGS) $(CFLAGS) $(LOPTFLAGS) $(X_TARGET_FLAGS) -g -Os -fdebug-disable-debug-info-print -S ${PROJ_SRC_DIR}/$*.cc -o Output/$*.first.s
	-$(LLVMGCC) $(CPPFLAGS) $(CFLAGS) $(LOPTFLAGS) $(X_TARGET_FLAGS) -Os -S ${PROJ_SRC_DIR}/$*.cc -o Output/$*.second.s
	@-if diff Output/$*.first.s Output/$*.second.s > $@; then \
	 echo "--------- TEST-PASS: $*"; \
	else \
	 echo "--------- TEST-FAIL: $*"; \
	fi

Output/%.s: %.m Output/.dir $(INCLUDES)
	-$(LLVMGCC) $(CFLAGS) $(LOPTFLAGS) $(X_TARGET_FLAGS) -g -Os -fdebug-disable-debug-info-print -S ${PROJ_SRC_DIR}/$*.m -o Output/$*.first.s
	-$(LLVMGCC) $(CFLAGS) $(LOPTFLAGS) $(X_TARGET_FLAGS) -Os -S ${PROJ_SRC_DIR}/$*.m -o Output/$*.second.s
	@-if diff Output/$*.first.s Output/$*.second.s > $@; then \
	 echo "--------- TEST-PASS: $*"; \
	else \
	 echo "--------- TEST-FAIL: $*"; \
	fi

Output/%.s: %.mm Output/.dir $(INCLUDES)
	-$(LLVMGCC) $(CPPFLAGS) $(CFLAGS) $(LOPTFLAGS) $(X_TARGET_FLAGS) -g -Os -fdebug-disable-debug-info-print -S ${PROJ_SRC_DIR}/$*.mm -o Output/$*.first.s
	-$(LLVMGCC) $(CPPFLAGS) $(CFLAGS) $(LOPTFLAGS) $(X_TARGET_FLAGS) -Os -S ${PROJ_SRC_DIR}/$*.mm -o Output/$*.second.s
	@-if diff Output/$*.first.s Output/$*.second.s > $@; then \
	 echo "--------- TEST-PASS: $*"; \
	else \
	 echo "--------- TEST-FAIL: $*"; \
	fi

Asms    := $(sort $(addsuffix .s, $(notdir $(basename $(Source)))))
AllAsms := $(addprefix Output/,$(Asms))

Output/%.diff: $(AllAsms)
	

