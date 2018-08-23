list(APPEND LDFLAGS -lm)

macro(test_input run_type input output)
  # The benchmark modifies the data file, need to copy a fresh one
  llvm_test_prepare(RUN_TYPE ${run_type} WORKDIR ${CMAKE_CURRENT_BINARY_DIR}
    cp -f data/${run_type}/input/${input} ${input}
  )
  llvm_test_run(RUN_TYPE ${run_type} WORKDIR ${CMAKE_CURRENT_BINARY_DIR}
    ${ARGN} ${input} > ${output}
  )
  llvm_test_verify(RUN_TYPE ${run_type} WORKDIR ${CMAKE_CURRENT_BINARY_DIR}
    ${FPCMP} -r 0.002 -a 0.00001 data/${run_type}/output/${output} ${output}
  )
endmacro()

test_input(test bombesin.hmm bombesin.out
  --fixed 0 --mean 325 --num 45000 --sd 200 --seed 0
)
test_input(train leng100.hmm leng100.out
  --fixed 0 --mean 425 --num 85000 --sd 300 --seed 0
)
# Copy nph3.hmm as well
llvm_test_prepare(RUN_TYPE ref WORKDIR ${CMAKE_CURRENT_BINARY_DIR}
  cp -f data/ref/input/nph3.hmm nph3.hmm
)
test_input(ref swiss41 nph3.out
  nph3.hmm
)
test_input(ref retro.hmm retro.out
  --fixed 0 --mean 500 --num 500000 --sd 350 --seed 0
)

llvm_test_executable(456.hmmer ${Source})
llvm_test_data_spec_default(456.hmmer)
