set(PARALLEL_DIRS)

set(PARALLEL_DIRS 2mm 3mm atax bicg cholesky doitgen gemm gemver gesummv mvt symm syr2k syrk trisolv trmm)
if(DEFINED BENCHMARKING_ONLY)
  llvm_filter_out(TMP1 2mm  ${PARALLEL_DIRS})
  set(PARALLEL_DIRS ${TMP1})
  llvm_filter_out(TMP2 3mm  ${PARALLEL_DIRS})
  set(PARALLEL_DIRS ${TMP2})
  llvm_filter_out(TMP3 gemm  ${PARALLEL_DIRS})
  set(PARALLEL_DIRS ${TMP3})
endif()

llvm_add_subdirectories(${PARALLEL_DIRS})
