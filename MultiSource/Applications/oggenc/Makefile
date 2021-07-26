LEVEL = ../../..
PROG = oggenc

CPPFLAGS += -fno-strict-aliasing -ffp-contract=off -DFMA_DISABLED=1
LDFLAGS  = -lm

STDIN_FILENAME = $(SourceDir)/tune
RUN_OPTIONS="-Q -s 901820 -"

include ../../Makefile.multisrc
