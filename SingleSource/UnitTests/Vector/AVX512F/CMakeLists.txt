list(APPEND LDFLAGS -lm)
list(APPEND CFLAGS "-march=${X86CPU_ARCH}")
list(APPEND CFLAGS -fms-extensions)
llvm_singlesource(PREFIX "Vector-AVX512F-")
