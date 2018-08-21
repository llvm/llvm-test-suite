##===- DetectArchitecture.cmake -------------------------------------------===##
#
# Performs a try_compile to determine the architecture of the target.
#
##===----------------------------------------------------------------------===##

function(detect_architecture variable)
  try_compile(HAVE_${variable}
    ${CMAKE_BINARY_DIR}
    ${CMAKE_SOURCE_DIR}/cmake/modules/DetectArchitecture.c
    OUTPUT_VARIABLE OUTPUT
    COPY_FILE ${CMAKE_BINARY_DIR}${CMAKE_FILES_DIRECTORY}/DetectArchitecture.bin)

  if(HAVE_${variable})
    file(STRINGS ${CMAKE_BINARY_DIR}${CMAKE_FILES_DIRECTORY}/DetectArchitecture.bin
      DETECT_ARCH_STRING LIMIT_COUNT 1 REGEX "ARCHITECTURE IS")
    if(DETECT_ARCH_STRING)
      string(REGEX MATCH "[^ ]*$" DETECT_ARCH_MATCH ${DETECT_ARCH_STRING})
      if(DETECT_ARCH_MATCH)
        message(STATUS "Check target system architecture: ${DETECT_ARCH_MATCH}")
        set(${variable} ${DETECT_ARCH_MATCH} PARENT_SCOPE)
      else()
        message(SEND_ERROR "Could not detect target system architecture!")
      endif()
    else()
      message(SEND_ERROR "Could not detect target system architecture!")
    endif()
  else()
    message(STATUS "Determine the system architecture - failed")
    file(APPEND ${CMAKE_BINARY_DIR}${CMAKE_FILES_DIRECTORY}/CMakeError.log
      "Determining the system architecture failed with the following output:\n${OUTPUT}")
    set(${variable} PARENT_SCOPE)
  endif()
  
endfunction(detect_architecture)

#
# Performs a try_run to determine the cpu architecture of target
#

function(detect_x86_cpu_architecture variable)
  try_run(HAVE_RUN_${variable} HAVE_COMPILE_${variable}
    ${CMAKE_BINARY_DIR}
    ${CMAKE_SOURCE_DIR}/cmake/modules/DetectX86CPUArchitecture.c
    COMPILE_OUTPUT_VARIABLE COMP_OUTPUT
    RUN_OUTPUT_VARIABLE RUN_OUTPUT)

  if(HAVE_COMPILE_${variable} AND NOT (HAVE_RUN_${variable} STREQUAL  FAILED_TO_RUN))
    if(RUN_OUTPUT)
      message(STATUS "Check target system architecture: ${RUN_OUTPUT}")
      set(${variable} ${RUN_OUTPUT} PARENT_SCOPE)
    else()
      message(SEND_ERROR "Could not detect target system cpu architecture!")
    endif()
  else()
    message(STATUS "Determine the system cpu architecture - failed")
    file(APPEND ${CMAKE_BINARY_DIR}${CMAKE_FILES_DIRECTORY}/CMakeError.log
      "Determining the system cpu architecture failed with the following output:\n${COMP_OUTPUT}\n${RUN_OUTPUT}")
    set(${variable} PARENT_SCOPE)
  endif()

endfunction(detect_x86_cpu_architecture)
