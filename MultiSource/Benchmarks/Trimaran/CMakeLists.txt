set(DIRS)
set(PARALLEL_DIRS)

set(LEVEL ../../..)
set(PARALLEL_DIRS enc-3des enc-md5 enc-pc1 enc-rc4 netbench-crc netbench-url)
llvm_multisource()

llvm_add_subdirectories(${DIRS} ${PARALLEL_DIRS})
