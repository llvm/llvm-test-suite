add_definitions(
  -DAPP_NO_THREADS
  -DXALAN_INMEM_MSG_LOADER
  -DPROJ_XMLPARSER
  -DPROJ_XMLUTIL
  -DPROJ_PARSERS
  -DPROJ_SAX4C
  -DPROJ_SAX2
  -DPROJ_DOM
  -DPROJ_VALIDATORS
  -DXML_USE_NATIVE_TRANSCODER
  -DXML_USE_INMEM_MESSAGELOADER
)

list(APPEND CXXFLAGS -std=gnu++98)

include_directories(
  ${CMAKE_CURRENT_SOURCE_DIR}
  ${BENCHMARK_DIR}/src
  ${BENCHMARK_DIR}/src/xercesc
  ${BENCHMARK_DIR}/src/xercesc/dom
  ${BENCHMARK_DIR}/src/xercesc/dom/impl
  ${BENCHMARK_DIR}/src/xercesc/sax
  ${BENCHMARK_DIR}/src/xercesc/util/MsgLoaders/InMemory
  ${BENCHMARK_DIR}/src/xercesc/util/Transcoders/Iconv
  ${BENCHMARK_DIR}/src/xalanc/include
)
if(TARGET_OS STREQUAL "Darwin")
  # Necessary for iOS
  list(APPEND LDFLAGS -Xlinker -stack_size -Xlinker 0x8000000)
endif()

macro(test_input run_type input output)
  llvm_test_run(RUN_TYPE ${run_type}
    WORKDIR %S/data/${run_type}/input
    -v ${input} xalanc.xsl
    > %S/${output}
  )
  llvm_test_verify(RUN_TYPE ${run_type}
    %b/${FPCMP} -r 0.001 %S/data/${run_type}/output/${output} %S/${output}
  )
endmacro()

test_input(test test.xml test.out)
test_input(train allbooks.xml train.out)
test_input(ref t5.xml ref.out)

llvm_test_executable(483.xalancbmk ${Source})
llvm_test_data_spec_default(483.xalancbmk)
