LEVEL=..
include $(LEVEL)/Makefile.programs

all:: timeit fpcmp TargetConfig.mk

# Avoid depending on timeit-target if it is not needed, some targets that use emulation cannot build it.
ifndef USER_MODE_EMULATION
all:: timeit-target
endif

ifndef USE_PERF
timeit: timeit.c
	$(ORIGINAL_CC) $(CFLAGS) -O3 -o $@ $<

timeit-target: timeit.c
	$(LD_ENV_OVERRIDES) $(LCC) -o $@ $< $(LDFLAGS) $(CFLAGS) $(TARGET_FLAGS) -O3
else
timeit: timeit.sh
	cp -f $< $@
	chmod u+x $@

timeit-target: timeit.sh
	cp -f $< $@
	chmod u+x $@
endif

fpcmp: fpcmp.c
	$(ORIGINAL_CC) $(CFLAGS) -O3 -o $@ $<

TargetConfig.mk: TargetConfig.mk.in
	$(LCC) $(LDFLAGS) $(CFLAGS) $(TARGET_FLAGS) -E -o $@ -x c $<

clean::
	rm -f timeit timeit-target fpcmp TargetConfig.mk
