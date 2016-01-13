set(DIRS)
set(PARALLEL_DIRS)

list(APPEND PARALLEL_DIRS multitest fp16_32_1)
llvm_multisource()

llvm_add_subdirectories(${DIRS} ${PARALLEL_DIRS})
