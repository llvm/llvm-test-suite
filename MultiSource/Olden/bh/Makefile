PROG = bh
LOCAL_CFLAGS=
LOCAL_LIBS= -lm

OBJS = args.o newbh.o util.o walksub.o

bh.bc : $(OBJS)
	../../../tools/Debug/link -f $(OBJS) -o $@


include	../makefile
