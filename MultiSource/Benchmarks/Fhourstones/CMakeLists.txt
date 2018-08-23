list(APPEND CPPFLAGS -DUNIX -DTRANSIZE=1050011 -DPROBES=8 -DREPORTPLY=8)
set(RUN_OPTIONS < input)
llvm_multisource(fhourstones)
llvm_test_data(fhourstones input)
