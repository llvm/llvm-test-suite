# https://www.spec.org/cpu2017/Docs/benchmarks/557.xz_r.html
include(../../SpecCPU2017.cmake)
if (NOT TEST_SUITE_SPEC2017_ROOT)
  return ()
endif ()

speccpu2017_benchmark(RATE)

add_definitions(-DHAVE_CONFIG_H=1 -DSPEC_MEM_IO -DSPEC_XZ)
speccpu2017_add_include_dirs(
  .
  spec_mem_io
  sha-2
  common
  liblzma/api
  liblzma/lzma
  liblzma/common
  liblzma/check
  liblzma/simple
  liblzma/delta
  liblzma/lz
  liblzma/rangecoder
)

## test ########################################################################

speccpu2017_run_test(
  cpu2006docs.tar.xz 4 055ce243071129412e9dd0b3b69a21654033a9b723d874b2015c774fac1553d9713be561ca86f74e4f16f22e664fc17a79f30caa5ad2c04fbc447549c2810fae 1548636 1555348 0
  STDOUT cpu2006docs.tar-4-0.out
  RUN_TYPE test
)

speccpu2017_run_test(
  cpu2006docs.tar.xz 4 055ce243071129412e9dd0b3b69a21654033a9b723d874b2015c774fac1553d9713be561ca86f74e4f16f22e664fc17a79f30caa5ad2c04fbc447549c2810fae 1462248 -1 1
  STDOUT cpu2006docs.tar-4-1.out
  RUN_TYPE test
)

speccpu2017_run_test(
  cpu2006docs.tar.xz 4 055ce243071129412e9dd0b3b69a21654033a9b723d874b2015c774fac1553d9713be561ca86f74e4f16f22e664fc17a79f30caa5ad2c04fbc447549c2810fae 1428548 -1 2
  STDOUT cpu2006docs.tar-4-2.out
  RUN_TYPE test
)

speccpu2017_run_test(
   cpu2006docs.tar.xz 4 055ce243071129412e9dd0b3b69a21654033a9b723d874b2015c774fac1553d9713be561ca86f74e4f16f22e664fc17a79f30caa5ad2c04fbc447549c2810fae 1034828 -1 3e
   STDOUT cpu2006docs.tar-4-3e.out
   RUN_TYPE test
)

speccpu2017_run_test(
  cpu2006docs.tar.xz 4 055ce243071129412e9dd0b3b69a21654033a9b723d874b2015c774fac1553d9713be561ca86f74e4f16f22e664fc17a79f30caa5ad2c04fbc447549c2810fae 1061968 -1 4
  STDOUT cpu2006docs.tar-4-4.out
  RUN_TYPE test
)

speccpu2017_run_test(
  cpu2006docs.tar.xz 4 055ce243071129412e9dd0b3b69a21654033a9b723d874b2015c774fac1553d9713be561ca86f74e4f16f22e664fc17a79f30caa5ad2c04fbc447549c2810fae 1034588 -1 4e
  STDOUT cpu2006docs.tar-4-4e.out
  RUN_TYPE test
)

speccpu2017_run_test(
  cpu2006docs.tar.xz 1 055ce243071129412e9dd0b3b69a21654033a9b723d874b2015c774fac1553d9713be561ca86f74e4f16f22e664fc17a79f30caa5ad2c04fbc447549c2810fae 650156 -1 0
  STDOUT cpu2006docs.tar-1-0.out
  RUN_TYPE test
)

speccpu2017_run_test(
  cpu2006docs.tar.xz 1 055ce243071129412e9dd0b3b69a21654033a9b723d874b2015c774fac1553d9713be561ca86f74e4f16f22e664fc17a79f30caa5ad2c04fbc447549c2810fae 639996 -1 1
  STDOUT cpu2006docs.tar-1-1.out
  RUN_TYPE test
)

speccpu2017_run_test(
  cpu2006docs.tar.xz 1 055ce243071129412e9dd0b3b69a21654033a9b723d874b2015c774fac1553d9713be561ca86f74e4f16f22e664fc17a79f30caa5ad2c04fbc447549c2810fae 637616 -1 2
  STDOUT cpu2006docs.tar-1-2.out
  RUN_TYPE test
)

speccpu2017_run_test(
  cpu2006docs.tar.xz 1 055ce243071129412e9dd0b3b69a21654033a9b723d874b2015c774fac1553d9713be561ca86f74e4f16f22e664fc17a79f30caa5ad2c04fbc447549c2810fae 628996 -1 3e
  STDOUT cpu2006docs.tar-1-3e.out
  RUN_TYPE test
)

speccpu2017_run_test(
  cpu2006docs.tar.xz 1 055ce243071129412e9dd0b3b69a21654033a9b723d874b2015c774fac1553d9713be561ca86f74e4f16f22e664fc17a79f30caa5ad2c04fbc447549c2810fae 631912 -1 4
  STDOUT cpu2006docs.tar-1-4.out
  RUN_TYPE test
)

speccpu2017_run_test(
  cpu2006docs.tar.xz 1 055ce243071129412e9dd0b3b69a21654033a9b723d874b2015c774fac1553d9713be561ca86f74e4f16f22e664fc17a79f30caa5ad2c04fbc447549c2810fae 629064 -1 4e
  STDOUT cpu2006docs.tar-1-4e.out
  RUN_TYPE test
)

## train #######################################################################

speccpu2017_run_test(
  input.combined.xz 40 a841f68f38572a49d86226b7ff5baeb31bd19dc637a922a972b2e6d1257a890f6a544ecab967c313e370478c74f760eb229d4eef8a8d2836d233d3e9dd1430bf 6356684 -1 8
  STDOUT input.combined-40-8.out
  RUN_TYPE train
)

speccpu2017_run_test(
  IMG_2560.cr2.xz 40 ec03e53b02deae89b6650f1de4bed76a012366fb3d4bdc791e8633d1a5964e03004523752ab008eff0d9e693689c53056533a05fc4b277f0086544c6c3cbbbf6 40822692 40824404 4
  STDOUT IMG_2560.cr2-40-4.out
  RUN_TYPE train
)

## ref #########################################################################

speccpu2017_run_test(
  cld.tar.xz 160 19cf30ae51eddcbefda78dd06014b4b96281456e078ca7c13e1c0c9e6aaea8dff3efb4ad6b0456697718cede6bd5454852652806a657bb56e07d61128434b474 59796407 61004416 6
  STDOUT cld.tar-160-6.out
  RUN_TYPE ref
  SUITE_TYPE rate
)

speccpu2017_run_test(
  cpu2006docs.tar.xz 250 055ce243071129412e9dd0b3b69a21654033a9b723d874b2015c774fac1553d9713be561ca86f74e4f16f22e664fc17a79f30caa5ad2c04fbc447549c2810fae 23047774 23513385 6e
  STDOUT cpu2006docs.tar-250-6e.out
  RUN_TYPE ref
  SUITE_TYPE rate
)

speccpu2017_run_test(
  input.combined.xz 250 a841f68f38572a49d86226b7ff5baeb31bd19dc637a922a972b2e6d1257a890f6a544ecab967c313e370478c74f760eb229d4eef8a8d2836d233d3e9dd1430bf 40401484 41217675 7
  STDOUT input.combined-250-7.out
  RUN_TYPE ref
  SUITE_TYPE rate
)

################################################################################

speccpu2017_verify_output()
speccpu2017_add_executable(
    spec.c
    spec_xz.c
    pxz.c
    common/tuklib_physmem.c
    liblzma/common/common.c
    liblzma/common/block_util.c
    liblzma/common/easy_preset.c
    liblzma/common/filter_common.c
    liblzma/common/hardware_physmem.c
    liblzma/common/index.c
    liblzma/common/stream_flags_common.c
    liblzma/common/vli_size.c
    liblzma/common/alone_encoder.c
    liblzma/common/block_buffer_encoder.c
    liblzma/common/block_encoder.c
    liblzma/common/block_header_encoder.c
    liblzma/common/easy_buffer_encoder.c
    liblzma/common/easy_encoder.c
    liblzma/common/easy_encoder_memusage.c
    liblzma/common/filter_buffer_encoder.c
    liblzma/common/filter_encoder.c
    liblzma/common/filter_flags_encoder.c
    liblzma/common/index_encoder.c
    liblzma/common/stream_buffer_encoder.c
    liblzma/common/stream_encoder.c
    liblzma/common/stream_flags_encoder.c
    liblzma/common/vli_encoder.c
    liblzma/common/alone_decoder.c
    liblzma/common/auto_decoder.c
    liblzma/common/block_buffer_decoder.c
    liblzma/common/block_decoder.c
    liblzma/common/block_header_decoder.c
    liblzma/common/easy_decoder_memusage.c
    liblzma/common/filter_buffer_decoder.c
    liblzma/common/filter_decoder.c
    liblzma/common/filter_flags_decoder.c
    liblzma/common/index_decoder.c
    liblzma/common/index_hash.c
    liblzma/common/stream_buffer_decoder.c
    liblzma/common/stream_decoder.c
    liblzma/common/stream_flags_decoder.c
    liblzma/common/vli_decoder.c
    liblzma/check/check.c
    liblzma/check/crc32_table.c
    liblzma/check/crc32_fast.c
    liblzma/check/crc64_table.c
    liblzma/check/crc64_fast.c
    liblzma/check/sha256.c
    liblzma/lz/lz_encoder.c
    liblzma/lz/lz_encoder_mf.c
    liblzma/lz/lz_decoder.c
    liblzma/lzma/lzma_encoder.c
    liblzma/lzma/lzma_encoder_presets.c
    liblzma/lzma/lzma_encoder_optimum_fast.c
    liblzma/lzma/lzma_encoder_optimum_normal.c
    liblzma/lzma/fastpos_table.c
    liblzma/lzma/lzma_decoder.c
    liblzma/lzma/lzma2_encoder.c
    liblzma/lzma/lzma2_decoder.c
    liblzma/rangecoder/price_table.c
    liblzma/delta/delta_common.c
    liblzma/delta/delta_encoder.c
    liblzma/delta/delta_decoder.c
    liblzma/simple/simple_coder.c
    liblzma/simple/simple_encoder.c
    liblzma/simple/simple_decoder.c
    liblzma/simple/x86.c
    liblzma/simple/powerpc.c
    liblzma/simple/ia64.c
    liblzma/simple/arm.c
    liblzma/simple/armthumb.c
    liblzma/simple/sparc.c
    xz/args.c
    xz/coder.c
    xz/file_io.c
    xz/hardware.c
    xz/list.c
    xz/main.c
    xz/message.c
    xz/options.c
    xz/signals.c
    xz/util.c
    common/tuklib_open_stdxxx.c
    common/tuklib_progname.c
    common/tuklib_exit.c
    common/tuklib_cpucores.c
    common/tuklib_mbstr_width.c
    common/tuklib_mbstr_fw.c
    spec_mem_io/spec_mem_io.c
    sha-2/sha512.c
)
speccpu2017_prepare_rundir()
