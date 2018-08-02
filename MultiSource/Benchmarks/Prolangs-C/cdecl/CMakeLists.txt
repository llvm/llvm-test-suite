list(APPEND CFLAGS -std=gnu89)
set(PROG cdecl)
set(RUN_OPTIONS < ${CMAKE_CURRENT_SOURCE_DIR}/testset)
llvm_multisource()
