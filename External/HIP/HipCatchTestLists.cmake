# Test lists for the hip-tests directories under catch/, kept outside catch/ so
# that it stays a straight copy of upstream.
#
# SOURCES names the .cc files that build test executables. Upstream directories
# also hold .cc files that are not tests, such as sources fed to hiprtc as data.
# A directory without an entry here builds every .cc file it contains.
#
# EXCLUDE_TESTS names test cases to skip, normally the ones upstream disables
# for amd_linux in config/configs/unit/<subdir>.yaml. Upstream applies that
# YAML through ENABLE_YAML_TAGS, which this build does not use. Names must
# match exactly: Catch2 silently ignores one that matches nothing, so recheck
# the YAML on every sync. The name of a templated test case also covers every
# instance of it, which Catch2 registers as "<name> - <type>". A file whose
# test cases would all be excluded belongs out of SOURCES instead, because a
# run that selects no tests fails.
#
# LINK_LIBS names ROCm libraries the directory's tests need, matching the
# LINKER_LIBS of upstream's CMakeLists.txt, for example hiprtc. Each is linked
# from the ROCm installation of the variant being built.

declare_catch_test_dir(unit compiler
  SOURCES
    hipClassKernel.cc
    hipSquare.cc
    hipSquareGenericTarget.cc
)

declare_catch_test_dir(unit device_memory
  SOURCES
    memcpy.cc
    memset.cc
  # Disabled for amd_linux (gfx94X failures) in upstream
  # config/configs/unit/device_memory.yaml
  EXCLUDE_TESTS
    Unit_Device_memcpy_Positive
  LINK_LIBS
    hiprtc
)

# Device math library: casting, intrinsics, half-precision, and math functions.
# 20 test files (10 hiprtc-free, 10 hiprtc-dependent); 23 negative-kernel .cc
# files and 25 .hh headers also live in the directory but are not in SOURCES.
# Disabled tests from upstream config/configs/unit/math.yaml (amd_linux).
declare_catch_test_dir(unit math
  SOURCES
    casting_double_funcs.cc
    casting_float_funcs.cc
    casting_half2_funcs.cc
    casting_half2int_funcs.cc
    casting_half_float_funcs.cc
    casting_int2half_funcs.cc
    casting_int_funcs.cc
    double_precision_intrinsics.cc
    half_precision_arithmetic.cc
    half_precision_comparison.cc
    half_precision_math.cc
    integer_intrinsics.cc
    log_funcs.cc
    misc_funcs.cc
    pow_funcs.cc
    remainder_and_rounding_funcs.cc
    root_funcs.cc
    single_precision_intrinsics.cc
    special_funcs.cc
    trig_funcs.cc
  EXCLUDE_TESTS
    Unit_Device_sinpi_Accuracy_Positive_double
    Unit_Device_cospi_Accuracy_Positive_double
    Unit_Device_sincospi_Accuracy_Positive_double
    Unit_Device_fma_Accuracy_Positive
    Unit_Device_fdim_Accuracy_Positive
    Unit_Device_remquo_Accuracy_Positive
    Unit_Device_modf_modff_Negative_RTC
    Unit_Device___frcp_rn_Accuracy_Positive
    Unit_Device___fsqrt_rn_Accuracy_Positive
    Unit_Device___frsqrt_rn_Accuracy_Positive
    Unit_Device___expf_Accuracy_Positive
    Unit_Device___exp10f_Accuracy_Positive
    Unit_Device___log2f_Accuracy_Positive
    Unit_Device_ilogbf_Accuracy_Positive
    Unit_Device_ilogb_Accuracy_Positive
    Unit_Device_tgammaf_Accuracy_Limited_Positive
    Unit_Device___float2half_rd_Accuracy_Limited_Positive
    Unit_Device___float2half_ru_Accuracy_Limited_Positive
    Unit_Device___float2half_rz_Accuracy_Limited_Positive
  LINK_LIBS
    hiprtc
)
