if(VAST_TEST_SUITE_ENABLE)
    message(STATUS "Enabling VAST for SingleSource tests")
    add_compile_options(
        --set-compiler vast-front
    )
    if(NOT VAST_TEST_SUITE_TARGET STREQUAL "bin")
            set(MLIR_TEST_GENERATION ON)
            add_compile_options(
                -vast-emit-mlir=${VAST_TEST_SUITE_TARGET}
            )
    endif()
endif()

add_subdirectory(Benchmarks)
if(NOT TEST_SUITE_BENCHMARKING_ONLY)
  add_subdirectory(UnitTests)
  add_subdirectory(Regression)
endif()

set(MLIR_TEST_GENERATION OFF)

file(COPY lit.local.cfg DESTINATION "${CMAKE_CURRENT_BINARY_DIR}")
