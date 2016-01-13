set(DIRS)
set(PARALLEL_DIRS)

set(LEVEL ../../..)
list(APPEND LDFLAGS -lm )
set(FP_TOLERANCE 0.001)
if(DEFINED BENCHMARKING_ONLY)
  list(APPEND PROGRAMS_TO_SKIP exptree)
endif()
llvm_singlesource()

llvm_add_subdirectories(${DIRS} ${PARALLEL_DIRS})
