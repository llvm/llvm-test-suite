add_executable(timeit-target ${CMAKE_CURRENT_SOURCE_DIR}/timeit.c)

# FIXME: Replicate Makefile.tools's logic for determining whether to use fpcmp/fpcmp.sh

# Note that we have to compile fpcmp and timeit for the host machine even when
# cross compiling to a different target. We use custom rules doing "cc file.c"
# as an ad-hoc solution for now. A proper solution would probably be based on
# ExternalProject_Add(); See also http://reviews.llvm.org/D15004

set(TEST_SUITE_HOST_CC "cc" CACHE STRING "C compiler targetting the host")
mark_as_advanced(TEST_SUITE_HOST_CC)
add_custom_target(fpcmp-host
    DEPENDS ${CMAKE_CURRENT_BINARY_DIR}/fpcmp)
add_custom_command(OUTPUT ${CMAKE_CURRENT_BINARY_DIR}/fpcmp
  COMMAND ${TEST_SUITE_HOST_CC} ${CMAKE_CURRENT_SOURCE_DIR}/fpcmp.c -o ${CMAKE_CURRENT_BINARY_DIR}/fpcmp
  DEPENDS ${CMAKE_CURRENT_SOURCE_DIR}/fpcmp.c
)
add_custom_target(timeit-host
    DEPENDS ${CMAKE_CURRENT_BINARY_DIR}/timeit)
add_custom_command(OUTPUT ${CMAKE_CURRENT_BINARY_DIR}/timeit
  COMMAND ${TEST_SUITE_HOST_CC} ${CMAKE_CURRENT_SOURCE_DIR}/timeit.c -o ${CMAKE_CURRENT_BINARY_DIR}/timeit
  DEPENDS ${CMAKE_CURRENT_SOURCE_DIR}/timeit.c
)
