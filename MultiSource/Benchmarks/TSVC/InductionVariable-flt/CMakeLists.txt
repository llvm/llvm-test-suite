list(APPEND LDFLAGS -lm)
set(RUN_OPTIONS 9100 5)
llvm_multisource(InductionVariable-flt)
set_property(TARGET InductionVariable-flt PROPERTY C_STANDARD 99)
