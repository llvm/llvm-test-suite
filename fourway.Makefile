##===- fourway.Makefile ------------------------------------*- Makefile -*-===##
#
# This file is intended to be included in four-way (gcc vs. llvm-gcc by
# debug vs. non-debug) reports, to provide raw data generating targets.
#
##===----------------------------------------------------------------------===##

Output/%.report.$(TEST).txt:
	@echo "---------------------------------------------------------------"
	@echo ">>> ========= '$*' Program"
	@echo "---------------------------------------------------------------"


Output/%.gcc.nodebug.o: %.cpp Output/.dir
	@-(time -p $(CXX) $*.cpp -O0 -c -o $@) 2>&1 | \
	  sed -e s/$$/gcc.nodebug/ > Output/$*.gcc.nodebug.time

Output/%.gcc.debug.o: %.cpp Output/.dir
	@-(time -p $(CXX) $*.cpp -O0 -gdwarf-2 -c -o $@) 2>&1 | \
	  sed -e s/$$/gcc.debug/ > Output/$*.gcc.debug.time

Output/%.llvmgcc.nodebug.o: %.cpp Output/.dir $(LLVMGXX)
	@-(time -p $(LLVMGXX) $*.cpp -O0 -c -o $@) 2>&1 | \
	  sed -e s/$$/llvmgcc.nodebug/ > Output/$*.llvmgcc.nodebug.time

Output/%.llvmgcc.debug.o: %.cpp Output/.dir $(LLVMGXX)
	@-(time -p $(LLVMGXX) $*.cpp -O0 -g -c -o $@) 2>&1 | \
	  sed -e s/$$/llvmgcc.debug/ > Output/$*.llvmgcc.debug.time

Output/%.gcc.nodebug.o: %.c Output/.dir
	@-(time -p $(CC) $*.c -O0 -c -o $@) 2>&1 | \
	  sed -e s/$$/gcc.nodebug/ > Output/$*.gcc.nodebug.time

Output/%.gcc.debug.o: %.c Output/.dir
	@-(time -p $(CC) $*.c -O0 -gdwarf-2 -c -o $@) 2>&1 | \
	  sed -e s/$$/gcc.debug/ > Output/$*.gcc.debug.time

Output/%.llvmgcc.nodebug.o: %.c Output/.dir $(LLVMGCC)
	@-(time -p $(LLVMGCC) $*.c -O0 -c -o $@) 2>&1 | \
	  sed -e s/$$/llvmgcc.nodebug/ > Output/$*.llvmgcc.nodebug.time

Output/%.llvmgcc.debug.o: %.c Output/.dir $(LLVMGCC)
	@-(time -p $(LLVMGCC) $*.c -O0 -g -c -o $@) 2>&1 | \
	  sed -e s/$$/llvmgcc.debug/ > Output/$*.llvmgcc.debug.time


Output/%.time:  Output/%.o
	@echo "" > /dev/null


Output/%.gcc.nodebug.size: Output/%.gcc.nodebug.o
	@-size Output/$*.gcc.nodebug.o 2>&1 | \
	  sed -e s/$$/gcc.nodebug/ > $@
	@-size -m Output/$*.gcc.nodebug.o 2>&1 | \
	  sed -e s/$$/gcc.nodebug/ >> $@

Output/%.gcc.debug.size: Output/%.gcc.debug.o
	@-size Output/$*.gcc.debug.o 2>&1 | \
	  sed -e s/$$/gcc.debug/ > $@
	@-size -m Output/$*.gcc.debug.o 2>&1 | \
	  sed -e s/$$/gcc.debug/ >> $@

Output/%.llvmgcc.nodebug.size: Output/%.llvmgcc.nodebug.o
	@-size Output/$*.llvmgcc.nodebug.o 2>&1 | \
	  sed -e s/$$/llvmgcc.nodebug/ > $@
	@-size -m Output/$*.llvmgcc.nodebug.o 2>&1 | \
	  sed -e s/$$/llvmgcc.nodebug/ >> $@

Output/%.llvmgcc.debug.size: Output/%.llvmgcc.debug.o
	@-size Output/$*.llvmgcc.debug.o 2>&1 | \
	  sed -e s/$$/llvmgcc.debug/ > $@
	@-size -m Output/$*.llvmgcc.debug.o 2>&1 | \
	  sed -e s/$$/llvmgcc.debug/ >> $@
