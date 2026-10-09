# XCore, older Darwin version and z/OS do not support thread local storage
if(NOT ARCH STREQUAL "XCore" AND NOT ARCH STREQUAL "Darwin" AND NOT TARGET_OS STREQUAL "OS390")
  list(APPEND LDFLAGS -pthread)
  list(APPEND CFLAGS -pthread)
  llvm_singlesource()
endif()
