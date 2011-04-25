LEVEL=..
include $(LEVEL)/Makefile.programs

all:: timeit timeit-target fpcmp

timeit: timeit.c
	$(ORIGINAL_CC) $(CFLAGS) -O3 -o $@ $<

timeit-target: timeit.c
	$(LD_ENV_OVERRIDES) $(LCC) -o $@ $< $(LDFLAGS) $(CFLAGS) $(TARGET_FLAGS) -O3

fpcmp: fpcmp.c
	$(ORIGINAL_CC) $(CFLAGS) -O3 -o $@ $<

clean::
	rm -f timeit timeit-target fpcmp
