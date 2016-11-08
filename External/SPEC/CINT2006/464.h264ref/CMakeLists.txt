list(APPEND LDFLAGS -lm)
list(APPEND CFLAGS -fsigned-char)

macro(test_input run_type leading level)
  llvm_test_run(RUN_TYPE ${run_type}
    -d ${leading}encoder_${level}.cfg
    > ${CMAKE_CURRENT_BINARY_DIR}/${leading}${level}_encodelog.out
    WORKDIR ${CMAKE_CURRENT_BINARY_DIR}/data/${run_type}/input
  )
  llvm_test_verify(RUN_TYPE ${run_type} ${FPCMP}
    ${BENCHMARK_DIR}/data/${run_type}/output/${leading}${level}_encodelog.out
    ${CMAKE_CURRENT_BINARY_DIR}/${leading}${level}_encodelog.out
  )
  llvm_test_verify(RUN_TYPE ${run_type} ${FPCMP}
    ${BENCHMARK_DIR}/data/${run_type}/output/${leading}${level}_leakybucketparam.cfg
    ${CMAKE_CURRENT_BINARY_DIR}/data/${run_type}/input/${leading}${level}_leakybucketparam.cfg
  )

endmacro()

test_input(test foreman_test_ baseline)
test_input(train foreman_train_ baseline)
test_input(ref foreman_ref_ baseline)
test_input(ref foreman_ref_ main)
test_input(ref sss_ main)

llvm_test_executable(${PROG} ${Source})

# TODO: This will copy a bit more than 50M of data, maybe we should symlink it?
include(CopyDir)
llvm_copy_dir(464.h264ref ${CMAKE_CURRENT_BINARY_DIR}/data/test/input
  ${BENCHMARK_DIR}/data/all/input
  ${BENCHMARK_DIR}/data/test/input
)
llvm_copy_dir(464.h264ref ${CMAKE_CURRENT_BINARY_DIR}/data/train/input
  ${BENCHMARK_DIR}/data/all/input
  ${BENCHMARK_DIR}/data/train/input
)
llvm_copy_dir(464.h264ref ${CMAKE_CURRENT_BINARY_DIR}/data/ref/input
  ${BENCHMARK_DIR}/data/all/input
  ${BENCHMARK_DIR}/data/ref/input
)
