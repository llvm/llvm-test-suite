list(APPEND LDFLAGS -lm)
set(RUN_OPTIONS 3125 5)
llvm_multisource(Equivalencing-flt)
set_property(TARGET Equivalencing-flt PROPERTY C_STANDARD 99)
