if(ARCH MATCHES "x86" OR ARCH MATCHES "riscv")
  add_subdirectory(gcc-c-torture)
endif()

list(APPEND LDFLAGS -lm)
llvm_singlesource(PREFIX "Regression-C-")
