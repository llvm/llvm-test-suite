set(PROG security-sha)
list(APPEND LDFLAGS -lm)
set(RUN_OPTIONS ${CMAKE_CURRENT_SOURCE_DIR}/input_large.asc )
llvm_multisource()
