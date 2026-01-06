list(APPEND LDFLAGS -lm)
set(RUN_OPTIONS 5880 5)
llvm_multisource(CrossingThresholds-flt)
set_property(TARGET CrossingThresholds-flt PROPERTY C_STANDARD 99)
