function(llvm_copy_dir target to) # args: dir0 dir1 ...
  set(COPY_COMMAND "")
  foreach(dir ${ARGN})
    set(COPY_COMMAND ${COPY_COMMAND} COMMAND ${CMAKE_COMMAND} -E copy_directory "${dir}" "${to}")
  endforeach()
  add_custom_command(
    TARGET ${target} POST_BUILD
    ${COPY_COMMAND}
  )
endfunction()

function(llvm_copy target to from)
  add_custom_command(
    TARGET ${target} POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy ${from} ${to}
  )
endfunction()

# On Windows create_symlink requires special permissions. Use copy_if_different instead.
if(CMAKE_HOST_WIN32)
  set(_link_or_copy copy_if_different)
else()
  set(_link_or_copy create_symlink)
endif()

function(llvm_create_symlink target to from)
  add_custom_command(
    TARGET ${target} POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E ${_link_or_copy} ${from} ${to}
  )
endfunction()

function(llvm_make_directory target)
  add_custom_command(
    TARGET ${target} POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E make_directory ${ARGN}
  )
endfunction()
