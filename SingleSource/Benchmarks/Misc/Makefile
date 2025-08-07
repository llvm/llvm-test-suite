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
SYMBOL = __init_cpu_features_resolver
endif
ifeq ($(TARGET_OS),Linux)
SYMBOL = __init_cpu_features
endif
# TARGET_LLVMGCC refers to the compiler specified with the --cc option,
# and can be checked in the build-tools.log file in the test results directory.
SYMBOL := $(shell echo "extern void $(SYMBOL)(void); void (*p)() = $(SYMBOL); int main() {}" | \
       $(TARGET_LLVMGCC) --rtlib=compiler-rt -x c - -o /dev/null 2>/dev/null && \
       echo $(SYMBOL) || echo undefined)
ifeq ($(SYMBOL),__init_cpu_features_resolver)
CFLAGS += --rtlib=compiler-rt -DHAS_DARWIN_FMV
endif
ifeq ($(SYMBOL),__init_cpu_features)
CFLAGS += --rtlib=compiler-rt -DHAS_LINUX_FMV
endif
ifeq ($(SYMBOL),undefined)
PROGRAMS_TO_SKIP := aarch64-init-cpu-features
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
