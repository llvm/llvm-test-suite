list(APPEND CPPFLAGS -DWANT_STDC_PROTO)
list(APPEND LDFLAGS -lm)

set(Source "")
foreach(dir IN ITEMS
        src/sgf src/engine src/interface src/patterns src/utils src)
  include_directories(${BENCHMARK_DIR}/${dir})
  file(GLOB MoreSource ${BENCHMARK_DIR}/${dir}/*.c)
  list(APPEND Source ${MoreSource})
endforeach()
include_directories(${BENCHMARK_DIR}/src/include)

macro(test_input run_type tstfile outfile)
  llvm_test_run(RUN_TYPE ${run_type}
    WORKDIR ${CMAKE_CURRENT_BINARY_DIR}/data/all/input
    --quiet --mode gtp
    < ${CMAKE_CURRENT_BINARY_DIR}/data/${run_type}/input/${tstfile}
    > ${CMAKE_CURRENT_BINARY_DIR}/${outfile}
  )
  llvm_test_verify(RUN_TYPE ${run_type} WORKDIR ${CMAKE_CURRENT_BINARY_DIR}
    ${FPCMP} data/${run_type}/output/${outfile} ${outfile}
  )
endmacro()

foreach(tstfile IN ITEMS
        capture.tst connect_rot.tst connection_rot.tst dniwog.tst connect.tst
        connection.tst cutstone.tst)
  get_filename_component(basename ${tstfile} NAME_WE)
  test_input(test ${tstfile} ${basename}.out)
endforeach()
foreach(tstfile IN ITEMS
        arb.tst arion.tst blunder.tst nicklas2.tst arend.tst atari_atari.tst
        buzco.tst nicklas4.tst)
  get_filename_component(basename ${tstfile} NAME_WE)
  test_input(train ${tstfile} ${basename}.out)
endforeach()
foreach(tstfile IN ITEMS
        13x13.tst nngs.tst score2.tst trevorc.tst trevord.tst)
  get_filename_component(basename ${tstfile} NAME_WE)
  test_input(ref ${tstfile} ${basename}.out)
endforeach()

llvm_test_executable(445.gobmk ${Source})
llvm_test_data_spec_default(445.gobmk)
