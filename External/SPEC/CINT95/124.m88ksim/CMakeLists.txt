include(TestBigEndian)
if(IS_BIGENDIAN)
  set(CTLFILE "ctl.big")
else()
  set(CTLFILE "ctl.lit")
  add_definitions(-DLEHOST)
endif()

set(SourceNames
  addd.c
  adds.c
  alignd.c
  aligns.c
  asm.c
  asmcmdstr.c
  bf.c
  bm.c
  br.c
  bs.c
  ckiob.c
  classify.c
  cm.c
  cmdparser.c
  cmdstruct.c
  cmmu.c
  cmmu_atc.c
  cmmu_cache.c
  cmmu_ctl.c
  cmmu_debug.c
  cmmu_func.c
  cmmu_init.c
  converters.c
  ctlregs.c
  dc.c
  dis.c
  divd.c
  divs.c
  dmem.c
  dpath.c
  fadd.c
  fadd64.c
  fadds.c
  fcdi.c
  fcds.c
  fcid.c
  fcis.c
  fcmp.c
  fcmp64.c
  fcmps.c
  fcsd.c
  fcsi.c
  fdiv.c
  fdiv64.c
  fdivs.c
  floaterr.c
  flt.c
  fmul.c
  fmul64.c
  fmuls.c
  fpunimp.c
  fsub.c
  fsub64.c
  fsubs.c
  go.c
  he.c
  id.c
  instab.c
  int.c
  interface.c
  lo.c
  main.c
  map.c
  md.c
  mem.c
  mm.c
  multd.c
  mults.c
  normalized.c
  normalizes.c
  opn_output.c
  pc.c
  rd.c
  reserved.c
  reserves.c
  returnd.c
  returns.c
  rm.c
  round.c
  roundd.c
  rounds.c
  runsim.c
  sdsr.c
  show.c
  signals.c
  sim_io.c
  sim_printf.c
  simload.c
  simtime.c
  stats.c
  symbols.c
  sysVbcs.c
  sysface.c
  table.c
  trap.c
  updstat.c
)
set(Source "")
foreach(FILENAME ${SourceNames})
  list(APPEND Source ${BENCHMARK_DIR}/src/${FILENAME})
endforeach()

macro(test_input run_type)
  llvm_test_run(RUN_TYPE ${run_type}
    -c < ${BENCHMARK_DIR}/data/${run_type}/input/${CTLFILE}
    > ${CMAKE_CURRENT_BINARY_DIR}/${run_type}.out
    WORKDIR ${BENCHMARK_DIR}/data/${run_type}/input
  )
  llvm_test_verify(RUN_TYPE ${run_type} ${FPCMP}
    ${BENCHMARK_DIR}/data/${run_type}/output/${run_type}.out
    ${CMAKE_CURRENT_BINARY_DIR}/${run_type}.out
  )
endmacro()

test_input(test)
test_input(train)
test_input(ref)

llvm_test_executable(${PROG} ${Source})
