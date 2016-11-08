# There's more files than we need in the src directory, provide a list:
set(SourceNames
  accum.c
  alpha.c
  alphabuf.c
  api1.c
  api2.c
  attrib.c
  bitmap.c
  blend.c
  clip.c
  colortab.c
  context.c
  copypix.c
  depth.c
  dlist.c
  drawpix.c
  enable.c
  eval.c
  feedback.c
  fog.c
  get.c
  hash.c
  image.c
  light.c
  lines.c
  logic.c
  masking.c
  matrix.c
  misc.c
  mmath.c
  osmesa.c
  pb.c
  pixel.c
  pointers.c
  points.c
  polygon.c
  quads.c
  rastpos.c
  readpix.c
  rect.c
  scissor.c
  shade.c
  span.c
  stencil.c
  teximage.c
  texobj.c
  texstate.c
  texture.c
  triangle.c
  varray.c
  vb.c
  vbfill.c
  vbrender.c
  vbxform.c
  winpos.c
  xform.c
  mesa4.c
)
set(Source "")
foreach(Filename ${SourceNames})
  list(APPEND Source ${BENCHMARK_DIR}/src/${Filename})
endforeach()

macro(test_input run_type frames)
  llvm_test_run(RUN_TYPE ${run_type}
    WORKDIR ${CMAKE_CURRENT_BINARY_DIR}/data/${run_type}/input
    -frames ${frames} -meshfile mesa.in -ppmfile mesa.ppm
  )
  llvm_test_verify(RUN_TYPE ${run_type} ${FPCMP}
    ${BENCHMARK_DIR}/data/${run_type}/output/mesa.log
    ${CMAKE_CURRENT_BINARY_DIR}/data/${run_type}/input/mesa.log
  )
  llvm_test_verify(RUN_TYPE ${run_type} ${FPCMP}
    -a 6.0
    ${BENCHMARK_DIR}/data/${run_type}/output/mesa.ppm
    ${CMAKE_CURRENT_BINARY_DIR}/data/${run_type}/input/mesa.ppm
  )
endmacro()

test_input(test 10)
test_input(train 500)
test_input(ref 1000)

llvm_test_executable(${PROG} ${Source})

# The benchmark writes the output where the input files are, so we have to
# copy the data over.
include(CopyDir)
llvm_copy_dir(177.mesa ${CMAKE_CURRENT_BINARY_DIR}/data ${BENCHMARK_DIR}/data)
