set(DIRS)
set(PARALLEL_DIRS)

set(REQUIRES_EH_SUPPORT 1)
if(DEFINED BENCHMARKING_ONLY)
  list(APPEND PROGRAMS_TO_SKIP class_hierarchy ConditionalExpr ctor_dtor_count ctor_dtor_count-2 dead_try_block exception_spec_test function_try_block inlined_cleanup recursive-throw simple_rethrow simple_throw throw_rethrow_test)
endif()
list(APPEND LDFLAGS -lstdc++)
llvm_singlesource()

llvm_add_subdirectories(${DIRS} ${PARALLEL_DIRS})
