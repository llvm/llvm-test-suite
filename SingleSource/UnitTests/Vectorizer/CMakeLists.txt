llvm_singlesource()
set_property(TARGET runtime-checks PROPERTY CXX_STANDARD 17)

# The VPlan-native path is specific to llvm.
if ("${CMAKE_C_COMPILER_ID}" MATCHES "Clang")
  add_subdirectory(VPlanNativePath)
endif()
