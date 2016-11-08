set(SourceNames
  Compute.C
  ComputeList.C
  ComputeNonbondedUtil.C
  LJTable.C
  Molecule.C
  Patch.C
  PatchList.C
  ResultSet.C
  SimParameters.C
  erf.C
  spec_namd.C
)
set(Source "")
foreach(FILENAME ${SourceNames})
  list(APPEND Source ${BENCHMARK_DIR}/src/${FILENAME})
endforeach()

macro(test_input run_type iters)
  llvm_test_run(RUN_TYPE ${run_type}
    --input ${BENCHMARK_DIR}/data/all/input/namd.input
    --iterations ${iters}
    --output ${CMAKE_CURRENT_BINARY_DIR}/namd.out
    > ${CMAKE_CURRENT_BINARY_DIR}/namd.stdout
  )
  llvm_test_verify(RUN_TYPE ${run_type} ${FPCMP}
    -a 0.00001
    ${BENCHMARK_DIR}/data/${run_type}/output/namd.out
    ${CMAKE_CURRENT_BINARY_DIR}/namd.out
  )
endmacro()

test_input(test 1)
test_input(train 1)
test_input(ref 38)

llvm_test_executable(${PROG} ${Source})
