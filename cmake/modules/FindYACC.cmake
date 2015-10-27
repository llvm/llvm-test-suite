##===- FindYACC.cmake -----------------------------------------------------===##
#
# Defines custom rules for building a YACC parser. Based on FindBISON.cmake.
#
##===----------------------------------------------------------------------===##

find_program(YACC_EXECUTABLE yacc DOC "Path to the YACC executable")
mark_as_advanced(YACC_EXECUTABLE)

if(YACC_EXECUTABLE)

  macro(add_yacc_parser target_name input_grammar output_c output_h)
    add_custom_command(OUTPUT ${output_c} ${output_h}
      COMMAND ${YACC_EXECUTABLE}
      ARGS -d -o ${output_c} ${input_grammar}
      DEPENDS ${input_grammar}
      COMMENT "Building YACC parser ${output_c}"
      WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR})
  endmacro(add_yacc_parser)

endif(YACC_EXECUTABLE)

include(FindPackageHandleStandardArgs)
find_package_handle_standard_args(YACC DEFAULT_MSG YACC_EXECUTABLE)
