# https://www.spec.org/cpu2017/Docs/benchmarks/502.gcc_r.html
include(../../SpecCPU2017.cmake)
if (NOT TEST_SUITE_SPEC2017_ROOT)
  return ()
endif ()

speccpu2017_benchmark(RATE)

add_definitions(-DSPEC_502 -DIN_GCC -DHAVE_CONFIG_H)
speccpu2017_add_include_dirs(. include spec_qsort)
add_compile_options(-fgnu89-inline)

## test ########################################################################

speccpu2017_run_test(
  "${RUN_test_DIR_REL}/t1.c" -O3 -finline-limit=50000 -o t1.opts-O3_-finline-limit_50000.s
  RUN_TYPE test
)

## train #######################################################################

speccpu2017_run_test(
  "${RUN_train_DIR_REL}/200.c" -O3 -finline-limit=50000 -o 200.opts-O3_-finline-limit_50000.s
  RUN_TYPE train
)

speccpu2017_run_test(
  "${RUN_train_DIR_REL}/scilab.c" -O3 -finline-limit=50000 -o scilab.opts-O3_-finline-limit_50000.s
  RUN_TYPE train
)

speccpu2017_run_test(
  "${RUN_train_DIR_REL}/train01.c" -O3 -finline-limit=50000 -o train01.opts-O3_-finline-limit_50000.s
  RUN_TYPE train
)

## ref #########################################################################

speccpu2017_run_test(
  "${RUN_ref_DIR_REL}/gcc-pp.c" -O3 -finline-limit=0 -fif-conversion -fif-conversion2 -o gcc-pp.opts-O3_-finline-limit_0_-fif-conversion_-fif-conversion2.s
  RUN_TYPE ref
  SUITE_TYPE rate
)

speccpu2017_run_test(
  "${RUN_ref_DIR_REL}/gcc-pp.c" -O2 -finline-limit=36000 -fpic -o gcc-pp.opts-O2_-finline-limit_36000_-fpic.s
  RUN_TYPE ref
  SUITE_TYPE rate
)

speccpu2017_run_test(
  "${RUN_ref_DIR_REL}/gcc-smaller.c" -O3 -fipa-pta -o gcc-smaller.opts-O3_-fipa-pta.s
  RUN_TYPE ref
  SUITE_TYPE rate
)

speccpu2017_run_test(
  "${RUN_ref_DIR_REL}/ref32.c" -O5 -o ref32.opts-O5.s
  RUN_TYPE ref
  SUITE_TYPE rate
)

speccpu2017_run_test(
  "${RUN_ref_DIR_REL}/ref32.c" -O3 -fselective-scheduling -fselective-scheduling2 -o ref32.opts-O3_-fselective-scheduling_-fselective-scheduling2.s
  RUN_TYPE ref
  SUITE_TYPE rate
)

################################################################################

speccpu2017_verify_output()
speccpu2017_add_executable(
  main.c
  cc1-checksum.c
  alias.c
  alloca.c
  alloc-pool.c
  argv.c
  attribs.c
  auto-inc-dec.c
  bb-reorder.c
  bid2dpd_dpd2bid.c
  bitmap.c
  bt-load.c
  c-lang.c
  c-errors.c
  c-lex.c
  c-pragma.c
  c-decl.c
  c-typeck.c
  c-convert.c
  c-aux-info.c
  c-common.c
  c-opts.c
  c-format.c
  c-semantics.c
  c-ppoutput.c
  c-objc-common.c
  c-dump.c
  c-parser.c
  c-gimplify.c
  c-pretty-print.c
  c-omp.c
  caller-save.c
  calls.c
  cfg.c
  cfganal.c
  cfgbuild.c
  cfgcleanup.c
  cfgexpand.c
  cfghooks.c
  cfglayout.c
  cfgloop.c
  cfgloopanal.c
  cfgloopmanip.c
  cfgrtl.c
  cgraph.c
  cgraphbuild.c
  cgraphunit.c
  combine.c
  combine-stack-adj.c
  concat.c
  convert.c
  coverage.c
  cp-demangle.c
  cp-demint.c
  cplus-dem.c
  cpp_directives.c
  cpp_lex.c
  cpp_errors.c
  cpp_expr.c
  cpp_charset.c
  cpp_macro.c
  cpp_traditional.c
  cpp_line-map.c
  cpp_symtab.c
  cpp_identifiers.c
  cpp_mkdeps.c
  cpp_pch.c
  cpp_directives-only.c
  crc32.c
  cse.c
  cselib.c
  dbxout.c
  dbgcnt.c
  dce.c
  ddg.c
  debug.c
  decContext.c
  decimal128.c
  decimal32.c
  decimal64.c
  decNumber.c
  df-byte-scan.c
  df-core.c
  df-problems.c
  df-scan.c
  dfp.c
  diagnostic.c
  dojump.c
  dominance.c
  domwalk.c
  double-int.c
  dse.c
  dwarf2asm.c
  dwarf2out.c
  dyn-string.c
  ebitmap.c
  emit-rtl.c
  et-forest.c
  except.c
  explow.c
  expmed.c
  expr.c
  fdmatch.c
  fibheap.c
  filename_cmp.c
  final.c
  fixed-value.c
  floatformat.c
  fold-const.c
  fopen_unlocked.c
  function.c
  fwprop.c
  gcse.c
  genrtl.c
  getopt1.c
  getopt.c
  getpwd.c
  getruntime.c
  ggc-common.c
  ggc-page.c
  gimple.c
  gimple-iterator.c
  gimple-low.c
  gimple-pretty-print.c
  gimplify.c
  graph.c
  graphds.c
  graphite.c
  graphite-blocking.c
  graphite-clast-to-gimple.c
  graphite-dependences.c
  graphite-interchange.c
  graphite-poly.c
  graphite-ppl.c
  graphite-scop-detection.c
  graphite-sese-to-poly.c
  gtype-desc.c
  haifa-sched.c
  hashtab.c
  hex.c
  hooks.c
  host-ieee128.c
  host-ieee32.c
  host-ieee64.c
  host-linux.c
  i386.c
  i386-c.c
  ifcvt.c
  incpath.c
  init-regs.c
  insn-attrtab.c
  insn-automata.c
  insn-emit.c
  insn-extract.c
  insn-modes.c
  insn-opinit.c
  insn-output.c
  insn-peep.c
  insn-preds.c
  insn-recog.c
  integrate.c
  ipa-cp.c
  ipa-inline.c
  ipa-prop.c
  ipa-pure-const.c
  ipa-reference.c
  ipa-struct-reorg.c
  ipa-type-escape.c
  ipa-utils.c
  ipa.c
  ira.c
  ira-build.c
  ira-costs.c
  ira-conflicts.c
  ira-color.c
  ira-emit.c
  ira-lives.c
  jump.c
  lambda-code.c
  lambda-mat.c
  lambda-trans.c
  langhooks.c
  lbasename.c
  lcm.c
  lists.c
  loop-doloop.c
  loop-init.c
  loop-invariant.c
  loop-iv.c
  loop-unroll.c
  loop-unswitch.c
  lower-subreg.c
  lrealpath.c
  lto-cgraph.c
  lto-streamer-in.c
  lto-streamer-out.c
  lto-section-in.c
  lto-section-out.c
  lto-symtab.c
  lto-opts.c
  lto-streamer.c
  lto-wpa-fixup.c
  make-relative-prefix.c
  make-temp-file.c
  partition.c
  matrix-reorg.c
  mcf.c
  md5.c
  mkstemps.c
  mode-switching.c
  modulo-sched.c
  objalloc.c
  obstack.c
  omega.c
  omp-low.c
  optabs.c
  options.c
  opts-common.c
  opts.c
  params.c
  passes.c
  physmem.c
  plugin.c
  pointer-set.c
  postreload-gcse.c
  postreload.c
  predict.c
  pretty-print.c
  print-rtl.c
  print-tree.c
  profile.c
  recog.c
  reg-stack.c
  regcprop.c
  regex.c
  reginfo.c
  regmove.c
  regrename.c
  regstat.c
  reload.c
  reload1.c
  reorg.c
  resource.c
  rtl-error.c
  rtl.c
  rtlanal.c
  rtlhooks.c
  safe-ctype.c
  sbitmap.c
  sched-deps.c
  sched-ebb.c
  sched-rgn.c
  sched-vis.c
  sdbout.c
  sel-sched-ir.c
  sel-sched-dump.c
  sel-sched.c
  sese.c
  sha1.c
  simplify-rtx.c
  sort.c
  spaces.c
  sparseset.c
  splay-tree.c
  sreal.c
  stack-ptr-mod.c
  statistics.c
  stmt.c
  stor-layout.c
  store-motion.c
  stringpool.c
  strsignal.c
  stub-objc.c
  targhooks.c
  timevar.c
  tracer.c
  tree-affine.c
  tree-call-cdce.c
  tree-cfg.c
  tree-cfgcleanup.c
  tree-chrec.c
  tree-complex.c
  tree-data-ref.c
  tree-dfa.c
  tree-dump.c
  tree-eh.c
  tree-if-conv.c
  tree-inline.c
  tree-into-ssa.c
  tree-iterator.c
  tree-loop-distribution.c
  tree-loop-linear.c
  tree-mudflap.c
  tree-nested.c
  tree-nrv.c
  tree-object-size.c
  tree-optimize.c
  tree-outof-ssa.c
  tree-parloops.c
  tree-phinodes.c
  tree-predcom.c
  tree-pretty-print.c
  tree-profile.c
  tree-scalar-evolution.c
  tree-sra.c
  tree-switch-conversion.c
  tree-ssa-address.c
  tree-ssa-alias.c
  tree-ssa-ccp.c
  tree-ssa-coalesce.c
  tree-ssa-copy.c
  tree-ssa-copyrename.c
  tree-ssa-dce.c
  tree-ssa-dom.c
  tree-ssa-dse.c
  tree-ssa-forwprop.c
  tree-ssa-ifcombine.c
  tree-ssa-live.c
  tree-ssa-loop-ch.c
  tree-ssa-loop-im.c
  tree-ssa-loop-ivcanon.c
  tree-ssa-loop-ivopts.c
  tree-ssa-loop-manip.c
  tree-ssa-loop-niter.c
  tree-ssa-loop-prefetch.c
  tree-ssa-loop-unswitch.c
  tree-ssa-loop.c
  tree-ssa-math-opts.c
  tree-ssa-operands.c
  tree-ssa-phiopt.c
  tree-ssa-phiprop.c
  tree-ssa-pre.c
  tree-ssa-propagate.c
  tree-ssa-reassoc.c
  tree-ssa-sccvn.c
  tree-ssa-sink.c
  tree-ssa-structalias.c
  tree-ssa-ter.c
  tree-ssa-threadedge.c
  tree-ssa-threadupdate.c
  tree-ssa-uncprop.c
  tree-ssa.c
  tree-ssanames.c
  tree-stdarg.c
  tree-tailcall.c
  tree-vect-generic.c
  tree-vect-patterns.c
  tree-vect-data-refs.c
  tree-vect-stmts.c
  tree-vect-loop.c
  tree-vect-loop-manip.c
  tree-vect-slp.c
  tree-vectorizer.c
  tree-vrp.c
  tree.c
  unlink-if-ordinary.c
  value-prof.c
  var-tracking.c
  varpool.c
  varasm.c
  varray.c
  vec.c
  vmsdbgout.c
  web.c
  xatexit.c
  xcoffout.c
  xexit.c
  xmalloc.c
  xmemdup.c
  xstrdup.c
  xstrerror.c
  xstrndup.c
  c-cppbuiltin.c
  c-pch.c
  cpp_files.c
  cpp_init.c
  cppdefault.c
  intl.c
  prefix.c
  strerror.c
  toplev.c
  vasprintf.c
  version.c
  builtins.c
  real.c
  mini-gmp.c
  spec_qsort/spec_qsort.c
)

speccpu2017_prepare_rundir()
