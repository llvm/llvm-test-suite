LEVEL = ../../../../../..

ifeq ($(RUN_TYPE),test)
RUN_OPTIONS     = cccp.i -o - -quiet
STDOUT_FILENAME = cccp.s
else
RUN_OPTIONS     = cp-decl.i -o - -quiet
STDOUT_FILENAME = cp-decl.s
endif

include ../../Makefile.spec2000

ifeq ($(ENDIAN),big)
  CPPFLAGS += -DHOST_WORDS_BIG_ENDIAN
endif

ifeq ($(ARCH),Sparc)
  ## SPEC portability note for GCC says to use these flags and cross fingers:
  CPPFLAGS += -DSPEC_CPU2000_LP64
endif
