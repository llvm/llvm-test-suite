set(PROG mybison)
set(RUN_OPTIONS ${CMAKE_CURRENT_SOURCE_DIR}/parse.y.in -v)
llvm_multisource()
