# Note that we have to compile fpcmp and timeit for the host machine even when
# cross compiling to a different target. We use custom rules doing "cc file.c"
# as an ad-hoc solution for now. A proper solution would probably be based on
# ExternalProject_Add(); See also http://reviews.llvm.org/D15004

set(TEST_SUITE_HOST_CC "cc" CACHE STRING "C compiler targetting the host")
mark_as_advanced(TEST_SUITE_HOST_CC)
macro(llvm_add_host_executable targetname exename sourcefile)
  add_custom_command(OUTPUT ${exename}
    COMMAND ${TEST_SUITE_HOST_CC} ${CMAKE_CURRENT_SOURCE_DIR}/${sourcefile} -o ${CMAKE_CURRENT_BINARY_DIR}/${exename}
    COMMENT "[TEST_SUITE_HOST_CC] Building host executable ${exename}"
    DEPENDS ${CMAKE_CURRENT_SOURCE_DIR}/${sourcefile}
  )
  add_custom_target(${targetname} DEPENDS ${CMAKE_CURRENT_BINARY_DIR}/${exename})
endmacro()

llvm_add_host_executable(fpcmp-host fpcmp fpcmp.c)

option(TEST_SUITE_USE_PERF "Use perf (timeit.sh) instead of timeit.c" Off)
if(TEST_SUITE_USE_PERF)
  add_custom_command(OUTPUT ${CMAKE_CURRENT_BINARY_DIR}/timeit
    COMMAND cp ${CMAKE_CURRENT_SOURCE_DIR}/timeit.sh ${CMAKE_CURRENT_BINARY_DIR}/timeit
    COMMAND chmod +x ${CMAKE_CURRENT_BINARY_DIR}/timeit
    DEPENDS ${CMAKE_CURRENT_SOURCE_DIR}/timeit.sh)
  add_custom_target(timeit-host DEPENDS ${CMAKE_CURRENT_BINARY_DIR}/timeit)
else()
  add_executable(timeit-target ${CMAKE_CURRENT_SOURCE_DIR}/timeit.c)
  llvm_add_host_executable(timeit-host timeit timeit.c)
endif()
