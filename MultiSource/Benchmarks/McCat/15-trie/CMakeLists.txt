set(PROG trie)
list(APPEND LDFLAGS -lm)
list(APPEND RUN_OPTIONS ${CMAKE_CURRENT_SOURCE_DIR}/trie.in1)
llvm_multisource()
