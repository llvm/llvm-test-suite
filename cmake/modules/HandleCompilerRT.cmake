# Find the path to compiler-rt builtins library for the target compiler
# and return it in `output_variable`.
function(find_compiler_rt_library variable)
  set(clang_command ${CMAKE_CXX_COMPILER})

  set(cmd_prefix "")
  if(MSVC)
    set(cmd_prefix "/clang:")
  endif()

  # If the C++ compiler is Clang, run it with -dumpmachine to find
  # the target triple
  set(target "")  
  if(${CMAKE_CXX_COMPILER_ID} MATCHES "Clang")
    execute_process(
      COMMAND "${clang_command}" ${cmd_prefix}-dumpmachine
      OUTPUT_VARIABLE target
      OUTPUT_STRIP_TRAILING_WHITESPACE
      ERROR_QUIET
    )
  endif()

  # If target is set and COMPILER_RT_LIBRARY_builtins_${target} 
  # cache variable is not defined, then set it by invoking Clang for the target triple.
  if(NOT ${target} STREQUAL "" AND NOT DEFINED COMPILER_RT_LIBRARY_builtins_${target})
    list(APPEND clang_command "${cmd_prefix}--target=${target}")
    execute_process(
      COMMAND ${clang_command} "${cmd_prefix}--rtlib=compiler-rt" "${cmd_prefix}-print-libgcc-file-name"
      RESULT_VARIABLE had_error
      OUTPUT_VARIABLE library_file
    )
    string(STRIP "${library_file}" library_file)
    file(TO_CMAKE_PATH "${library_file}" library_file)
    get_filename_component(basename ${library_file} NAME)
    if(basename MATCHES ".*clang_rt\.([a-z0-9_\-]+)\.(a|lib)" AND EXISTS ${library_file})
      message(STATUS "Found compiler-rt builtin library: ${basename}")
      set(COMPILER_RT_LIBRARY_builtins_${target} "${basename}" CACHE INTERNAL
        "compiler-rt library for ${target}")
    else()
      message(STATUS "Failed to find compiler-rt library for ${target}")
      set(COMPILER_RT_LIBRARY_builtins_${target} "" CACHE INTERNAL
          "compiler-rt library for ${target}")
    endif()
  endif()
  if(DEFINED COMPILER_RT_LIBRARY_builtins_${target})
    set(${variable} "${COMPILER_RT_LIBRARY_builtins_${target}}" PARENT_SCOPE)
  else()
    set(${variable} "" PARENT_SCOPE)
  endif()
endfunction()

