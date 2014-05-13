LEVEL = ../../..
LDFLAGS += -lm 
FP_TOLERANCE := 0.001

include $(LEVEL)/Makefile.config

# dt uses posix_memalign, which doesn't exist on PPC darwin.
ifeq ($(ARCH),PowerPC)
ifeq ($(TARGET_OS),Darwin)
PROGRAMS_TO_SKIP := dt
endif
endif

ifeq ($(ARCH),Mips)
RUNTIMELIMIT := 2000
endif

ifeq ($(ARCH),XCore)
ifndef SMALL_PROBLEM_SIZE
# XCore takes over 2 hours.
RUNTIMELIMIT:=10800
endif
endif

include $(LEVEL)/SingleSource/Makefile.singlesrc
