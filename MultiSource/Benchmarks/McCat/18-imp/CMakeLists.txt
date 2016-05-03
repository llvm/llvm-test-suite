set(PROG imp)
list(APPEND RUN_OPTIONS ${CMAKE_CURRENT_SOURCE_DIR}/sg01.imp)
list(APPEND LDFLAGS -lm)
llvm_multisource()
