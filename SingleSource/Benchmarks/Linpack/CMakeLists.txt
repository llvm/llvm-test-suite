set(DIRS)
set(PARALLEL_DIRS)

set(LEVEL ../../..)
list(APPEND LDFLAGS -lm)
set(FP_TOLERANCE 0.0001)
llvm_singlesource()

llvm_add_subdirectories(${DIRS} ${PARALLEL_DIRS})
