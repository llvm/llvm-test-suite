list(APPEND CPPFLAGS -DUNIX)
list(APPEND CFLAGS -Wno-implicit-int)
set(RUN_OPTIONS 8 tob.38-44 liv.42-48)
llvm_multisource(sim)

llvm_test_data(sim tob.38-44 liv.42-48)
