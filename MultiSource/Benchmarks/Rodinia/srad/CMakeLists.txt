list(APPEND LDFLAGS -lm)
set(FP_ABSTOLERANCE 0.00001)
list(APPEND CFLAGS -I${CMAKE_CURRENT_SOURCE_DIR}/../Common)
set(WORKDIR ${CMAKE_CURRENT_BINARY_DIR})
llvm_multisource(srad
  main.c
  sradKernel.c
  ../Common/glibc_compat_rand.c
)
