macro(llvm_copy_dir target to) # args: dir0 dir1 ...
  set(COPY_COMMAND "")
  foreach(dir ${ARGN})
    set(COPY_COMMAND ${COPY_COMMAND} COMMAND ${CMAKE_COMMAND} -E copy_directory "${dir}" "${to}")
  endforeach()
  add_custom_command(
    TARGET ${target} POST_BUILD
    ${COPY_COMMAND}
  )
endmacro()

macro(llvm_copy target to from)
  add_custom_command(
    TARGET ${target} POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy ${from} ${to}
  )
endmacro()
