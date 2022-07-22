list(APPEND CFLAGS -Wno-int-conversion)
list(APPEND LDFLAGS -lm)
llvm_multisource(assembler)
