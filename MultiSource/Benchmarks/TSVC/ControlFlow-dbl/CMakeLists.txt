list(APPEND LDFLAGS -lm)
set(RUN_OPTIONS 2325 14)
llvm_multisource(ControlFlow-dbl)
set_property(TARGET ControlFlow-dbl PROPERTY C_STANDARD 99)
