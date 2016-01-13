set(DIRS)
set(PARALLEL_DIRS)

set(DISABLE_JIT 1)
set(DIRS )
list(APPEND LDFLAGS -lobjc -framework Foundation)
if(DEFINED CC_UNDER_TEST_IS_LLVM_GCC)
  set(EXEC_XFAILS dot-syntax-2)
endif()

llvm_add_subdirectories(${DIRS} ${PARALLEL_DIRS})
