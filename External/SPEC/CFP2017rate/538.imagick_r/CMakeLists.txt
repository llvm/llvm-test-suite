# https://www.spec.org/cpu2017/Docs/benchmarks/538.imagick_r.html
include(../../SpecCPU2017.cmake)
if (NOT TEST_SUITE_SPEC2017_ROOT)
  return ()
endif ()

speccpu2017_benchmark(RATE)

speccpu2017_add_include_dirs(.)
link_libraries(-lm)

## test ########################################################################

speccpu2017_run_test(
  -limit disk 0 "${RUN_test_DIR_REL}/test_input.tga" -shear 25 -resize 640x480
  -negate -alpha Off test_output.tga
  RUN_TYPE test
)
speccpu2017_validate_image(
  test_output.tga test_expected.tga test_validate.out
  -avg -threshold 0.95 -maxthreshold 0.001
  RUN_TYPE test
)

## train #######################################################################

speccpu2017_run_test(
  -limit disk 0 "${RUN_train_DIR_REL}/train_input.tga" -resize 320x240 -shear 31
  -edge 140 -negate -flop -resize 900x900 -edge 10 train_output.tga
  RUN_TYPE train
)
speccpu2017_validate_image(
  train_output.tga train_expected.tga train_validate.out
  -avg -threshold 0.95 -maxthreshold 0.001
  RUN_TYPE train
)

## ref #########################################################################

speccpu2017_run_test(
  -limit disk 0 "${RUN_ref_DIR_REL}/refrate_input.tga" -edge 41
  -resample 181% -emboss 31 -colorspace YUV -mean-shift 19x19+15%
  -resize 30% refrate_output.tga
  RUN_TYPE ref
  SUITE_TYPE rate
)
speccpu2017_validate_image(
  refrate_output.tga refrate_expected.tga refrate_validate.out
  -avg -threshold 0.95 -maxthreshold 0.001
  RUN_TYPE ref
  SUITE_TYPE rate
)

################################################################################

speccpu2017_verify_output(RELATIVE_TOLERANCE 0.01)
speccpu2017_add_executable(
  coders/tga.c
  filters/analyze.c
  magick/accelerate.c
  magick/animate.c
  magick/annotate.c
  magick/artifact.c
  magick/attribute.c
  magick/blob.c
  magick/cache-view.c
  magick/cache.c
  magick/channel.c
  magick/cipher.c
  magick/client.c
  magick/coder.c
  magick/color.c
  magick/colormap.c
  magick/colorspace.c
  magick/compare.c
  magick/composite.c
  magick/compress.c
  magick/configure.c
  magick/constitute.c
  magick/decorate.c
  magick/delegate.c
  magick/display.c
  magick/distort.c
  magick/distribute-cache.c
  magick/draw.c
  magick/effect.c
  magick/enhance.c
  magick/exception.c
  magick/feature.c
  magick/fourier.c
  magick/fx.c
  magick/gem.c
  magick/geometry.c
  magick/hashmap.c
  magick/histogram.c
  magick/identify.c
  magick/image.c
  magick/layer.c
  magick/list.c
  magick/locale.c
  magick/log.c
  magick/magic.c
  magick/magick.c
  magick/matrix.c
  magick/memory.c
  magick/mime.c
  magick/module.c
  magick/monitor.c
  magick/montage.c
  magick/morphology.c
  magick/option.c
  magick/paint.c
  magick/pixel.c
  magick/policy.c
  magick/prepress.c
  magick/profile.c
  magick/property.c
  magick/quantize.c
  magick/quantum-export.c
  magick/quantum-import.c
  magick/quantum.c
  magick/random.c
  magick/registry.c
  magick/resample.c
  magick/resize.c
  magick/resource.c
  magick/segment.c
  magick/semaphore.c
  magick/shear.c
  magick/signature.c
  magick/splay-tree.c
  magick/static.c
  magick/statistic.c
  magick/stream.c
  magick/string.c
  magick/threshold.c
  magick/timer.c
  magick/token.c
  magick/transform.c
  magick/type.c
  magick/utility.c
  magick/version.c
  magick/xml-tree.c
  utilities/convert.c
  wand/convert.c
  wand/drawing-wand.c
  wand/magick-image.c
  wand/magick-wand.c
  wand/mogrify.c
  wand/pixel-wand.c
  wand/magick-property.c
  wand/pixel-iterator.c
  wand/wand.c
  magick/deprecate.c
)
speccpu2017_prepare_rundir()
