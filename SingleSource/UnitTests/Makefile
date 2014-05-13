# SingleSource/UnitTests/Makefile
LEVEL = ../..
include $(LEVEL)/Makefile.config

DIRS := SetjmpLongjmp

# FIXME: Disable SJLJ tests for now, until EH edges are represented.
DIRS :=

DIRS += Vector 
DIRS += Vectorizer

DIRS += SignlessTypes Threads

# Only test Obj-C on Darwin.
ifeq ($(TARGET_OS),Darwin)
DIRS += ObjC ObjC++
endif

# Darwin doesn't support weak/weak_import in a way that we can test in this
# framework.
ifeq ($(TARGET_OS),Darwin)
PROGRAMS_TO_SKIP := 2007-04-25-weak
# The gcc on Darwin PPC doesn't support atomic ops, so we can't test them in this
# framework (even though they work OK in llvm).
ifeq ($(ARCH),PowerPC)
PROGRAMS_TO_SKIP += AtomicOps
endif
endif

# The ms_struct tests only make sense on x86_64.
ifneq ($(ARCH),x86_64)
PROGRAMS_TO_SKIP += ms_struct-bitfield-init-1 ms_struct-bitfield-init ms_struct-bitfield ms_struct_pack_layout-1 ms_struct_pack_layout ms_struct-bitfield-1
endif

# Add special tests for Mips
ifeq ($(ARCH),Mips)
DIRS += Mips
endif

ifeq ($(ARCH),XCore)
# XCore does not support atomic read/write
PROGRAMS_TO_SKIP += AtomicOps
# XCore does not support init_priority attribute
PROGRAMS_TO_SKIP += initp1
# 2007-04-25-weak contains a branch to zero.
# XCore BLR instruction can only branch 21bits, hence restrict memory to 20bits viz: 0x100000->0x1fffff
XCORE_TARGET_NEEDS_MEMORY := 1
endif

LDFLAGS += -lstdc++
include $(LEVEL)/SingleSource/Makefile.singlesrc
