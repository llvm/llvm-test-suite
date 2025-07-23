LEVEL = ../../..
LDFLAGS += -lm 
CFLAGS += -Wno-implicit-int
FP_TOLERANCE := 0.001

include $(LEVEL)/Makefile.config

# dt uses posix_memalign, which doesn't exist on PPC darwin.
ifeq ($(ARCH),PowerPC)
ifeq ($(TARGET_OS),Darwin)
PROGRAMS_TO_SKIP := dt
endif
endif

ifeq ($(ARCH),AArch64)
	ifeq ($(TARGET_OS),Darwin)
		CHECK_FMV := $(shell echo "void __init_cpu_features_resolver(void);" > CheckHasAArch64FMV.h && \
			$(CC) -c -x c CheckHasAArch64FMV.h -o CheckHasAArch64FMV.o 2>/dev/null && \
			echo yes || echo no; \
			rm -f CheckHasAArch64FMV.h CheckHasAArch64FMV.o)
		ifeq ($(CHECK_FMV),yes)
			CFLAGS += -DHAS_DARWIN_FMV
		endif
	endif
	ifeq ($(TARGET_OS),Linux)
		CHECK_FMV := $(shell echo "void __init_cpu_features(void);" > CheckHasAArch64FMV.h && \
			$(CC) -c -x c CheckHasAArch64FMV.h -o CheckHasAArch64FMV.o 2>/dev/null && \
			echo yes || echo no; \
			rm -f CheckHasAArch64FMV.h CheckHasAArch64FMV.o)
		ifeq ($(CHECK_FMV),yes)
			CFLAGS += -DHAS_LINUX_FMV
		endif
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
