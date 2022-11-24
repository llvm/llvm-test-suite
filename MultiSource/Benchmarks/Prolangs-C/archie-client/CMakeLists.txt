include(CheckFunctionExists)
list(APPEND CFLAGS -Wno-implicit-function-declaration)
list(APPEND CXXFLAGS -Wno-implicit-function-declaration)
check_function_exists(re_comp HAVE_RE_COMP)

# archie-client utilizes functions from <netdb.h>. However, since
# _XOPEN_SOURCE=700 is defined globally on AIX, it prevents us from having
# access to some of the functions that are required within archie-client.
# Thus, _XOPEN_SOURCE=600 is defined explicitly for AIX to resolve this issue.
if(TARGET_OS STREQUAL "AIX")
  list(APPEND CFLAGS -D_XOPEN_SOURCE=600)
  list(APPEND CXXFLAGS -D_XOPEN_SOURCE=600)
endif()

if(HAVE_RE_COMP)
  if(TARGET_OS STREQUAL "SunOS")
    list(APPEND LDFLAGS -lsocket -lnsl)
  endif()
  llvm_multisource(archie)
  target_include_directories(archie PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})
endif()
