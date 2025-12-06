list(APPEND CPPFLAGS -fcommon)
list(APPEND LDFLAGS -lm)
llvm_multisource(simulator)
set_property(TARGET simulator PROPERTY C_STANDARD 17)
