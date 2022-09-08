# https://www.spec.org/cpu2017/Docs/benchmarks/511.povray_r.html
include(../../SpecCPU2017.cmake)
if (NOT TEST_SUITE_SPEC2017_ROOT)
  return ()
endif ()

speccpu2017_benchmark(RATE)

speccpu2017_add_include_dirs(frontend base . spec_qsort)

## test ########################################################################

speccpu2017_run_test(
  SPEC-benchmark-test.ini
  RUN_TYPE test
)
speccpu2017_validate_image(
  SPEC-benchmark.tga SPEC-benchmark.org.tga imagevalidate_SPEC-benchmark.tga.out
  RUN_TYPE test
)

## train #######################################################################

speccpu2017_run_test(
  SPEC-benchmark-train.ini
  RUN_TYPE train
)
speccpu2017_validate_image(
  SPEC-benchmark.tga SPEC-benchmark.org.tga imagevalidate_SPEC-benchmark.tga.out
  RUN_TYPE train
)

## ref #########################################################################

speccpu2017_run_test(
  SPEC-benchmark-ref.ini
  RUN_TYPE ref
)
speccpu2017_validate_image(
  SPEC-benchmark.tga SPEC-benchmark.org.tga imagevalidate_SPEC-benchmark.tga.out
  RUN_TYPE ref
)

################################################################################

# Using IGNORE_WHITESPACE because the reference output has CRLF line endings,
# while the program output uses LF.
speccpu2017_verify_output(RELATIVE_TOLERANCE 0.06 IGNORE_WHITESPACE)
speccpu2017_add_executable(
  atmosph.cpp
  bbox.cpp
  bcyl.cpp
  benchmark.cpp
  bezier.cpp
  blob.cpp
  boxes.cpp
  bsphere.cpp
  camera.cpp
  chi2.cpp
  colour.cpp
  colutils.cpp
  cones.cpp
  csg.cpp
  discs.cpp
  express.cpp
  fncode.cpp
  fnintern.cpp
  fnpovfpu.cpp
  fnsyntax.cpp
  fpmetric.cpp
  fractal.cpp
  function.cpp
  hcmplx.cpp
  hfield.cpp
  histogra.cpp
  iff.cpp
  image.cpp
  interior.cpp
  isosurf.cpp
  lathe.cpp
  lbuffer.cpp
  lightgrp.cpp
  lighting.cpp
  mathutil.cpp
  matrices.cpp
  media.cpp
  mesh.cpp
  normal.cpp
  objects.cpp
  octree.cpp
  optout.cpp
  parse.cpp
  parsestr.cpp
  parstxtr.cpp
  pattern.cpp
  pgm.cpp
  photons.cpp
  pigment.cpp
  planes.cpp
  point.cpp
  poly.cpp
  polygon.cpp
  polysolv.cpp
  povmsend.cpp
  povmsrec.cpp
  povray.cpp
  pov_mem.cpp
  pov_util.cpp
  ppm.cpp
  prism.cpp
  quadrics.cpp
  quatern.cpp
  radiosit.cpp
  rad_data.cpp
  ray.cpp
  rendctrl.cpp
  render.cpp
  renderio.cpp
  reswords.cpp
  sor.cpp
  spheres.cpp
  sphsweep.cpp
  splines.cpp
  statspov.cpp
  super.cpp
  targa.cpp
  texture.cpp
  tokenize.cpp
  torus.cpp
  triangle.cpp
  truetype.cpp
  txttest.cpp
  userdisp.cpp
  userio.cpp
  vbuffer.cpp
  vlbuffer.cpp
  warps.cpp
  base/fileinputoutput.cpp
  base/povms.cpp
  base/povmscpp.cpp
  base/processoptions.cpp
  base/stringutilities.cpp
  base/textstream.cpp
  base/textstreambuffer.cpp
  frontend/defaultplatformbase.cpp
  frontend/defaultrenderfrontend.cpp
  frontend/messageoutput.cpp
  frontend/processrenderoptions.cpp
  frontend/renderfrontend.cpp
  spec_qsort/spec_qsort.c
)
set_property(TARGET ${PROG} PROPERTY CXX_STANDARD 14)
speccpu2017_prepare_rundir()
