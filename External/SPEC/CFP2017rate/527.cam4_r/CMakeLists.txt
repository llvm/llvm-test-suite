# https://www.spec.org/cpu2017/Docs/benchmarks/527.cam4_r.html
include(../../SpecCPU2017.cmake)
if (NOT TEST_SUITE_SPEC2017_ROOT)
  return ()
endif ()

ninja_required()

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

  set(VALIDATOR cam4_validate-target)
  if (NOT TARGET ${VALIDATOR})
    add_executable(${VALIDATOR} "${SRC_DIR}/validate-cam.f90" $<TARGET_OBJECTS:netcdf>)
  endif ()

  llvm_test_verify(
    cd "${RUN_${_carg_RUN_TYPE}_DIR}" &&
    "${CMAKE_CURRENT_BINARY_DIR}/../../CFP2017rate/527.cam4_r/${VALIDATOR}" 10 0.0035
    "${DATA_${_carg_RUN_TYPE}_DIR}/compare/h0_ctrl.nc" h0.nc >
    "${RUN_${_carg_RUN_TYPE}_DIR}/cam4_validate.txt" &&
    diff -b "${RUN_${_carg_RUN_TYPE}_DIR}/cam4_validate.txt" "${OUTPUT_${_carg_RUN_TYPE}_DIR}/cam4_validate.txt"
    RUN_TYPE ${_carg_RUN_TYPE}
    )
endmacro ()

speccpu2017_benchmark(RATE)

# two binaries (exe,validator) are in the same directory with
# overlapping source and ninja gives a hard error during the depency
# analysis because it leads to duplicate rules for common modules
# modules. Create a OBJECT library from netcdf sources and re-use the
# this target

if (NOT TARGET netcdf)
  file(GLOB netcdf_sources "${SRC_DIR}/netcdf/*.c")
  list(APPEND netcdf_sources "${SRC_DIR}/netcdf/typeSizes.f90"
    "${SRC_DIR}/netcdf/netcdf.f90" 
    "${SRC_DIR}/spec_qsort/spec_qsort.c")
  list(REMOVE_ITEM netcdf_sources "${SRC_DIR}/netcdf/ncio.c")

  add_library(netcdf OBJECT ${netcdf_sources})
  target_compile_definitions(netcdf PRIVATE SPEC)
endif ()

speccpu2017_add_include_dirs(
  include
  spec_qsort
  netcdf/include
)

# speed test is recompiled due to additional preprocessor flag, but
# the netcdf modules are in the build directory for the rate test
include_directories("${CMAKE_CURRENT_BINARY_DIR}/../../CFP2017rate/527.cam4_r")
  
add_definitions(
  -DNO_SHR_VMATH
  -DCO2A
  -DPERGRO
  -DPLON=144
  -DPLAT=96
  -DPLEV=26
  -DPCNST=3
  -DPCOLS=4
  -DPTRM=1
  -DPTRN=1
  -DPTRK=1
  -DSTAGGERED
  -D_NETCDF
  -DNO_R16
  -DHIDE_MPI
  -D_MPISERIAL
  -DNO_MPI2
  -DSPEC_CASE_FLAG
)

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

speccpu2017_add_executable(
  ESMF_BaseMod.F90
  ESMF_BaseTimeMod.F90
  ESMF_FractionMod.F90
  ESMF_CalendarMod.F90
  ESMF_TimeIntervalMod.F90
  ESMF_Stubs.F90
  ESMF_TimeMod.F90
  ESMF_AlarmMod.F90
  ESMF_ClockMod.F90
  ESMF_AlarmClockMod.F90
  ESMF_Mod.F90
  cam_logfile.F90
  debugutilitiesmodule.F90
  decompmodule.F90
  shr_kind_mod.F90
  ghostmodule.F90
  perf_utils.F90
  shr_log_mod.F90
  shr_mpi_mod.F90
  shr_sys_mod.F90
  shr_file_mod.F90
  string_utils.F90
  namelist_utils.F90
  perf_mod.F90
  mod_comm.F90
  parutilitiesmodule.F90
  mpishorthand.F90
  abortutils.F90
  units.F90
  spmd_utils.F90
  fv_control_mod.F90
  pft_module.F90
  dynamics_vars.F90
  FVperf_module.F90
  GPTLget_memusage.c
  GPTLprint_memusage.c
  GPTLutil.c
  MISR_simulator.F90
  Meat.F90
  pmgrid.F90
  dycore.F90
  pio_kinds.F90
  pio_support.F90
  pio_types.F90
  pio_msg_mod.F90
  alloc_mod.F90
  pio_utils.F90
  nf_mod.F90
  pionfput_mod.F90
  pionfatt_mod.F90
  pio_spmd_utils.F90
  calcdisplace_mod.F90
  box_rearrange.F90
  rearrange.F90
  pionfread_mod.F90
  iompi_mod.F90
  pionfwrite_mod.F90
  piodarray.F90
  ionf_mod.F90
  calcdecomp.F90
  pio_mpi_utils.F90
  piolib_mod.F90
  pionfget_mod.F90
  pio.F90
  shr_timer_mod.F90
  shr_string_mod.F90
  shr_const_mod.F90
  shr_cal_mod.F90
  time_manager.F90
  ppgrid.F90
  physconst.F90
  constituents.F90
  commap.F90
  infnan.F90
  pspect.F90
  rgrid.F90
  spmd_dyn.F90
  hycoef.F90
  dyn_grid.F90
  m_chars.F90
  m_flow.F90
  m_stdio.F90
  m_mpif.F90
  m_realkinds.F90
  m_mpif90.F90
  m_dropdead.F90
  m_ioutil.F90
  m_mpout.F90
  m_die.F90
  m_MergeSorts.F90
  phys_grid.F90
  ioFileMod.F90
  cam_history_support.F90
  cam_control_mod.F90
  m_mall.F90
  m_String.F90
  m_rankMerge.F90
  m_IndexBin_logical.F90
  m_Permuter.F90
  m_IndexBin_char.F90
  m_IndexBin_integer.F90
  m_SortingTools.F90
  m_List.F90
  m_TraceBack.F90
  m_AttrVect.F90
  m_GlobalMap.F90
  m_FcComms.F90
  m_MCTWorld.F90
  m_GlobalSegMap.F90
  m_AttrVectComms.F90
  m_SparseMatrix.F90
  m_SparseMatrixDecomp.F90
  m_SparseMatrixComms.F90
  m_Navigator.F90
  m_GlobalToLocal.F90
  m_SparseMatrixToMaps.F90
  m_ConvertMaps.F90
  m_ExchangeMaps.F90
  m_Router.F90
  m_Rearranger.F90
  m_SparseMatrixPlus.F90
  m_GeneralGrid.F90
  m_Transfer.F90
  m_inpak90.F90
  m_GlobalSegMapComms.F90
  m_Accumulator.F90
  m_MatAttrVectMul.F90
  m_GeneralGridComms.F90
  mct_mod.F90
  seq_comm_mct.F90
  seq_drydep_mod.F90
  seq_flds_mod.F90
  seq_io_mod.F90
  cam_pio_utils.F90
  sat_hist.F90
  solar_data.F90
  shr_orb_mod.F90
  shr_tInterp_mod.F90
  shr_stream_mod.F90
  shr_pcdf_mod.F90
  shr_mct_mod.F90
  shr_map_mod.F90
  shr_ncread_mod.F90
  shr_dmodel_mod.F90
  shr_strdata_mod.F90
  shr_scam_mod.F90
  wrap_nf.F90
  scamMod.F90
  error_messages.F90
  interpolate_data.F90
  geopotential.F90
  ref_pres.F90
  phys_control.F90
  physics_types.F90
  time_utils.F90
  repro_sum_mod.F90
  phys_gmean.F90
  mo_constants.F90
  m_types.F90
  mo_flbc.F90
  chem_surfvals.F90
  cam_history_buffers.F90
  filenames.F90
  cosp_share.F90
  interp_mod.F90
  cam_history.F90
  advect_tend.F90
  phys_buffer.F90
  ghg_data.F90
  radconstants.F90
  radae.F90
  quicksort.F90
  radlw.F90
  pkg_cldoptics.F90
  phys_debug_util.F90
  conv_water.F90
  param_cldoptics.F90
  mo_util.F90
  rad_solar_var.F90
  cmparray_mod.F90
  radsw.F90
  phys_prop.F90
  rad_constituents.F90
  wv_saturation.F90
  modal_aer_opt.F90
  aer_rad_props.F90
  camsrfexch_types.F90
  radiation_data.F90
  cosp_constants.F90
  cosp_utils.F90
  radar_simulator_types.f90
  cosp_types.F90
  modis_simulator.F90
  cosp_modis_simulator.F90
  cosp_lidar.F90
  cosp_misr_simulator.F90
  llnl_stats.F90
  lmd_ipsl_stats.F90
  cosp_stats.F90
  atmos_lib.f90
  mrgrnk.f90
  array_lib.f90
  format_input.f90
  math_lib.f90
  optics_lib.f90
  cosp_radar.F90
  cosp_isccp_simulator.F90
  cosp_simulator.F90
  cosp.F90
  cospsimulator_intr.F90
  chemistry.F90
  radheat.F90
  radiation.F90
  horizontal_interpolate.F90
  polar_avg.F90
  tracer_data.F90
  prescribed_ghg.F90
  prescribed_aero.F90
  trb_mtn_stress.F90
  phys_debug.F90
  hb_diff.F90
  upper_bc.F90
  molec_diff.F90
  diffusion_solver.F90
  eddy_diff.F90
  vertical_diffusion.F90
  boundarydata.F90
  cam3_ozone_data.F90
  aoa_tracers.F90
  iondrag.F90
  cam3_aero_data.F90
  tracers_suite.F90
  tracers.F90
  tropopause.F90
  prescribed_volcaero.F90
  prescribed_ozone.F90
  aircraft_emit.F90
  modal_aero_deposition.F90
  aerodep_flx.F90
  advnce.F90
  drydep_mod.F90
  wetdep.F90
  dust_sediment_mod.F90
  dust_intr.F90
  progseasalts_intr.F90
  scyc.F90
  aerosol_intr.F90
  history_scam.F90
  xpavg_mod.F90
  ncdio_atm.F90
  metdata.F90
  co2_data_flux.F90
  co2_cycle.F90
  buffer.F90
  comsrf.F90
  restart_physics.F90
  pfixer.F90
  ctem.F90
  diag_module.F90
  dyn_comp.F90
  dyn_internal_state.F90
  restart_dynamics.F90
  cam_restart.F90
  readinitial.F90
  history_defaults.F90
  error_function.F90
  uw_conv.F90
  uwshcu.F90
  cldwat.F90
  zm_conv.F90
  hk_conv.F90
  convect_shallow.F90
  cloud_fraction.F90
  cldwat2m_macro.F90
  ndrop.F90
  cldwat2m_micro.F90
  microp_aero.F90
  microp_driver.F90
  pkg_cld_sediment.F90
  stratiform.F90
  inidat.F90
  startup_initialconds.F90
  inital.F90
  check_energy.F90
  dp_coupling.F90
  fv_prints.F90
  stepon.F90
  ionosphere.F90
  cloud_diagnostics.F90
  cloud_rad_props.F90
  tidal_diag.F90
  constituent_burden.F90
  cam_diagnostics.F90
  flux_avg.F90
  macrop_driver.F90
  gw_drag.F90
  zm_conv_intr.F90
  convect_deep.F90
  rayleigh_friction.F90
  majorsp_diffusion.F90
  sslt_rebin.F90
  physpkg.F90
  cam_comp.F90
  seq_infodata_mod.F90
  seq_cdata_mod.F90
  runtime_opts.F90
  cam_cpl_indices.F90
  seq_timemgr_mod.F90
  atm_comp_mct.F90
  benergy.F90
  binary_io.F90
  bnddyi.F90
  seq_flds_indices.F90
  seq_diag_mct.F90
  seq_rearr_mod.F90
  map_ocnocn_mct.F90
  mrg_x2s_mct.F90
  ice_comp_mct.F90
  mrg_x2o_mct.F90
  seq_avdata_mod.F90
  seq_hist_mod.F90
  mrg_x2a_mct.F90
  map_iceocn_mct.F90
  seq_map_mod.F90
  map_atmlnd_mct.F90
  map_atmice_mct.F90
  map_snoglc_mct.F90
  map_atmocn_mct.F90
  seq_domain_mct.F90
  seq_rest_mod.F90
  mrg_x2l_mct.F90
  seq_frac_mct.F90
  shr_flux_mod.F90
  seq_flux_mct.F90
  map_lndlnd_mct.F90
  map_iceice_mct.F90
  map_glcglc_mct.F90
  lnd_comp_mct.F90
  ocn_types.F90
  ocn_comp.F90
  ocn_comp_mct.F90
  map_rofrof_mct.F90
  map_atmatm_mct.F90
  map_rofocn_mct.F90
  shr_mem_mod.F90
  map_snosno_mct.F90
  mrg_x2g_mct.F90
  mrg_x2i_mct.F90
  glc_comp_mct.F90
  ccsm_comp_mod.F90
  ccsm_driver.F90
  tp_core.F90
  sw_core.F90
  cd_core.F90
  cldsav.F90
  collective.c
  comm.c
  comspe.F90
  cpslec.F90
  d2a3dijk.F90
  d2a3dikj.F90
  dadadj.F90
  datetime.F90
  diag_dynvar_ic.F90
  mean_module.F90
  dryairm.F90
  dsd.f90
  mapz_module.F90
  epvd.F90
  esinti.F90
  f_wrappers.c
  fft99.F90
  fill_module.F90
  fort.F90
  gases.f90
  gauaw_mod.F90
  geopk.F90
  get_zeits.c
  gffgch.F90
  gptl.c
  gptl_papi.c
  group.c
  handles.c
  hirsbtpar.f90
  hirsbt.f90
  icarus.F90
  initcom.F90
  initindx.F90
  intp_util.F90
  iop_surf.F90
  lidar_simulator.F90
  list.c
  load_hydrometeor_classes.f90
  m_AccumulatorComms.F90
  m_AttrVectReduce.F90
  m_StrTemplate.F90
  m_FileResolv.F90
  m_Filename.F90
  m_Merge.F90
  m_SpatialIntegralV.F90
  m_SpatialIntegral.F90
  m_zeit.F90
  marsaglia.F90
  mcshallow.F90
  pio_quicksort.F90
  mct_rearrange.F90
  miesubs.F90
  mo_msis_ubc.F90
  mo_regrider.F90
  mo_solar_parms.F90
  mpi.c
  msise00.F90
  p_d_adjust.F90
  pack.c
  par_vecsum.F90
  par_xsum.F90
  pf_to_mr.F90
  pio_msg_callbacks.F90
  pio_msg_getput_callbacks.F90
  pio_nf_utils.F90
  pkez.F90
  prec_scops.F90
  puminterfaces.F90
  qneg3.F90
  qneg4.F90
  radar_simulator.f90
  recv.c
  redistributemodule.F90
  req.c
  scops.F90
  send.c
  sgexx.F90
  shr_jlcp.c
  shr_msg_mod.F90
  shr_vmath_fwrap.c
  shr_vmath_mod.F90
  srchutil.F90
  srfxfer.F90
  sulchem.F90
  te_map.F90
  threadutil.c
  time.c
  topology.c
  tphysac.F90
  tphysbc.F90
  tphysidl.F90
  trac2d.F90
  trunc.F90
  tsinti.F90
  uv3s_update.F90
  virtem.F90
  vrtmap.F90
  wrap_mpi.F90
  wrf_error_fatal.F90
  wrf_message.F90
  zeff.f90
  zenith.F90
)

check_fortran_compiler_flag("-fallow-argument-mismatch" SUPPORTS_FALLOW_ARGUMENT_MISMATCH)
if (SUPPORTS_FALLOW_ARGUMENT_MISMATCH)
  target_compile_options(${PROG} PRIVATE $<$<COMPILE_LANGUAGE:Fortran>:-fallow-argument-mismatch>)
endif ()

target_link_libraries(${PROG} PRIVATE netcdf)

speccpu2017_prepare_rundir()
