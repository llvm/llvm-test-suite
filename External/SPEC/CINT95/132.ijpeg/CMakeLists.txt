# This define leads to errno.h getting included
add_definitions(-D__VMS)

set(SourceNames
  jcapi.c
  jccoefct.c
  jccolor.c
  jcdctmgr.c
  jchuff.c
  jcmainct.c
  jcmarker.c
  jcmaster.c
  jcomapi.c
  jcparam.c
  jcprepct.c
  jcsample.c
  jdapi.c
  jdatadst.c
  jdatasrc.c
  jdcoefct.c
  jdcolor.c
  jddctmgr.c
  jdhuff.c
  jdmainct.c
  jdmarker.c
  jdmaster.c
  jdmerge.c
  jdpostct.c
  jdsample.c
  jerror.c
  jfdctflt.c
  jfdctfst.c
  jfdctint.c
  jidctflt.c
  jidctfst.c
  jidctint.c
  jidctred.c
  jmemmgr.c
  jmemnobs.c
  jquant1.c
  jquant2.c
  jutils.c
  libpbm1.c
  libpbm2.c
  libpbm3.c
  libpbm4.c
  libpbm5.c
  libpgm1.c
  libpgm2.c
  libppm1.c
  libppm2.c
  libppm3.c
  libppm4.c
  libppm5.c
  rdbmp.c
  rdgif.c
  rdppm.c
  rdtarga.c
  spec_image.c
  spec_jmemdst.c
  spec_jmemsrc.c
  spec_main.c
  wrbmp.c
  wrgif.c
  wrppm.c
  wrtarga.c
)
set(Source "")
foreach(FILENAME ${SourceNames})
  list(APPEND Source ${BENCHMARK_DIR}/src/${FILENAME})
endforeach()

macro(test_input run_type input output)
  llvm_test_run(RUN_TYPE ${run_type}
    -image_file ${input}
    -compression.quality 90
    -compression.optimize_coding 0
    -compression.smoothing_factor 90
    -difference.image 1
    -difference.x_stride 10
    -difference.y_stride 10
    -verbose 1
    -GO.findoptcomp
    > ${CMAKE_CURRENT_BINARY_DIR}/${output}
    WORKDIR ${BENCHMARK_DIR}/data/${run_type}/input
  )
  llvm_test_verify(RUN_TYPE ${run_type} ${FPCMP}
    ${BENCHMARK_DIR}/data/${run_type}/output/${output}
    ${CMAKE_CURRENT_BINARY_DIR}/${output}
  )
endmacro()

test_input(test specmun.ppm specmun.out)
test_input(train vigo.ppm vigo.out)
test_input(ref penguin.ppm penguin.out)
test_input(ref specmun.ppm specmun.out)
test_input(ref vigo.ppm vigo.out)

llvm_test_executable(${PROG} ${Source})
