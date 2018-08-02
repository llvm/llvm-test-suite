list(APPEND CFLAGS -fno-strict-aliasing)
list(APPEND LDFLAGS -lm)
set(RUN_OPTIONS -Q -s 901820 - < ${CMAKE_CURRENT_SOURCE_DIR}/tune)
llvm_multisource(oggenc)
