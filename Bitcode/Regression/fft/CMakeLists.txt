set(NO_REFERENCE_OUTPUT true)
file(GLOB uosources ${CMAKE_CURRENT_SOURCE_DIR}/modules/*.bc)
SET_SOURCE_FILES_PROPERTIES(${uosources} PROPERTIES LANGUAGE CXX)
SET_SOURCE_FILES_PROPERTIES(${CMAKE_CURRENT_SOURCE_DIR}/x86_17.06.19_halide_runtime.bc PROPERTIES LANGUAGE CXX)

find_package(Threads)
list(APPEND LDFLAGS ${CMAKE_THREAD_LIBS_INIT})
foreach(lib ${CMAKE_DL_LIBS})
  list(APPEND LDFLAGS -l${lib})
endforeach()

llvm_multisource(fft
  ${CMAKE_CURRENT_SOURCE_DIR}/driver.cpp
  ${CMAKE_CURRENT_SOURCE_DIR}/x86_17.06.19_halide_runtime.bc
  ${uosources}
)


