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
xcrun_find_update_cache(CMAKE_LINKER ld)

if (CMAKE_C_COMPILER)
  # The user manually specified a compiler which is usually different than
  # the one coming with the SDK.

  # Construct shim for ranlib, ar, etc.
  # This is necessary because the ranlib coming with the xcode sdk looks for
  # ../lib/libLTO.dylib and will therefor pick up libLTO.dylib coming with the
  # SDK. However for correct behavior it has to pick up libLTO.dylib coming
  # the clang compiler used.
  xcrun_find_update_cache(SDK_RANLIB ranlib)
  get_filename_component(COMPILER_DIR ${CMAKE_C_COMPILER} DIRECTORY)

  macro(create_shim VARIABLE TOOLNAME)
    xcrun_find(SDK_TOOL_BIN ${TOOLNAME})
    file(WRITE ${CMAKE_BINARY_DIR}/${TOOLNAME} "
# Shim to have the tool use the correct libLTO.dylib
DYLD_LIBRARY_PATH=\"${COMPILER_DIR}/../lib:$DYLD_LIBRARY_PATH\" ${SDK_TOOL_BIN} \"$@\"
    ")
    execute_process(COMMAND chmod +x ${CMAKE_BINARY_DIR}/${TOOLNAME})
    set(${VARIABLE} ${CMAKE_BINARY_DIR}/${TOOLNAME} CACHE STRING "")
  endmacro()

  create_shim(CMAKE_AR ar)
  create_shim(CMAKE_NM nm)
  create_shim(CMAKE_RANLIB ranlib)
  create_shim(CMAKE_STRIP strip)

  # Skip linking in cmake compiler tests, as the cmake won't pass the -B flags
  # required to pick up the correct linker to the early compiler tests. However
  # it does have an option to not link in the early tests.
  set(CMAKE_TRY_COMPILE_TARGET_TYPE STATIC_LIBRARY CACHE STRING "")

  # Some benchmarks check for the function re_comp by using
  # check_function_exists. This function is not available in any Xcode SDK, and
  # the check returns YES with custom built compilers when we cross-compile,
  # because of "CMAKE_TRY_COMPILE_TARGET_TYPE STATIC_LIBRARY" explained just
  # above. We work around that by forcing it to NO.
  set(HAVE_RE_COMP CACHE BOOL NO)

  # Likewise, some benchmarks look for librt, which does not exist on darwin
  # systems, but the check returns YES because we don't actually link, given
  # the CMAKE_TRY_COMPILE_TARGET_TYPE setting above.  We work around that by
  # forcing it to NO.
  set(HAVE_LIB_RT CACHE BOOL NO)
else()
  # Search and use compiler coming with the SDK.
  # Note that we do not search CMAKE_CXX_COMPILER here. cmake will try
  # `${CMAKE_C_COMPILER}++` and use that if available.
  xcrun_find_update_cache(CMAKE_AR ar)
  xcrun_find_update_cache(CMAKE_NM nm)
  xcrun_find_update_cache(CMAKE_C_COMPILER clang)
  xcrun_find_update_cache(CMAKE_RANLIB ranlib)
  xcrun_find_update_cache(CMAKE_STRIP strip)
endif()

set(CMAKE_OSX_SYSROOT "${SDK_PATH}" CACHE STRING "")

# Append -B so clang picks up the linker coming with the SDK instead of the
# one in $PATH.
xcrun_find(LINKER_PATH ld)
get_filename_component(LINKER_DIR ${LINKER_PATH} DIRECTORY)
set(TEST_SUITE_ARCH_FLAGS "${TEST_SUITE_ARCH_FLAGS} -B ${LINKER_DIR}" CACHE STRING "")

# The problem with TEST_SUITE_ARCH_FLAGS is that they will not be used when
# cmake is testing for features with try_compile().
#
# This is a work around for this: try_compile() does honor toolchain files which
# can chane CMAKE_C_FLAGS.
#
# Note that CMAKE_TRY_COMPILE_PLATFORM_VARIABLES used by this is only available
# in cmake >=3.6
set(CMAKE_TOOLCHAIN_FILE ${CMAKE_CURRENT_LIST_DIR}/arch_flags_toolchain.cmake CACHE STRING "")
set(CMAKE_TRY_COMPILE_PLATFORM_VARIABLES "TEST_SUITE_ARCH_FLAGS_FORWARD" CACHE STRING "")
set(TEST_SUITE_ARCH_FLAGS_FORWARD "${TEST_SUITE_ARCH_FLAGS}" CACHE STRING "")
