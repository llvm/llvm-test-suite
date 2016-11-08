add_definitions(-DHAVE_CONFIG_H)
include_directories(${BENCHMARK_DIR}/src ${BENCHMARK_DIR}/src/libutil)
list(APPEND LDFLAGS -lm)

macro(test_input run_type)
  llvm_test_run(RUN_TYPE ${run_type}
    ctlfile . args.an4
    > ${CMAKE_CURRENT_BINARY_DIR}/data/${run_type}/input/an4.log
    WORKDIR ${CMAKE_CURRENT_BINARY_DIR}/data/${run_type}/input
  )
  llvm_test_verify(RUN_TYPE ${run_type} ${FPCMP}
    -r .0004
    ${BENCHMARK_DIR}/data/${run_type}/output/considered.out
    ${CMAKE_CURRENT_BINARY_DIR}/data/${run_type}/input/considered.out
  )
  llvm_test_verify(RUN_TYPE ${run_type} ${FPCMP}
    -r 1e-6
    ${BENCHMARK_DIR}/data/${run_type}/output/total_considered.out
    ${CMAKE_CURRENT_BINARY_DIR}/data/${run_type}/input/total_considered.out
  )
  llvm_test_verify(RUN_TYPE ${run_type} ${FPCMP}
    -r .001
    ${BENCHMARK_DIR}/data/${run_type}/output/an4.log
    ${CMAKE_CURRENT_BINARY_DIR}/data/${run_type}/input/an4.log
  )
endmacro()

test_input(test)
test_input(train)
test_input(ref)

# The benchmark includes the filenames of the .c files in its output and we
# cannot have full paths in there so hack around...
foreach(s ${Source})
  get_filename_component(basename ${s} NAME)
  set_source_files_properties(${s} PROPERTIES COMPILE_DEFINITIONS __FILE__="${basename}")
endforeach()

llvm_test_executable(${PROG} ${Source})

macro(prepare_data run_type)
  set(DESTDIR ${CMAKE_CURRENT_BINARY_DIR}/data/${run_type}/input)
  llvm_copy_dir(${PROG} ${DESTDIR}/model
    ${BENCHMARK_DIR}/data/all/input/model
  )
  llvm_copy(${PROG} ${DESTDIR} ${BENCHMARK_DIR}/data/${run_type}/input/args.an4)
  llvm_copy(${PROG} ${DESTDIR} ${BENCHMARK_DIR}/data/${run_type}/input/beams.dat)
  # Create ctlfile and copy .raw files depending on endianess
  if(IS_BIGENDIAN)
    file(GLOB files "${BENCHMARK_DIR}/data/${run_type}/input/*.be.raw")
  else()
    file(GLOB files "${BENCHMARK_DIR}/data/${run_type}/input/*.le.raw")
  endif()
  set(CTLFILE "")
  foreach(f ${files})
    get_filename_component(basename ${f} NAME)
    string(REGEX REPLACE ".(be|le).raw$" "" basename "${basename}")
    llvm_copy(${PROG} ${DESTDIR}/${basename}.raw ${f})
    # Determine file size...
    file(READ ${f} content HEX)
    string(LENGTH ${content} content_length)
    math(EXPR filesize "${content_length} / 2")
    # Append line to ctlfile
    set(CTLFILE "${CTLFILE}${basename} ${filesize}\n")
  endforeach()
  file(GENERATE OUTPUT ${DESTDIR}/ctlfile CONTENT "${CTLFILE}")
endmacro()

prepare_data(test)
prepare_data(train)
prepare_data(ref)

# Data comes with *.test files which should not be read by lit.
file(GENERATE
  OUTPUT ${CMAKE_CURRENT_BINARY_DIR}/data/lit.local.cfg
  CONTENT "config.suffixes = []"
)
