set(PROG ks)
list(APPEND RUN_OPTIONS ${CMAKE_CURRENT_SOURCE_DIR}/KL-4.in)
llvm_multisource()
