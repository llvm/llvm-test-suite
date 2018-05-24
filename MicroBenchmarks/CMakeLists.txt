file(COPY lit.local.cfg DESTINATION ${CMAKE_CURRENT_BINARY_DIR})

add_subdirectory(libs)
add_subdirectory(XRay)
add_subdirectory(LCALS)
