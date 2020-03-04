list(APPEND CPPFLAGS -fcommon)
list(APPEND LDFLAGS -lm)
llvm_multisource(loader)
