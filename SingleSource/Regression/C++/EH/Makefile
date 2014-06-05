LEVEL = ../../../..
REQUIRES_EH_SUPPORT = 1

include $(LEVEL)/Makefile.config

ifdef BENCHMARKING_ONLY
PROGRAMS_TO_SKIP += \
	class_hierarchy \
	ConditionalExpr \
	ctor_dtor_count \
	ctor_dtor_count-2 \
	dead_try_block \
	exception_spec_test \
	function_try_block \
	inlined_cleanup \
	recursive-throw \
	simple_rethrow \
	simple_throw \
	throw_rethrow_test
endif

LDFLAGS += -lstdc++
include $(LEVEL)/SingleSource/Makefile.singlesrc
