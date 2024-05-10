include(External)
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

if(APPLE)
  # Building Povray breaks with -fdefine-target-os-macros, add flag to disable
  # it as workaround.
  include(CheckCCompilerFlag)
  check_c_compiler_flag(-fno-define-target-os-macros
                        COMPILER_HAS_NO_DEFINE_TARGET_OS_MACROS)
  if (COMPILER_HAS_NO_DEFINE_TARGET_OS_MACROS)
	list(APPEND CPPFLAGS
      -fno-define-target-os-macros
    )
  endif()
endif()

  list(APPEND CPPFLAGS
    -I${TEST_SUITE_POVRAY_ROOT}/source
    -I${TEST_SUITE_POVRAY_ROOT}/source/unix
    -I${TEST_SUITE_POVRAY_ROOT}/source/libpng
    -DPREFIX="${CMAKE_CURRENT_BINARY_DIR}"
    -DSYSCONFDIR="${CMAKE_CURRENT_BINARY_DIR}"
  )
  list(APPEND LDFLAGS -lz -lm)

  llvm_test_run(WORKDIR %S
    -Iscenes/advanced/chess2.pov
    -Linclude
    -GA/dev/null -O-
  )
  llvm_test_verify(%b/${FPCMP} %o %S/povray.reference_output)

  llvm_test_executable(povray ${Source})
  llvm_test_data(povray povray.reference_output)
  llvm_test_data(povray SOURCE_DIR ${TEST_SUITE_POVRAY_ROOT} scenes include)

  file(COPY lit.local.cfg DESTINATION "${CMAKE_CURRENT_BINARY_DIR}")
endif()
