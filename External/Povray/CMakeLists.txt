llvm_externals_find(TEST_SUITE_POVRAY_ROOT "povray31" "POV-Ray 3.1")

if(TEST_SUITE_POVRAY_ROOT)
  file(GLOB Source
    ${TEST_SUITE_POVRAY_ROOT}/source/*.c
    ${TEST_SUITE_POVRAY_ROOT}/source/libpng/*.c
  )
  list(REMOVE_ITEM Source
    ${TEST_SUITE_POVRAY_ROOT}/source/libpng/ansi2knr.c
    ${TEST_SUITE_POVRAY_ROOT}/source/libpng/pngtest.c
    ${TEST_SUITE_POVRAY_ROOT}/source/libpng/example.c
  )

  list(APPEND CPPFLAGS
    -I${TEST_SUITE_POVRAY_ROOT}/source
    -I${TEST_SUITE_POVRAY_ROOT}/source/unix
    -I${TEST_SUITE_POVRAY_ROOT}/source/libpng
    -DPREFIX="${CMAKE_CURRENT_BINARY_DIR}"
    -DSYSCONFDIR="${CMAKE_CURRENT_BINARY_DIR}"
  )
  list(APPEND LDFLAGS -lz -lm)

  llvm_test_run(
    -I${TEST_SUITE_POVRAY_ROOT}/scenes/advanced/chess2.pov
    -L${TEST_SUITE_POVRAY_ROOT}/include
    -GA/dev/null -O-
  )
  llvm_test_verify(${FPCMP}
    %o
    ${CMAKE_CURRENT_SOURCE_DIR}/povray.reference_output
  )

  llvm_test_executable(povray ${Source})
endif()
