set(CMAKE_CXX_STANDARD 17)
llvm_singlesource()
include(CheckCXXCompilerFlag)

function(llvm_vectorizer_variant prefix)
  llvm_singlesource(PREFIX "${prefix}-" DEST_SUFFIX "-${prefix}")
endfunction()

# The VPlan-native path is specific to llvm.
if ("${CMAKE_C_COMPILER_ID}" MATCHES "Clang")
  add_subdirectory(VPlanNativePath)

  # Check if tail-folding-policy option is available
  check_cxx_compiler_flag("-mllvm -tail-folding-policy=must-fold-tail" HAS_TAIL_FOLDING_POLICY)
  if (HAS_TAIL_FOLDING_POLICY)
    # Use the new flag
    set(TAIL_FOLDING_OPT "-tail-folding-policy")
    set(TAIL_FOLDING_VAL "must-fold-tail")
  else()
    # Fall back to the old flag
    set(TAIL_FOLDING_OPT "-prefer-predicate-over-epilogue")
    set(TAIL_FOLDING_VAL "predicate-dont-vectorize")
  endif()

  set(BASE_CXXFLAGS ${CXXFLAGS})

  # Add targets for all tests with forced tail folding.
  list(APPEND CXXFLAGS
    "-mllvm" "${TAIL_FOLDING_OPT}=${TAIL_FOLDING_VAL}"
    "-mllvm" "-force-tail-folding-style=data"
  )
  llvm_vectorizer_variant("tfactivelanemask")

  # Add targets for all tests with forced tail folding using data without lane mask.
  set(CXXFLAGS ${BASE_CXXFLAGS})
  list(APPEND CXXFLAGS
    "-mllvm" "${TAIL_FOLDING_OPT}=${TAIL_FOLDING_VAL}"
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
    "-mllvm" "${TAIL_FOLDING_OPT}=${TAIL_FOLDING_VAL}"
    "-mllvm" "-force-tail-folding-style=data"
  )
  llvm_vectorizer_variant("tfactivelanemask-ftic")

  # Add targets with instruction cost forced to 1 and forced tail-folding without lane mask.
  set(CXXFLAGS ${BASE_CXXFLAGS})
  list(APPEND CXXFLAGS
    "-mllvm" "-force-target-instruction-cost=1"
    "-mllvm" "${TAIL_FOLDING_OPT}=${TAIL_FOLDING_VAL}"
    "-mllvm" "-force-tail-folding-style=data-without-lane-mask"
  )
  llvm_vectorizer_variant("tf-ftic")

  set(CXXFLAGS ${BASE_CXXFLAGS})
endif()
