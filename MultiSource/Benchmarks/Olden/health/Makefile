PROG = health
LOCAL_CFLAGS=
LOCAL_LIBS= -lm

OBJS = args.o health.o list.o poisson.o

health.bc : $(OBJS)
	link $(OBJS) -o $@

include	../makefile
