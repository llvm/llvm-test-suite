list(APPEND LDFLAGS -lm)
set(RUN_OPTIONS 3125 14)
llvm_multisource(Equivalencing-dbl)
set_property(TARGET Equivalencing-dbl PROPERTY C_STANDARD 99)
