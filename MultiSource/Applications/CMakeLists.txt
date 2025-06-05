if(NOT TARGET_OS STREQUAL "OpenBSD")
  # [DEV] Disable JM
  # add_subdirectory(JM)
endif()

add_subdirectory(SIBsim4)
add_subdirectory(aha)
add_subdirectory(d)
if(NOT ARCH STREQUAL "PowerPC")
# This test has problems running on powerpc starting with r295538 and should
# be restored when the issue is corrected.
  # [DEV] Disable oggenc
  # add_subdirectory(oggenc)
endif()
add_subdirectory(sgefa)
add_subdirectory(spiff)
add_subdirectory(viterbi)

# [DEV] Disable ALAC
# add_subdirectory(ALAC)
add_subdirectory(hbd)
add_subdirectory(lambda-0.1.3)
add_subdirectory(minisat)
if(NOT TARGET_OS STREQUAL "SunOS")
  add_subdirectory(hexxagon)
endif()
if(NOT DEFINED SMALL_PROBLEM_SIZE)
  # [DEV] Disable lua
  # add_subdirectory(lua)
endif()
if((TARGET_OS STREQUAL "Linux" OR TARGET_OS STREQUAL "Darwin") AND (NOT ARCH STREQUAL "XCore"))
  add_subdirectory(obsequi)
endif()
if(NOT TARGET_OS STREQUAL "SunOS")
  # [DEV] Disable kimwitu++
  # add_subdirectory(kimwitu++)
endif()
if(NOT TARGET_OS STREQUAL "SunOS")
  add_subdirectory(SPASS)
endif()
if(NOT ARCH STREQUAL "XCore")
  # [DEV] Disable ClamAV
  # add_subdirectory(ClamAV)
  add_subdirectory(lemon)
  add_subdirectory(siod)
endif()
if((NOT ARCH STREQUAL "PowerPC") AND (NOT ARCH STREQUAL "XCore"))
  # [DEV] Disable sqlite3
  # add_subdirectory(sqlite3)
endif()
if(NOT TEST_SUITE_BENCHMARKING_ONLY)
  add_subdirectory(Burg)
  add_subdirectory(treecc)
endif()
