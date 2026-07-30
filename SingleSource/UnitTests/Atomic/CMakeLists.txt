# Link the Clang built libatomic.
execute_process(COMMAND ${CMAKE_C_COMPILER} --print-file-name=libclang_rt.atomic.so
                OUTPUT_VARIABLE _path_to_libatomic
                OUTPUT_STRIP_TRAILING_WHITESPACE)
if(NOT _path_to_libatomic STREQUAL "libclang_rt.atomic.so")
  get_directory_property(CURRENT_LINK_OPTIONS LINK_OPTIONS)
  get_filename_component(_libatomic_dir ${_path_to_libatomic} DIRECTORY)
  add_link_options("LINKER:${_path_to_libatomic},-rpath=${_libatomic_dir}")

  llvm_singlesource(PREFIX "libclang_rt-atomic-")
  set_directory_properties(LINK_OPTIONS ${CURRENT_LINK_OPTIONS})
endif()

add_link_options("LINKER:-latomic")
llvm_singlesource(PREFIX "latomic-")

