##===- TEST.dbg.Makefile ----------------------------------*- Makefile -*--===##
#
# This test is used to measure quality of debugging information.
#
##===----------------------------------------------------------------------===##

#----------------------------------------------------------------------
# Be sure to add the python path that points to the LLDB shared library.
# On MacOSX csh, tcsh:
#   setenv PYTHONPATH /Developer/Library/PrivateFrameworks/LLDB.framework/Resources/Python
# On MacOSX sh, bash:
#   export PYTHONPATH=/Developer/Library/PrivateFrameworks/LLDB.framework/Resources/Python
#----------------------------------------------------------------------

CURDIR  := $(shell cd .; pwd)
PROGDIR := $(PROJ_SRC_ROOT)
RELDIR  := $(subst $(PROGDIR),,$(CURDIR))

REPORTS_TO_GEN := dbg
REPORTS_SUFFIX := $(addsuffix .report.txt, $(REPORTS_TO_GEN))

Output/%.bp: %.c Output/.dir
	$(LCC) $(CPPFLAGS) $(CFLAGS) -g -c -emit-llvm $< -o $@.bc
	$(LOPT) -print-breakpoints-for-testing $@.bc -o $@

Output/%.bp: %.cpp Output/.dir
	$(LCXX) $(CPPFLAGS) $(CFLAGS) -g -c -emit-llvm $< -o $@.bc
	$(LOPT) -print-breakpoints-for-testing $@.bc -o $@

Output/%.bp: %.m Output/.dir
	$(LCC) $(CPPFLAGS) $(CFLAGS) -g -c -emit-llvm $< -o $@.bc
	$(LOPT) -print-breakpoints-for-testing $@.bc -o $@

Output/%.bp: %.mm Output/.dir
	$(LCXX) $(CPPFLAGS) $(CFLAGS) -g -c -emit-llvm $< -o $@.bc
	$(LOPT) -print-breakpoints-for-testing $@.bc -o $@

$(PROGRAMS_TO_TEST:%=test.$(TEST).%): \
test.$(TEST).%: Output/%.bp Output/%.dbg Output/%.dbg.opt
	echo $@
	echo $*
	mv *.dSYM Output/.
	$(LLVM_SRC_ROOT)/utils/CollectDebugInfoUsingLLDB.py Output/$*.dbg Output/$*.bp Output/$*.dbg.out
	$(LLVM_SRC_ROOT)/utils/CollectDebugInfoUsingLLDB.py Output/$*.dbg.opt Output/$*.bp Output/$*.dbg.opt.out
	$(LLVM_SRC_ROOT)/utils/CompareDebugInfo.py Output/$*.dbg.out Output/$*.dbg.opt.out $* 

