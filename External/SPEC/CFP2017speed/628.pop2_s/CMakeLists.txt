# https://www.spec.org/cpu2017/Docs/benchmarks/628.pop2_s.html
include(../../SpecCPU2017.cmake)
if (NOT TEST_SUITE_SPEC2017_ROOT)
  return ()
endif ()

ninja_required()

speccpu2017_convert_bigendian_required()

speccpu2017_benchmark(SPEED)

macro(pop2_prepare_rundir)
  # Re-use the speccpu2017_prepare_rundir but then implement an input
  # file fix at the end. input file for pop2 is hard-coded to drv_in,
  # but actual filename in SPEC2017 benchmark input directory is
  # drv_in.in. The SPEC perl run script renames the file as well.
  speccpu2017_prepare_rundir()
  foreach (_runtype IN LISTS TEST_SUITE_RUN_TYPE)
    llvm_copy(${PROG} "${RUN_${_runtype}_DIR}/drv_in" "${INPUT_${_runtype}_DIR}/drv_in.in")
  endforeach ()
endmacro()

speccpu2017_add_include_dirs(
  ${CMAKE_CURRENT_BINARY_DIR}
  ${SRC_DIR}
  ${SRC_DIR}/netcdf/include
)

# pop2 has Fortran sources that need to be processed with specpp and C
# sources that do not require it.

# Compiler definitions affect C and *.f90 files, but not *.F90 files.
add_definitions(
  -D_MPISERIAL
  -D_NETCDF
  -D_USEBOX
  -DCCSMCOUPLED=1
  -DNO_SHR_VMATH
  -DBLCKX=50
  -DBLCKY=4
  -DMXBLCKS=58
  -DNO_GETTIMEOFDAY
  -DSPEC_CASE_FLAG
)


## test ########################################################################

speccpu2017_run_test(RUN_TYPE test)

## train #######################################################################

speccpu2017_run_test(RUN_TYPE train)

## ref #########################################################################

speccpu2017_run_test(RUN_TYPE ref)

################################################################################

# SPEC Test has both absolute and relative tolerance with same order
speccpu2017_verify_output(IGNORE_WHITESPACE ABSOLUTE_TOLERANCE 0.03 RELATIVE_TOLERANCE 0.03)

# *.F90 files are preprocessed with specpp and written to the CMake build
# directory. We only list C sources files and Fortran files that don't
# need to be preprocessed below.
speccpu2017_add_executable(
  netcdf/attr.c
  netcdf/dim.c
  netcdf/error.c
  netcdf/fort-attio.c
  netcdf/fort-control.c
  netcdf/fort-dim.c
  netcdf/fort-genatt.c
  netcdf/fort-geninq.c
  netcdf/fort-genvar.c
  netcdf/fort-lib.c
  netcdf/fort-misc.c
  netcdf/fort-v2compat.c
  netcdf/fort-var1io.c
  netcdf/fort-varaio.c
  netcdf/fort-vario.c
  netcdf/fort-varmio.c
  netcdf/fort-varsio.c
  netcdf/libvers.c
  netcdf/nc.c
  netcdf/ncx.c
  netcdf/posixio.c
  netcdf/putget.c
  netcdf/string.c
  netcdf/v1hpg.c
  netcdf/v2i.c
  netcdf/var.c
  netcdf/netcdf.f90
  netcdf/typeSizes.f90
  mpi.c
  send.c
  recv.c
  collective.c
  req.c
  list.c
  handles.c
  comm.c
  group.c
  time.c
  pack.c
  get_zeits.c
  pnetcdfversion.c
  topology.c
  f_wrappers.c
  GPTLget_memusage.c
  GPTLprint_memusage.c
  GPTLutil.c
  shr_jlcp.c
  shr_vmath_fwrap.c
  threadutil.c
)

# Preprocess *.F90 with specpp and add sources to target
file(GLOB POP2_F90_SRCS ${SRC_DIR}/*.F90)
list(REMOVE_ITEM POP2_F90_SRCS ${SRC_DIR}/test.F90)

speccpu2017_run_specpp(TARGET ${PROG}
  SRCS ${POP2_F90_SRCS} DEFS
  -D_MPISERIAL
  -D_NETCDF
  -D_USEBOX
  -DCCSMCOUPLED=1
  -DNO_SHR_VMATH
  -DBLCKX=50
  -DBLCKY=4
  -DMXBLCKS=58
  -DNO_GETTIMEOFDAY
  -I${SRC_DIR}/netcdf/include
)


# Several compiler options below for C and Fortran
set_property(TARGET ${PROG} PROPERTY C_STANDARD 99)

if (SUPPORTS_FALLOW_ARGUMENT_MISMATCH)
  target_compile_options(${PROG} PRIVATE $<$<COMPILE_LANGUAGE:Fortran>:-fallow-argument-mismatch>)
endif ()

if (SUPPORTS_FCONVERT_BIG_ENDIAN) # GCC
  target_compile_options(${PROG} PRIVATE $<$<COMPILE_LANGUAGE:Fortran>:-fconvert=big-endian>)
elseif (SUPPORTS_CONVERT_BIG_ENDIAN) # Intel
  target_compile_options(${PROG} PRIVATE $<$<COMPILE_LANGUAGE:Fortran>:-convert big_endian>)
endif ()

pop2_prepare_rundir()
