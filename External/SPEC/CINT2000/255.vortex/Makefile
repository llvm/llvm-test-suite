LEVEL = ../../../../../..
#STDOUT_FILENAME := input.random.out

include ../../Makefile.spec

ifeq ($(ARCH),Sparc)
  ## SPEC portability note for vortex says to use this flag on 64-bit machines
  CPPFLAGS += -DSPEC_CPU2000_LP64

  # If we're on sparc, use the Big Endian input file
  RUN_OPTIONS     = bendian.raw
else
  # Use the Little Endian input file
  RUN_OPTIONS     = lendian.raw
endif

