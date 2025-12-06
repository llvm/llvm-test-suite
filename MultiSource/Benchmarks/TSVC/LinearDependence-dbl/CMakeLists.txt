list(APPEND LDFLAGS -lm)
set(RUN_OPTIONS 3570 14)
llvm_multisource(LinearDependence-dbl)
set_property(TARGET LinearDependence-dbl PROPERTY C_STANDARD 99)
