set(PROG vor)
set(STDIN_FILENAME ${CMAKE_CURRENT_SOURCE_DIR}/vor.in3)
list(APPEND LDFLAGS -lm)
llvm_multisource()
