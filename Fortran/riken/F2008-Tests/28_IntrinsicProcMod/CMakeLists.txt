# Auto-generated while integrating the riken F2008 test set into the
# CMake-driven test-suite build. `_cNNN` sources are negative/error-case
# tests (expect a compile-time diagnostic); the current llvm_singlesource()
# helper only supports build-and-run tests, so they are excluded here and
# left for follow-up work (see Fortran/riken/README.md).
file(GLOB _sources *.f90)
list(FILTER _sources EXCLUDE REGEX "_c[0-9]+\\.f90$")

# Excluded for this integration pass:
list(REMOVE_ITEM _sources ${CMAKE_CURRENT_SOURCE_DIR}/28_executeCommandLine_001.f90) # checks side-effect files via `ls`, not just stdout; needs custom verify
list(REMOVE_ITEM _sources ${CMAKE_CURRENT_SOURCE_DIR}/28_executeCommandLine_002.f90) # checks side-effect files via `ls`, not just stdout; needs custom verify
list(REMOVE_ITEM _sources ${CMAKE_CURRENT_SOURCE_DIR}/28_addModProc_001.f90) # asserts COMPILER_OPTIONS()/COMPILER_VERSION() text, which is inherently tied to the exact compiler invocation and not portable across builds
list(REMOVE_ITEM _sources ${CMAKE_CURRENT_SOURCE_DIR}/28_selectedRealKind_001.f90) # confirmed with real flang: rejects SELECTED_REAL_KIND() called with zero arguments ("missing mandatory 'p=' argument"); gfortran accepts it. Looks like a real flang conformance gap, worth an upstream report
list(REMOVE_ITEM _sources ${CMAKE_CURRENT_SOURCE_DIR}/28_ieeeSelectedRealKind_001.f90) # confirmed with real flang: same zero-argument rejection as 28_selectedRealKind_001, this time for IEEE_SELECTED_REAL_KIND()
list(REMOVE_ITEM _sources ${CMAKE_CURRENT_SOURCE_DIR}/28_bessel_001.f90) # confirmed with real flang: link fails with undefined symbols _j0f/_j1f/_jnf/_y0f. flang's BESSEL_* runtime for REAL(4) calls single-precision libm entry points (the glibc `*f` variants) that do not exist in macOS's libm/libSystem. This is a macOS-platform-specific runtime gap, not expected to reproduce on Linux
list(REMOVE_ITEM _sources ${CMAKE_CURRENT_SOURCE_DIR}/28_constants_003.f90) # confirmed with real flang: link fails with an undefined symbol for iso_fortran_env's CHARACTER_KINDS array (__QMiso_fortran_envECcharacter_kinds). Looks like a real gap in flang's iso_fortran_env implementation, worth an upstream report
list(REMOVE_ITEM _sources ${CMAKE_CURRENT_SOURCE_DIR}/28_bitProcesssing_007.f90) # confirmed with real flang: MASKL(I, KIND) with I > BIT_SIZE(KIND) is genuinely non-deterministic across repeated runs of the same binary (each run prints a different garbage value on that line) - looks like flang reads uninitialized memory for this out-of-range case. Real bug, worth an upstream report; do not just relax the reference_output tolerance for this line

if(NOT RIKEN_HAS_REAL128)
  list(REMOVE_ITEM _sources ${CMAKE_CURRENT_SOURCE_DIR}/28_constants_002.f90) # requires REAL128, not supported by this compiler/platform
endif()

if(_sources)
  set(Source ${_sources})
  llvm_singlesource()

  # Several riken test files reuse the same module name as a sibling
  # test in this directory (e.g. `module m`). llvm_singlesource() builds
  # every source in this directory's shared CMAKE_CURRENT_BINARY_DIR, so
  # without this, parallel builds race on the same .mod file. Give each
  # target its own module directory, mirroring gfortran_make_working_dir()
  # in Fortran/gfortran/CMakeLists.txt.
  foreach(_src ${_sources})
    get_filename_component(_name ${_src} NAME_WE)
    file(MAKE_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/${_name}.mod_dir)
    set_target_properties(${_name} PROPERTIES
      Fortran_MODULE_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/${_name}.mod_dir)
  endforeach()

  file(COPY lit.local.cfg DESTINATION "${CMAKE_CURRENT_BINARY_DIR}")
endif()
