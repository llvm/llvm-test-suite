set(PROG security-sha)
set(LDFLAGS -lm)
set(RUN_OPTIONS ${CMAKE_CURRENT_SOURCE_DIR}/input_large.asc )
llvm_multisource()
