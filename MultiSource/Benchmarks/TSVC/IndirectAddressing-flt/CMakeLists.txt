list(APPEND LDFLAGS -lm)
set(RUN_OPTIONS 12500 5)
llvm_multisource(IndirectAddressing-flt)
set_property(TARGET IndirectAddressing-flt PROPERTY C_STANDARD 99)
