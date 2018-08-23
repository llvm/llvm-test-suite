list(APPEND CPPFLAGS -DSTDC_HEADERS=1 -DHAVE_SYS_TYPES_H=1 -DHAVE_SYS_STAT_H=1 -DHAVE_STDLIB_H=1 -DHAVE_STRING_H=1 -DHAVE_MEMORY_H=1 -DHAVE_STRINGS_H=1 -DHAVE_INTTYPES_H=1 -DHAVE_STDINT_H=1 -DHAVE_UNISTD_H=1 -DSQLITE_OMIT_LOAD_EXTENSION=1 -DSQLITE_THREADSAFE=0 -I.)
set(RUN_OPTIONS -init sqlite3rc :memory: < commands)
set(FP_TOLERANCE 1.0e-9)
set(GeneratedTestInputs ${CMAKE_CURRENT_BINARY_DIR}/test15.sql)

if(SMALL_PROBLEM_SIZE)
  set(SQLITE_INPUTNAME smalltest)
else()
  set(SQLITE_INPUTNAME speedtest)
endif()
add_custom_command(OUTPUT ${CMAKE_CURRENT_BINARY_DIR}/test15.sql
    COMMAND ${TCL_TCLSH} ${CMAKE_CURRENT_SOURCE_DIR}/${SQLITE_INPUTNAME}.tcl
    WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}
    COMMENT "Generating sqlite test inputs")
add_custom_target(sqlite_input SOURCES ${CMAKE_CURRENT_BINARY_DIR}/test15.sql)
llvm_multisource(sqlite3
  sqlite3.c
  shell.c
)
add_dependencies(sqlite3 sqlite_input)
llvm_test_data(sqlite3 sqlite3rc commands)
