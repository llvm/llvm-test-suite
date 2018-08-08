set(NO_REFERENCE_OUTPUT true)
file(GLOB uosources ${CMAKE_CURRENT_SOURCE_DIR}/${ARCH}_tests/*.bc)
SET_SOURCE_FILES_PROPERTIES(${uosources} PROPERTIES LANGUAGE CXX)
file(GLOB scalar_sources ${CMAKE_CURRENT_SOURCE_DIR}/${ARCH}_scalar_tests/*.bc)
SET_SOURCE_FILES_PROPERTIES(${scalar_sources} PROPERTIES LANGUAGE CXX)
SET_SOURCE_FILES_PROPERTIES(${CMAKE_CURRENT_SOURCE_DIR}/${ARCH}_halide_runtime.bc PROPERTIES LANGUAGE CXX)

find_package(Threads)
list(APPEND LDFLAGS ${CMAKE_THREAD_LIBS_INIT})
foreach(lib ${CMAKE_DL_LIBS})
  list(APPEND LDFLAGS -l${lib})
endforeach()
add_library(simd_ops STATIC simd_ops.cpp ${ARCH}_halide_runtime.bc)
target_link_libraries(simd_ops)
test_suite_add_build_dependencies(simd_ops)
set_target_properties(simd_ops PROPERTIES LINKER_LANGUAGE CXX)

foreach(sourcebc ${uosources})
  string(REGEX REPLACE ".[cp]+$" "" pathbc ${sourcebc})
  string(REGEX REPLACE ".*/" "" namebc ${pathbc})
  string(REPLACE "." "" namebc ${namebc})
  llvm_multisource(simd_ops_${namebc}
    ${CMAKE_CURRENT_SOURCE_DIR}/${ARCH}_halide_runtime.bc
    ${CMAKE_CURRENT_SOURCE_DIR}/${ARCH}_tests/${namebc}.bc
    ${CMAKE_CURRENT_SOURCE_DIR}/${ARCH}_scalar_tests/scalar_${namebc}.bc
  )
  target_link_libraries(simd_ops_${namebc} simd_ops)
endforeach()
