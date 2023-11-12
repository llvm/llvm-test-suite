include(CheckFortranCompilerFlag)

# LLVMFlang prefixes error stop output to stdout/stderr with "Fortran"
# and other compilers don't.
# The `specification_expression_finalization.f90` test requires
# examining the output of an `error_stop` statement.
# Configure the expected results based on the Fortran compiler in use.

set(MAYBE_LLVM_ERROR_STOP_PREFIX "")
set(MAYBE_LLVM_ERROR_STOP_COLON "")
if(CMAKE_Fortran_COMPILER_ID MATCHES "LLVMFlang")
  set(MAYBE_LLVM_ERROR_STOP_PREFIX "Fortran ")
  set(MAYBE_LLVM_ERROR_STOP_COLON ":")
endif()

configure_file(
  specification_expression_finalization.reference_output.in
  ${CMAKE_CURRENT_SOURCE_DIR}/specification_expression_finalization.reference_output
  @ONLY)

set(Source)
list(APPEND Source
  allocatable_component.f90
  allocated_allocatable_lhs.f90
  block_end.f90
  finalize_on_deallocate.f90
  finalize_on_end.f90
  intent_out.f90
  lhs_object.f90
  rhs_function_reference.f90
  specification_expression_finalization.f90
  target_deallocation.f90)

# set(FP_IGNOREWHITESPACE OFF)

llvm_singlesource()

file(COPY lit.local.cfg DESTINATION "${CMAKE_CURRENT_BINARY_DIR}")
