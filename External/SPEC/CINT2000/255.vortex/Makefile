LEVEL = ../../../../../..
RUN_OPTIONS     = lendian.raw
#STDOUT_FILENAME := input.random.out
include ../../Makefile.spec
ifeq ($(ARCH),Sparc)
  ## SPEC portability note for vortex says to use this flag on 64-bit machines
  CPPFLAGS += -DSPEC_CPU2000_LP64
endif
