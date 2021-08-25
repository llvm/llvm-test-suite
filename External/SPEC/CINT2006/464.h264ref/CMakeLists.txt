list(APPEND LDFLAGS -lm)
list(APPEND CFLAGS -fsigned-char)

macro(test_input run_type leading level)
  llvm_test_run(RUN_TYPE ${run_type}
    WORKDIR %S/data/${run_type}/input
    -d ${leading}encoder_${level}.cfg
    > %S/${leading}${level}_encodelog.out
  )
  llvm_test_verify(RUN_TYPE ${run_type}
    %b/${FPCMP}
    %S/data/${run_type}/output/${leading}${level}_encodelog.out
    %S/${leading}${level}_encodelog.out
  )
  llvm_test_verify(RUN_TYPE ${run_type}
    %b/${FPCMP}
    %S/data/${run_type}/output/${leading}${level}_leakybucketparam.cfg
    %S/data/${run_type}/input/${leading}${level}_leakybucketparam.cfg
  )

endmacro()

test_input(test foreman_test_ baseline)
test_input(train foreman_train_ baseline)
test_input(ref foreman_ref_ baseline)
test_input(ref foreman_ref_ main)
test_input(ref sss_ main)

llvm_test_executable(464.h264ref ${Source})
llvm_test_data_spec(464.h264ref
  data/test/output
  data/train/output
  data/ref/output
)

# TODO: This will copy a bit more than 50M of data, maybe we should symlink it?
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
