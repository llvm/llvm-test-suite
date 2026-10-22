# Auto-generated while integrating the riken F2008 test set into the
# CMake-driven test-suite build. `_cNNN` sources are negative/error-case
# tests (expect a compile-time diagnostic); the current llvm_singlesource()
# helper only supports build-and-run tests, so they are excluded here and
# left for follow-up work (see Fortran/riken/README.md).
file(GLOB _sources *.f90)
list(FILTER _sources EXCLUDE REGEX "_c[0-9]+\\.f90$")

# Excluded for this integration pass:
list(REMOVE_ITEM _sources ${CMAKE_CURRENT_SOURCE_DIR}/01_submodule_001.f90) # confirmed with real flang: links fail with undefined symbols for the submodule procedures (__QMalphaPsecond/__QMalphaPthird) when the module, both submodules, and the main program all live in one source file. Looks like a real flang bug/limitation in single-file submodule codegen, worth an upstream report

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
