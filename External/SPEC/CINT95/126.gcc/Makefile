LEVEL = ../../../../../..
CPPFLAGS += -U_STDARG_H -DSPEC -I$(SPEC95_ROOT)/CINT95/126.gcc/src/src.alt
RUN_OPTIONS := -quiet -funroll-loops -fforce-mem -fcse-follow-jumps -fcse-skip-blocks -fexpensive-optimizations -fstrength-reduce -fpeephole -fschedule-insns -finline-functions -fschedule-insns2 -O -o -
STDIN_FILENAME = cccp.i
STDOUT_FILENAME = cccp.s

include ../../Makefile.spec95

