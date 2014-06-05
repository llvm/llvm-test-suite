# SingleSource/UnitTests/Vector/Altivec/Makefile
LEVEL = ../../../..

include $(LEVEL)/Makefile.config

DIRS = 

# Needed because of MADDs in stepfft.
FP_TOLERANCE := 0.002

TARGET_FLAGS += -maltivec
# setting TEST_TARGET_FLAGS is needed within the LNT environment.
TEST_TARGET_FLAGS += -maltivec
LCCFLAGS += -maltivec

ifdef BENCHMARKING_ONLY
PROGRAMS_TO_SKIP += \
	2007-01-07-lvsl-lvsr-Regression alti.sdot \
	casts test1 \
	extract insert ld lde ldl merge mult-even-odd \
	pack perm splat st ste stl sum2s sums unpack
endif

include $(LEVEL)/SingleSource/Makefile.singlesrc
