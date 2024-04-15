# MultiSource/UnitTests/Float Makefile:  Build all subdirectories automatically

LEVEL = ../../..

PARALLEL_DIRS :=

# Tests in 'rounding' can run only if the target implements builtin functions
# for rounding mode manipulation.
ifneq (,$(filter $(ARCH), X86_64 AArch64))
PARALLEL_DIRS += rounding
endif

include $(LEVEL)/Makefile.config
include $(LEVEL)/Makefile.programs
