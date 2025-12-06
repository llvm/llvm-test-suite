list(APPEND CFLAGS -Wno-int-conversion)
list(APPEND LDFLAGS -lm)
llvm_multisource(assembler)
set_property(TARGET assembler PROPERTY C_STANDARD 17)
