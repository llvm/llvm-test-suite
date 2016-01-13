set(DIRS)
set(PARALLEL_DIRS)

set(PARALLEL_DIRS mpeg2dec)

llvm_add_subdirectories(${DIRS} ${PARALLEL_DIRS})
