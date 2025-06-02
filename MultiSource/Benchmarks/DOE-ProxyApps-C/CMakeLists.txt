# XSBench and RSBench have problems running on CSKY.
# The biggest alignment of CSKY is 4 bytes so that the expected
# Est. Memory Usage is different with reference output.
if(NOT ARCH STREQUAL "CSKY")
  add_subdirectory(XSBench)
  add_subdirectory(RSBench)
endif()
add_subdirectory(Pathfinder)
add_subdirectory(miniAMR)
add_subdirectory(miniGMG)
add_subdirectory(SimpleMOC)
if(NOT CMAKE_SYSTEM_NAME MATCHES "AIX")
add_subdirectory(CoMD)
endif()
