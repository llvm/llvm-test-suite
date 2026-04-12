set(CMAKE_CXX_STANDARD 17)
llvm_singlesource()

function(llvm_vectorizer_variant prefix)
  llvm_singlesource(PREFIX "${prefix}-" DEST_SUFFIX "-${prefix}")
endfunction()

# The VPlan-native path is specific to llvm.
if ("${CMAKE_C_COMPILER_ID}" MATCHES "Clang")
  add_subdirectory(VPlanNativePath)

  set(BASE_CXXFLAGS ${CXXFLAGS})

  # Add targets for all tests with forced tail folding.
  list(APPEND CXXFLAGS
    "-mllvm" "-prefer-predicate-over-epilogue=predicate-dont-vectorize"
    "-mllvm" "-force-tail-folding-style=data"
  )
  llvm_vectorizer_variant("tfactivelanemask")

  # Add targets for all tests with forced tail folding using data without lane mask.
  set(CXXFLAGS ${BASE_CXXFLAGS})
  list(APPEND CXXFLAGS
    "-mllvm" "-prefer-predicate-over-epilogue=predicate-dont-vectorize"
    "-mllvm" "-force-tail-folding-style=data-without-lane-mask"
  )
  llvm_vectorizer_variant("tf")

  # Add targets with instruction cost forced to 1.
  set(CXXFLAGS ${BASE_CXXFLAGS})
  list(APPEND CXXFLAGS
    "-mllvm" "-force-target-instruction-cost=1"
  )
  llvm_vectorizer_variant("ftic")

  # Add targets with instruction cost forced to 1 and forced tail-folding.
  set(CXXFLAGS ${BASE_CXXFLAGS})
  list(APPEND CXXFLAGS
    "-mllvm" "-force-target-instruction-cost=1"
    "-mllvm" "-prefer-predicate-over-epilogue=predicate-dont-vectorize"
    "-mllvm" "-force-tail-folding-style=data"
  )
  llvm_vectorizer_variant("tfactivelanemask-ftic")

  # Add targets with instruction cost forced to 1 and forced tail-folding without lane mask.
  set(CXXFLAGS ${BASE_CXXFLAGS})
  list(APPEND CXXFLAGS
    "-mllvm" "-force-target-instruction-cost=1"
    "-mllvm" "-prefer-predicate-over-epilogue=predicate-dont-vectorize"
    "-mllvm" "-force-tail-folding-style=data-without-lane-mask"
  )
  llvm_vectorizer_variant("tf-ftic")

  set(CXXFLAGS ${BASE_CXXFLAGS})
endif()
