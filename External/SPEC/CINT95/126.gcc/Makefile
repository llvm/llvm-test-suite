LEVEL = ../../../../../..
CPPFLAGS += -DSPEC -idirafter $(SPEC95_ROOT)/CINT95/126.gcc/src/src.alt
RUN_OPTIONS := -quiet -funroll-loops -fforce-mem -fcse-follow-jumps -fcse-skip-blocks -fexpensive-optimizations -fstrength-reduce -fpeephole -fschedule-insns -finline-functions -fschedule-insns2 -O -o -
STDIN_FILENAME = amptjp.i
STDOUT_FILENAME = amptjp.s

include ../../Makefile.spec95

