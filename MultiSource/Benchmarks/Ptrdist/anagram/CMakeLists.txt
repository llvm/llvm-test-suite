list(APPEND CFLAGS -Wno-implicit-function-declaration)
set(RUN_OPTIONS words 2 < input.OUT)
llvm_multisource(anagram)
llvm_test_data(anagram words input.OUT)
