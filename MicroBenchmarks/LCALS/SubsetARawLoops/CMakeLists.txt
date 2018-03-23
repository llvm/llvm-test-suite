list(APPEND CPPFLAGS -std=c++11 -DLCALS_USE_DOUBLE -DLCALS_USE_RESTRICT_PTR -DLCALS_VERIFY_CHECKSUM -DLCALS_USE_CLOCK -DLCALS_COMPILER_CLANG)
llvm_test_run()
llvm_test_executable(lcalsARaw ../main.cxx RawSubsetAbenchmarks.cxx ../LCALSStats.cxx ../LCALSSuite.cxx ../runReferenceLoops.cxx)
target_link_libraries(lcalsARaw benchmark)
