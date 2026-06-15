# Exclude tests that require unimplemented feature (conditional expression as
# actual argument)
file(GLOB _sources *.f90)
list(REMOVE_ITEM _sources
  ${CMAKE_CURRENT_SOURCE_DIR}/condexpr_array_lval_01.f90
  ${CMAKE_CURRENT_SOURCE_DIR}/condexpr_array_lval_02.f90
  ${CMAKE_CURRENT_SOURCE_DIR}/condexpr_nil_01.f90
  ${CMAKE_CURRENT_SOURCE_DIR}/condexpr_nil_02.f90
  ${CMAKE_CURRENT_SOURCE_DIR}/condexpr_nil_03.f90
  ${CMAKE_CURRENT_SOURCE_DIR}/condexpr_nil_04.f90
  ${CMAKE_CURRENT_SOURCE_DIR}/condexpr_nil_05.f90
  ${CMAKE_CURRENT_SOURCE_DIR}/condexpr_scalar_lval_01.f90
)
set(Source ${_sources})

llvm_singlesource()

file(COPY lit.local.cfg DESTINATION "${CMAKE_CURRENT_BINARY_DIR}")
