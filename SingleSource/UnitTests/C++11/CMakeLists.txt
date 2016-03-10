list(APPEND CPPFLAGS -std=c++11 -pthread)
list(APPEND LDFLAGS -lstdc++ -pthread)
llvm_singlesource()
