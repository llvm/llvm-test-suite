LEVEL = ../../../../../..
ifeq ($(RUN_TYPE),test)
RUN_OPTIONS     = cccp.i -o cccp.s
else
RUN_OPTIONS     = cp-decl.i -o cp-decl.s
endif
STDOUT_FILENAME = cccp.out
include ../../Makefile.spec2000
ifeq ($(ARCH),Sparc)
  ## SPEC portability note for GCC says to use these flags and cross fingers:
  CPPFLAGS += -DHOST_WORDS_BIG_ENDIAN -DSPEC_CPU2000_LP64
endif
