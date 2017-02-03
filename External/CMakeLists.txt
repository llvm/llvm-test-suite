set(TEST_SUITE_EXTERNALS_DIR "" CACHE PATH
    "Directory containing test-suite external benchmark sources")

# Find path containing an external benchmark and set PATHVAR to it.
# Specifically this:
# - Adds a CACHE variable for PATHVAR
# - If PATHVAR is unset set it to the first existing directory in this list:
#   - ${TEST_SUITE_EXTERNALS_DIR}/${NAME}
#   - ${CMAKE_SOURCE_DIR}/test-suite-externals/${NAME}
macro(llvm_externals_find PATHVAR NAME DESCRIPTION)
  set(${PATHVAR} "" CACHE PATH "Directory containing ${DESCRIPTION} sourcecode")
  if(TEST_SUITE_EXTERNALS_DIR)
    if (NOT ${PATHVAR} AND IS_DIRECTORY "${TEST_SUITE_EXTERNALS_DIR}/${NAME}")
      set(${PATHVAR} "${TEST_SUITE_EXTERNALS_DIR}/${NAME}")
    endif()
  else()
    if(NOT ${PATHVAR} AND
       IS_DIRECTORY "${CMAKE_SOURCE_DIR}/test-suite-externals/${NAME}")
      set(${PATHVAR} "${CMAKE_SOURCE_DIR}/test-suite-externals/${NAME}")
    endif()
  endif()
  if(${PATHVAR})
    message(STATUS "Found ${DESCRIPTION}: ${${PATHVAR}}")
  endif()
endmacro()

add_subdirectory(CUDA)
add_subdirectory(HMMER)
add_subdirectory(Nurbs)
add_subdirectory(Povray)
add_subdirectory(SPEC)
add_subdirectory(skidmarks10)
