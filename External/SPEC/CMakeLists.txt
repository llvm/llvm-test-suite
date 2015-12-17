if(TARGET_OS STREQUAL "Darwin")
  # Work around built in -Werror=implicit-function-declaration default on iOS
  list(APPEND CPPFLAGS -Wno-implicit-function-declaration)
endif()

llvm_externals_find(TEST_SUITE_SPEC2000_ROOT "speccpu2000" "SPEC CPU2000")

if(TEST_SUITE_SPEC2000_ROOT)
  llvm_add_subdirectories(CFP2000 CINT2000)
endif()

file(COPY lit.local.cfg DESTINATION "${CMAKE_CURRENT_BINARY_DIR}")
