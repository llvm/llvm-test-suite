set(PROG anagram)
set(RUN_OPTIONS ${CMAKE_CURRENT_SOURCE_DIR}/words 2)
set(STDIN_FILENAME ${CMAKE_CURRENT_SOURCE_DIR}/input.OUT)
llvm_multisource()
