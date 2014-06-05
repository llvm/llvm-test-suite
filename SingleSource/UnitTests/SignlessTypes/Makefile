DIRS := Large

LEVEL = ../../..

# You can use this seed value to get a different test
# each day, but don't forget to 'make clean' To use it,
# change RUN_OPTIONS (below) to be $(SEED)
SEED := $(shell date +%j)

# Use a consistent seed value for the tests so they produce
# the same results regardless of whether you make clean or not.
RUN_OPTIONS := 31415926

ifdef BENCHMARKING_ONLY
PROGRAMS_TO_SKIP += cast2 cast-bug ccc div factor shr
endif

LDFLAGS += -lstdc++
include $(LEVEL)/SingleSource/Makefile.singlesrc
