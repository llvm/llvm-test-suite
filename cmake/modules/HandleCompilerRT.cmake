# Find the path to compiler-rt builtins library for the current target and
# and return it in `variable`.
function(find_compiler_rt_library variable)
  set(target "${CMAKE_CXX_COMPILER_TARGET}")
  if(NOT CMAKE_CXX_COMPILER_TARGET AND LLVM_DEFAULT_TARGET_TRIPLE)
    set(target "${LLVM_DEFAULT_TARGET_TRIPLE}")

  if(NOT DEFINED COMPILER_RT_LIBRARY_builtins_${target} OR NOT ${CMAKE_CXX_COMPILER_ID} MATCHES "Clang")
    # If the cache variable is not defined, invoke Clang and then
    # set it with cache_compiler_rt_library.
    set(clang_command ${CMAKE_CXX_COMPILER} "${ARG_FLAGS}")
    if(target)
      list(APPEND clang_command "--target=${target}")
    endif()
    get_property(cxx_flags CACHE CMAKE_CXX_FLAGS PROPERTY VALUE)
    string(REPLACE " " ";" cxx_flags "${cxx_flags}")
    list(APPEND clang_command ${cxx_flags})
    set(cmd_prefix "")
    if(MSVC)
      set(cmd_prefix "/clang:")
    endif()
    execute_process(
      COMMAND ${clang_command} "${cmd_prefix}--rtlib=compiler-rt" "${cmd_prefix}-print-libgcc-file-name"
      RESULT_VARIABLE had_error
      OUTPUT_VARIABLE library_file
    )
    string(STRIP "${library_file}" library_file)
    file(TO_CMAKE_PATH "${library_file}" library_file)
    get_filename_component(basename ${library_file} NAME)
    if(EXISTS "${library_file}" AND (basename MATCHES ".*clang_rt\.([a-z0-9_\-]+)\.(a|lib)"))
      message(STATUS "Found compiler-rt library: ${basename}")
      set(COMPILER_RT_LIBRARY_builtins_${target} "${basename}" CACHE INTERNAL
        "compiler-rt library for ${target}")
    else()
      message(STATUS "Failed to find compiler-rt library for ${target}")
      set(COMPILER_RT_LIBRARY_builtins_${target} "NOTFOUND" CACHE INTERNAL
          "compiler-rt library for ${target}")
    endif()
  endif()

  if(NOT COMPILER_RT_LIBRARY_builtins_${target})
    set(${variable} "NOTFOUND" PARENT_SCOPE)
  else()
    set(${variable} "${COMPILER_RT_LIBRARY_builtins_${target}}" PARENT_SCOPE)
  endif()
endfunction()
