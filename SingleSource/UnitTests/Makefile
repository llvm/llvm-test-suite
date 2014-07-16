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

# The ms_struct tests only make sense on x86_64 and x86_64h.
ifeq (,$(filter $(ARCH),x86_64 x86_64h))
PROGRAMS_TO_SKIP += ms_struct-bitfield-init-1 ms_struct-bitfield-init ms_struct-bitfield ms_struct_pack_layout-1 ms_struct_pack_layout ms_struct-bitfield-1
endif

# Add special tests for Mips
ifeq ($(ARCH),Mips)
DIRS += Mips
# MIPS 32-bit does not support 8 bytes atomic operations.
ifeq (,$(findstring mips64,$(MIPSARCH)))
PROGRAMS_TO_SKIP += AtomicOps
endif
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

ifdef BENCHMARKING_ONLY
PROGRAMS_TO_SKIP += \
	2002-04-17-PrintfChar \
	2002-05-02-ArgumentTest \
	2002-05-02-CastTest \
	2002-05-02-CastTest1 \
	2002-05-02-CastTest2 \
	2002-05-02-CastTest3 \
	2002-05-02-ManyArguments \
	2002-05-03-NotTest \
	2002-05-19-DivTest \
	2002-08-02-CastTest \
	2002-08-02-CastTest2 \
	2002-08-19-CodegenBug \
	2002-10-09-ArrayResolution \
	2002-10-12-StructureArgs \
	2002-10-12-StructureArgsSimple \
	2002-10-13-BadLoad \
	2002-12-13-MishaTest \
	2003-04-22-Switch \
	2003-05-02-DependentPHI \
	2003-05-07-VarArgs \
	2003-05-12-MinIntProblem \
	2003-05-14-AtExit \
	2003-05-26-Shorts \
	2003-05-31-CastToBool \
	2003-05-31-LongShifts \
	2003-07-06-IntOverflow \
	2003-07-08-BitOpsTest \
	2003-07-09-LoadShorts \
	2003-07-09-SignedArgs \
	2003-07-10-SignConversions \
	2003-08-05-CastFPToUint \
	2003-08-11-VaListArg \
	2003-08-20-FoldBug \
	2003-09-18-BitFieldTest \
	2003-10-13-SwitchTest \
	2003-10-29-ScalarReplBug \
	2004-02-02-NegativeZero \
	2004-06-20-StaticBitfieldInit \
	2004-11-28-GlobalBoolLayout \
	2005-05-11-Popcount-ffs-fls \
	2005-05-12-Int64ToFP \
	2005-05-13-SDivTwo \
	2005-07-17-INT-To-FP \
	2005-11-29-LongSwitch \
	2006-01-29-SimpleIndirectCall \
	2006-02-04-DivRem \
	2006-12-01-float_varg \
	2006-12-04-DynAllocAndRestore \
	2006-12-07-Compare64BitConstant \
	2006-12-11-LoadConstants \
	2007-01-04-KNR-Args \
	2007-03-02-VaCopy \
	2007-04-25-weak \
	2008-04-18-LoopBug \
	2008-04-20-LoopBug2 \
	2008-07-13-InlineSetjmp \
	2009-04-16-BitfieldInitialization \
	2009-12-07-StructReturn \
	2010-05-24-BitfieldTest \
	AtomicOps \
	block-byref-cxxobj-test \
	block-byref-test \
	block-call-r7674133 \
	block-copied-in-cxxobj \
	block-copied-in-cxxobj-1 \
	blockstret \
	byval-alignment \
	conditional-gnu-ext \
	conditional-gnu-ext-cxx \
	DefaultInitDynArrays \
	FloatPrecision \
	initp1 \
	member-function-pointers \
	printargs \
	stmtexpr \
	StructModifyTest \
	TestLoop \
	vla \
	ms_struct-bitfield \
	ms_struct-bitfield-1 \
	ms_struct-bitfield-init \
	ms_struct-bitfield-init-1 \
	ms_struct_pack_layout \
	ms_struct_pack_layout-1
endif

LDFLAGS += -lstdc++
include $(LEVEL)/SingleSource/Makefile.singlesrc
