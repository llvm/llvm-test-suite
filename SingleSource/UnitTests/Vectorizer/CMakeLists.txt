
# Enable matrix types extension tests for compilers supporting -fenable-matrix.
check_c_compiler_flag("-mllvm -enable-early-exit-vectorization" COMPILER_HAS_EE_VEC_FLAG)
if (COMPILER_HAS_EE_VEC_FLAG)
  set_property(SOURCE early-exit.cpp PROPERTY COMPILE_FLAGS "-mllvm -enable-early-exit-vectorization")
else()
  list(REMOVE_ITEM Source early-exit.cpp)
endif()

llvm_singlesource()
set_property(TARGET runtime-checks PROPERTY CXX_STANDARD 17)

# The VPlan-native path is specific to llvm.
if ("${CMAKE_C_COMPILER_ID}" MATCHES "Clang")
  add_subdirectory(VPlanNativePath)
endif()
