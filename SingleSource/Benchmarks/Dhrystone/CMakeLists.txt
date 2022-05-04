list(APPEND LDFLAGS -lm)
list(APPEND CFLAGS -Wno-implicit-int)
llvm_singlesource()
