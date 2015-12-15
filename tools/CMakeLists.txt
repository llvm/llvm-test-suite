add_executable(timeit-target timeit.c)

# FIXME: Replicate Makefile.tools's logic for determining whether to use fpcmp/fpcmp.sh
set(TEST_SUITE_HOST_CC "cc" CACHE STRING "C compiler targetting the host")
mark_as_advanced(TEST_SUITE_HOST_CC)
add_custom_target(fpcmp
  COMMAND ${TEST_SUITE_HOST_CC} ${CMAKE_CURRENT_SOURCE_DIR}/fpcmp.c -o ${CMAKE_CURRENT_BINARY_DIR}/fpcmp
  DEPENDS ${CMAKE_CURRENT_SOURCE_DIR}/fpcmp.c
)
add_custom_target(timeit
  COMMAND ${TEST_SUITE_HOST_CC} ${CMAKE_CURRENT_SOURCE_DIR}/timeit.c -o ${CMAKE_CURRENT_BINARY_DIR}/timeit
  DEPENDS ${CMAKE_CURRENT_SOURCE_DIR}/timeit.c
)
