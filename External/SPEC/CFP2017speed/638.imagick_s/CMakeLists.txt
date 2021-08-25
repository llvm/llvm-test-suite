# https://www.spec.org/cpu2017/Docs/benchmarks/638.imagick_s.html
include(../../SpecCPU2017.cmake)
if (NOT TEST_SUITE_SPEC2017_ROOT)
  return ()
endif ()

speccpu2017_benchmark(SPEED ORIGIN 538.imagick_r)

## ref #########################################################################

speccpu2017_run_test(
  -limit disk 0 "${RUN_ref_DIR_REL}/refspeed_input.tga" -resize 817%
  -rotate -2.76 -shave 540x375 -alpha remove -auto-level -contrast-stretch 1x1%
  -colorspace Lab -channel R -equalize +channel -colorspace sRGB
  -define histogram:unique-colors=false -adaptive-blur 0x5 -despeckle
  -auto-gamma -adaptive-sharpen 55 -enhance -brightness-contrast 10x10
  -resize 30% refspeed_output.tga
  RUN_TYPE ref
  SUITE_TYPE speed
)
speccpu2017_validate_image(
  refspeed_output.tga refspeed_expected.tga refspeed_validate.out
  -avg -threshold 0.95 -maxthreshold 0.001
  RUN_TYPE ref
  SUITE_TYPE speed
)

################################################################################

speccpu2017_inherit(../../CFP2017rate/538.imagick_r)
