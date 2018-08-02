list(APPEND CFLAGS -std=gnu89)
set(RUN_OPTIONS < ${CMAKE_CURRENT_SOURCE_DIR}/testset)
llvm_multisource(cdecl)
