include(${CMAKE_CURRENT_SOURCE_DIR}/../../DgOptions.txt)

file(COPY lit.local.cfg DESTINATION "${CMAKE_CURRENT_BINARY_DIR}")

add_subdirectory(execute)
