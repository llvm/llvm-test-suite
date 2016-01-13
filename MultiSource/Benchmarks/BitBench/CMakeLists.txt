set(DIRS)
set(PARALLEL_DIRS)

set(PARALLEL_DIRS five11 drop3 uudecode uuencode)
llvm_multisource()

llvm_add_subdirectories(${DIRS} ${PARALLEL_DIRS})
