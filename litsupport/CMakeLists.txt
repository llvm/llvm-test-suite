# Copy python files from litsupport to target directory. The idea is that the
# test-suite build directory can be used to run all benchmarks even when the
# source directory is not available.
set(LITSUPPORT_FILES
  __init__.py
  shellcommand.py
  testfile.py
  testplan.py
  test.py
  modules/codesize.py
  modules/compiletime.py
  modules/hash.py
  modules/hpmcount.py
  modules/__init__.py
  modules/microbenchmark.py
  modules/perf.py
  modules/profilegen.py
  modules/remote.py
  modules/run.py
  modules/run_under.py
  modules/stats.py
  modules/timeit.py
  ../lit.cfg
)
set(LITSUPPORT_TARGETS)
foreach(file ${LITSUPPORT_FILES})
  add_custom_command(
    OUTPUT ${CMAKE_CURRENT_BINARY_DIR}/${file}
    COMMAND ${CMAKE_COMMAND} -E copy
      ${CMAKE_CURRENT_SOURCE_DIR}/${file} ${CMAKE_CURRENT_BINARY_DIR}/${file}
    DEPENDS ${file}
  )
  list(APPEND LITSUPPORT_TARGETS ${CMAKE_CURRENT_BINARY_DIR}/${file})
endforeach()
add_custom_target(build-litsupport DEPENDS ${LITSUPPORT_TARGETS})
