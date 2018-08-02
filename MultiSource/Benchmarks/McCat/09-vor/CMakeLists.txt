set(RUN_OPTIONS < ${CMAKE_CURRENT_SOURCE_DIR}/vor.in3)
list(APPEND LDFLAGS -lm)
llvm_multisource(vor)
