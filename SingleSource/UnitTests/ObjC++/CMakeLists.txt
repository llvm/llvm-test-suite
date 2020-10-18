list(APPEND LDFLAGS -lobjc -framework Foundation)
file(GLOB Source *.mm)
llvm_singlesource()
