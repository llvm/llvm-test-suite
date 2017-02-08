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
# Note that we do not search CMAKE_CXX_COMPILER to not disturb cmakes
# convenient way to defaulting to xxx/clang++ if the c compiler is xxx/clang.
xcrun_find_update_cache(CMAKE_RANLIB ranlib)
xcrun_find_update_cache(CMAKE_AR ar)
xcrun_find_update_cache(CMAKE_STRIP strip)
xcrun_find_update_cache(CMAKE_NM nm)
xcrun_find_update_cache(CMAKE_LINKER ld)

set(CMAKE_OSX_SYSROOT "${SDK_PATH}" CACHE STRING "")

# Append -B so clang picks up the linker coming with the SDK instead of the
# one in $PATH.
set(TEST_SUITE_ARCH_FLAGS "${TEST_SUITE_ARCH_FLAGS} -B ${LINKER_DIR}" CACHE STRING "")
