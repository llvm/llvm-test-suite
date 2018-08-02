list(APPEND LDFLAGS -lobjc -framework Foundation)
file(GLOB Source *.m)
llvm_singlesource()
