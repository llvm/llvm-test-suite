LEVEL = ../../../../../..
CPPFLAGS += -DSPEC -idirafter $(SPEC95_ROOT)/CINT95/126.gcc/src/src.alt
RUN_OPTIONS := -quiet -funroll-loops -fforce-mem -fcse-follow-jumps -fcse-skip-blocks -fexpensive-optimizations -fstrength-reduce -fpeephole -fschedule-insns -finline-functions -fschedule-insns2 -O -o -

ifeq ($(RUN_TYPE),test)
STDIN_FILENAME = cccp.i
STDOUT_FILENAME = cccp.s
else
STDIN_FILENAME = amptjp.i
STDOUT_FILENAME = amptjp.s
endif

include ../../Makefile.spec95

