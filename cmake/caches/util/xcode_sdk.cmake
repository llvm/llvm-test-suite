macro(xcrun_find VARIABLE NAME)
  execute_process(COMMAND xcrun ${XCRUN_FLAGS} -f ${NAME}
                  OUTPUT_STRIP_TRAILING_WHITESPACE
                  OUTPUT_VARIABLE ${VARIABLE})
endmacro()
macro(xcrun_find_update_cache VARIABLE NAME)
  xcrun_find(${VARIABLE} ${NAME})
  set(${VARIABLE} "${${VARIABLE}}" CACHE STRING "")
endmacro()

execute_process(COMMAND xcrun ${XCRUN_FLAGS} --show-sdk-path
                OUTPUT_STRIP_TRAILING_WHITESPACE
                OUTPUT_VARIABLE SDK_PATH)
xcrun_find(LINKER_PATH ld)
get_filename_component(LINKER_DIR ${LINKER_PATH} DIRECTORY)
xcrun_find_update_cache(CMAKE_C_COMPILER clang)
xcrun_find_update_cache(CMAKE_CXX_COMPILER clang++)
xcrun_find_update_cache(CMAKE_RANLIB ranlib)
xcrun_find_update_cache(CMAKE_AR ar)
xcrun_find_update_cache(CMAKE_STRIP strip)
xcrun_find_update_cache(CMAKE_NM nm)

# I couldn't find a way to stop cmake from adding a -isysroot, at least make it
# add the correct path
set(CMAKE_OSX_SYSROOT "${SDK_PATH}" CACHE STRING "")

set(ARCH_FLAGS "${ARCH_FLAGS} --sysroot ${SDK_PATH}")
set(ARCH_FLAGS "${ARCH_FLAGS} -ccc-install-dir ${LINKER_DIR}")
include(${CMAKE_CURRENT_LIST_DIR}/arch_flags.cmake)
