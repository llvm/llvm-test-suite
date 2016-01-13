set(PROG unix-smail)
set(RUN_OPTIONS -v ALL)
set(STDIN_FILENAME ${CMAKE_CURRENT_SOURCE_DIR}/main.c)
llvm_multisource()
