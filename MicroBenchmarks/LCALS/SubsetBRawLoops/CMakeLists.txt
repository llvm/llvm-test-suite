list(APPEND CPPFLAGS -DLCALS_USE_DOUBLE -DLCALS_USE_RESTRICT_PTR -DLCALS_VERIFY_CHECKSUM -DLCALS_USE_CLOCK -DLCALS_COMPILER_CLANG)
llvm_test_run()
llvm_test_executable(lcalsBRaw ../main.cxx RawSubsetBbenchmarks.cxx  ../LCALSStats.cxx ../LCALSSuite.cxx  ../LCALSTraversalMethods.cxx ../runReferenceLoops.cxx)
set_property(TARGET lcalsBRaw PROPERTY CXX_STANDARD 11)
target_link_libraries(lcalsBRaw benchmark)

