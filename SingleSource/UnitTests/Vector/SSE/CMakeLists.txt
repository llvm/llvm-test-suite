set(DIRS)
set(PARALLEL_DIRS)

set(DIRS )
set(FP_TOLERANCE 0.016)
list(APPEND LDFLAGS -lm)
list(APPEND TARGET_FLAGS -msse2)
list(APPEND LCCFLAGS -msse2)
llvm_singlesource()

llvm_add_subdirectories(${DIRS} ${PARALLEL_DIRS})
