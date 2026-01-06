list(APPEND CPPFLAGS -fcommon)
list(APPEND LDFLAGS -lm)
llvm_multisource(loader)
set_property(TARGET loader PROPERTY C_STANDARD 17)
