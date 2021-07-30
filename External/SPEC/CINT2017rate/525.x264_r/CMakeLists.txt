# https://www.spec.org/cpu2017/Docs/benchmarks/525.x264_r.html
include(../../SpecCPU2017.cmake)
if (NOT TEST_SUITE_SPEC2017_ROOT)
  return ()
endif ()

speccpu2017_benchmark(RATE)

speccpu2017_add_include_dirs(
  x264_src
  x264_src/extras
  x264_src/common
)
link_libraries(-lm)

## test ########################################################################

speccpu2017_run_test(
  --dumpyuv 50 --frames 156 -o BuckBunny_New.264 BuckBunny.yuv 1280x720
  RUN_TYPE test
)

foreach (_frame IN ITEMS 50 100 155)
  speccpu2017_validate_image(frame_${_frame}.yuv
    frame_${_frame}.org.tga imagevalidate_frame_${_frame}.out
    -avg -threshold 0.5 -maxthreshold 20
    RUN_TYPE test
  )
endforeach()

## train #######################################################################

speccpu2017_run_test(
  --dumpyuv 50 --frames 142 -o BuckBunny_New.264 BuckBunny.yuv 1280x720
  RUN_TYPE train
)

foreach (_frame IN ITEMS 50 100 141)
  speccpu2017_validate_image(frame_${_frame}.yuv
    frame_${_frame}.org.tga imagevalidate_frame_${_frame}.out
    -avg -threshold 0.5 -maxthreshold 20
    RUN_TYPE train
  )
endforeach ()

## ref #########################################################################

speccpu2017_run_test(
  --pass 1 --stats x264_stats.log --bitrate 1000 --frames 1000
  -o BuckBunny_New.264 BuckBunny.yuv 1280x720
  RUN_TYPE ref
)

speccpu2017_run_test(
  --pass 2 --stats x264_stats.log --bitrate 1000 --dumpyuv 200 --frames 1000
  -o BuckBunny_New.264 BuckBunny.yuv 1280x720
  RUN_TYPE ref
)

speccpu2017_run_test(
  --seek 500 --dumpyuv 200 --frames 1250
  -o BuckBunny_New.264 BuckBunny.yuv 1280x720
  RUN_TYPE ref
)

foreach (_frame IN ITEMS 200 400 600 700 800 900 999 1100 1249)
  speccpu2017_validate_image(frame_${_frame}.yuv
    frame_${_frame}.org.tga imagevalidate_frame_${_frame}.out
    -avg -threshold 0.5 -maxthreshold 20
    RUN_TYPE ref
  )
endforeach ()

################################################################################

speccpu2017_verify_output(RELATIVE_TOLERANCE 0.085)
speccpu2017_add_executable(
  x264_src/common/mc.c
  x264_src/common/predict.c
  x264_src/common/pixel.c
  x264_src/common/macroblock.c
  x264_src/common/frame.c
  x264_src/common/dct.c
  x264_src/common/cpu.c
  x264_src/common/cabac.c
  x264_src/common/common.c
  x264_src/common/mdate.c
  x264_src/common/rectangle.c
  x264_src/common/set.c
  x264_src/common/quant.c
  x264_src/common/deblock.c
  x264_src/common/vlc.c
  x264_src/common/mvpred.c
  x264_src/encoder/analyse.c
  x264_src/encoder/me.c
  x264_src/encoder/ratecontrol.c
  x264_src/encoder/set.c
  x264_src/encoder/macroblock.c
  x264_src/encoder/cabac.c
  x264_src/encoder/cavlc.c
  x264_src/encoder/encoder.c
  x264_src/encoder/lookahead.c
  x264_src/input/timecode.c
  x264_src/input/yuv.c
  x264_src/input/y4m.c
  x264_src/output/raw.c
  x264_src/output/matroska.c
  x264_src/output/matroska_ebml.c
  x264_src/output/flv.c
  x264_src/output/flv_bytestream.c
  x264_src/input/thread.c
  x264_src/x264.c
  x264_src/extras/getopt.c
)

set(ldecod_SourceNames
  ldecod_src/nal.c
  ldecod_src/mbuffer_mvc.c
  ldecod_src/image.c
  ldecod_src/mb_access.c
  ldecod_src/memalloc.c
  ldecod_src/mc_prediction.c
  ldecod_src/mb_prediction.c
  ldecod_src/intra4x4_pred_mbaff.c
  ldecod_src/loop_filter_mbaff.c
  ldecod_src/context_ini.c
  ldecod_src/configfile.c
  ldecod_src/cabac.c
  ldecod_src/sei.c
  ldecod_src/leaky_bucket.c
  ldecod_src/filehandle.c
  ldecod_src/errorconcealment.c
  ldecod_src/decoder_test.c
  ldecod_src/img_process.c
  ldecod_src/mv_prediction.c
  ldecod_src/fmo.c
  ldecod_src/output.c
  ldecod_src/mc_direct.c
  ldecod_src/rtp.c
  ldecod_src/nalucommon.c
  ldecod_src/config_common.c
  ldecod_src/intra_chroma_pred.c
  ldecod_src/transform8x8.c
  ldecod_src/blk_prediction.c
  ldecod_src/intra8x8_pred_mbaff.c
  ldecod_src/erc_do_i.c
  ldecod_src/io_tiff.c
  ldecod_src/mbuffer.c
  ldecod_src/block.c
  ldecod_src/intra4x4_pred.c
  ldecod_src/transform.c
  ldecod_src/annexb.c
  ldecod_src/ldecod.c
  ldecod_src/macroblock.c
  ldecod_src/vlc.c
  ldecod_src/parset.c
  ldecod_src/loop_filter_normal.c
  ldecod_src/parsetcommon.c
  ldecod_src/erc_do_p.c
  ldecod_src/loopFilter.c
  ldecod_src/intra16x16_pred_mbaff.c
  ldecod_src/intra4x4_pred_normal.c
  ldecod_src/intra16x16_pred_normal.c
  ldecod_src/win32.c
  ldecod_src/intra16x16_pred.c
  ldecod_src/intra8x8_pred_normal.c
  ldecod_src/io_raw.c
  ldecod_src/img_io.c
  ldecod_src/nalu.c
  ldecod_src/quant.c
  ldecod_src/intra8x8_pred.c
  ldecod_src/erc_api.c
  ldecod_src/header.c
  ldecod_src/biaridecod.c
  ldecod_src/input.c
)
speccpu2017_prepare_rundir()
set(ldecod_Sources)
foreach (_file IN LISTS ldecod_SourceNames)
  list(APPEND ldecod_Sources "${SRC_DIR}/${_file}")
endforeach ()
llvm_add_host_executable(ldecod_${SUFFIX}-host
  ldecod_${SUFFIX} ${ldecod_Sources}
  CPPFLAGS -I "${SRC_DIR}/ldecod_src/inc" -DSPEC
  LDFLAGS -lm
)


# Prepare BuckBunny.yuv used for x264 as input.
foreach (_run_type IN LISTS TEST_SUITE_RUN_TYPE)
  add_custom_command(
    OUTPUT "${RUN_${_run_type}_DIR}/BuckBunny.yuv"
    DEPENDS "${INPUT_${_run_type}_DIR}/BuckBunny.264"
            "${CMAKE_CURRENT_BINARY_DIR}/ldecod_${SUFFIX}"
    COMMAND "${CMAKE_CURRENT_BINARY_DIR}/ldecod_${SUFFIX}"
	        -i "${INPUT_${_run_type}_DIR}/BuckBunny.264" -o BuckBunny.yuv
			> inputgen_ldecod_x264.out
    WORKING_DIRECTORY "${RUN_${_run_type}_DIR}"
    COMMENT "Decoding ${_run_type}/input/BuckBunny.264"
    VERBATIM
  )
  add_custom_target(BuckBunny_yuv_${_run_type}_${SUFFIX}
    DEPENDS "${RUN_${_run_type}_DIR}/BuckBunny.yuv"
  )
  add_dependencies(${PROG} BuckBunny_yuv_${_run_type}_${SUFFIX})
endforeach ()
