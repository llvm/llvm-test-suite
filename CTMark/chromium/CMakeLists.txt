# 60 translation units of Chromium's Linux `chrome` build, compiled (not linked) with
# Chromium's own command lines. See README.md.

if(NOT CMAKE_C_COMPILER_ID MATCHES "Clang" OR NOT CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  message(STATUS "Skipping CTMark/chromium: it needs clang")
  return()
endif()

# lit reports the compile time of all *.o.time files in a test's directory, so a trivial
# program carries the test, and the translation units below are compiled next to it.
llvm_multisource(chromium main.c)

set(CHROMIUM_OUT_DIR ${CMAKE_CURRENT_SOURCE_DIR}/src/out/gnlinux)
set(CHROMIUM_TIMEIT)
set(CHROMIUM_TIMEIT_DEPENDS)
if(TEST_SUITE_COLLECT_COMPILE_TIME)
  separate_arguments(CHROMIUM_TIMEIT UNIX_COMMAND "${TIMEIT_CMD_PREFIX}")
  set(CHROMIUM_TIMEIT_DEPENDS build-timeit)
endif()

set(CHROMIUM_OBJECTS)
function(chromium_tu name lang src)
  set(obj ${CMAKE_CURRENT_BINARY_DIR}/tu/${name}.o)
  set(timeit)
  if(CHROMIUM_TIMEIT)
    set(timeit ${CHROMIUM_TIMEIT} --summary ${obj}.time)
  endif()
  # The flags (relative include paths, --sysroot, the target) are Chromium's, so the
  # compiler runs in Chromium's build directory, and CMAKE_<LANG>_FLAGS don't apply.
  add_custom_command(OUTPUT ${obj}
    COMMAND ${timeit} ${CMAKE_${lang}_COMPILER} ${ARGN} -c ${src} -o ${obj}
    WORKING_DIRECTORY ${CHROMIUM_OUT_DIR}
    DEPENDS ${CHROMIUM_OUT_DIR}/${src} ${CHROMIUM_TIMEIT_DEPENDS}
    COMMENT "Compiling Chromium translation unit ${src}"
    VERBATIM)
  set(CHROMIUM_OBJECTS ${CHROMIUM_OBJECTS} ${obj} PARENT_SCOPE)
endfunction()

include(tus.cmake)

add_custom_target(chromium-tus DEPENDS ${CHROMIUM_OBJECTS})
add_dependencies(chromium chromium-tus)
