##===- DetectLoongArchSupportVector.cmake ---------------------------------===##
#
# Performs a try_run with a simple program calling LSX/LASX builtin
# to determine if the LoongArch CPU supports vector instructions.
# This is not used for cross compile.
#
##===----------------------------------------------------------------------===##
function(detect_loongarch_cpu_supports_sx variable)
  file(WRITE ${CMAKE_BINARY_DIR}${CMAKE_FILES_DIRECTORY}/CMakeTmp/SimpleProgramCallLSXBuiltin.c
       "#include <lsxintrin.h>
        int main(void) {
          __m128i a, b, c;
          c = __lsx_vand_v(a, b);
          return 0;
        }")
  set(SX_FLAG "-mlsx")
  try_run(HAVE_RUN_${variable} HAVE_COMPILE_${variable}
    ${CMAKE_BINARY_DIR}
    ${CMAKE_BINARY_DIR}${CMAKE_FILES_DIRECTORY}/CMakeTmp/SimpleProgramCallLSXBuiltin.c
    CMAKE_FLAGS "-DCOMPILE_DEFINITIONS=${SX_FLAG}"
    COMPILE_OUTPUT_VARIABLE COMP_OUTPUT
    RUN_OUTPUT_VARIABLE RUN_OUTPUT)

  set(${variable} false PARENT_SCOPE)
  if(HAVE_COMPILE_${variable} AND (HAVE_RUN_${variable} EQUAL 0))
    message(STATUS "Check if LoongArch cpu supports SX - Success")
    set(${variable} true PARENT_SCOPE)
  else()
    message(STATUS "Check if LoongArch cpu supports SX - Failed")
    file(APPEND ${CMAKE_BINARY_DIR}${CMAKE_FILES_DIRECTORY}/CMakeError.log
        "LoongArch cpu does not support SX with the following output:\n${COMP_OUTPUT}\n${RUN_OUTPUT}")
  endif()

endfunction(detect_loongarch_cpu_supports_sx)

function(detect_loongarch_cpu_supports_asx variable)
  file(WRITE ${CMAKE_BINARY_DIR}${CMAKE_FILES_DIRECTORY}/CMakeTmp/SimpleProgramCallLASXBuiltin.c
       "#include <lasxintrin.h>
        int main(void) {
          __m256i a, b, c;
          c = __lasx_xvand_v(a, b);
          return 0;
        }")
  set(ASX_FLAG "-mlasx")
  try_run(HAVE_RUN_${variable} HAVE_COMPILE_${variable}
    ${CMAKE_BINARY_DIR}
    ${CMAKE_BINARY_DIR}${CMAKE_FILES_DIRECTORY}/CMakeTmp/SimpleProgramCallLASXBuiltin.c
    CMAKE_FLAGS "-DCOMPILE_DEFINITIONS=${ASX_FLAG}"
    COMPILE_OUTPUT_VARIABLE COMP_OUTPUT
    RUN_OUTPUT_VARIABLE RUN_OUTPUT)

  set(${variable} false PARENT_SCOPE)
  if(HAVE_COMPILE_${variable} AND (HAVE_RUN_${variable} EQUAL 0))
    message(STATUS "Check if LoongArch cpu supports ASX - Success")
    set(${variable} true PARENT_SCOPE)
  else()
    message(STATUS "Check if LoongArch cpu supports ASX - Failed")
    file(APPEND ${CMAKE_BINARY_DIR}${CMAKE_FILES_DIRECTORY}/CMakeError.log
        "LoongArch cpu does not support ASX with the following output:\n${COMP_OUTPUT}\n${RUN_OUTPUT}")
  endif()

endfunction(detect_loongarch_cpu_supports_asx)
