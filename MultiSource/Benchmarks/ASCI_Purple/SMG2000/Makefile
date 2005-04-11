LEVEL = ../../../..

PROG     = smg2000 
 
CPPFLAGS += -D_POSIX_SOURCE -DHYPRE_TIMING -DHYPRE_SEQUENTIAL 
CPPFLAGS += -I. 

LIBS += -lm
LDFLAGS += -lm

#include $(LLVM_OBJ_ROOT)/Makefile.config

RUN_OPTIONS ="-n 100 40 100 -c 0.1 1.0 10.0"

include	../../../Makefile.multisrc
