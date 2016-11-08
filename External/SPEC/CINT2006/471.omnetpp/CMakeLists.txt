include_directories(
  ${BENCHMARK_DIR}/src
  ${BENCHMARK_DIR}/src/omnet_include
  ${BENCHMARK_DIR}/src/libs/envir
)
set(SourceNames
  eth-index_n.cc
  EtherApp_m.cc
  EtherAppCli.cc
  EtherAppCli_n.cc
  EtherAppSrv.cc
  EtherAppSrv_n.cc
  EtherBus.cc
  EtherBus_n.cc
  EtherCtrl_m.cc
  EtherEncap.cc
  EtherEncap_n.cc
  EtherFrame_m.cc
  EtherHost_n.cc
  EtherHub.cc
  EtherHub_n.cc
  EtherLLC.cc
  EtherLLC_n.cc
  EtherMAC.cc
  EtherMAC_n.cc
  EtherSwitch_n.cc
  LargeNet_n.cc
  libs/cmdenv/cmdenv.cc
  libs/cmdenv/enumstr.cc
  libs/cmdenv/heap.cc
  libs/envir/akoutvectormgr.cc
  libs/envir/args.cc
  libs/envir/cenvir.cc
  libs/envir/cinifile.cc
  libs/envir/filemgrs.cc
  libs/envir/main.cc
  libs/envir/omnetapp.cc
  libs/envir/patmatch.cc
  libs/envir/platdep.cc
  libs/envir/seeds.cc
  libs/envir/slaveapp.cc
  libs/envir/speedmtr.cc
  libs/sim/carray.cc
  libs/sim/cchannel.cc
  libs/sim/ccoroutine.cc
  libs/sim/cdensity.cc
  libs/sim/cdetect.cc
  libs/sim/cdispstr.cc
  libs/sim/cenum.cc
  libs/sim/cexception.cc
  libs/sim/cfsm.cc
  libs/sim/cgate.cc
  libs/sim/chead.cc
  libs/sim/chist.cc
  libs/sim/cksplit.cc
  libs/sim/cllist.cc
  libs/sim/cmessage.cc
  libs/sim/cmodule.cc
  libs/sim/cmsgheap.cc
  libs/sim/cnetmod.cc
  libs/sim/cobject.cc
  libs/sim/coutvect.cc
  libs/sim/cpacket.cc
  libs/sim/cpar.cc
  libs/sim/cpsquare.cc
  libs/sim/cqueue.cc
  libs/sim/csimul.cc
  libs/sim/cstat.cc
  libs/sim/cstruct.cc
  libs/sim/ctopo.cc
  libs/sim/ctypes.cc
  libs/sim/cvarhist.cc
  libs/sim/cwatch.cc
  libs/sim/distrib.cc
  libs/sim/errmsg.cc
  libs/sim/onstartup.cc
  libs/sim/random.cc
  libs/sim/std/netpack.cc
  libs/sim/task.cc
  libs/sim/util.cc
  libs/spec/spec_qsort.cc
  MACAddress.cc
  MACAddress_m.cc
  MACRelayUnit_n.cc
  MACRelayUnitBase.cc
  MACRelayUnitNP.cc
  MACRelayUnitNP_n.cc
  MACRelayUnitPP.cc
  MACRelayUnitPP_n.cc
  Networks_n.cc
  utils.cc
)
set(Source "")
foreach(FILENAME ${SourceNames})
  list(APPEND Source ${BENCHMARK_DIR}/src/${FILENAME})
endforeach()

macro(test_input run_type)
  llvm_test_run(RUN_TYPE ${run_type}
    -f ${BENCHMARK_DIR}/data/${run_type}/input/omnetpp.ini
    > ${CMAKE_CURRENT_BINARY_DIR}/omnetpp.log
    WORKDIR ${CMAKE_CURRENT_BINARY_DIR}
  )
  llvm_test_verify(RUN_TYPE ${run_type} ${FPCMP}
    -r 0.00001 -a 0.000001
    ${BENCHMARK_DIR}/data/${run_type}/output/omnetpp.log
    ${CMAKE_CURRENT_BINARY_DIR}/omnetpp.log
  )
  llvm_test_verify(RUN_TYPE ${run_type} ${FPCMP}
    -r 0.00001 -a 0.000001
    ${BENCHMARK_DIR}/data/${run_type}/output/omnetpp.sca
    ${CMAKE_CURRENT_BINARY_DIR}/omnetpp.sca
  )
endmacro()

test_input(test)
test_input(train)
test_input(ref)

llvm_test_executable(${PROG} ${Source})
