set(PROG hotspot)
set(FP_ABSTOLERANCE 0.00001)
list(APPEND CFLAGS -I${CMAKE_CURRENT_SOURCE_DIR}/../Common)
set(Source hotspotKernel.c main.c ../Common/glibc_compat_rand.c)
set(WORKDIR ${CMAKE_CURRENT_BINARY_DIR})

llvm_multisource()
