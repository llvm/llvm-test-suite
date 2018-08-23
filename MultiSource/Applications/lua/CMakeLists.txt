list(APPEND LDFLAGS -lm)
if(NOT ARCH STREQUAL "XCore")
  list(APPEND CPPFLAGS -DLUA_USE_POSIX)
endif()
set(RUN_OPTIONS alltests.lua "")
set(HASH_PROGRAM_OUTPUT 1)

add_custom_command(OUTPUT ${CMAKE_CURRENT_BINARY_DIR}/generate_inputs.sh
    COMMAND cp ${CMAKE_CURRENT_SOURCE_DIR}/generate_inputs.sh ${CMAKE_CURRENT_BINARY_DIR}
    COMMAND cp -r ${CMAKE_CURRENT_SOURCE_DIR}/test ${CMAKE_CURRENT_BINARY_DIR}
    COMMAND cp -r ${CMAKE_CURRENT_SOURCE_DIR}/bench ${CMAKE_CURRENT_BINARY_DIR}
    COMMAND cp -r ${CMAKE_CURRENT_SOURCE_DIR}/input ${CMAKE_CURRENT_BINARY_DIR}
    COMMAND cp -r ${CMAKE_CURRENT_SOURCE_DIR}/*.lua ${CMAKE_CURRENT_BINARY_DIR}
    COMMAND ${CMAKE_CURRENT_BINARY_DIR}/generate_inputs.sh
    WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}
    COMMENT "Generating lua test inputs")
add_custom_target(lua_input SOURCES ${CMAKE_CURRENT_BINARY_DIR}/generate_inputs.sh)
llvm_multisource(lua
  lapi.c
  lcode.c
  ldebug.c
  ldo.c
  ldump.c
  lfunc.c
  lgc.c
  llex.c
  lmem.c
  lobject.c
  lopcodes.c
  lparser.c
  lstate.c
  lstring.c
  ltable.c
  ltm.c
  lundump.c
  lvm.c
  lzio.c
  lauxlib.c
  lbaselib.c
  ldblib.c
  liolib.c
  lmathlib.c
  loslib.c
  ltablib.c
  lstrlib.c
  loadlib.c
  linit.c
  lua.c
)
add_dependencies(lua lua_input)
