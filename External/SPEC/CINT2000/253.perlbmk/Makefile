LEVEL = ../../../../../..
RUN_OPTIONS     = $(RUN_TYPE).pl
STDOUT_FILENAME = $(RUN_TYPE).out
CPPFLAGS = -DSPEC_CPU2000_LINUX -Dbool=char -DI_TIME -DI_SYS_TIME

ifneq ($(ARCH),Sparc)
CPPFLAGS += -D__LITTLE_ENDIAN__
endif

include ../../Makefile.spec
