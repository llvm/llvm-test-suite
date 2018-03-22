set(PROG HPCCG)
list(APPEND CXXFLAGS -DREDSTORM) # -DREDSTORM for mkdir
list(APPEND LDFLAGS -lm)
set(RUN_OPTIONS 50 50 50)
llvm_multisource()
