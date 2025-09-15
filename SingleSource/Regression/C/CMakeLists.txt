if(ARCH MATCHES "x86" OR ARCH MATCHES "riscv" OR
   ARCH MATCHES "SystemZ" OR ARCH MATCHES "Mips" OR
   ARCH MATCHES "AArch64" OR ARCH MATCHES "ARM" OR
   ARCH MATCHES "LoongArch" OR ARCH MATCHES "Hexagon")
  add_subdirectory(gcc-c-torture)
endif()

list(APPEND LDFLAGS -lm)
list(APPEND CFLAGS -Wno-implicit-int)
list(APPEND CFLAGS -Wno-error=incompatible-pointer-types)
llvm_singlesource(PREFIX "Regression-C-")
