macro(test_input run_type output)
  llvm_test_run(RUN_TYPE ${run_type}
    ${ARGN} > ${CMAKE_CURRENT_BINARY_DIR}/${output}
  )
  llvm_test_verify(RUN_TYPE ${run_type} WORKDIR ${CMAKE_CURRENT_BINARY_DIR}
    ${FPCMP} -r 0.01 data/${run_type}/output/${output} ${output}
  )
endmacro()

test_input(test test.out
  WORKDIR ${CMAKE_CURRENT_BINARY_DIR}/data/test/input
  -scanfile c756hel.in
  -trainfile1 a10.img
  -stride 2
  -startx 134
  -starty 220
  -endx 139
  -endy 225
  -objects 1
)
test_input(train train.out
  WORKDIR ${CMAKE_CURRENT_BINARY_DIR}/data/train/input
  -scanfile c756hel.in
  -trainfile1 a10.img
  -stride 2
  -startx 134
  -starty 220
  -endx 184
  -endy 240
  -objects 3
)
test_input(ref ref.1.out
  WORKDIR ${CMAKE_CURRENT_BINARY_DIR}/data/ref/input
  -scanfile c756hel.in
  -trainfile1 a10.img
  -trainfile2 hc.img
  -stride 2
  -startx 110
  -starty 200
  -endx 160
  -endy 240
  -objects 10
)
test_input(ref ref.2.out
  WORKDIR ${CMAKE_CURRENT_BINARY_DIR}/data/ref/input
  -scanfile c756hel.in
  -trainfile1 a10.img
  -trainfile2 hc.img
  -stride 2
  -startx 470
  -starty 140
  -endx 520
  -endy 180
  -objects 10
)

llvm_test_executable(179.art ${Source})
llvm_test_data_spec_default(179.art)
