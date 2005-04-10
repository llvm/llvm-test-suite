LEVEL = ../../../..
#RUN_OPTIONS     = 
STDIN_FILENAME  = crafty.in
STDOUT_FILENAME = crafty.out

Source = $(addprefix $(SPEC_BENCH_DIR)/src/,  \
         attacks.c draw.c enprise.c init.c iterate.c make.c nexte.c output.c \
	 preeval.c resign.c searchr.c swap.c utility.c boolean.c drawn.c     \
	 evaluate.c input.c lookup.c movgen.c nextr.c phase.c quiesce.c      \
	 root.c setboard.c time.c validate.c edit.c history.c interupt.c     \
	 main.c next.c option.c ponder.c repeat.c search.c store.c unmake.c  \
	 valid.c)

include ../../Makefile.spec2000

ifeq ($(ARCH),Alpha)
  CPPFLAGS += -DALPHA -DLINUX
endif
ifeq ($(ARCH),X86)
  CPPFLAGS += -DLINUX_i386
endif
ifeq ($(ARCH),PowerPC)
   CPPFLAGS += -DLINUX_PPC32
endif
