list(APPEND LDFLAGS -lstdc++ -lobjc -framework Foundation)
file(GLOB Source *.mm)
llvm_singlesource()
