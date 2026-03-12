llvm_singlesource()
set_property(TARGET runtime-checks PROPERTY CXX_STANDARD 17)
set_property(TARGET early-exit PROPERTY CXX_STANDARD 17)

# The VPlan-native path is specific to llvm.
if ("${CMAKE_C_COMPILER_ID}" MATCHES "Clang")
  add_subdirectory(VPlanNativePath)

  set(_base_cxxflags ${CXXFLAGS})


  # Add targets for all tests with forced tail folding.
  list(APPEND CXXFLAGS  "-mllvm" "-prefer-predicate-over-epilogue=predicate-dont-vectorize" "-mllvm" "-force-tail-folding-style=data")
  llvm_singlesource(PREFIX "tfactivelanemask-")

  # Add targets for all tests with forced tail folding using data without lane mask.
  set(CXXFLAGS ${_base_cxxflags})
  list(APPEND CXXFLAGS  "-mllvm" "-prefer-predicate-over-epilogue=predicate-dont-vectorize" "-mllvm" "-force-tail-folding-style=data-without-lane-mask")
  llvm_singlesource(PREFIX "tf-")

  # Add targets with instruction cost forced to 1.
  set(CXXFLAGS ${_base_cxxflags})
  list(APPEND CXXFLAGS "-mllvm" "-force-target-instruction-cost=1")
  llvm_singlesource(PREFIX "ftic-")

  # Add targets with instruction cost forced to 1 and forced tail-folding.
  set(CXXFLAGS ${_base_cxxflags})
  list(APPEND CXXFLAGS "-mllvm" "-force-target-instruction-cost=1" "-mllvm" "-prefer-predicate-over-epilogue=predicate-dont-vectorize" "-mllvm" "-force-tail-folding-style=data")
  llvm_singlesource(PREFIX "tfactivelanemask-ftic-")

  # Add targets with instruction cost forced to 1 and forced tail-folding without lane mask.
  set(CXXFLAGS ${_base_cxxflags})
  list(APPEND CXXFLAGS "-mllvm" "-force-target-instruction-cost=1" "-mllvm" "-prefer-predicate-over-epilogue=predicate-dont-vectorize" "-mllvm" "-force-tail-folding-style=data-without-lane-mask")
  llvm_singlesource(PREFIX "tf-ftic-")

endif()
