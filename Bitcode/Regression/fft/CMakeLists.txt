set(NO_REFERENCE_OUTPUT true)
file(GLOB uosources ${CMAKE_CURRENT_SOURCE_DIR}/modules/*.bc)
SET_SOURCE_FILES_PROPERTIES(${uosources} PROPERTIES LANGUAGE CXX)
SET_SOURCE_FILES_PROPERTIES(${CMAKE_CURRENT_SOURCE_DIR}/x86_17.06.19_halide_runtime.bc PROPERTIES LANGUAGE CXX)

list(APPEND LDFLAGS -lpthread -ldl)

set(Source ${CMAKE_CURRENT_SOURCE_DIR}/driver.cpp ${CMAKE_CURRENT_SOURCE_DIR}/x86_17.06.19_halide_runtime.bc ${uosources})
set(PROG fft)
llvm_multisource()


