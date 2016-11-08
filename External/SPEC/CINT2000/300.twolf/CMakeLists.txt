list(APPEND CPPFLAGS -DHAVE_SIGNED_CHAR)
list(APPEND LDFLAGS -lm)
list(APPEND CFLAGS -Wno-return-type)

macro(test_input run_type)
  llvm_test_run(RUN_TYPE ${run_type}
    WORKDIR ${CMAKE_CURRENT_BINARY_DIR}/data/${run_type}/input
    ${run_type}
    > ${CMAKE_CURRENT_BINARY_DIR}/data/${run_type}/input/${run_type}.stdout
  )
  foreach(file IN ITEMS ${run_type}.twf ${run_type}.pl2 ${run_type}.sav ${run_type}.pl1 ${run_type}.pl1 ${run_type}.pin ${run_type}.stdout ${run_type}.sv2 ${run_type}.out)
    llvm_test_verify(RUN_TYPE ${run_type} ${FPCMP}
      ${CMAKE_CURRENT_BINARY_DIR}/data/${run_type}/input/${file}
      ${BENCHMARK_DIR}/data/${run_type}/output/${file}
    )
  endforeach()
endmacro()

test_input(test)
test_input(train)
test_input(ref)

llvm_test_executable(${PROG} ${Source})

# The benchmark writes the output where the input files are, so we have to
# copy the data over.
include(CopyDir)
llvm_copy_dir(${PROG} ${CMAKE_CURRENT_BINARY_DIR}/data ${BENCHMARK_DIR}/data)
