##===- test/Programs/Makefile.TEST.poolalloc ---------------*- Makefile -*-===##
#
# Old tests for pool allocation.  These will almost certainly have to be updated
# to be useful in the future.
#
# Note that this is Sparc specific!
#
##===----------------------------------------------------------------------===##

.PRECIOUS: Output/%.poolalloc.bc

N32Objects := $(addprefix Output/n32/,$(NObjs))
.PRECIOUS: $(N32Objects) Output/n32/.dir
Output/%.native32: $(N32Objects)
	$(CC) -o $@ $(N32Objects) $(LDFLAGS)

Output/n32/%.o: %.c Output/n32/.dir
	$(CC) -DTORONTO -g -xarch=v8 -c $< -o $@

.PRECIOUS: Output/%.poolalloc8.llvm.bc Output/%.poolalloc16.llvm.bc Output/%.poolalloc32.llvm.bc Output/%.poolalloc16nle.llvm.bc Output/%.poolalloc32nle.llvm.bc

# Pool allocate memory objects if possible
Output/%.poolalloc8.llvm.bc: Output/%.linked.bc $(LOPT)
	$(LOPT) -internalize -poolalloc -ptrsize=8 -globaldce -instcombine -die -gcse < $< -o $@ -f
Output/%.poolalloc16.llvm.bc: Output/%.linked.bc $(LOPT)
	$(LOPT) -internalize -poolalloc -ptrsize=16 -globaldce -instcombine -die -gcse < $< -o $@ -f
Output/%.poolalloc32.llvm.bc: Output/%.linked.bc $(LOPT)
	$(LOPT) -internalize -poolalloc -ptrsize=32 -globaldce -instcombine -die -gcse < $< -o $@ -f

Output/%.poolalloc8nle.llvm.bc: Output/%.linked.bc $(LOPT)
	$(LOPT) -internalize -poolalloc -no-pool-load-elim -ptrsize=8 -globaldce -instcombine -die < $< -o $@ -f
Output/%.poolalloc16nle.llvm.bc: Output/%.linked.bc $(LOPT)
	$(LOPT) -internalize -poolalloc -no-pool-load-elim -ptrsize=16 -globaldce -instcombine -die < $< -o $@ -f
Output/%.poolalloc32nle.llvm.bc: Output/%.linked.bc $(LOPT)
	$(LOPT) -internalize -poolalloc -no-pool-load-elim -ptrsize=32 -globaldce -instcombine -die < $< -o $@ -f



# Link the pool allocator into the programs...
LLC_PROG_LIBS += /home/vadve/lattner/PoolAllocated/PoolAllocator.o

.PRECIOUS: Output/%.out-pa Output/%.diff-pa
Output/%.out-pa: Output/%.llc
	-$< > $@ 2>&1

Output/%.diff-pa: Output/%.out-pa Output/%.out-llc
	@echo "DIFFING pool allocated vs nonpoolallocated output:"
	diff $< $(<:%-pa=%-llc)
	@touch $@

TESTNAME = $(subst test.example.,,$@)

test.poolalloc.%: Output/%.poolalloc32.diff-pa Output/%.poolalloc32.llc \
                  Output/%.poolalloc16.llc     Output/%.poolalloc32nle.llc \
                  Output/%.poolalloc16nle.llc  Output/%.native32
	$(TIMEPROG) 'Normal LLC build...' Output/$(TESTNAME).llc
	$(TIMEPROG) '32 bit pool alloc NLE...' Output/$(TESTNAME).poolalloc32nle.llc
	$(TIMEPROG) '32 bit pool allocation...' Output/$(TESTNAME).poolalloc32.llc
	$(TIMEPROG) '16 bit pool alloc NLE...' Output/$(TESTNAME).poolalloc16nle.llc
	$(TIMEPROG) '16 bit pool allocation...' Output/$(TESTNAME).poolalloc16.llc

	$(TIMEPROG) 'Native Sun CC 64...' Output/$(TESTNAME).native
	$(TIMEPROG) 'Native Sun CC 32...' Output/$(TESTNAME).native32
