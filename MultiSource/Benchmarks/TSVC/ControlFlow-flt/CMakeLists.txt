list(APPEND LDFLAGS -lm)
set(RUN_OPTIONS 2325 5)
llvm_multisource(ControlFlow-flt)
set_property(TARGET ControlFlow-flt PROPERTY C_STANDARD 99)
