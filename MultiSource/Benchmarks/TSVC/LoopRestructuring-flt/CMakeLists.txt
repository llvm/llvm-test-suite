list(APPEND LDFLAGS -lm)
set(RUN_OPTIONS 4350 5)
llvm_multisource(LoopRestructuring-flt)
set_property(TARGET LoopRestructuring-flt PROPERTY C_STANDARD 99)
