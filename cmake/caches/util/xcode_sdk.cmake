execute_process(COMMAND xcrun ${XCRUN_FLAGS} --show-sdk-path
                OUTPUT_STRIP_TRAILING_WHITESPACE
                OUTPUT_VARIABLE SDK_PATH)
execute_process(COMMAND xcrun ${XCRUN_FLAGS} -f ld
                OUTPUT_STRIP_TRAILING_WHITESPACE
                OUTPUT_VARIABLE LINKER_PATH)
get_filename_component(LINKER_DIR ${LINKER_PATH} DIRECTORY)
execute_process(COMMAND xcrun ${XCRUN_FLAGS} -f ranlib
                OUTPUT_STRIP_TRAILING_WHITESPACE
                OUTPUT_VARIABLE CMAKE_RANLIB)
set(CMAKE_RANLIB "${CMAKE_RANLIB}" CACHE STRING "")
execute_process(COMMAND xcrun ${XCRUN_FLAGS} -f ar
                OUTPUT_STRIP_TRAILING_WHITESPACE
                OUTPUT_VARIABLE CMAKE_AR)
set(CMAKE_AR "${CMAKE_AR}" CACHE STRING "")
execute_process(COMMAND xcrun ${XCRUN_FLAGS} -f strip
                OUTPUT_STRIP_TRAILING_WHITESPACE
                OUTPUT_VARIABLE CMAKE_STRIP)
set(CMAKE_STRIP "${CMAKE_STRIP}" CACHE STRING "")
execute_process(COMMAND xcrun ${XCRUN_FLAGS} -f nm
                OUTPUT_STRIP_TRAILING_WHITESPACE
                OUTPUT_VARIABLE CMAKE_NM)
set(CMAKE_NM "${CMAKE_NM}" CACHE STRING "")
# I couldn't find a way to stop cmake from adding a -isysroot, at least make it
# add the correct path
set(CMAKE_OSX_SYSROOT "${SDK_PATH}" CACHE STRING "")

set(ARCH_FLAGS "${ARCH_FLAGS} --sysroot ${SDK_PATH}")
set(ARCH_FLAGS "${ARCH_FLAGS} -ccc-install-dir ${LINKER_DIR}")
include(${CMAKE_CURRENT_LIST_DIR}/arch_flags.cmake)
