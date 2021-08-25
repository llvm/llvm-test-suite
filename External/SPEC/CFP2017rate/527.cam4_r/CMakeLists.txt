# https://www.spec.org/cpu2017/Docs/benchmarks/527.cam4_r.html
include(../../SpecCPU2017.cmake)
if (NOT TEST_SUITE_SPEC2017_ROOT)
  return ()
endif ()

ninja_required()

speccpu2017_benchmark(RATE)

# CAM4 and its validator are complex to build. We break them up into three targets:
# ${PROG} the main binary
# ${VALIDATOR} the validatory binary
# cam4_netcdf an object library for the netcdf sources

macro(cam4_validator)
  # build and run the cam4 test validator, then check
  # cam4_validate.txt to make sure the test pass.
  # cam4 test validate compares NETCDF4 files.
  #
  # the validator for the speed and rate test are the same
  # so we hard code in the location of the binary in the rate
  # directory.
  #
  # ${SPECDIFF_BIN} is used to check that all the test pass in
  # cam4_validate.txt. We replace this with a call to `diff -b` so
  # that SPEC need not be installed. The `-b` is used to ignore
  # extraneous whitespace.
  #
  #
  # There are four arguements to the validator and only the
  # location of the reference data changes. Tolerances
  # and filenames are hard coded.
  cmake_parse_arguments(_carg "" "RUN_TYPE" "" ${ARGN})

  set(VALIDATOR cam4_validate-target_${BENCHMARK_SUITE_TYPE})
  if (NOT TARGET ${VALIDATOR})
    add_executable(${VALIDATOR} "${SRC_DIR}/validate-cam.f90" $<TARGET_OBJECTS:cam4_netcdf>)
  endif ()

  llvm_test_verify(WORKDIR ${RUN_${_carg_RUN_TYPE}_DIR_REL}
    "%S/${VALIDATOR}" 10 0.0035
    "${RUN_${_carg_RUN_TYPE}_DIR_REL}/compare/h0_ctrl.nc" h0.nc >
    "${RUN_${_carg_RUN_TYPE}_DIR_REL}/cam4_validate.txt" &&
    diff -b "${RUN_${_carg_RUN_TYPE}_DIR_REL}/cam4_validate.txt" "${RUN_${_carg_RUN_TYPE}_DIR_REL}/compare/cam4_validate.txt"
    RUN_TYPE ${_carg_RUN_TYPE}
    )
endmacro ()

# Create NETCDF OBJECT library for re-use in main target and validator
if (NOT TARGET cam4_netcdf)
  file(GLOB netcdf_sources "${SRC_DIR}/netcdf/*.c")
  list(APPEND netcdf_sources "${SRC_DIR}/netcdf/typeSizes.f90"
    "${SRC_DIR}/netcdf/netcdf.f90" 
    "${SRC_DIR}/spec_qsort/spec_qsort.c")
  list(REMOVE_ITEM netcdf_sources "${SRC_DIR}/netcdf/ncio.c")

  add_library(cam4_netcdf OBJECT ${netcdf_sources})
  target_compile_definitions(cam4_netcdf PRIVATE SPEC)
endif ()

speccpu2017_add_include_dirs(
  include
  spec_qsort
  netcdf/include
)

# speed test is recompiled due to additional preprocessor flag, but
# the netcdf modules are in the build directory for the rate test
include_directories("${CMAKE_CURRENT_BINARY_DIR}/../../CFP2017rate/527.cam4_r")

set(CAM4_C_DEFS "-DNO_SHR_VMATH;-DCO2A;-DPERGRO")
list(APPEND CAM4_C_DEFS "-DPLON=144;-DPLAT=96;-DPLEV=26;-DPCNST=3;-DPCOLS=4")
list(APPEND CAM4_C_DEFS "-DPTRM=1;-DPTRN=1;-DPTRK=1")
list(APPEND CAM4_C_DEFS "-DSTAGGERED;-D_NETCDF;-DNO_R16;-DSPEC_CASE_FLAG")

add_definitions(${CAM4_C_DEFS})

## test ########################################################################

speccpu2017_run_test(RUN_TYPE test)

cam4_validator(RUN_TYPE test)

## train #######################################################################

speccpu2017_run_test(RUN_TYPE train)

cam4_validator(RUN_TYPE train)

## ref #########################################################################

speccpu2017_run_test(RUN_TYPE ref)

cam4_validator(RUN_TYPE ref)

################################################################################

# *.F90 files are preprocessed with specpp and written to the CMake build
# directory. We only list C sources files and Fortran files that don't
# need to be preprocessed below.

speccpu2017_add_executable(
  GPTLget_memusage.c
  GPTLprint_memusage.c
  GPTLutil.c
  collective.c
  comm.c
  atmos_lib.f90
  mrgrnk.f90
  array_lib.f90
  format_input.f90
  math_lib.f90
  optics_lib.f90
  dsd.f90
  f_wrappers.c
  gases.f90
  get_zeits.c
  gptl.c
  gptl_papi.c
  group.c
  handles.c
  hirsbtpar.f90
  hirsbt.f90
  list.c
  load_hydrometeor_classes.f90
  mpi.c
  pack.c
  radar_simulator.f90
  radar_simulator_types.f90
  recv.c
  req.c
  send.c
  shr_jlcp.c
  shr_vmath_fwrap.c
  threadutil.c
  time.c
  topology.c
  zeff.f90
)

# Preprocess *.F90 with specpp, then add sources to ${PROG}
#
# CAM4 SRC *.f90 and *.F90 both produce modules with interpendencies
# Not possible to make seperate TARGETs that are either all *.f90 or
# all *.F90 because Ninja is then not able to figure out all dependencies.
file(GLOB CAM4_F90_SRCS ${SRC_DIR}/*.F90)

# Written this way intentionally because rate test uses different
# compiler definitions.
if (NOT DEFINED CAM4_SPECPP_DEFS)
  set(CAM4_SPECPP_DEFS ${CAM4_C_DEFS})
else ()
  list(APPEND CAM4_SPECPP_DEFS ${CAM4_C_DEFS})
endif ()


list(APPEND CAM4_SPECPP_DEFS "-DHIDE_MPI;-D_MPISERIAL;-DNO_MPI2")
list(APPEND CAM4_SPECPP_DEFS "-I${SRC_DIR}/include;-I${SRC_DIR}/netcdf/include")
speccpu2017_run_specpp(TARGET ${PROG}
  SRCS ${CAM4_F90_SRCS} DEFS ${CAM4_SPECPP_DEFS})

check_fortran_compiler_flag("-fallow-argument-mismatch" SUPPORTS_FALLOW_ARGUMENT_MISMATCH)
if (SUPPORTS_FALLOW_ARGUMENT_MISMATCH)
  target_compile_options(${PROG} PRIVATE $<$<COMPILE_LANGUAGE:Fortran>:-fallow-argument-mismatch>)
endif ()

target_link_libraries(${PROG} PRIVATE cam4_netcdf)

speccpu2017_prepare_rundir()
