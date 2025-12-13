list(APPEND LDFLAGS -lm)
list(APPEND CFLAGS -Wno-implicit-int)
llvm_singlesource()
set_property(TARGET dry fldry PROPERTY C_STANDARD 17)
