# Auto-generated while integrating the riken F2008 test set into the
# CMake-driven test-suite build. `_cNNN` sources are negative/error-case
# tests (expect a compile-time diagnostic); the current llvm_singlesource()
# helper only supports build-and-run tests, so they are excluded here and
# left for follow-up work (see Fortran/riken/README.md).
file(GLOB _sources *.f90)
list(FILTER _sources EXCLUDE REGEX "_c[0-9]+\\.f90$")

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

  llvm_test_data(23_unlimitedFormatItem_004 data.txt)
  llvm_test_data(23_unlimitedFormatItem_005 data.txt)

  file(COPY lit.local.cfg DESTINATION "${CMAKE_CURRENT_BINARY_DIR}")
endif()
