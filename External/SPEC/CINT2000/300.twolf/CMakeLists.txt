list(APPEND CPPFLAGS -DHAVE_SIGNED_CHAR)
list(APPEND LDFLAGS -lm)
list(APPEND CFLAGS -Wno-return-type)

macro(test_input run_type)
  llvm_test_run(RUN_TYPE ${run_type}
    WORKDIR ${CMAKE_CURRENT_BINARY_DIR}/data/${run_type}/input
    ${run_type} > ${run_type}.stdout
  )
  foreach(file IN ITEMS ${run_type}.twf ${run_type}.pl2 ${run_type}.sav ${run_type}.pl1 ${run_type}.pl1 ${run_type}.pin ${run_type}.stdout ${run_type}.sv2 ${run_type}.out)
    llvm_test_verify(RUN_TYPE ${run_type} WORKDIR ${CMAKE_CURRENT_BINARY_DIR}
      ${FPCMP} data/${run_type}/output/${file} data/${run_type}/input/${file}
    )
  endforeach()
endmacro()

test_input(test)
test_input(train)
test_input(ref)

llvm_test_executable(300.twolf ${Source})
llvm_test_data_spec(300.twolf MUST_COPY data)
