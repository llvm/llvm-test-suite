include(External)
llvm_externals_find(TEST_SUITE_HMMER_ROOT "hmmer" "HMMER 2.3.2")

if(TEST_SUITE_HMMER_ROOT)
  list(APPEND CFLAGS -pthread)
  list(APPEND LDFLAGS -pthread)
  if(ARCH STREQUAL "PowerPC")
    list(APPEND CFLAGS -maltivec)
    list(APPEND LDFLAGS -maltivec)
  endif()
  if(ARCH STREQUAL "x86")
    add_definitions(-DSSE2)
  endif()

  llvm_test_prepare(WORKDIR %S
    cp -f globin.hmm run.hmm
  )
  if(LARGE_PROBLEM_SIZE)
    llvm_test_run(WORKDIR %S
      --fixed 400 --cpu 1 --num 200000 --seed 1158818515 run.hmm
    )
  else()
    llvm_test_run(WORKDIR %S
      --fixed 400 --cpu 1 --num 80000 --seed 1158818515 run.hmm
    )
  endif()
  FILE(GLOB SOURCES ${TEST_SUITE_HMMER_ROOT}/*.c)
  llvm_test_executable(hmmcalibrate ${SOURCES})
  llvm_test_data(hmmcalibrate SOURCE_DIR ${TEST_SUITE_HMMER_ROOT} globin.hmm)
endif()
