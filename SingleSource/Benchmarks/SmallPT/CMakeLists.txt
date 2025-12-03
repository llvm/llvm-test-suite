list(APPEND LDFLAGS -lm)
set(FP_TOLERANCE 0.001)
llvm_singlesource()
set_property(TARGET smallpt PROPERTY CXX_STANDARD 98)
