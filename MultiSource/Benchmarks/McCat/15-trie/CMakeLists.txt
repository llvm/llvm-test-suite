set(DIRS)
set(PARALLEL_DIRS)

set(LEVEL ../../../..)
set(PROG trie)
set(LDFLAGS -lm)
list(APPEND RUN_OPTIONS ${CMAKE_CURRENT_SOURCE_DIR}/trie.in1)
llvm_multisource()

llvm_add_subdirectories(${DIRS} ${PARALLEL_DIRS})
