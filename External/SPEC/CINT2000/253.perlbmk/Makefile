LEVEL = ../../../../../..
REQUIRES_EH_SUPPORT = 1
RUN_OPTIONS     = test.pl
STDOUT_FILENAME = test.out
CPPFLAGS = -DSPEC_CPU2000_LINUX -Dbool=char -DI_TIME -DI_SYS_TIME

ifneq ($(ARCH),Sparc)
CPPFLAGS += -D__LITTLE_ENDIAN__
endif

include ../../Makefile.spec2000
