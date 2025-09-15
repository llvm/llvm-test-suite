list(APPEND CPPFLAGS -fcommon)
list(APPEND CPPFLAGS -Wno-error=incompatible-pointer-types)
list(APPEND LDFLAGS -lm)
llvm_multisource(timberwolfmc)
