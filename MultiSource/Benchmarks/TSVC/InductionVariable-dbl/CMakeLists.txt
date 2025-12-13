list(APPEND LDFLAGS -lm)
set(RUN_OPTIONS 9100 14)
llvm_multisource(InductionVariable-dbl)
set_property(TARGET InductionVariable-dbl PROPERTY C_STANDARD 99)
