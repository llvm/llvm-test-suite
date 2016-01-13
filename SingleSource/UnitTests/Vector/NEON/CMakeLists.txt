set(DIRS)
set(PARALLEL_DIRS)

set(DIRS )
if(DEFINED BENCHMARKING_ONLY)
  list(APPEND PROGRAMS_TO_SKIP simple)
endif()
list(APPEND CFLAGS -std=c99)
llvm_singlesource()

llvm_add_subdirectories(${DIRS} ${PARALLEL_DIRS})
