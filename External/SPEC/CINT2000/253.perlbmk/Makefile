LEVEL = ../../../..
REQUIRES_EH_SUPPORT = 1
CPPFLAGS = -DSPEC_CPU2000_LINUX -Dbool=char -DI_TIME -DI_SYS_TIME

ifeq ($(ARCH),Alpha)
  CPPFLAGS += -DSPEC_CPU2000_LINUX_ALPHA
endif

ifeq ($(RUN_TYPE),test)
RUN_OPTIONS     = test.pl
STDOUT_FILENAME := test.out
else
RUN_OPTIONS      = scrabbl.pl
STDIN_FILENAME  := scrabbl.in
STDOUT_FILENAME := scrabbl.out
endif

include ../../Makefile.spec2000

ifeq ($(ENDIAN),little)
CPPFLAGS += -D__LITTLE_ENDIAN__
endif

