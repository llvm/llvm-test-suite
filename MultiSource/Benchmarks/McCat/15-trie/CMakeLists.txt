list(APPEND LDFLAGS -lm)
list(APPEND RUN_OPTIONS trie.in1)
llvm_multisource(trie)
llvm_test_data(trie trie.in1)
