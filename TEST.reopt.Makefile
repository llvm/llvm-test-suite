##===- test/Programs/TEST.reopt.Makefile -------------------*- Makefile -*-===##
#
# Do a reoptimizer build for each program; then run the program. The expected
# output is 1) any debug output the reoptimizer outputs, if its debug flags
#              are set
#           2) no core dumps unless the unaltered program also dumps core
#           3) same output as unaltered program
#
# Admittedly this is pretty weak but it serves as a kind of "hello
# world"-level test.
#
##===----------------------------------------------------------------------===##

TESTNAME = $*

# Libraries that contain the Reoptimizer itself
REOPTIMIZER_LIBS = $(DESTLIBCURRENT)/firstTrigger.o \
	$(DESTLIBCURRENT)/tracecache.o $(DESTLIBCURRENT)/mapinfo.o \
	$(DESTLIBCURRENT)/scratchmemory.o

# Libraries that contain common LLVM code the Reoptimizer depends on
REOPTIMIZER_LLVM_SUPPORT_LIBS = $(DESTLIBCURRENT)/libscalaropts.a \
	$(DESTLIBCURRENT)/libtransformutils.a $(DESTLIBCURRENT)/vmcore.o \
	$(DESTLIBCURRENT)/libsupport.a $(DESTLIBCURRENT)/bcreader.o \
	$(DESTLIBCURRENT)/libanalysis.a

# Solaris libraries that the Reoptimizer depends on
REOPTIMIZER_SOLARIS_SUPPORT_LIBS = -lcpc -lm -lrt -lmalloc

# Libraries that should be checked for freshness when doing 
# Reoptimizer tests (http://www.goodegg.com/eggdating.html)
REOPTIMIZER_LIBDEPS = $(REOPTIMIZER_LIBS) $(REOPTIMIZER_LLVM_SUPPORT_LIBS)

# Things that need to be added to the link line when linking a
# program with the Reoptimizer
REOPTIMIZER_LDADD = $(REOPTIMIZER_LIBS) $(REOPTIMIZER_LLVM_SUPPORT_LIBS) \
	$(REOPTIMIZER_SOLARIS_SUPPORT_LIBS)

.PRECIOUS: Output/%.out-reopt-llc

$(PROGRAMS_TO_TEST:%=test.$(TEST).%): \
test.$(TEST).%: Output/%.out-reopt-llc
	@echo "========================================="

# 1. Run the necessary opt passes over the bytecode, then...
# 1a. Compile it with LLC, using the SPARC backend's special option to
# insert the mapping information.  We use -disable-sched to reduce
# compile times significantly.
$(PROGRAMS_TO_TEST:%=Output/%.reopt-llc.s): \
Output/%.reopt-llc.s: Output/%.llvm.bc
	@echo "========================================="
	@echo "Compiling Reoptimizer version of '$(TESTNAME)'"
	-$(LOPT) -q -inline -lowerswitch -branch-combine -emitfuncs -instloops $< | $(LLC) $(LLCFLAGS) -disable-sched -f -enable-maps -o $@

# 2. Link the instrumented binary with the necessary parts of the
# compiler.
$(PROGRAMS_TO_TEST:%=Output/%.reopt-llc): \
Output/%.reopt-llc: Output/%.reopt-llc.s $(REOPTIMIZER_LIBDEPS)
	-$(CXX) $(CFLAGS) $< -o $@ $(REOPTIMIZER_LDADD)

# 3. Run the reoptimized version.
$(PROGRAMS_TO_TEST:%=Output/%.out-reopt-llc): \
Output/%.out-reopt-llc: Output/%.reopt-llc
	@echo "Running Reoptimizer version of '$(TESTNAME)'"
	-$(RUNSAFELY) $(STDIN_FILENAME) $@ $< $(RUN_OPTIONS)

