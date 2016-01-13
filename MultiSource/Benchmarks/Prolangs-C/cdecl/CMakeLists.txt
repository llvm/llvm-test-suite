list(APPEND CFLAGS -std=gnu89)
set(PROG cdecl)
set(STDIN_FILENAME ${CMAKE_CURRENT_SOURCE_DIR}/testset)
llvm_multisource()
