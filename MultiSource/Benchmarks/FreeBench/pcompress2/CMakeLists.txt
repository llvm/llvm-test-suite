set(PROG pcompress2)
list(APPEND CPPFLAGS -DVERSION="1.00" -DCOMPDATE="today" -DCFLAGS="" -DHOSTNAME="thishost")
if(LARGE_PROBLEM_SIZE)
  set(INPUT_FILE ref.in)
else()
  set(INPUT_FILE test.in)
endif()
set(RUN_OPTIONS ${CMAKE_CURRENT_BINARY_DIR}/${INPUT_FILE})
set(GeneratedTestInputs copy-input-file)

add_custom_command(OUTPUT ${CMAKE_CURRENT_BINARY_DIR}/${INPUT_FILE}
    COMMAND cp ${CMAKE_CURRENT_SOURCE_DIR}/${INPUT_FILE} ${CMAKE_CURRENT_BINARY_DIR}/${INPUT_FILE}
    WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}
    COMMENT "Copying pcompress2 test input")
add_custom_target(pcompress2_input SOURCES ${CMAKE_CURRENT_BINARY_DIR}/${INPUT_FILE})
    llvm_multisource()
add_dependencies(pcompress2 pcompress2_input)
