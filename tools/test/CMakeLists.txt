llvm_test_executable_no_test(ret1 ret1.c)
add_dependencies(ret1 not)
llvm_test_run(EXECUTABLE "$<TARGET_FILE:not>" "$<TARGET_FILE:ret1>")
llvm_add_test_for_target(ret1)

llvm_test_executable_no_test(ret0 ret0.c)
add_dependencies(ret0 not)
llvm_test_run(EXECUTABLE "$<TARGET_FILE:not>" "$<TARGET_FILE:not>" "$<TARGET_FILE:ret0>")
llvm_add_test_for_target(ret0)

# Check that expected crashes are handled correctly under user-mode emulation.
llvm_test_executable_no_test(abrt abort.c)
add_dependencies(abrt not)
llvm_test_run(EXECUTABLE ${NOT_TOOL} "--crash" "$<TARGET_FILE:abrt>")
llvm_add_test_for_target(abrt)

# Check that not passes environment variables to the called executable.
llvm_test_executable_no_test(test_not test_not.cpp)
llvm_test_executable_no_test(check_env check_env.c)
add_dependencies(check_env not test_not)
if(TEST_SUITE_USER_MODE_EMULATION AND TEST_SUITE_RUN_UNDER)
  # ${TEST_SUITE_RUN_UNDER} is needed here because test_not is not itself
  # user-mode emulation aware, unlike the not tool.
  llvm_test_run(EXECUTABLE "$<TARGET_FILE:test_not>" ${TEST_SUITE_RUN_UNDER}
                           ${NOT_TOOL} "$<TARGET_FILE:check_env>")
else()
  llvm_test_run(EXECUTABLE "$<TARGET_FILE:test_not>" ${NOT_TOOL}
                           "$<TARGET_FILE:check_env>")
endif()
llvm_add_test_For_target(check_env)
