list(APPEND LDFLAGS -lm)
set(RUN_OPTIONS 12500 14)
llvm_multisource(IndirectAddressing-dbl)
set_property(TARGET IndirectAddressing-dbl PROPERTY C_STANDARD 99)
