LEVEL = ../../../../../..
RUN_OPTIONS     = cccp.i -o cccp.s
STDOUT_FILENAME = cccp.out
include ../../Makefile.spec
ifeq ($(ARCH),Sparc)
  ## SPEC portability note for GCC says to use these flags and cross fingers:
  CPPFLAGS += -DHOST_WORDS_BIG_ENDIAN -DSPEC_CPU2000_LP64
endif
