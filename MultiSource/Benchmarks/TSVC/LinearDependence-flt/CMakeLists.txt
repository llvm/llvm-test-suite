list(APPEND LDFLAGS -lm)
set(RUN_OPTIONS 3570 5)
llvm_multisource(LinearDependence-flt)
set_property(TARGET LinearDependence-flt PROPERTY C_STANDARD 99)
