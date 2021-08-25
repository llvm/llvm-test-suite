# https://www.spec.org/cpu2017/Docs/benchmarks/521.wrf_r.html
include(../../SpecCPU2017.cmake)
if (NOT TEST_SUITE_SPEC2017_ROOT)
  return ()
endif ()

ninja_required()

speccpu2017_convert_bigendian_required()

speccpu2017_benchmark(RATE)

# WRF and its validator are complex to build. We break them up into four targets:
# ${PROG} the main binary
# ${VALIDATOR} the validatory binary
# wrf_specpp_${BENCHMARK_SUITE_TYPE} an object library for the F90 sources
# that will be processed by specpp and is common to ${PROG} and ${VALIDATOR}
# wrf_netcdf an object library for the netcdf sources

# There is only one argument to the validator. Only the location
# of the reference data changes. Tolerances and filenames are hard
# coded.
#
# ${SPECDIFF_BIN} is used to check that all the test pass in
# diffwrf_output_01.txt. We replace this with a call to `diff -b` so
# that SPEC need not be installed. The `-b` is used to ignore
# extraneous whitespace.
macro(wrf_validator)
  cmake_parse_arguments(_carg "" "RUN_TYPE" "" ${ARGN})

  set(VALIDATOR wrf_validate-target_${BENCHMARK_SUITE_TYPE})
  if (NOT TARGET ${VALIDATOR})
    add_executable(${VALIDATOR} ${SRC_DIR}/c_code.c ${SRC_DIR}/collect_on_comm.c
      ${SRC_DIR}/data.c ${SRC_DIR}/hires_timer.c ${SRC_DIR}/landread.c ${SRC_DIR}/misc.c
      ${SRC_DIR}/my_strtok.c ${SRC_DIR}/pack_utils.c ${SRC_DIR}/period.c
      ${SRC_DIR}/reg_parse.c ${SRC_DIR}/rsl_bcast.c ${SRC_DIR}/symtab_gen.c
      ${SRC_DIR}/task_for_point.c ${SRC_DIR}/type.c ${SRC_DIR}/wrf_num_bytes_between.c
      $<TARGET_OBJECTS:wrf_netcdf> $<TARGET_OBJECTS:wrf_specpp_${BENCHMARK_SUITE_TYPE}>)
  endif ()

  llvm_test_verify(WORKDIR ${RUN_${_carg_RUN_TYPE}_DIR_REL}
    "%S/${VALIDATOR}"
    "${RUN_${_carg_RUN_TYPE}_DIR_REL}/compare/wrf_reference_01"
    wrfout_d01_2000-01-24_14_00_00 >
    "${RUN_${_carg_RUN_TYPE}_DIR_REL}/diffwrf_output_01.txt" &&
    diff -b "${RUN_${_carg_RUN_TYPE}_DIR_REL}/diffwrf_output_01.txt" "${RUN_${_carg_RUN_TYPE}_DIR_REL}/compare/diffwrf_output_01.txt"
    RUN_TYPE ${_carg_RUN_TYPE}
    )
endmacro ()

speccpu2017_add_include_dirs(
  ${SRC_DIR}
  ${SRC_DIR}/netcdf/include
  ${SRC_DIR}/inc

)

# wrf has Fortran sources that need to be processed with specpp and C
# sources that do not require it.

# Compiler definitions affect C and *.f90 files, but not *.F90 files.
add_definitions(
  -DSTUBMPI
  -DSPEC_CASE_FLAG
)

# Create NETCDF OBJECT library for re-use in main target and validator
if (NOT TARGET wrf_netcdf)
  file(GLOB netcdf_sources "${SRC_DIR}/netcdf/*.c")
  list(REMOVE_ITEM netcdf_sources ${SRC_DIR}/netcdf/fort-v2compat.c
  ${SRC_DIR}/netcdf/fort-var1io.c ${SRC_DIR}/netcdf/fort-vario.c
  ${SRC_DIR}/netcdf/fort-varmio.c ${SRC_DIR}/netcdf/varsio.c
  ${SRC_DIR}/netcdf/posixio.c)
  add_library(wrf_netcdf OBJECT ${netcdf_sources})
  target_compile_definitions(wrf_netcdf PRIVATE SPEC_CASE_FLAG)
endif ()

## test ########################################################################

speccpu2017_run_test(RUN_TYPE test)

wrf_validator(RUN_TYPE test)

## train #######################################################################

speccpu2017_run_test(RUN_TYPE train)

wrf_validator(RUN_TYPE train)

## ref #########################################################################

speccpu2017_run_test(RUN_TYPE ref)

wrf_validator(RUN_TYPE ref)

################################################################################



# *.F90 files are preprocessed with specpp and written to the CMake build
# directory. We only list C sources files and Fortran files that don't
# need to be preprocessed below.
speccpu2017_add_executable(
        alloc_2d.c
        apply_bitmap.c
        bobrand.c
        c_code.c
        collect_on_comm.c
        data.c
        flt2ieee.c
        gbyte.c
        get_region_center.c
        grib1_routines.c
        grib_dec.c
        grib_enc.c
        grib_seek.c
        grib_uthin.c
        gribgetbds.c
        gribgetbms.c
        gribgetgds.c
        gribgetpds.c
        gribhdr2file.c
        gribmap.c
        gribputbds.c
        gribputgds.c
        gribputpds.c
        gridnav.c
        hires_timer.c
        init_dec_struct.c
        init_gribhdr.c
        io_int_idx.c
        landread.c
        ld_dec_lookup.c
        ld_grib_origctrs.c
        misc.c
        my_strtok.c
        pack_spatial.c
        pack_utils.c
        period.c
        read_grib.c
        reg_parse.c
        rsl_bcast.c
        set_bytes.c
        setfeenv.c
        symtab_gen.c
        task_for_point.c
        trim.c
        type.c
        upd_child_errmsg.c
        wrf_num_bytes_between.c
)
      
# Preprocess *.F90 with specpp, create target OBJECT library, then
# add sources to OBJECT library.
#
# WRF SRC directory has files that are needed because they are
# functions or routines that are linked into the main binary, but also
# other sources files that need to be compiled due to module
# dependencies. Rather than make an explicit list of everything that
# is needed, we compile all of them except the ones that cause
# link-time issues due to multiply defined functions. There are a few
# sources that are also not Fortran90 compliant, but luckily these
# don't seem to be needed at all (either for .mod or *.o).
file(GLOB WRF_F90_SRCS ${SRC_DIR}/*.F90)
list(REMOVE_ITEM WRF_F90_SRCS
  ${SRC_DIR}/diffwrf.F90 ${SRC_DIR}/wrf.F90 ${SRC_DIR}/nup_em.F90
  ${SRC_DIR}/ndown_em.F90 ${SRC_DIR}/tc_em.F90 ${SRC_DIR}/real_em.F90
  ${SRC_DIR}/f_xpose.F90 ${SRC_DIR}/io_grib1.F90 ${SRC_DIR}/module_wrfsi_static.F90
  ${SRC_DIR}/module_io_int_idx.F90 ${SRC_DIR}/module_random.F90
  ${SRC_DIR}/module_initialize_real.F90)

add_library(wrf_specpp_${BENCHMARK_SUITE_TYPE} OBJECT)

# specpp takes a long list of arguments
set(SPECPP_WRF_DEFS "-m;literal.pm;-I${SRC_DIR}/inc;-I${SRC_DIR}/netcdf/include")
list(APPEND SPECPP_WRF_DEFS "-DDM_PARALLEL;-DEM_CORE=1;-DNMM_CORE=0;-DNMM_MAX_DIM=2600")
list(APPEND SPECPP_WRD_DEFS "-DCOAMPS_CORE=0;-DDA_CORE=0;-DEXP_CORE=0;")
list(APPEND SPECPP_WRF_DEFS "-DIWORDSIZE=4;-DDWORDSIZE=8;-DRWORDSIZE=4;-DLWORDSIZE=4")
list(APPEND SPECPP_WRF_DEFS "-DNETCDF;-DINTIO;-DCONFIG_BUF_LEN=32768;-DMAX_DOMAINS_F=21")
list(APPEND SPECPP_WRF_DEFS "-DNMM_NEST=0;-DMAX_HISTORY=25")
list(APPEND SPECPP_WRF_DEFS "-DSTUBMPI;-DSPEC_NOUNDERSCORE")

# most of the specpp processed sources go into the first target
speccpu2017_run_specpp(TARGET wrf_specpp_${BENCHMARK_SUITE_TYPE}
  SRCS ${WRF_F90_SRCS} DEFS ${SPECPP_WRF_DEFS})

speccpu2017_run_specpp(TARGET ${VALIDATOR}
  SRCS ${SRC_DIR}/diffwrf.F90 DEFS ${SPECPP_WRF_DEFS})

speccpu2017_run_specpp(TARGET ${PROG}
  SRCS ${SRC_DIR}/wrf.F90 DEFS ${SPECPP_WRF_DEFS})

# work around esoteric compiler error, probably the compilation line is too long once the preprocessor
# replaces __FILE__ with the actual filename
set_source_files_properties(${CMAKE_CURRENT_BINARY_DIR}/input_wrf.F90 PROPERTIES COMPILE_DEFINITIONS __FILE__='input_wrf.F90')
set_source_files_properties(${CMAKE_CURRENT_BINARY_DIR}/output_wrf.F90 PROPERTIES COMPILE_DEFINITIONS __FILE__='output_wrf.F90')

if (SUPPORTS_FALLOW_ARGUMENT_MISMATCH)
  target_compile_options(wrf_specpp_${BENCHMARK_SUITE_TYPE} PRIVATE $<$<COMPILE_LANGUAGE:Fortran>:-fallow-argument-mismatch>)
endif ()

# Number of additional flags needed to compile for GCC
check_fortran_compiler_flag("-fallow-invalid-boz" SUPPORTS_FALLOW_INVALID_BOZ)
if (SUPPORTS_FALLOW_INVALID_BOZ) # GCC 10.x
  target_compile_options(wrf_specpp_${BENCHMARK_SUITE_TYPE} PRIVATE $<$<COMPILE_LANGUAGE:Fortran>:-fallow-invalid-boz>)
endif ()
check_fortran_compiler_flag("-fno-range-check" SUPPORTS_FNO_RANGE_CHECK)
if (SUPPORTS_FNO_RANGE_CHECK) # GCC 7.x or later
  target_compile_options(wrf_specpp_${BENCHMARK_SUITE_TYPE} PRIVATE $<$<COMPILE_LANGUAGE:Fortran>:-fno-range-check>)
endif ()

# Compiler flag needed to support IO inputs on little-endian architectures.
# According to the GCC man pages, this is a runtime option.
if (SUPPORTS_FCONVERT_BIG_ENDIAN) # GCC
  target_compile_options(${PROG} PRIVATE $<$<COMPILE_LANGUAGE:Fortran>:-fconvert=big-endian>)
elseif (SUPPORTS_CONVERT_BIG_ENDIAN) # Intel
  target_compile_options(${PROG} PRIVATE $<$<COMPILE_LANGUAGE:Fortran>:-convert big_endian>)
endif ()

target_link_libraries(${PROG} PRIVATE wrf_specpp_${BENCHMARK_SUITE_TYPE} wrf_netcdf)

speccpu2017_prepare_rundir()
