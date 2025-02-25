# Copy these files to the build directory so that the tests can be run even
# without the source directory.
configure_file(test_not.py test_not.py
  COPYONLY)

llvm_test_executable_no_test(ret1 ret1.c)
add_dependencies(ret1 not)
llvm_test_run(EXECUTABLE "$<TARGET_FILE:not>" "$<TARGET_FILE:ret1>")
llvm_add_test_for_target(ret1)

llvm_test_executable_no_test(ret0 ret0.c)
add_dependencies(ret0 not)
llvm_test_run(EXECUTABLE "$<TARGET_FILE:not>" "$<TARGET_FILE:not>" "$<TARGET_FILE:ret0>")
llvm_add_test_for_target(ret0)

# These test will always fail under user-mode emulation because 'not'
# spawns a subprocess outside the emulator and the check_env test
# runs the host python interpreter under the emulator for the target.
if(NOT(TEST_SUITE_USER_MODE_EMULATION AND TEST_SUITE_RUN_UNDER))
  # Check that expected crashes are handled correctly.
  llvm_test_executable_no_test(abrt abort.c)
  add_dependencies(abrt not)
  llvm_test_run(EXECUTABLE "$<TARGET_FILE:not>" "--crash" "$<TARGET_FILE:abrt>")
  llvm_add_test_for_target(abrt)

  # Check that not passes environment variables to the called executable.
  find_package(Python COMPONENTS Interpreter)
  llvm_test_executable_no_test(check_env check_env.c)
  add_dependencies(check_env not)
  llvm_test_run(EXECUTABLE ${Python_EXECUTABLE} "%b/test/test_not.py" "$<TARGET_FILE:not>" "$<TARGET_FILE:check_env>")
  llvm_add_test_For_target(check_env)
endif()
