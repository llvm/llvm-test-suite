set(PROG bintr)
list(APPEND LDFLAGS -lm)
set(STDIN_FILENAME ${CMAKE_CURRENT_SOURCE_DIR}/bnchmrk.in1)
llvm_multisource()
