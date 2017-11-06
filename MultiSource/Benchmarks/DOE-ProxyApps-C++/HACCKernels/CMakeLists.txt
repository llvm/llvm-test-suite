set(PROG HACCKernels)
list(APPEND CPPFLAGS -ffast-math -DVERIFICATION_OUTPUT_ONLY=ON)
set(RUN_OPTIONS 450)
llvm_multisource()
