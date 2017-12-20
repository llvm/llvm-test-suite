list(APPEND LDFLAGS -lm)
list(APPEND CFLAGS -march=skylake-avx512)
list(APPEND CFLAGS -fms-extensions)
llvm_singlesource(PREFIX "Vector-AVX512-")
