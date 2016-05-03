set(PROG testtrie)
list(APPEND LDFLAGS -lm)
list(APPEND RUN_OPTIONS ${CMAKE_CURRENT_SOURCE_DIR}/testtrie.in2)
llvm_multisource()
