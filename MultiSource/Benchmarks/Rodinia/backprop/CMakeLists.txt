set(PROG backprop)
list(APPEND CFLAGS -I${CMAKE_CURRENT_SOURCE_DIR}/../Common)
list(APPEND LDFLAGS -lm)
set(FP_ABSTOLERANCE 0.00001)
llvm_multisource(backprop 
  main.c 
  backpropKernel.c 
  ../Common/glibc_compat_rand.c
)
