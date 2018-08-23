set(FP_ABSTOLERANCE 0.00001)
list(APPEND CFLAGS -I${CMAKE_CURRENT_SOURCE_DIR}/../Common)

llvm_multisource(hotspot
  hotspotKernel.c
  main.c
  ../Common/glibc_compat_rand.c
)
