include(CheckSymbolExists)

list(APPEND LDFLAGS -lm )
list(APPEND CFLAGS -Wno-implicit-int)
set(FP_TOLERANCE 0.001)
set(Source
  ReedSolomon.c
  evalloop.c
  fbench.c
  ffbench.c
  flops-1.c
  flops-2.c
  flops-3.c
  flops-4.c
  flops-5.c
  flops-6.c
  flops-7.c
  flops-8.c
  flops.c
  fp-convert.c
  himenobmtxpa.c
  lowercase.c
  mandel-2.c
  mandel.c
  matmul_f64_4x4.c
  oourafft.c
  perlin.c
  pi.c
  revertBits.c
  richards_benchmark.c
  salsa20.c
  whetstone.c
)
if(NOT ARCH STREQUAL "PowerPC" OR NOT TARGET_OS STREQUAL "Darwin")
  list(APPEND Source dt.c)
endif()
if(ARCH STREQUAL "AArch64")
  if(TARGET_OS STREQUAL "Darwin")
    file(WRITE ${CMAKE_CURRENT_BINARY_DIR}/CheckHasAArch64FMV.h "void __init_cpu_features_resolver(void);")
    check_symbol_exists(__init_cpu_features_resolver ${CMAKE_CURRENT_BINARY_DIR}/CheckHasAArch64FMV.h HAS_AARCH64_FMV)
    if(HAS_AARCH64_FMV)
      list(APPEND CFLAGS -DHAS_DARWIN_FMV)
      list(APPEND Source aarch64-init-cpu-features.c)
    endif()
  elseif(TARGET_OS STREQUAL "Linux")
    file(WRITE ${CMAKE_CURRENT_BINARY_DIR}/CheckHasAArch64FMV.h "void __init_cpu_features(void);")
    check_symbol_exists(__init_cpu_features ${CMAKE_CURRENT_BINARY_DIR}/CheckHasAArch64FMV.h HAS_AARCH64_FMV)
    if(HAS_AARCH64_FMV)
      list(APPEND CFLAGS -DHAS_LINUX_FMV)
      list(APPEND Source aarch64-init-cpu-features.c)
    endif()
  endif()
endif()
llvm_singlesource()
