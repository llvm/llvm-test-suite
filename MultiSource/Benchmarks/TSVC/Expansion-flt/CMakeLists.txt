list(APPEND LDFLAGS -lm)
set(RUN_OPTIONS 4160 5)
llvm_multisource(Expansion-flt)
set_property(TARGET Expansion-flt PROPERTY C_STANDARD 99)
