set(DIRS)
set(PARALLEL_DIRS)

set(LEVEL ../../../..)
set(DIRS )
set(FP_TOLERANCE 0.002)
list(APPEND TARGET_FLAGS -maltivec)
list(APPEND TEST_TARGET_FLAGS -maltivec)
list(APPEND LCCFLAGS -maltivec)
llvm_singlesource()

llvm_add_subdirectories(${DIRS} ${PARALLEL_DIRS})
