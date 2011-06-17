##===- TEST.lineinfo.Makefile -----------------------------*- Makefile -*--===##
#
# This test is used to measure quality of debugging information.
#
##===----------------------------------------------------------------------===##

CURDIR  := $(shell cd .; pwd)
PROGDIR := $(PROJ_SRC_ROOT)
RELDIR  := $(subst $(PROGDIR),,$(CURDIR))
COLLECTOR := $(PROJ_SRC_ROOT)/CollectDebugInfoUsingLLDB.py 

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
test.$(TEST).%: Output/%.bp Output/%.dbg Output/%.dbg.opt Output/%.native.dbg Output/%.native.dbg.opt
	@-is_skip=0; \
	if test "$*" == "reversefile"; then \
	  is_skip=1; \
	fi; \
	if test "$*" == "spellcheck"; then \
	  is_skip=1; \
	fi; \
	if test "$*" == "sumcol"; then \
	  is_skip=1; \
	fi; \
	if test "$*" == "wc"; then \
	  is_skip=1; \
	fi; \
	if test "$*" == "wordfreq"; then \
	  is_skip=1; \
	fi; \
	if test "$*" == "exptree"; then \
	  is_skip=1; \
	fi; \
	if test "$*" == "ray"; then \
	  is_skip=1; \
	fi; \
	if test "$*" == "oscar"; then \
	  is_skip=1; \
	fi; \
	if test "$*" == "spirit"; then \
	  is_skip=1; \
	fi; \
	if test $$is_skip == 0; then \
	  $(PROJ_SRC_ROOT)/PrintLineNo.sh $*; \
	  $(PROJ_SRC_ROOT)/FindMissingLineNo.py $* $(PROJ_SRC_ROOT);\
	fi

