set(PROG simulator)
list(APPEND LDFLAGS -lm)
llvm_multisource()
