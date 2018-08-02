list(APPEND LDFLAGS -lm)
set(RUN_OPTIONS < ${CMAKE_CURRENT_SOURCE_DIR}/bnchmrk.in1)
llvm_multisource(bintr)
