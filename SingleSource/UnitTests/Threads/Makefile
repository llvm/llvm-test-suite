# SingleSource/UnitTests/Threads/Makefile
LEVEL = ../../..

include $(LEVEL)/Makefile.config

# xcore does not support pthreads
ifneq ($(ARCH),XCore)
LDFLAGS += -lpthread
else
PROGRAMS_TO_SKIP := tls
endif

# Darwin doesn't support tls.
ifeq ($(TARGET_OS),Darwin)
PROGRAMS_TO_SKIP := tls 2010-12-08-tls
endif

include $(LEVEL)/SingleSource/Makefile.singlesrc
