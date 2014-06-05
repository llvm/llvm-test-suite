LEVEL = ../../..

ifeq ($(ARCH),x86)
ifdef USE_REFERENCE_OUTPUT
EXEC_XFAILS = casts
endif
endif

ifdef BENCHMARKING_ONLY
PROGRAMS_TO_SKIP += \
	2003-05-14-initialize-string \
	2003-05-21-BitfieldHandling \
	2003-05-21-UnionBitfields \
	2003-05-21-UnionTest \
	2003-05-22-LocalTypeTest \
	2003-05-22-VarSizeArray \
	2003-05-23-TransparentUnion \
	2003-06-16-InvalidInitializer \
	2003-06-16-VolatileError \
	2003-10-12-GlobalVarInitializers \
	2004-02-03-AggregateCopy \
	2004-03-15-IndirectGoto \
	2005-05-06-LongLongSignedShift \
	2008-01-07-LongDouble \
	badidx \
	bigstack \
	callargs \
	casts \
	compare \
	ConstructorDestructorAttributes \
	DuffsDevice \
	globalrefs \
	pointer_arithmetic \
	PR10189 \
	PR1386 \
	PR491 \
	PR640 \
	sumarray \
	sumarraymalloc \
	testtrace
endif

include $(LEVEL)/SingleSource/Makefile.singlesrc

