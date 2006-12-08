##===- TEST.fourway.Makefile -------------------------------*- Makefile -*-===##
#
# This test tries running the compiler on all of the programs and
# reports on detailed compile time and resulting sizes.
#
##===----------------------------------------------------------------------===##

Output/%.report.$(TEST).txt:
	@echo "---------------------------------------------------------------"
	@echo ">>> ========= '$*' Program"
	@echo "---------------------------------------------------------------"

$(PROGRAMS_TO_TEST:%=test.$(TEST).%): \
test.$(TEST).%: $(LLVMGCC) $(LLVMGXX) $(CC) $(CXX) \
Output/%.report.$(TEST).txt \
Output/%.$(TEST).gcc.nodebug \
Output/%.$(TEST).gcc.debug \
Output/%.$(TEST).llvmgcc.nodebug \
Output/%.$(TEST).llvmgcc.debug
	@-cat Output/$*.$(TEST).gcc.nodebug
	@-cat Output/$*.$(TEST).gcc.debug
	@-cat Output/$*.$(TEST).llvmgcc.nodebug
	@-cat Output/$*.$(TEST).llvmgcc.debug

%.cpp:

%.c:

Output/%.$(TEST).gcc.nodebug: %.cpp $(CXX)
	@-mkdir -p Output
	@echo $@ > $@.tmp
	@-(time -p $(CXX) $*.cpp -O0 -c -o $@.o) 2> $@.tmp > $@.tmp
	@-(size $@.o) 2>> $@.tmp >> $@.tmp
	@-(sed -e s/$$/gcc.nodebug/ $@.tmp) > $@

Output/%.$(TEST).gcc.debug: %.cpp $(CXX)
	@-mkdir -p Output
	@echo $@ > $@.tmp
	@-(time -p $(CXX) $*.cpp -O0 -gdwarf-2 -c -o $@.o) 2> $@.tmp > $@.tmp
	@-(size $@.o) 2>> $@.tmp >> $@.tmp
	@-(sed -e s/$$/gcc.debug/ $@.tmp) > $@

Output/%.$(TEST).llvmgcc.nodebug: %.cpp $(LLVMGXX)
	@-mkdir -p Output
	@echo $@ > $@.tmp
	@-(time -p $(LLVMGXX) $*.cpp -O0 -c -o $@.o) 2> $@.tmp > $@.tmp
	@-(size $@.o) 2>> $@.tmp >> $@.tmp
	@-(sed -e s/$$/llvmgcc.nodebug/ $@.tmp) > $@

Output/%.$(TEST).llvmgcc.debug: %.cpp $(LLVMGXX)
	@-mkdir -p Output
	@echo $@ > $@.tmp
	@-(time -p $(LLVMGXX) $*.cpp -O0 -g -c -o $@.o) 2> $@.tmp > $@.tmp
	@-(size $@.o) 2>> $@.tmp >> $@.tmp
	@-(sed -e s/$$/llvmgcc.debug/ $@.tmp) > $@

Output/%.$(TEST).gcc.nodebug: %.c $(CC)
	@-mkdir -p Output
	@echo $@ > $@.tmp
	@-(time -p $(CC) $*.c -O0 -c -o $@.o) 2> $@.tmp > $@.tmp
	@-(size $@.o) 2>> $@.tmp >> $@.tmp
	@-(sed -e s/$$/gcc.nodebug/ $@.tmp) > $@

Output/%.$(TEST).gcc.debug: %.c $(CC)
	@-mkdir -p Output
	@echo $@ > $@.tmp
	@-(time -p $(CC) $*.c -O0 -gdwarf-2 -c -o $@.o) 2> $@.tmp > $@.tmp
	@-(size $@.o) 2>> $@.tmp >> $@.tmp
	@-(sed -e s/$$/gcc.debug/ $@.tmp) > $@

Output/%.$(TEST).llvmgcc.nodebug: %.c $(LLVMGCC)
	@-mkdir -p Output
	@echo $@ > $@.tmp
	@-(time -p $(LLVMGCC) $*.c -O0 -c -o $@.o) 2> $@.tmp > $@.tmp
	@-(size $@.o) 2>> $@.tmp >> $@.tmp
	@-(sed -e s/$$/llvmgcc.nodebug/ $@.tmp) > $@

Output/%.$(TEST).llvmgcc.debug: %.c $(LLVMGCC)
	@-mkdir -p Output
	@echo $@ > $@.tmp
	@-(time -p $(LLVMGCC) $*.c -O0 -g -c -o $@.o) 2> $@.tmp > $@.tmp
	@-(size $@.o) 2>> $@.tmp >> $@.tmp
	@-(sed -e s/$$/llvmgcc.debug/ $@.tmp) > $@
