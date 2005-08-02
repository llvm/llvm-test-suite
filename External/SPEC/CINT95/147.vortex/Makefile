LEVEL = ../../../..

#include $(LEVEL)/Makefile.config

STDOUT_FILENAME := vortex.out
LDFLAGS += -lm
LIBS    += -lm

include ../../Makefile.spec95

#a grep of the source seems to say that SPEC_CPU2000_LP64 isn't used at all

ifeq ($(ARCH),Sparc)
  ## SPEC portability note for vortex says to use this flag on 64-bit machines
  CPPFLAGS += -DSPEC_CPU2000_LP64
endif
ifeq ($(ARCH),Alpha)
  ## SPEC portability note for vortex says to use this flag on 64-bit machines
  CPPFLAGS += -DSPEC_CPU2000_LP64 -D__RISC_64__
endif
ifeq ($(ARCH),IA64)
  ## SPEC portability note for vortex says to use this flag on 64-bit machines
  CPPFLAGS += -DSPEC_CPU2000_LP64
endif

ifeq ($(ENDIAN), big)
  RUN_OPTIONS  = vortex.in.big
else
  RUN_OPTIONS  = vortex.in.little
endif
