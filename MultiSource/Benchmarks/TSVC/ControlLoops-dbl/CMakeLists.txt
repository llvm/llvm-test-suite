list(APPEND LDFLAGS -lm)
set(RUN_OPTIONS 1640 14)
llvm_multisource(ControlLoops-dbl)
set_property(TARGET ControlLoops-dbl PROPERTY C_STANDARD 99)
