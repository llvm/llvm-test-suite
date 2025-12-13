list(APPEND LDFLAGS -lm)
set(RUN_OPTIONS 1640 5)
llvm_multisource(ControlLoops-flt)
set_property(TARGET ControlLoops-flt PROPERTY C_STANDARD 99)
