set(DISABLE_JIT 1)
list(APPEND LDFLAGS -lobjc -framework Foundation)
file(GLOB Source *.m)
llvm_singlesource()
