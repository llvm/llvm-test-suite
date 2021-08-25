# We need to include unistd.h because something with Fedora Core 1 is broken,
# and we need the sysconf() macros.
list(APPEND CPPFLAGS -include unistd.h -DSYS_HAS_CALLOC_PROTO -DSYS_HAS_IOCTL_PROTO -DSYS_HAS_TIME_PROTO -DSYS_HAS_READ_PROTO)

if(TARGET_OS STREQUAL "Darwin")
  list(APPEND CPPFLAGS -DSYS_IS_BSD)
  include_directories(${CMAKE_CURRENT_SOURCE_DIR}/stubs)
else()
  list(APPEND CPPFLAGS -DSYS_IS_USG)
endif()

# 254.gap relies on signed arithmetic overflow being well-defined.
LIST(APPEND CFLAGS -fwrapv)

macro(test_input run_type heapsize)
  llvm_test_run(RUN_TYPE ${run_type} WORKDIR %S
    -l data/all/input -q -m ${heapsize}
    < data/${run_type}/input/${run_type}.in
    > ${run_type}.out
  )
  llvm_test_verify(RUN_TYPE ${run_type}
    %b/${FPCMP} -r 0.01 %S/data/${run_type}/output/${run_type}.out %S/${run_type}.out
  )
endmacro()

test_input(ref 192M)
test_input(train 128M)
test_input(test 64M)

llvm_test_executable(254.gap ${Source})
llvm_test_data_spec_default(254.gap)
