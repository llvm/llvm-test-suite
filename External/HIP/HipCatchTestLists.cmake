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
# the YAML on every sync. A file whose test cases would all be excluded belongs
# out of SOURCES instead, because a run that selects no tests fails.

declare_catch_test_dir(unit compiler
  SOURCES
    hipClassKernel.cc
    hipSquare.cc
    hipSquareGenericTarget.cc
)
