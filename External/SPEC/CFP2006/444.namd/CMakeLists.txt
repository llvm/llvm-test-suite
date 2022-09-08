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
  llvm_test_run(RUN_TYPE ${run_type} WORKDIR %S
    --input data/all/input/namd.input
    --iterations ${iters}
    --output namd.out
    > namd.stdout
  )
  llvm_test_verify(RUN_TYPE ${run_type}
    %b/${FPCMP} -a 0.00001 %S/data/${run_type}/output/namd.out %S/namd.out
  )
endmacro()

test_input(test 1)
test_input(train 1)
test_input(ref 38)

llvm_test_executable(444.namd ${Source})
set_property(TARGET 444.namd PROPERTY CXX_STANDARD 14)
llvm_test_data_spec_default(444.namd)
