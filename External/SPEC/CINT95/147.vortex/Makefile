LEVEL = ../../../..

#include $(LEVEL)/Makefile.config

STDOUT_FILENAME := vortex.out
LDFLAGS += -lm
LIBS    += -lm

ifeq ($(ARCH),Sparc)
  ## SPEC portability note for vortex says to use this flag on 64-bit machines
  CPPFLAGS += -DSPEC_CPU2000_LP64
endif
ifeq ($(ARCH),Alpha)
  ## SPEC portability note for vortex says to use this flag on 64-bit machines
  CPPFLAGS += -DSPEC_CPU2000_LP64
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

include ../../Makefile.spec95
