set(DIRS)
set(PARALLEL_DIRS)

set(DIRS Large)
set(LEVEL ../../..)
list(APPEND LDFLAGS -lm)
llvm_singlesource()

llvm_add_subdirectories(${DIRS} ${PARALLEL_DIRS})
