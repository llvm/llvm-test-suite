list(APPEND LDFLAGS -lm)
set(RUN_OPTIONS 5880 14)
llvm_multisource(CrossingThresholds-dbl)
set_property(TARGET CrossingThresholds-dbl PROPERTY C_STANDARD 99)
