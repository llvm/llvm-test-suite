file(GLOB uosources ${CMAKE_CURRENT_SOURCE_DIR}/${ARCH}_tests/*.bc)
SET_SOURCE_FILES_PROPERTIES(${uosources} PROPERTIES LANGUAGE CXX)
file(GLOB scalar_sources ${CMAKE_CURRENT_SOURCE_DIR}/${ARCH}_scalar_tests/*.bc)
SET_SOURCE_FILES_PROPERTIES(${scalar_sources} PROPERTIES LANGUAGE CXX)
SET_SOURCE_FILES_PROPERTIES(${CMAKE_CURRENT_SOURCE_DIR}/simd_op_check_runtime.bc PROPERTIES LANGUAGE CXX)

list(APPEND LDFLAGS -lpthread -ldl)

foreach(sourcebc ${uosources})
  string(REGEX REPLACE ".[cp]+$" "" pathbc ${sourcebc})
  string(REGEX REPLACE ".*/" "" namebc ${pathbc})
  string(REPLACE "." "" namebc ${namebc})
  add_custom_command(
    OUTPUT    ${CMAKE_CURRENT_BINARY_DIR}/${ARCH}_opt_tests/${namebc}.bc
    DEPENDS   ${CMAKE_CURRENT_SOURCE_DIR}/${ARCH}_tests/${namebc}.bc
    COMMAND   sh ${CMAKE_CURRENT_SOURCE_DIR}/opt_test.sh ${namebc} ${CMAKE_CURRENT_SOURCE_DIR} ${ARCH}
    COMMENT   Optimized tests (vectorized and scalar)
  )
  add_custom_command(
    OUTPUT    ${CMAKE_CURRENT_BINARY_DIR}/${ARCH}_opt_scalar_tests/scalar_${namebc}.bc
    DEPENDS   ${CMAKE_CURRENT_SOURCE_DIR}/${ARCH}_scalar_tests/scalar_${namebc}.bc
    COMMAND   sh ${CMAKE_CURRENT_SOURCE_DIR}/opt_test.sh ${namebc} ${CMAKE_CURRENT_SOURCE_DIR} ${ARCH} scalar
    COMMENT   Optimized tests (vectorized and scalar)
  )
  set(Source ${CMAKE_CURRENT_SOURCE_DIR}/simd_ops.cpp ${CMAKE_CURRENT_SOURCE_DIR}/simd_op_check_runtime.bc ${CMAKE_CURRENT_BINARY_DIR}/${ARCH}_opt_tests/${namebc}.bc ${CMAKE_CURRENT_BINARY_DIR}/${ARCH}_opt_scalar_tests/scalar_${namebc}.bc ${CMAKE_CURRENT_SOURCE_DIR}/${ARCH}_tests/${namebc}.bc ${CMAKE_CURRENT_SOURCE_DIR}/${ARCH}_scalar_tests/scalar_${namebc}.bc)
  SET_SOURCE_FILES_PROPERTIES(${CMAKE_CURRENT_BINARY_DIR}/${ARCH}_opt_tests/${namebc}.bc PROPERTIES LANGUAGE CXX)
  SET_SOURCE_FILES_PROPERTIES(${CMAKE_CURRENT_BINARY_DIR}/${ARCH}_opt_scalar_tests/scalar_${namebc}.bc PROPERTIES LANGUAGE CXX)
  set(PROG simd_ops_${namebc})
  llvm_multisource()
endforeach()


