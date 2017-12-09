list(APPEND CXXFLAGS -std=gnu++98)
list(APPEND LDFLAGS -lm -lstdc++)
set(FP_TOLERANCE 0.001)
llvm_singlesource()
