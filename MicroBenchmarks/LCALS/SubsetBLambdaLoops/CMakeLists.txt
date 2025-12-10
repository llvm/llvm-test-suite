list(APPEND CPPFLAGS -std=c++11 -DLCALS_USE_DOUBLE -DLCALS_USE_RESTRICT_PTR -DLCALS_VERIFY_CHECKSUM -DLCALS_USE_CLOCK -DLCALS_COMPILER_CLANG)
llvm_test_run()
llvm_test_executable(lcalsBLambda ../main.cxx LambdaSubsetBbenchmarks.cxx  ../LCALSStats.cxx ../LCALSSuite.cxx  ../LCALSTraversalMethods.cxx ../runReferenceLoops.cxx)
target_link_libraries(lcalsBLambda benchmark)

