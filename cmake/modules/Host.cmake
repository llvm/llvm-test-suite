
if(CMAKE_HOST_SYSTEM_NAME STREQUAL "Windows" AND NOT TEST_SUITE_HOST_CC)
  set(TEST_SUITE_HOST_CC "clang" CACHE STRING "C compiler targetting the host")
else()
  set(TEST_SUITE_HOST_CC "cc" CACHE STRING "C compiler targetting the host")
endif()

mark_as_advanced(TEST_SUITE_HOST_CC)

function(llvm_add_host_executable targetname exename)
  cmake_parse_arguments(_arg "" "" "LDFLAGS;CPPFLAGS" ${ARGN})

  set(_objs)
  foreach (_srcfile IN LISTS _arg_UNPARSED_ARGUMENTS)
    get_filename_component(
	  _srcfile "${_srcfile}" ABSOLUTE BASE_DIR "${CMAKE_CURRENT_SOURCE_DIR}")
    get_filename_component(_filename "${_srcfile}" NAME)
    set(_objfile "${CMAKE_CURRENT_BINARY_DIR}/${_filename}.o")

    add_custom_command(OUTPUT "${_objfile}"
      COMMAND ${TEST_SUITE_HOST_CC} ${_arg_CPPFLAGS}
	    -c "${_srcfile}" -o "${_objfile}"
      COMMENT "[TEST_SUITE_HOST_CC] Compiling host source ${_filename}"
      DEPENDS "${_srcfile}"
      VERBATIM
    )

    list(APPEND _objs ${_objfile})
  endforeach ()

  # Append ".exe" to the executable name on Windows
  if(WIN32)
    set(exename "${exename}.exe")
  endif()

  add_custom_command(OUTPUT ${exename}
    COMMAND ${TEST_SUITE_HOST_CC} ${_objs}
	  -o "${CMAKE_CURRENT_BINARY_DIR}/${exename}" ${_arg_LDFLAGS}
    COMMENT "[TEST_SUITE_HOST_CC] Linking host executable ${exename}"
    DEPENDS ${_objs}
    VERBATIM
  )
  add_custom_target(${targetname}
    DEPENDS "${CMAKE_CURRENT_BINARY_DIR}/${exename}")
  llvm_codesign(${targetname}
          BUNDLE_PATH "${CMAKE_CURRENT_BINARY_DIR}/${exename}")
endfunction()
