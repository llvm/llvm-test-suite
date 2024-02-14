if(TEST_SUITE_VAST_ENABLE)
    message(STATUS "Enabling VAST for SingleSource tests")
    add_compile_options(
        --set-compiler vast-front
    )
    if(NOT TEST_SUITE_VAST_TARGET STREQUAL "")
            add_compile_options(
                -vast-emit-mlir=${TEST_SUITE_VAST_TARGET}
            )
    endif()
endif()

add_subdirectory(Benchmarks)
if(NOT TEST_SUITE_BENCHMARKING_ONLY)
  add_subdirectory(UnitTests)
  add_subdirectory(Regression)
endif()

file(COPY lit.local.cfg DESTINATION "${CMAKE_CURRENT_BINARY_DIR}")
