set(RUN_OPTIONS ${CMAKE_CURRENT_SOURCE_DIR}/words 2 < ${CMAKE_CURRENT_SOURCE_DIR}/input.OUT)
llvm_multisource(anagram)
