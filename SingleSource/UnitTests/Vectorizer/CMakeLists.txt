set(CMAKE_CXX_STANDARD 17)
llvm_singlesource()

# The VPlan-native path is specific to llvm.
if ("${CMAKE_C_COMPILER_ID}" MATCHES "Clang")
  add_subdirectory(VPlanNativePath)

  set(BASE_CXXFLAGS ${CXXFLAGS})

  # Add targets for all tests with forced tail folding.
  list(APPEND CXXFLAGS
    "-mllvm" "-prefer-predicate-over-epilogue=predicate-dont-vectorize"
    "-mllvm" "-force-tail-folding-style=data"
  )
  llvm_singlesource(PREFIX "tfactivelanemask-")

  # Add targets for all tests with forced tail folding using data without lane mask.
  set(CXXFLAGS ${BASE_CXXFLAGS})
  list(APPEND CXXFLAGS
    "-mllvm" "-prefer-predicate-over-epilogue=predicate-dont-vectorize"
    "-mllvm" "-force-tail-folding-style=data-without-lane-mask"
  )
  llvm_singlesource(PREFIX "tf-")

  # Add targets with instruction cost forced to 1.
  set(CXXFLAGS ${BASE_CXXFLAGS})
  list(APPEND CXXFLAGS
    "-mllvm" "-force-target-instruction-cost=1"
  )
  llvm_singlesource(PREFIX "ftic-")

  # Add targets with instruction cost forced to 1 and forced tail-folding.
  set(CXXFLAGS ${BASE_CXXFLAGS})
  list(APPEND CXXFLAGS
    "-mllvm" "-force-target-instruction-cost=1"
    "-mllvm" "-prefer-predicate-over-epilogue=predicate-dont-vectorize"
    "-mllvm" "-force-tail-folding-style=data"
  )
  llvm_singlesource(PREFIX "tfactivelanemask-ftic-")

  # Add targets with instruction cost forced to 1 and forced tail-folding without lane mask.
  set(CXXFLAGS ${BASE_CXXFLAGS})
  list(APPEND CXXFLAGS
    "-mllvm" "-force-target-instruction-cost=1"
    "-mllvm" "-prefer-predicate-over-epilogue=predicate-dont-vectorize"
    "-mllvm" "-force-tail-folding-style=data-without-lane-mask"
  )
  llvm_singlesource(PREFIX "tf-ftic-")

  set(CXXFLAGS ${BASE_CXXFLAGS})
endif()
