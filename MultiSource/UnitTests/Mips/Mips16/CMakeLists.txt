set(PARALLEL_DIRS)

list(APPEND PARALLEL_DIRS multitest fp16_32_1)

llvm_add_subdirectories(${PARALLEL_DIRS})
