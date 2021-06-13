list(APPEND LDFLAGS -lm)
set(FP_ABSTOLERANCE 0.00001)
list(APPEND CFLAGS -I${CMAKE_CURRENT_SOURCE_DIR}/../Common)
# Floating point contraction must be suppressed due to accuracy issues
list(APPEND CXXFLAGS -ffp-contract=off -DFMA_DISABLED=1)
list(APPEND CFLAGS -ffp-contract=off -DFMA_DISABLED=1)

llvm_multisource(srad
  main.c
  sradKernel.c
  ../Common/glibc_compat_rand.c
)
