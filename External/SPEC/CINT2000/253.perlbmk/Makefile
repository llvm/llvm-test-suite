LEVEL = ../../../../../..
REQUIRES_EH_SUPPORT = 1
CPPFLAGS = -DSPEC_CPU2000_LINUX -Dbool=char -DI_TIME -DI_SYS_TIME

ifeq ($(RUN_TYPE),test)
RUN_OPTIONS     = test.pl
STDOUT_FILENAME := test.out
else
RUN_OPTIONS     = scrabble.pl
STDOUT_FILENAME := scrabble.out
endif


ifneq ($(ARCH),Sparc)
CPPFLAGS += -D__LITTLE_ENDIAN__
endif

include ../../Makefile.spec2000
