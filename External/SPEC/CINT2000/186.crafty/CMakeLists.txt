if(ARCH STREQUAL "Alpha")
  list(APPEND CPPFLAGS -DALPHA -DLINUX)
elseif(ARCH STREQUAL "PowerPC")
  list(APPEND CPPFLAGS -DLINUX_PPC32)
elseif(ARCH STREQUAL "Sparc")
  list(APPEND CPPFLAGS -DSUN_BSD)
endif()

if(TARGET_OS STREQUAL "Darwin")
  list(APPEND CPPFLAGS -DUNIX -DLINUX)
elseif(TARGET_OS STREQUAL "Linux")
  list(APPEND CPPFLAGS -DUNIX -DLINUX)
endif()

if(ENDIAN STREQUAL "little")
  list(APPEND CPPFLAGS -DLITTLE_ENDIAN_ARCH)
endif()

include(CheckTypeSize)
check_type_size("long" LONG64_TYPE_SIZE BUILTIN_TYPES_ONLY)
if(LONG64_TYPE_SIZE EQUAL 8)
  list(APPEND CPPFLAGS -DLONG_HAS_64BITS)
endif()
check_type_size("long long" LONG_LONG_TYPE_SIZE BUILTIN_TYPES_ONLY)
if(LONG_LONG_TYPE_SIZE GREATER 7)
  list(APPEND CPPFLAGS -DHAS_LONGLONG)
endif()
list(APPEND CFLAGS -fcommon)

set(SourceNames
  attacks.c
  boolean.c
  draw.c
  drawn.c
  edit.c
  enprise.c
  evaluate.c
  history.c
  init.c
  input.c
  interupt.c
  iterate.c
  lookup.c
  main.c
  make.c
  movgen.c
  next.c
  nexte.c
  nextr.c
  option.c
  output.c
  phase.c
  ponder.c
  preeval.c
  quiesce.c
  repeat.c
  resign.c
  root.c
  search.c
  searchr.c
  setboard.c
  store.c
  swap.c
  time.c
  unmake.c
  utility.c
  valid.c
  validate.c
)
set(Source "")
foreach(FILENAME ${SourceNames})
  list(APPEND Source ${BENCHMARK_DIR}/src/${FILENAME})
endforeach()

macro(test_input run_type)
  llvm_test_run(RUN_TYPE ${run_type} WORKDIR %S
    < data/${run_type}/input/crafty.in > crafty.out
  )
  llvm_test_verify(RUN_TYPE ${run_type}
    %b/${FPCMP} %S/data/${run_type}/output/crafty.out %S/crafty.out
  )
endmacro()

test_input(ref)
test_input(train)
test_input(test)

llvm_test_executable(186.crafty ${Source})
llvm_test_data_spec_default(186.crafty)
