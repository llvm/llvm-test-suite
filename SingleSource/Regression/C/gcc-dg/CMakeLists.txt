include(${CMAKE_CURRENT_SOURCE_DIR}/../../DgOptions.txt)

set(TestsToSkip)

##
## Main Test Blacklist for Clang
##

# Tests with features unsupported by Clang (usually GCC extensions)
# (Big list of naughty tests)
file(GLOB UnsupportedTests CONFIGURE_DEPENDS
  # skip tests that include dg-error, dg-bogus or other error-checking
  # or gcc emits warning but clang shows error
  dg-test-1.c
  lvalue-6.c
  Wmissing-field-initializers-2.c
  attr-copy.c
  redecl-7.c
  pr64223-2.c
  c2x-typeof-2.c
  Wc99-c11-compat-7.c
  Wstrict-aliasing-bogus-ref-all-2.c
  spellcheck-stdbool.c
  pr101171.c
  pr83373.c
  uninit-pr65244-2.c
  20081223-1.c
  Wrestrict-11.c
  Warray-bounds-18.c
  parse-else-error-3.c
  pr49899.c
  no-asm-3.c
  pointer-arith-4.c
  spellcheck-options-6.c
  anon-struct-15.c
  large-size-array-3.c
  declspec-9.c
  c99-array-lval-1.c
  diag-aka-3.c
  init-bad-3.c
  pr22458-1.c
  c99-idem-qual-2.c
  uninit-pred-7_d.c
  uninit-pr61112.c
  missing-field-init-1.c
  c11-static-assert-8.c
  Warray-bounds-39.c
  va-arg-4.c
  c99-return-1.c
  Wimplicit-function-declaration-c89-default.c
  decl-8.c
  pr13804-1.c
  Wrestrict-8.c
  pr65658.c
  c2x-empty-init-2.c
  builtin-redefine.c
  overflow-warn-2.c
  Wtype-limits-no.c
  pr69819.c
  large-size-array.c
  bitint-32.c
  Warray-bounds-80.c
  pr67580.c
  uninit-27-gimple.c
  pr71514.c
  uninit-pred-8_a.c
  Wtraditional-conversion.c
  cast-lvalue-2.c
  pr99578-3.c
  c2x-attr-deprecated-3.c
  c90-vla-1.c
  Wshadow-compatible-local-1.c
  c11-unproto-1.c
  c99-typespec-1.c
  Wstringop-overflow-65.c
  c99-func-2.c
  pr84853.c
  pr71362.c
  Wunused-var-6.c
  Warray-bounds-20.c
  inline-21.c
  uninit-pred-9_a.c
  c90-idem-qual-2.c
  assign-warn-1.c
  atomic-pr51256.c
  Warray-bounds-77.c
  utf-badconcat2.c
  enum-incomplete-3.c
  gnu89-dupqual-1.c
  20031111-1.c
  wtr-union-init-3.c
  vla-init-2.c
  c99-bool-2.c
  pr17424-1.c
  c2x-old-style-definition-2.c
  assign-warn-3.c
  spellcheck-options-5.c
  20020919-1.c
  pr40946.c
  gnu99-static-1.c
  extra-semi-3.c
  c90-array-lval-4.c
  pr15698-3.c
  pr93582.c
  gnu99-const-expr-1.c
  pr107805-2.c
  attr-access-4.c
  unused-5.c
  stdckdint-2.c
  redecl-4.c
  anon-struct-13.c
  Warray-bounds-21.c
  c11-thread-local-2.c
  c90-complit-2.c
  Warray-bounds-flex-arrays-3.c
  c90-noreturn-1.c
  pr94726.c
  pr20368-3.c
  inline-12.c
  c99-init-2.c
  pr67964.c
  pr107618.c
  pr39323-1.c
  pr69650.c
  Wlogical-op-1.c
  Wstringop-overflow-4.c
  sync-fetch.c
  pr99578-2.c
  pr48524.c
  c11-floatn-2.c
  pr17301-1.c
  divbyzero.c
  driver-specs.c
  spellcheck-transposition.c
  two-types-5.c
  Wstrict-flex-arrays.c
  gnu99-const-expr-3.c
  binary-constants-4.c
  c99-left-shift-3.c
  pr25559.c
  uninit-pred-3_d.c
  pr27528.c
  attr-copy-2.c
  decl-2.c
  Wstringop-overflow-21-novec.c
  init-string-2.c
  pr30949.c
  Wstrict-overflow-24.c
  warn-1.c
  uninit-pred-11.c
  pr93577-1.c
  c99-array-nonobj-1.c
  spellcheck-inttypes.c
  spellcheck-options-15.c
  uninit-pred-8_d.c
  pr81854.c
  darwin-comm-1.c
  c99-static-assert-1.c
  ucnid-7-utf8.c
  attr-unavailable-6.c
  nodfp-1.c
  array-3.c
  pr77521.c
  gimplefe-error-4.c
  wtr-aggr-init-1.c
  ucnid-8.c
  Wzero-length-array-bounds-2.c
  uninit-28-gimple.c
  pr69554-1.c
  bitint-27.c
  cond-constqual-1.c
  c90-return-1.c
  c90-typedef-1.c
  atomic-op-6.c
  comp-goto-3.c
  wcaselabel-1.c
  pr63477.c
  c99-thread-local-1.c
  always_inline.c
  pr65050.c
  diag-aka-2.c
  Wreturn-type2.c
  c99-flex-array-typedef-3.c
  declspec-18.c
  c2x-attr-noreturn-2.c
  march.c
  uninit-1-O0.c
  attr-access.c
  declspec-13.c
  Wstringop-truncation-2.c
  union-3.c
  two-types-10.c
  Winfinite-recursion-3.c
  c90-align-1.c
  uninit-pred-9_b.c
  Wstringop-truncation-4.c
  Warray-bounds-88.c
  pr87600-2.c
  c11-fordecl-1.c
  pr48552-1.c
  pr51034.c
  c90-const-expr-3.c
  uninit-pr65244-1.c
  label-decl-4.c
  declspec-11.c
  intmax_t-1.c
  pure-2.c
  Warray-bounds-27.c
  Wstringop-overflow-51.c
  Wc99-c11-compat-6.c
  c2x-complit-8.c
  inline-5.c
  Warray-bounds-7.c
  m-un-1.c
  c90-restrict-1.c
  const-1.c
  uninit-pred-8_b.c
  c90-idem-qual-3.c
  diagnostic-input-charset-1.c
  pr66066-2.c
  pr36093.c
  20041213-1.c
  pr18596-2.c
  pr56724-1.c
  assign-warn-2.c
  wtypequal.c
  Wsequence-point-pr18050.c
  uninit-30-gimple.c
  c99-vla-jump-1.c
  pr60797.c
  auto-type-2.c
  pr60915.c
  wmain.c
  c90-init-1.c
  pr82112.c
  fixits.c
  Warray-bounds-67.c
  c11-empty-init-1.c
  Wstrict-aliasing-bogus-upcast.c
  vla-init-4.c
  two-types-4.c
  c2x-thread-local-2.c
  c11-atomic-3.c
  .CMakeLists.txt.swp
  stmt-expr-3.c
  funroll-loops-all.c
  pr66618.c
  c99-typedef-1.c
  c99-vla-jump-4.c
  attr-unavailable-4.c
  gnu2x-attrs-1.c
  c2x-qual-5.c
  gimplefe-error-13.c
  attr-aligned-2.c
  asm-scope-1.c
  register-var-3.c
  pr101419.c
  parse-decl-after-label.c
  register-var-2.c
  20031223-1.c
  c11-attr-syntax-1.c
  parse-else-error.c
  nofixed-point-2.c
  pr37261.c
  pr14963.c
  fixits-pr84852-1.c
  c99-main-1.c
  pr61053.c
  Wtype-limits.c
  noreturn-2.c
  builtin-choose-expr-2.c
  20041014-1.c
  decl-3.c
  inline4.c
  pr53265.c
  uninit-pr55060.c
  uninit-10-O0.c
  spellcheck-fields-2.c
  c99-restrict-1.c
  c11-floatn-1.c
  enum-redef-1.c
  c99-vla-jump-3.c
  pr30551-5.c
  pr69483.c
  20040223-1.c
  builtins-28.c
  Werror-10.c
  c99-impl-int-2.c
  attr-assume-2.c
  uninit-A.c
  Warray-bounds-38.c
  pr20368-1.c
  sizeof-1.c
  pr98029.c
  switch-7.c
  pr70859-2.c
  Wdeclaration-after-statement-3.c
  uninit-pr65686.c
  c90-const-expr-11.c
  Warray-bounds-12.c
  Winfinite-recursion-5.c
  c90-array-lval-8.c
  c99-vla-1.c
  c90-array-lval-6.c
  c90-const-expr-6.c
  c99-array-lval-8.c
  Wmissing-field-initializers-3.c
  c99-atomic-1.c
  pr7356-2.c
  20020122-1.c
  c90-typespec-1.c
  Warray-bounds-37.c
  pr98271.c
  bss.c
  gnu2x-stdarg-1.c
  init-excess-3.c
  c90-hexfloat-1.c
  vla-init-5.c
  Wstrict-flex-arrays-3.c
  Wunused-value-2.c
  Wstrict-aliasing-bogus-struct-included.c
  compound-literal-cast-lvalue-1.c
  pr61692.c
  pr80468.c
  Wdangling-pointer-pr106868.c
  c2x-attr-syntax-6.c
  dollar.c
  pr65345-3.c
  diagnostic-range-static-assert.c
  c90-flex-array-1.c
  two-types-7.c
  gnu2x-utf8str.c
  c11-pointer-float-1.c
  spellcheck-options-17.c
  pr30260.c
  Warray-bounds-23.c
  simd-1.c
  old-style-prom-3.c
  switch-2.c
  Wstringop-overflow-63.c
  c11-anon-struct-2.c
  pr35441.c
  Wvla-parameter-13.c
  pr57149.c
  dremf-type-compat-3.c
  Wpointer-arith.c
  Wimplicit-int-2.c
  sync-fetch-bool.c
  c2x-nullptr-3.c
  parser-pr28152.c
  redecl-14.c
  pr51644.c
  c90-func-1.c
  attr-access-3.c
  pr20245-1.c
  pr35445.c
  case-const-3.c
  gimplefe-error-5.c
  c2x-attr-fallthrough-3.c
  c99-const-expr-9.c
  attr-ifunc-2.c
  decl-1.c
  pr13519-1.c
  uninit-4.c
  pr89340.c
  pr108375-2.c
  uninit-3.c
  Wcxx-compat-8.c
  pr29254.c
  two-types-2.c
  pr35440.c
  Wredundant-decls-1.c
  pr30551-4.c
  cast-1.c
  c11-binary-constants-2.c
  uninit-6-O0.c
  Wparentheses-1.c
  gnu99-init-2.c
  Wvla-3.c
  c2x-auto-3.c
  c2x-constexpr-6.c
  Wstringop-overflow-21.c
  compare1.c
  pr35334.c
  pr85045.c
  pr83595.c
  pr55570.c
  floatn-errs.c
  uninit-pred-6_a.c
  missing-field-init-2.c
  c99-tag-1.c
  c90-static-1.c
  c99-flex-array-typedef-5.c
  union-cast-2.c
  pr104506-2.c
  c11-fordecl-2.c
  cast-qual-1.c
  init-desig-obs-1.c
  pr105331.c
  Warray-parameter-6.c
  c11-enum-1.c
  c11-parm-omit-1.c
  pr66618-2.c
  c2x-attr-maybe_unused-3.c
  pr43082.c
  Wmissing-parameter-type-no.c
  Wbuiltin-declaration-mismatch-16.c
  Werror-5.c
  opts-5.c
  pr59827.c
  Werror-1.c
  c99-flex-array-typedef-1.c
  Wrestrict-23.c
  spellcheck-options-11.c
  c90-array-lval-5.c
  pr32370.c
  switch-5.c
  c99-init-6.c
  uninit-18.c
  pr80163.c
  builtin-stringop-chk-9.c
  pr15698-5.c
  label-decl-3.c
  builtin-inf-1.c
  spellcheck-identifiers.c
  pr105149.c
  Warray-bounds-56.c
  uninit-pr89230-1.c
  bitfld-14.c
  pr79983.c
  spellcheck-params-2.c
  c99-flex-array-5.c
  bitint-14.c
  Wint-in-bool-context-4.c
  va-arg-pack-len-2.c
  c99-restrict-3.c
  redecl-5.c
  Wc90-c99-compat-8.c
  c99-idem-qual-3.c
  c2x-attr-maybe_unused-4.c
  typespec-1.c
  c99-tag-2.c
  20011214-1.c
  c90-idem-qual-1.c
  decl-9.c
  pr67784-2.c
  uninit-11-O0.c
  init-undef-1.c
  c2x-attr-noreturn-3.c
  opts-6.c
  pr81795.c
  asm-qual-1.c
  pr52904.c
  nonnull-6.c
  struct-parse-1.c
  noreturn-7.c
  Warray-bounds-flex-arrays-6.c
  spellcheck-options-22.c
  c99-flex-array-2.c
  gimplefe-error-9.c
  declspec-17.c
  attr-assume-3.c
  transparent-union-2.c
  c11-complit-1.c
  c99-idem-qual-1.c
  pr15698-2.c
  ucnid-8-utf8.c
  sequence-pt-1.c
  mtune.c
  cast-pretty-print-1.c
  c2x-enum-3.c
  Wmissing-field-initializers-4.c
  parser-pr28152-2.c
  c2x-attr-nodiscard-3.c
  20001201-1.c
  Wunused-var-4.c
  anon-struct-8.c
  qual-return-9.c
  20031222-1.c
  uninit-H.c
  array-5.c
  pr15236.c
  c2x-enum-4.c
  vla-6.c
  Warray-bounds-16.c
  pr14475.c
  pr61096-2.c
  c2x-thread-local-1.c
  20050620-1.c
  atomic-invalid.c
  vla-19.c
  pr20672-1.c
  two-types-1.c
  auto-init-pr104550-1.c
  vla-init-3.c
  pr57287.c
  lvalue-9.c
  c99-const-expr-2.c
  nested-func-1.c
  builtins-68.c
  pr80776-1.c
  c99-array-lval-6.c
  c99-complex-1.c
  compare8.c
  c99-arraydecl-1.c
  c11-generic-2.c
  spellcheck-options-23.c
  builtin-clear-padding-2.c
  uninit-suppress.c
  pr104506-1.c
  pr79412.c
  attr-unavailable-5.c
  pr36901-4.c
  20030625-1.c
  pr18725.c
  asm-8.c
  pr109412.c
  gnu2x-attr-syntax-2.c
  pr64766.c
  pr36227.c
  c99-vla-jump-5.c
  Wshadow-1.c
  pr11492.c
  pr61096-1.c
  opts-3.c
  bitfld-8.c
  c90-anon-struct-1.c
  c90-dupqual-1.c
  utf-badconcat.c
  Wno-all.c
  nested-func-6.c
  c2x-unproto-1.c
  misc-column.c
  940409-1.c
  nest.c
  encoding-issues-unicode.c
  struct-empty-3.c
  pr51321.c
  Wc90-c99-compat-12.c
  compare9.c
  auto-init-pr102276-2.c
  Warray-parameter-9.c
  c2x-nullptr-6.c
  Wstringop-overflow-19.c
  declspec-5.c
  array-11.c
  c99-tag-4.c
  spellcheck-options-16.c
  pr20368-2.c
  func-outside-2.c
  Wrestrict-9.c
  qual-return-5.c
  cast-2.c
  nonnull-2.c
  Wattributes-10.c
  cast-lvalue-1.c
  pr16194.c
  uninit-5.c
  union-cast-4.c
  pr91134.c
  Wstrict-overflow-26.c
  typedef-init.c
  20040910-1.c
  uninit-1.c
  nofixed-point-1.c
  pr56724-3.c
  init-bad-5.c
  pr18809-1.c
  pr95141.c
  Warray-bounds-59.c
  nested-func-2.c
  init-bad-1.c
  parm-forwdecl-1.c
  warn-strnlen-no-nul.c
  c2x-digit-separators-3.c
  pr79677.c
  pr26632.c
  Wstringop-overflow-72.c
  pr84628.c
  uninit-pred-2_c.c
  qual-component-1.c
  boolcomplex-1.c
  auto-init-pr104550-2.c
  pr97882.c
  init-desig-obs-3.c
  Wswitch-error.c
  Wstringop-overread-6.c
  c99-fordecl-3.c
  pr48062.c
  pr78957.c
  c99-impl-int-1.c
  diagnostic-token-ranges.c
  c99-array-lval-5.c
  gimplefe-error-6.c
  redecl-10.c
  pr93577-5.c
  builtin-protos-1.c
  pr86835.c
  struct-parse-2.c
  uninit-6.c
  bitfld-1.c
  c99-complit-2.c
  spellcheck-options-9.c
  utf8-2.c
  nested-redef-1.c
  pr77323.c
  decl-4.c
  pr61861.c
  pr100834.c
  two-types-8.c
  Warray-bounds-57.c
  Wrestrict-25.c
  stmt-expr-label-2.c
  const-2.c
  Wshadow-local-2.c
  diag-aka-5a.c
  bitfld-22.c
  array-2.c
  mismatch-decl-1.c
  c2x-complit-5.c
  pr96377-1.c
  pr66066-3.c
  declspec-10.c
  struct-semi-3.c
  attr-mode-1.c
  redecl-2.c
  uninit-2.c
  c2x-attr-maybe_unused-2.c
  gnu89-const-expr-2.c
  c99-func-4.c
  pr25801.c
  spellcheck-options-3.c
  compound-literal-1.c
  Wswitch-unreachable-1.c
  spellcheck-params.c
  c99-flex-array-typedef-7.c
  uninit-H-O0.c
  overflow-warn-7.c
  inline-25.c
  fltconst-pedantic-dfp.c
  missing-symbol-3.c
  label-compound-stmt-1.c
  pr44061.c
  pr63626.c
  bitfld-12.c
  gnu2x-enum-1.c
  c99-noreturn-1.c
  pr51721.c
  uninit-pr106155-1.c
  diag-aka-1.c
  pointer-array-atomic.c
  c11-static-assert-4.c
  inline3.c
  initpri2.c
  parm-forwdecl-3.c
  inline-14.c
  c99-impl-decl-1.c
  bitfld-2.c
  c11-labels-3.c
  opts-1.c
  case-bogus-1.c
  vla-25.c
  pr61240.c
  Wreturn-local-addr-9.c
  concat.c
  nested-func-3.c
  setjmp-1.c
  always_inline3.c
  func-args-1.c
  init-bad-9.c
  uninit-B-2.c
  old-style-then-proto-1.c
  Wparentheses-11.c
  pointer-arith-8.c
  Warray-bounds-flex-arrays-5.c
  alias-3.c
  c2x-old-style-definition-6.c
  funcdef-storage-1.c
  pragma-message.c
  pr63877.c
  attr-weakref-5.c
  Werror-7.c
  Warray-bounds-35.c
  pr66066-1.c
  darwin-cfstring-format-1.c
  strict-flex-array-1.c
  empty-source-3.c
  uninit-pr105109.c
  simd-6.c
  attr-vector_size.c
  pragma-diag-4.c
  c99-const-expr-12.c
  c99-anon-struct-1.c
  two-types-3.c
  parse-else-error-4.c
  Warray-bounds-flex-arrays-1.c
  union-duplicate-field.c
  declspec-7.c
  pr93577-2.c
  pr39084.c
  20040920-1.c
  c11-generic-3.c
  diagnostic-input-utf8-bom.c
  pragma-diag-10.c
  attr-assume-4.c
  spellcheck-options-14.c
  pr108043.c
  uninit-pr59970.c
  compare7.c
  declspec-8.c
  multiple-overflow-warn-2.c
  pr96377-5.c
  alias-12.c
  pr30551-2.c
  concat2.c
  opts-7.c
  Wstringop-overflow-39.c
  c99-left-shift-2.c
  attr-section.c
  pure-3.c
  c90-atomic-1.c
  attr-malloc.c
  bitint-15.c
  gnu99-const-expr-4.c
  parse-decl-after-if.c
  Warray-bounds-44.c
  pr23075.c
  Walloc-size-larger-than-16.c
  Wcomplain-wrong-lang-3.c
  Wunused-value-3.c
  c99-flex-array-3.c
  pr94963.c
  c99-const-expr-10.c
  pr90760.c
  enum-const-3.c
  c99-const-expr-14.c
  asm-qual-3.c
  c99-vla-jump-2.c
  attr-access-read-write.c
  c99-const-expr-3.c
  attr-assume_aligned-2.c
  func-args-2.c
  fixits-pr84852-2.c
  pr65345-1.c
  pr110699.c
  diagnostic-range-bad-called-object.c
  pr69900.c
  c11-static-assert-2.c
  c99-const-expr-5.c
  redecl-13.c
  Wuse-after-free-3.c
  pr8788-1.c
  utf-dflt.c
  struct-in-proto-1.c
  diag-aka-4.c
  pr15698-8.c
  uninit-pr20644-O0.c
  20020104-1.c
  c90-array-lval-2.c
  pr48552-2.c
  Warray-bounds-17.c
  bitfld-7.c
  c90-arraydecl-1.c
  parm-mismatch-1.c
  pr27953.c
  pr64417.c
  gimplefe-error-10.c
  sso-5.c
  parse-error-1.c
  redecl-11.c
  pr68320.c
  c11-align-4.c
  20010516-1.c
  Werror-implicit-function-declaration.c
  qual-return-7.c
  pr22231.c
  uninit-pred-10.c
  cast-3.c
  20040322-1.c
  Wcxx-compat-21.c
  two-types-6.c
  inline1.c
  declspec-6.c
  compare2.c
  Wvla-7.c
  builtin-assume-aligned-2.c
  c2x-attr-deprecated-4.c
  asm-6.c
  encoding-issues-bytes.c
  spellcheck-options-19.c
  utf-array.c
  pr15698-4.c
  ucnid-13.c
  c11-align-3.c
  Wattributes-2.c
  uninit-pr61409.c
  c11-align-9.c
  spellcheck-options-24.c
  pr104506-3.c
  no-asm-4.c
  c99-complex-3.c
  gimplefe-error-7.c
  Warray-bounds-42.c
  pointer-arith-1.c
  spellcheck-stdlib.c
  c11-unproto-2.c
  vla-init-1.c
  c2x-no-dfp-1.c
  c90-const-expr-1.c
  pr100547.c
  Wzero-length-array-bounds-3.c
  stmt-expr-label-1.c
  20021014-1.c
  20050209-1.c
  c99-flex-array-7.c
  uninit-pr61869.c
  bconstp-4.c
  c11-noreturn-5.c
  array-9.c
  darwin-cfstring-2.c
  vla-8.c
  Wrestrict-21.c
  anon-struct-5.c
  pr93577-3.c
  pr107805-1.c
  Wstringop-overflow-43.c
  pr93573-1.c
  c99-align-1.c
  readonly-loc.c
  parm-impl-decl-2.c
  bad-dereference.c
  multiple-overflow-warn-3.c
  Wswitch-enum-error.c
  Wstringop-overflow-pr106904.c
  pr59940.c
  register-var-1.c
  simd-4.c
  large-size-array-6.c
  diag-sanity.c
  declspec-4.c
  init-bad-8.c
  auto-init-pr102276-1.c
  pr63748.c
  pr97463.c
  Warray-bounds-13.c
  pr40340-4.c
  c99-tag-3.c
  Warray-bounds-25.c
  c2x-attr-deprecated-2.c
  Wstringop-overflow-61.c
  unordered-1.c
  Wstring-compare-2.c
  redecl-16.c
  call-diag-2.c
  Wvla-larger-than-5.c
  pr89350.c
  visibility-13.c
  Wstringop-overread-3.c
  fltconst-double-pedantic-2.c
  anon-struct-14.c
  uninit-pred-6_b.c
  Wvla-parameter-9.c
  c99-static-1.c
  redecl-18.c
  pr35742.c
  anon-struct-9.c
  bitint-1.c
  c11-stdarg-1.c
  Warray-bounds-11.c
  pr90082.c
  c99-const-expr-8.c
  Wvla-parameter-3.c
  overflow-warn-1.c
  no-asm-2.c
  init-bad-2.c
  c2x-qual-4.c
  attr-access-read-only.c
  c90-const-expr-7.c
  c11-typedef-1.c
  Wfatal-2.c
  vla-18.c
  gnu2x-empty-init-2.c
  pr105676.c
  c2x-concat-1.c
  Wdesignated-init.c
  c11-align-8.c
  c99-array-lval-2.c
  attr-weakref-2.c
  asm-7.c
  Wnonnull-7.c
  c2x-unproto-2.c
  spellcheck-options-4.c
  c90-longlong-1.c
  alias-13.c
  fold-nonneg-1.c
  cleanup-1.c
  pointer-arith-2.c
  gnu-cond-expr-3.c
  pr39464.c
  pr36901-3.c
  Wmissing-field-initializers-1.c
  attr-access-write-only.c
  bitint-21.c
  c11-static-assert-3.c
  comp-goto-6.c
  c2x-attr-fallthrough-2.c
  c99-intconst-2.c
  c2x-enum-7.c
  Werror-11.c
  spellcheck-options-12.c
  c99-const-expr-7.c
  Wfatal.c
  large-size-array-4.c
  spellcheck-typenames.c
  enum3.c
  c2x-digit-separators-2.c
  pr109238.c
  spellcheck-options-7.c
  pr79730.c
  sso-4.c
  redecl-3.c
  pr63549.c
  pr89061.c
  Wshadow-2.c
  Wstringop-overflow-66.c
  Wimplicit-function-declaration-c99-pedantic.c
  pr93573-2.c
  bitfld-11.c
  overflow-warn-4.c
  pr18164.c
  Winfinite-recursion-4.c
  pr30551-3.c
  pr40340-3.c
  pr17188-1.c
  c2x-has-c-attribute-4.c
  atomic-pr81231.c
  parse-error-3.c
  Wvla-parameter-12.c
  spellcheck-options-20.c
  c90-array-lval-7.c
  c2x-static-assert-2.c
  Wstringop-overflow-32.c
  pr64778.c
  pr17730-1.c
  pr67088.c
  Wstringop-truncation-5.c
  940510-1.c
  c2x-old-style-definition-4.c
  c99-init-5.c
  struct-incompl-1.c
  c99-const-expr-11.c
  variable-sized-type-flex-array.c
  c2x-qual-6.c
  simd-1b.c
  auto-init-pr104550-3.c
  Warray-bounds-24.c
  c2x-binary-constants-3.c
  uninit-pr101912.c
  enum-incomplete-1.c
  c99-flex-array-1.c
  Warray-bounds-87.c
  spellcheck-options-10.c
  attr-aligned.c
  bitfld-13.c
  lvalue-4.c
  array-10.c
  pr17301-2.c
  asm-10.c
  Wattributes-8.c
  uninit-pred-4_a.c
  pr15360-1.c
  Wno-pointer-sign.c
  spellcheck-options-2.c
  c99-longlong-1.c
  incomplete-typedef-1.c
  pr14765-1.c
  Wmissing-field-initializers-5.c
  cast-qual-2.c
  c2x-utf8str.c
  Werror-4.c
  enum-compat-1.c
  pr8927-1.c
  spellcheck-stdint.c
  gnu2x-auto-1.c
  bad-binary-ops.c
  array-14.c
  alias-4.c
  switch-A.c
  march-generic.c
  lvalue-8.c
  no-asm-1.c
  c11-floatn-3.c
  pr53532.c
  cond-lvalue-1.c
  pr65901.c
  pr22308-1.c
  c2x-attr-syntax-3.c
  Wstringop-truncation.c
  redecl-25.c
  utf32-4.c
  pr58893.c
  c90-array-lval-3.c
  return-type-2.c
  Wstrict-aliasing-bogus-never-dereferenced.c
  builtin-tgmath-err-1.c
  Wtype-limits-Wextra.c
  pr83620.c
  lvalue1.c
  asm-wide-1.c
  c11-uni-string-2.c
  redecl-21.c
  c90-enum-comma-1.c
  Wbuiltin-declaration-mismatch-11.c
  label-decl-2.c
  pr53196-1.c
  pragma-diag-3.c
  array-12.c
  pointer-array-quals-2.c
  Warray-parameter-2.c
  c90-static-assert-1.c
  Wstringop-overflow-30.c
  c99-hexfloat-1.c
  attr-copy-4.c
  inline-9.c
  pr99990.c
  unclosed-init.c
  Wreturn-local-addr.c
  pr35442.c
  builtin-complex-err-2.c
  compound-lvalue-1.c
  do-empty.c
  20050121-1.c
  Warray-bounds-48.c
  c99-flex-array-typedef-8.c
  c2x-enum-2.c
  attr-unavailable-2.c
  Warray-bounds-14.c
  gimplefe-error-1.c
  gnu89-const-expr-1.c
  c2x-attr-fallthrough-5.c
  c99-array-lval-4.c
  gimplefe-error-14.c
  array-8.c
  ordered-comparison-3.c
  utf-array-short-wchar.c
  cwsc0.c
  uninit-pred-7_a.c
  always_inline2.c
  pr84953.c
  uninit-5-O0.c
  pr100680.c
  c99-arraydecl-3.c
  c90-complit-1.c
  c90-fordecl-1.c
  pr69796.c
  c99-init-3.c
  Wcomplain-wrong-lang-4.c
  uninit-pred-12.c
  gnu99-const-expr-2.c
  uninit-11.c
  Warray-bounds-46.c
  Warray-bounds-15.c
  gimplefe-error-15.c
  union-cast-3.c
  pr36774-1.c
  label-decl-1.c
  spellcheck-fields.c
  c99-arraydecl-2.c
  20051207-3.c
  c90-const-expr-8.c
  enum-incomplete-4.c
  uninit-pred-3_c.c
  pr94436.c
  pr89525.c
  c99-fordecl-2.c
  pr34088.c
  Wstringop-overflow-86.c
  sso-2.c
  pr64223-1.c
  spellcheck-options-1.c
  pr108375-1.c
  uninit-3-O0.c
  c90-const-expr-9.c
  Wstring-compare.c
  c11-floatn-4.c
  noreturn-1.c
  compare3.c
  gimplefe-error-11.c
  pr84721.c
  c90-complex-1.c
  proto-1.c
  pragma-diag-2.c
  long-long-typespec-1.c
  simd-2.c
  stmt-expr-label-3.c
  attr-unavailable-1.c
  trunc-1.c
  pointer-array-quals-1.c
  cast-function-1.c
  Wstringop-truncation-3.c
  builtins-error.c
  pr88568.c
  Wfree-nonheap-object.c
  pr105175.c
  old-style-param-1.c
  uninit-8.c
  pr69627.c
  call-diag-1.c
  c90-thread-local-1.c
  gnu90-const-expr-1.c
  c2x-unproto-4.c
  pr69974.c
  c2x-utf8char-3.c
  setjmp-5.c
  c99-const-expr-6.c
  funcdef-var-1.c
  pr53196-2.c
  redecl-22.c
  pr27428-1.c
  Walloca-2.c
  large-size-array-5.c
  noreturn-6.c
  pr57287-2.c
  atomic-fetch-bool.c
  uninit-pred-3_a.c
  pr56989.c
  pr37561.c
  Wstrict-aliasing-bogus-const-ptr-nonconst-ptr.c
  attr-alloc_align-2.c
  uninit-9-O0.c
  attr-alias-5.c
  c99-compare-incomplete-2.c
  pr29521-2.c
  asm-qual-2.c
  pr67432.c
  init-empty-3.c
  pr36997.c
  spellcheck-fields-3.c
  declspec-1.c
  c2x-attr-nodiscard-2.c
  redecl-19.c
  pr97932.c
  typedef-var-2.c
  pr87309.c
  funcdef-var-2.c
  c11-typeof-3.c
  pr68090.c
  pr41842.c
  pr87811.c
  spellcheck-options-8.c
  sso-1.c
  uninit-A-O0.c
  inline5.c
  redecl-1.c
  pr54355.c
  c2x-constexpr-9.c
  Wcomplain-wrong-lang-5.c
  uninit-pr101494.c
  pr54113.c
  pr68533.c
  pr43211.c
  lvalue-3.c
  Wstringop-overflow-34.c
  c11-enum-4.c
  pr64709.c
  vla-11.c
  pr28419.c
  decl-nospec-3.c
  pr87811-2.c
  pr15698-7.c
  array-7.c
  pr105080.c
  comp-goto-5.c
  uninit-pr107839.c
  c2x-stdarg-3.c
  anon-struct-11.c
  Wrestrict-15.c
  attr-error-1.c
  store_merging_12.c
  c99-left-shift-1.c
  for-1.c
  pr42611.c
  uninit-9.c
  pr45079.c
  attr-aligned-3.c
  darwin-aligned-globals.c
  two-types-9.c
  parm-incomplete-1.c
  sso-3.c
  pr93577-6.c
  utf-dflt2.c
  uninit-pred-6_c.c
  builtin-complex-err-1.c
  c90-mixdecl-1.c
  pr45750.c
  c90-const-expr-5.c
  c2x-attr-syntax-7.c
  Warray-bounds-flex-arrays-4.c
  pr99578-1.c
  pr53037-4.c
  20030612-2.c
  Warray-bounds-61.c
  c99-hexfloat-3.c
  Wrestrict-18.c
  gimplefe-error-2.c
  spellcheck-identifiers-4.c
  redecl-8.c
  pr94705.c
  pr97955.c
  c90-const-expr-2.c
  pr18596-3.c
  builtin-arith-overflow-4.c
  20011021-1.c
  pragma-diag-7.c
  990506-0.c
  uninit-pr78295.c
  builtin-constant_p-1.c
  pr63543.c
  Wuse-after-free-pr109123.c
  addr_builtin-1.c
  stack-usage-2.c
  pr65228.c
  pr80776-2.c
  pr91195.c
  qual-return-3.c
  Werror-13.c
  pr94968.c
  ivdep.c
  init-string-1.c
  Wuse-after-free-pr109170.c
  redecl-23.c
  gimplefe-error-12.c
  uninit-pred-2_a.c
  darwin-cfstring-1.c
  pr24293.c
  spellcheck-options-18.c
  Wstringop-overflow-10.c
  multiple-overflow-warn-1.c
  pr84095.c
  Warray-bounds-flex-arrays-2.c
  decl-10.c
  pointer-arith-3.c
  Wstringop-truncation-8.c
  spellcheck-options-13.c
  c2x-constexpr-3.c
  uninit-10.c
  uninit-21.c
  missing-symbol-2.c
  bitfld-10.c
  ucnid-13-utf8.c
  Wdangling-pointer-4.c
  large-size-array-2.c
  Wdouble-promotion.c
  uninit-pred-6_d.c
  unused-9.c
  c99-complex-2.c
  c2x-constexpr-7.c
  binary-constants-3.c
  uninit-24.c
  pr107787.c
  ifelse-1.c
  pr37529.c
  uninit-pred-6_e.c
  pr62294.c
  uninit-B-O0-2.c
  pr84772.c
  redecl-20.c
  pr18596-1.c
  pr96377-3.c
  fltconst-1.c
  c2x-attr-fallthrough-6.c
  simd-5.c
  pr101172.c
  pr21419.c
  pr40989.c
  Wstringop-overflow-41.c
  pr84100.c
  va-arg-2.c
  array-const-3.c
  uninit-pr65178.c
  enum-mode-1.c
  c2x-static-assert-4.c
  pragma-diag-1.c
  pr109409.c
  switch-3.c
  asm-1.c
  pr35635.c
  c90-const-expr-10.c
  uninit-pred-8_c.c
  spellcheck-pr83056.c
  vla-20.c
  lvalue-2.c
  reg-vol-struct-1.c
  uninit-2-O0.c
  pr29736.c
  gimplefe-error-8.c
  c11-align-5.c
  c90-array-lval-1.c
  uninit-4-O0.c
  ucnid-7.c
  uninit-8-O0.c
  va-arg-pack-1.c
  c90-impl-decl-1.c
  c99-dupqual-1.c
  spellcheck-options-21.c
  param-type-mismatch.c
  Warray-bounds-4.c
  unused-6-no.c
  init-bad-4.c
  pr35443.c
  Wstrict-flex-arrays-2.c
  redecl-24.c
  Werror-6.c
  pr61162-2.c
  Werror-12.c
  c99-bool-1.c
  c11-anon-struct-3.c
  pr7356.c
  Wuse-after-free.c
  parse-else-error-2.c
  pr37772.c
  float-range-2.c
  declspec-3-no.c
  c2x-attr-syntax-5.c
  c99-flex-array-typedef-2.c
  overflow-warn-3.c
  pr56980.c
  Warray-bounds-79.c
  utf16-4.c
  array-15.c
  Wincompatible-pointer-types-1.c
  attr-unavailable-3.c
  uninit-pred-5_a.c
  c11-noreturn-3.c
  sizeof-2.c
  redecl-12.c
  c17-nullptr-2.c
  bitfld-21.c
  diag-aka-5b.c
  pr93577-4.c
  lvalue-7.c
  atomic-param.c
  pr43783.c
  uninit-pr63660.c
  pr35746.c
  uninit-pr81782.c
  pr36774-2.c
  uninit-pred-4_b.c
  gnu11-typeof-4.c
  parse-error-2.c
  Warray-bounds-26.c
  gimplefe-error-3.c
  comp-return-1.c
  pr34965.c
  Warray-bounds-47.c
  20030626-1.c
  pr70859.c
  builtin-tgmath-err-2.c
  Walloca-16.c
  Wrestrict-4.c
  Wattributes-6.c
  Wbuiltin-declaration-mismatch-12.c
  Wmissing-braces-fixits.c
  Wrestrict-19.c
  Wvla-larger-than-3.c
  atomic-invalid-2.c
  attr-alloc_align-4.c
  attr-alloc_size-12.c
  attr-assume_aligned-4.c
  attr-weakref-3.c
  attr-weakref-4.c
  bad-pragma-locations.c
  builtin-prefetch-1.c
  c11-atomic-4.c
  c11-complit-2.c
  c11-atomic-1.c
  c99-fordecl-2.c
  c99-fordecl-3.c
  c11-stdarg-2.c
  c11-stdarg-3.c
  pr102009.c
  c2x-fordecl-3.c
  declspec-15.c
  declspec-16.c
  fltconst-double-pedantic-1.c
  dll-9.c
  inline-11.c
  inline-8.c
  init-excess-1.c
  parm-forwdecl-2.c
  parm-impl-decl-1.c
  parm-impl-decl-3.c
  pr100791.c
  pr105140.c
  pr105635.c
  pr105853.c
  pr19984.c
  pr29521.c
  pr30551-6.c
  pr30551.c
  pr35899.c
  pr37645.c
  pr56167.c
  pr56724-2.c
  pr61077.c
  pr67730.c
  pr79788-1.c
  pr79788-2.c
  pr87483.c
  pr89410-2.c
  pr90648.c
  pr98198.c
  pr99136.c
  pr99323-2.c
  predict-1.c
  profile-info-section.c
  redecl-15.c
  struct-semi-4.c
  visibility-7.c
  warn-nsstring.c
  winline-10.c
  attr-alloc_size.c
  pr99323-1.c
  c11-fordecl-3.c
  init-bad-6.c
  

  # cannot cust 0 to nullptr_t
  c2x-nullptr-1.c
  
  # qualifer not lost by ternary (pre C2x)
  c11-qual-1.c

  # undefined fenv functions (library issue?)
  bitint-29.c
  bitint-30.c
  pr95115.c
  pr110755.c

  ### BOOL_MAX not defined BOOL_WIDTH != 1
  c2x-bool-limits-1.c
  # __float80/128 is not supported on this target
  const-float128-ped.c
  const-float80-ped.c
  # "CR_DECIMAL_DIG not defined"
  cr-decimal-dig-3.c

  # pragma GCC
  associative-math-1.c
  associative-math-2.c

  # pragma init & fini
  pragma-init-fini.c

  # Skip darwin only test
  darwin-minversion-2.c
  darwin-20040812-1.c
  darwin-minversion-3.c
  darwin-comm.c
  darwin-minversion-4.c
  darwin-ld-1.c
  darwin-minversion-5.c
  darwin-ld-20040809-1.c
  darwin-minversion-6.c
  darwin-ld-20040809-2.c
  darwin-minversion-7.c
  darwin-ld-20040828-1.c
  darwin-minversion-8.c
  darwin-ld-20040828-2.c
  darwin-minversion-9.c
  darwin-ld-20040828-3.c
  darwin-minversion-link.c
  darwin-ld-2.c
  darwin-sections.c
  darwin-ld-3.c
  darwin-segaddr.c
  darwin-ld-4.c
  darwin-version-1.c
  darwin-ld-5.c
  darwin-weakimport-1.c
  darwin-minversion-10.c
  darwin-weakimport-2.c
  darwin-minversion-11.c
  darwin-weakimport-3.c
  darwin-minversion-12.c
  darwin-weakref-1.c
  darwin-minversion-1.c
  attr-weakref-1-darwin.c
  framework-1.c
  framework-2.c

  # Skip solaris2 only test
  c99-math-long-double-1.c
  c99-math-double-1.c
  c99-math-float-1.c

  # bad return type
  20030906-1.c
  20030906-2.c
  diagnostic-range-bad-return.c

  # Clang not support vector size not an integral multiple of component size
  vshift-7.c

  # GCC Extension: Nested functions
  20011130-1.c
  20030331-2.c
  20031218-2.c
  20031218-3.c
  20050607-1.c
  cleanup-7.c
  inline-28.c
  inline-29.c
  inline-30.c
  nested-func-4.c
  nested-func-5.c
  nested-func-7.c
  nested-func-8.c
  nested-func-9.c
  nested-func-10.c
  nested-func-11.c
  nested-func-12.c
  Wswitch-unreachable-2.c
  Wunused-local-typedefs.c
  non-local-goto-1.c
  non-local-goto-2.c
  wtr-func-def-1.c
  trampoline-1.c
  pr23547.c
  pr30045.c
  pr49994-1.c
  pr59011.c
  pr59920-3.c
  pr18963-1.c
  pr79255.c
  pr89342.c
  pr94780.c
  pr79494.c
  pr89045.c
  Wshadow-4.c
  Wtrampolines.c
  Wunused-var-1.c
  attr-externally-visible-2.c
  pr94842.c
  nested-vla-2.c
  nested-vla-3.c
  pr102273.c
  pr105972.c
  pr106421.c
  pr106465.c
  qual-return-8.c

  # Variable length arrays in structs
  20050527-1.c
  packed-vla.c
  pr19345.c
  pr27301.c
  pr30189.c
  pr33238.c
  pr47766.c
  pr51990-2.c
  pr83844.c
  vla-2.c
  vla-22.c
  pr51990.c
  pr34457-1.c
  pr51628-18.c
  pr51628-19.c
  Wstringop-overflow-15.c
  Warray-bounds-50.c
  Wrestrict.c
  Wrestrict-17.c
  Warray-bounds-51-novec.c
  Warray-bounds-51.c
  Warray-bounds-22.c
  Wrestrict-24.c
  builtin-clear-padding-1.c
  builtin-dynamic-object-size-0.c
  nested-vla-1.c
  pr109450-1.c
  pr109450-2.c
  pr70418.c
  pr99122-1.c
  pr99122-2.c
  pr99122-3.c
  typename-vla-3.c
  typename-vla-4.c
  typename-vla-6.c
  vla-stexp-1.c
  vla-stexp-2.c
  vla-stexp-5.c
  vla-stexp-8.c
  typename-vla-5.c

  # GCC Extension: __builtin_*
  pr28796-1.c
  pr28796-2.c
  pr29215.c
  pr32041.c
  pr38338.c
  pr44539.c
  pr46251.c
  pr48826.c
  pr49994-3.c
  pr50251.c
  pr52691.c
  pr61773.c
  pr62090.c
  pr62090-2.c
  pr64252.c
  pr71478.c
  pr78768.c
  pr78775.c
  pr78902.c
  pr78973-2.c
  pr79538.c
  pr79715.c
  pr80020.c
  pr81650.c
  pr82123.c
  pr82274-2.c
  pr82916.c
  pr83198.c
  pr84068.c
  pr84503-1.c
  pr85414.c
  pr85512.c
  pr87024.c
  pr87490.c
  pr89435.c
  pr89521-2.c
  pr89795.c
  pr90037.c
  pr90898.c
  pr91014.c
  pr91069.c
  pr93376.c
  pr93412.c
  pr93430.c
  pr93986.c
  pr94189.c
  sibcall-6.c
  predict-16.c
  nextafter-1.c
  nextafter-2.c
  nextafter-3.c
  nextafter-4.c
  strlenopt-83.c
  strlenopt-84.c
  strlenopt-85.c
  strlenopt-86.c
  Walloca-3.c
  Walloca-4.c
  Walloca-8.c
  Walloca-9.c
  Walloca-10.c
  Walloc-size-larger-than.c
  Walloc-size-larger-than-1.c
  Walloc-size-larger-than-2.c
  Walloc-size-larger-than-3.c
  Walloc-size-larger-than-4.c
  Walloc-size-larger-than-5.c
  Walloc-size-larger-than-6.c
  Walloc-size-larger-than-7.c
  Walloc-size-larger-than-8.c
  Walloc-size-larger-than-9.c
  Walloc-size-larger-than-10.c
  Walloc-size-larger-than-11.c
  Walloc-size-larger-than-12.c
  Walloc-size-larger-than-13.c
  Walloc-size-larger-than-14.c
  Walloc-size-larger-than-15.c
  Walloc-size-larger-than-17.c
  Wc90-c99-compat-4.c
  Wstringop-overflow-22.c
  Wmissing-attributes.c
  Wstringop-overflow-28.c
  va-arg-pack-2.c
  va-arg-pack-len-1.c
  fold-bcopy.c
  attr-copy-6.c
  attr-copy-7.c
  attr-copy-8.c
  builtin-has-attribute.c
  builtin-return-1.c
  gnu2x-builtins-no-dfp-1.c
  builtin-apply4.c
  builtins-43.c
  builtins-44.c
  builtin-apply1.c
  builtin-apply2.c
  builtin-apply3.c
  builtin-apply4.c
  20001117-1.c
  20031002-1.c
  attr-alloc_size-6.c
  attr-alloc_size-7.c
  attr-alloc_size-8.c
  attr-alloc_size-9.c
  builtin-alloc-size.c
  builtin-stringop-chk-5.c
  builtin-stringop-chk-8.c
  Wstringop-truncation-6.c
  spec-barrier-3.c
  builtins-12.c
  builtins-55.c
  builtins-57.c
  fold-convround-1.c
  pr84503-2.c
  webizer.c
  builtin-tgmath-1.c
  builtin-tgmath-2.c
  builtin-tgmath-3.c
  Wbuiltin-declaration-mismatch-3.c
  nonnull-3.c
  fold-perm.c
  Wunused-var-3.c
  builtins-nonnull.c
  builtins-1.c
  pr89520-2.c
  strlenopt-42.c
  string-opt-1.c
  pr89520-1.c
  builtins-45.c
  builtins-85.c
  builtins-59.c
  builtins-60.c
  pr68474.c
  pr54346.c
  pr100239.c
  pr102897.c
  pr105591.c
  pr104389.c

  # GCC Ext: __attribute__((__vector_size__))
  pr106063.c
  pr109230.c
  pr109583.c
  pr96377-4.c
  pr96377-6.c
  vshift-6.c

  # GCC Ext: __attribute__ scalar_storage_order
  sso-17.c

  
  # clang doesn't guarantee tail calls for self calls
  sibcall-*.c

  # semicolon in function args
  pr109970.c

  # __builtin_clz redefined with a different type
  pr100521.c
  pr100790.c

  # 1st 2 args of  '__builtin_shufflevector' must have the same type
  pr100887.c
  pr101294.c

  # Skip the test case that need ${srcdir} defined by GCC scripts
  pr33919.c

  # Test cases need gnu99 extension
  vla-12.c
  vla-14.c
  vla-15.c
  pragma-align-2.c
  pr56078.c
  Wc99-c11-compat-4.c
  Wparentheses-10.c
  fltconst-2.c
  gnu99-init-1.c
  inline-7.c
  noreturn-5.c
  pr18502-1.c
  utf-inc-init.c
  utf-type.c
  utf16-1.c
  utf16-2.c
  utf16-3.c
  utf32-1.c
  utf32-2.c
  utf32-3.c
  utf-cvt.c
  binary-constants-1.c
  dll-7.c

  # Test cases need gnu89 extension
  20040203-1.c
  anon-struct-3.c
  inline-6.c
  gnu89-init-1.c
  gnu89-init-2.c
  gnu89-init-3.c
  gnu89-init-4.c
  dll-6.c
  fail_always_inline2.c

  # Test case need gnu90 extension
  Wc90-c99-compat-5.c
  Wc90-c99-compat-7.c

  # Test case need gnu11 extension
  gnu11-*.c

  # Test case need gnu2x extension
  gnu2x-*.c
  bitint-12.c
  bitint-17.c
  bitint-28.c

  # GCC ext __typeof_unqual__
  c11-typeof-2.c


  # Skip the test case need scan gcc's MD pattern
  old-style-asm-1.c

  # Skip the test cases need gcc's marco, __GCC_IEC_559
  iec-559-macros-1.c
  iec-559-macros-2.c
  iec-559-macros-3.c
  iec-559-macros-4.c
  iec-559-macros-5.c
  iec-559-macros-6.c
  iec-559-macros-7.c
  iec-559-macros-8.c
  iec-559-macros-9.c
  c99-predef-1.c
  
  # malloc attribute with arguments
  Wmismatched-dealloc.c
  Wmismatched-dealloc-2.c
  Wmismatched-dealloc-3.c

  # clang doesn't support declaration and } after goto label
  c11-labels-1.c
  c11-labels-2.c
  c2x-labels-*.c
  pr100349.c
  

  # clang doesn't support comma in preprocessor define
  bitint-31.c

  # preprocessor version macros __STDC_VERSION* not defined
  c2x-has-c-attribute-2.c
  c2x-limits-1.c
  c2x-stdarg-5.c
  c2x-stdatomic-1.c
  c2x-stddef-1.c
  c2x-stdint-1.c

  # __NO_SIGNED_ZEROS__ not defined
  no-signed-zeros-*.c

  # __NO_TRAPPING_MATH__ not defined
  no-trapping-math-*.c

  # "__RECIPROCAL_MATH__ not defined"
  reciprocal-math-*.c

  # __ROUNDING_MATH__ not defined
  rounding-math-*.c

  # GCC --help=X
  opts-8.c

  # C2x UTF-8 string not unsigned char *
  c2x-utf8str-type.c

  # clang has incomplete C2x typeof implementation
  c2x-typeof-1.c

  # clang does not support unsigned bitfields
  bitfld-9.c

  # Clang won't define __NO_MATH_ERRNO__ marco, when using
  # -fno-math-errno or -fmath-errno or -ffast-math.
  no-math-errno-1.c
  no-math-errno-2.c
  no-math-errno-3.c
  no-math-errno-4.c

  # Clang not support GNU decimal type extension
  pr105173.c
  pr105263.c
  pr107686.c
  pr105376.c
  pr96370.c
  pr96579.c
  pr98099.c
  pr57371-5.c

  # Clang can support -fleading-underscore option
  unwind-1.c

  # gcov tests
  gcov-info-to-gcda.c
  # gimple tests
  gimplefe-*.c
  pr109732.c
  pr81192.c
  pr95582.c
  pr98211.c
  gimplefe-10.c
  gimplefe-11.c
  gimplefe-12.c
  gimplefe-13.c
  gimplefe-14.c
  gimplefe-15.c
  gimplefe-16.c
  gimplefe-17.c
  gimplefe-18.c
  gimplefe-19.c
  gimplefe-1.c
  gimplefe-20.c
  gimplefe-21.c
  gimplefe-22.c
  gimplefe-23.c
  gimplefe-24.c
  gimplefe-25.c
  gimplefe-26.c
  gimplefe-27.c
  gimplefe-28.c
  gimplefe-29.c
  gimplefe-2.c
  gimplefe-30.c
  gimplefe-31.c
  gimplefe-32.c
  gimplefe-33.c
  gimplefe-34.c
  gimplefe-35.c
  gimplefe-36.c
  gimplefe-37.c
  gimplefe-38.c
  gimplefe-39.c
  gimplefe-3.c
  gimplefe-42.c
  gimplefe-43.c
  gimplefe-44.c
  gimplefe-4.c
  gimplefe-5.c
  gimplefe-6.c
  gimplefe-7.c
  gimplefe-8.c
  gimplefe-9.c
  uninit-25-gimple.c
  uninit-29-gimple.c
  uninit-31-gimple.c
  uninit-pr90394-1-gimple.c
  pr80170.c
  pr90726.c
  pr93820-2.c

  # Clang not support fold non-constant strlen relational expressions
  strlenopt-81.c

  # clang does not support c2x constexpr
  c2x-constexpr-1.c
  c2x-constexpr-2a.c
  c2x-constexpr-2b.c
  c2x-constexpr-4.c
  c2x-constexpr-5.c
  c2x-constexpr-8.c
  bitint-2.c

  # Using C2X features in C11
  c11-complit-3.c
  c11-floatn-5.c
  c11-floatn-6.c
  c11-floatn-8.c


  # clang doesn't support c2x storage class specifiers
  c2x-complit-*.c

  # C2x enumeration
  c2x-enum-*.c

  # C2x __STDC_VERSION_*
  c2x-float-13.c

  # C2x INFINITY/NAN not in float.h
  c2x-float-2.c
  c2x-float-3.c
  c2x-float-4.c
  c2x-float-5.c

  # FLT/DBL_IS_IEC_60559 / FLT/DBL_SNAN
  c2x-float-10.c
  c2x-float-6.c
  c2x-float-7a.c
  c2x-float-7b.c
  c2x-float-7c.c
  
  
  # gnu::asume
  attr-assume-1.c

  # Clang not support "IBM1047" codeset
  strlenopt-56.c
  c2x-utf8char-2.c

  # Clang not support iso-8859-* codeset
  ucnid-9-utf8.c
  utf8-1.c
  ucnid-9.c
  ucnid-5.c

  # Clang not support -finput-charset=latin1
  ucnid-16-utf8.c

  # Clang not support -fallow-parameterless-variadic-functions
  va-arg-5.c
  c2x-stdarg-1.c
  c2x-stdarg-2.c

  # stddef.h not included
  c2x-nullptr-5.c

  # Clang didn't define INTX_WIDTH in clang/lib/Headers/stdint.h
  stdint-width-1.c
  stdint-width-2.c

  # Clang didn't define INT_FAST16_MIN in clang/lib/Headers/stdint.h
  c99-stdint-7.c

  # Clang didn't define CHAR_WIDTH in clang/lib/Headers/limit.h
  limits-width-1.c
  limits-width-2.c

  # Clang not support -fsso-struct=
  sso-6.c
  sso-7.c
  sso-8.c
  sso-10.c

  # Clang not support for vector enum type
  pr87286.c

  # Clang not support _Atomic qualifier syntax properly yet
  Warray-bounds-90.c
  typeof-2.c
  pr65345-2.c
  Wtype-limits2.c
  Wstringop-overflow-77.c
  Wstringop-overflow-78.c
  bitint-18.c
  c2x-qual-7.c
  lvalue-11.c

  # Clang not support --specs=
  spec-options.c

  # Clang not allow dwo section contain any relocations.
  # dwo section will be created for split dwarf debut section.
  pr79342.c
  pr86064.c
  pr86459.c

  # Clang not support apply restrict type qualifier with typedef
  c99-restrict-2.c

  # GCC expect to show warning when -fprofile-use with no profile files,
  # but Clang will show error.
  pr51957-1.c
  pr80747.c
  pr40209.c
  Wmissing-profile.c
  pr32773.c

  # GCC expect -Wno-c11-c2x-compat could disable warning message,
  # but Clang will show error.
  c11-attr-syntax-3.c

  # GCc expect builtin math function could to constant folding
  # but clang can't do it now.
  builtins-32.c

  # Clang not support initializer element is a compile-time constant
  Wc90-c99-compat-6.c
  c11-complex-1.c
  fold-reassoc-3.c
  pr14649-1.c
  pr36901-1.c
  pr36901-2.c
  pr55019.c
  pr83801.c

  # Clang not support non-ASCII characters outside of literals and identifiers
  ucnid-5-utf8.c
  ucnid-15-utf8.c

  # Clang not support -fprofile-generate -fprofile-use in the same command
  # line
  pr26570.c

  # Clang not support __attribute__((no_reorder) attribute
  noreorder.c
  noreorder2.c
  noreorder4.c

  # clang does not support __attribuite__((alias(...))) on typedef
  attr-alias-4.c

  # Clang not allow probability argument to __builtin_expect_with_probability
  # outside the range [0.0, 1.0]
  pr87811-3.c

  # Clang not support __FLT128_MAX__
  pr88074-2.c

  # Clang can't not detect address of vector element defined by typedef
  pr85376.c
  fold-cvect.c

  # Clang not support 'd' on floating constant 
  # https://github.com/Unidata/netcdf-c/issues/811
  pr79574-2.c
  Wunsuffixed-float-constants-1.c

  # Clang will expect second parameter of 'main' (argument array) must
  # be of type 'char **'
  pr78582.c
  pr83415.c

  # Clang will treat _setjmp as builtin instead of the declaration in
  # the test case
  pr71084.c

  # Clang syntax error of static_assert
  pr61817-1.c
  pr61817-2.c
  c11-static-assert-1.c
  c11-static-assert-5.c
  c11-static-assert-6.c
  c11-static-assert-7.c
  c11-static-assert-9.c
  c11-static-assert-10.c

  # Clang will define nan as builtin functions
  builtins-35.c

  # Clang will not define __SIG_ATOMIC_TYPE__
  c99-stdint-5.c

  # Clang not support parameter references not allowed in naked functions
  pr44290-1.c

  # Clang will show integer literal is too large to be represented in any
  # integer type error message
  pr82765.c

  # GCC expect that function could be removed by compile time # but clang can't
  builtins-10.c
  builtins-11.c
  builtins-18.c
  builtins-19.c
  builtins-20.c
  builtins-26.c
  builtins-27.c
  builtins-31.c
  builtins-41.c
  builtins-52.c
  builtins-54.c
  builtins-65.c
  builtin-bswap-12.c
  pr102950.c
  pr42461.c
  20050121-2.c

  # Clang not support _FloatX
  float128-align.c
  float32x-align.c
  floatn-arithconv.c
  float128-typeof.c
  float32x-typeof.c
  float128x-align.c
  float64-align.c
  float-range-1.c
  float128x-typeof.c
  float64-typeof.c
  float-range-3.c
  float16-align.c
  float64x-align.c
  float-range-4.c
  float16-typeof.c
  float64x-typeof.c
  float-range-5.c
  float32-align.c
  float-exact-1.c
  float32-typeof.c
  bitint-35.c
  c2x-floatn-*.c
  pr104511.c
  pr105211.c
  pr105250.c
  pr107967-1.c
  pr107967-2.c
  pr107967-3.c

  # '-fsignaling-nans' is not supported
  pr105414.c

  # Clang not support some GNU inline asm syntax
  Woverlength-strings-pedantic-c89-asm.c
  Woverlength-strings-pedantic-c90-asm.c
  Woverlength-strings-pedantic-c99-asm.c
  builtin-unreachable-1.c
  asm-2.c
  asm-3.c
  asm-4.c
  asm-a.c
  pr44290-2.c
  asm-pr24146.c

  # Clang will generate __muloti4 which only contain in compiler-rt
  # not in libgcc
  pr82274-1.c

  # Clang will need profiling library libclang_rt.profile-riscv64.a
  # from compiler-rt
  pr48770.c
  20020201-1.c
  profile-generate-1.c
  profile-generate-2.c
  profile-generate-3.c

  # Clang not support the argument of __builtin_assume_aligned is variable
  builtin-assume-aligned-1.c

  # clang does not support '__builtin_clear_padding 
  bitint-16.c

  # __builtin_bswap128 not defined
  builtin-bswap-11.c

  #  builtin functions must be directly called
  builtin-dynamic-object-size-19.c
  pr59630.c
  pr69156.c
  pr98330.c

  # Clang not support u8 identifier
  c2x-utf8char-1.c

  # Clang not support GCC mcount profiling
  pr43643.c
  pr32450.c
  aru-2.c

  # Clang not support -fno-keep-inline-dllexport
  dll-10.c
  dll-11.c
  dll-12.c

  # Clang required weakref declaration must also have an alias attribute
  attr-weakref-1.c

  # Clang has differrent builtin argument type for __atomic_is_lock_free
  atomic-noinline.c
  atomic-noinline-aux.c
  atomic-lockfree.c
  atomic-lockfree-aux.c

  # Clang have different behavior of __builtin_object_size and
  # __builtin_offsetof
  builtin-object-size-*.c
  builtin-dynamic-object-size-*.c
  pr101836*.c
  strict-flex-array-3.c

  # Clang not support GNU "cleanup" attribute
  cleanup-5.c
  cleanup-8.c
  cleanup-9.c
  cleanup-10.c
  cleanup-11.c
  cleanup-12.c
  cleanup-13.c

  # Clang not support GNU parameter forward declarations
  parm-forwdecl-4.c

  # Clang not support define the function name already is clang's builtin
  atomic-generic.c
  atomic-generic-aux.c

  # Some macros won't define by Clang
  c2x-float-1.c
  builtin-arith-overflow-3.c
  c99-stdint-6.c
  c99-stdint-7.c
  c99-stdint-8.c
  cr-decimal-dig-1.c
  c90-float-1.c

  # Clang not support -fplan9-extensions
  anon-struct-12.c

  # Clang not support -fpermitted-flt-eval-methods
  fpermitted-flt-eval-methods_1.c
  fpermitted-flt-eval-methods_2.c
  fpermitted-flt-eval-methods_3.c
  fpermitted-flt-eval-methods_4.c

  # Clang not support get address with _Alignas
  c11-align-7.c

  # Clang not allow __attribute__((alloc_size(n))) with function of no
  # arguments
  attr-alloc_size-2.c

  # Clang not support __float80
  const-float80.c

  # Ignore the case because LLVM could not determine __builtin_constant_p(x)
  # at compile time in this case.
  # __builtin_constant_p (x) will return 1 if x could determine as constant
  # at compile time.
  addr_equal-1.c

  # Clang preprocessor have different behavior
  c90-hexfloat-2.c

  # Clang not support -fstack-protector-explicit
  stackprotectexplicit1.c

  # Clang not support GNU ifunc attribute
  attr-ifunc-1.c
  attr-ifunc-3.c
  attr-ifunc-4.c
  attr-ifunc-5.c

  # attributes between extern and type
  c2x-align-1.c

  # attribute cannot be applied to a statement
  c2x-attr-maybe_unused-1.c
  c2x-attr-syntax-2.c

  # clang does not support C2x type inference
  c2x-auto-*.c

  # clang does not support C2x Storage-class specifiers for compound literals
  c2x-complit-*.c
  gnu2x-complit-*.c


  # C2x removal of for declation restriction, not supported by clang
  c2x-fordecl-1.c


  # Skip mingw/cygwin only tests
  bf-ms-attrib.c

  # In the following case, it seems that clang will take ptr alias to &b
  # according to the asm line, but GCC think they are not alias
  #
  # int *b;
  # int main() {
  #   float **ptr;
  #   asm ("":"=r"(ptr):"0"(&b));
  #   b=NULL;
  #   *ptr=(float*)(size_t)1;
  #   if (b)
  #     __builtin_abort ();
  #   return 0;
  # }
  alias-14.c

  # If there are only weak symbol functions with the same name in each compile
  # unit, GCC expect to pick the function within the same compile unit
  # But Clang didn't. Clang will assert abort() in localalias-2.c:tt()
  localalias.c
  localalias-2.c

  # GCC expect the sign of foo (0.0 / -5.0, 10) in the test case will change
  # with the flag -fvariable-expansion-in-unroller. But clang doesn't support
  # the flag.
  pr30957-1.c

  # GCC has -fexcess-precision=standard as a way to force well-defined
  # precision for cast and assignment operations. But clang doesn't support
  # the flag.
  pr61441.c

  # The floating multiplication in the test case may geneate negative zeros.
  # With the -fno-signed-zeros flag, GCC will eliminate the signed zeros
  # But clang won't which make the floating zero comparison return false
  pr88598-3.c

  # The test case compile with -Ofast will enable -fno-signed-zeros.
  # GCC will eliminate the negative zores. But clang won't.
  sinatan-1.c

  # Clang not support some GNU openmp syntax
  pr88071.c

  # Disable the time consuming test cases.
  memcmp-1.c
  pr59605-2.c

  # Infinite loops are UB in C11
  pr78185.c


  # -INT_MIN is undefined behaviour
  signbit-6.c

  # Clang-15 no support old style definition
  c2x-old-style-definition-*.c
  Wold-style-definition-2.c

  # Skip h8300 target test
  kpice1.c


  # skip tests that include subfolders not ported yet
  pr81588.c
  pr77664.c
  pr81621.c
  pr84225.c
  pr86979.c
  pr88676.c
  
  # These tests require effective target `sync_int_128_runtime`. But
  # infact, there is no backend in GCC that provides this target
  # requirement, therefore we should always skip them.
  atomic-compare-exchange-5.c
  atomic-load-5.c
  atomic-store-5.c
  atomic-store-6.c
  atomic-op-5.c

  # Clang doesn't support the `p` asm constraint
  pr58805.c

  # This test uses inline assembly, but doesn't restrict itself to a
  # specific backend. Unlike GCC, Clangs `asm` implementation cares
  # about the actual instruction inside the quotes, so we would have
  # to port it to every possible backend.
  pr43564.c

  # We don't support the GNU BitInt decimal type
  bitint-10.c

  # Attempt to declare a global register variable
  pr34351.c
  pr57104.c

  # -m32 specific
  attr-ms_struct-1.c
  attr-ms_struct-2.c

  # Weird architectures only
  bf-spl1.c

  # Something to do with neted functions
  cwsc1.c

  # LLVM expects us to mark variables as volatile if we want to
    re-read them after longjmp'ing back
  setjmp-3.c
  setjmp-4.c
)

list(APPEND TestsToSkip ${UnsupportedTests})

# Tests where clang currently has bugs or issues
file(GLOB FailingTests CONFIGURE_DEPENDS
  pr59992.c
  pr78547.c
  pr89314.c
  pr87985.c
  pr85180.c
  strlenopt-55.c
  stack-check-16.c
  c99-intconst-1.c
  transparent-union-6.c
  20020425-1.c
  Wnonnull-2.c
  Wnonnull-3.c

  # Temporary skip LTO test cases until we enabled the feature
  pr30762-1.c
  pr31529-1.c
  pr43157.c
  pr34668-1.c
  pr43557-1.c
  initpri3.c
  pr97172-2.c

  # "foo" == __func__ optimized to true
  c99-func-3.c

  # clang crashes
  pr105094.c
  vla-stexp-4.c
  vla-stexp-6.c
  vla-stexp-7.c
)
list(APPEND TestsToSkip ${FailingTests})

# RISC-V Test Blacklist
if(ARCH MATCHES "riscv")
  file(GLOB RISCVTestsToSkip CONFIGURE_DEPENDS
    # No backend support for __builtin_longjmp/__builtin_setjmp
    setjmp-2.c
    setjmp-3.c
    setjmp-4.c
    setjmp-6.c
    pr26983.c
    pr56727-2.c
    Winfinite-recursion.c
    Winfinite-recursion-2.c
    pr101156.c

    # RISCV target not support split stack
    split-1.c
    split-2.c
    split-3.c
    split-4.c
    split-5.c
    split-6.c
    split-7.c
    split-8.c
    pr79499.c
    pr84300.c

    # The test cases for several backends but not for riscv
    pr31866.c
    pr89313.c
    pr87600-1.c
    20020103-1.c
    bf-spl1.c

    # Support clz only when Zbb extension enabled
    pr43564.c

    # RISCV not support -fsanitize=thread yet
    pr55702.c
    pr57104.c

    # RISCV not support -fstack-protector yet
    ssp-1.c
    ssp-2.c

    # Invalid output constraint for RISCV
    pr58805.c

    # PIE not default enabled
    pie-5.c

    # RISCV not support atomic operations on "int_128" values
    atomic-store-6.c
    atomic-compare-exchange-5.c
    atomic-op-5.c

    # RISCV not support __float128
    const-float128.c

    # RISCV not support atomic operation with width 1 and 2.
    atomic-exchange-1.c
    atomic-exchange-2.c
    atomic-op-1.c
    atomic-op-2.c
    atomic-compare-exchange-1.c
    atomic-compare-exchange-2.c

    # RISCV not support c99 tgmath.
    c99-tgmath-1.c
    c99-tgmath-2.c
    c99-tgmath-3.c
    c99-tgmath-4.c

    # RISCV does not support `__bf16`
    pr107262.c
  )

  if (LIBC MATCHES "musl")
    file(GLOB TestsToSkipForMuslLibc
      # Musl defines some things that this disallows
      c99-float-1.c

      # No memcpy_chk
      strlenopt-2f.c
      strlenopt-14gf.c

      # PIE defined
      pie-6.c
      20020312-2.c

      # Not support issignaling
      pr59833.c
    )
    list(APPEND TestsToSkip ${TestsToSkipForMuslLibc})
  endif()

  if (ARCH MATCHES "riscv32")
    file(GLOB RISCV32TestsToSkip CONFIGURE_DEPENDS
      # No support for __int128 on rv32
      pr67029.c
      pr68835-1.c
      pr68835-2.c
      pr69535.c
      pr69896.c
      pr70219.c
      pr70326.c
      pr76783.c
      pr78526.c
      pr78540.c
      pr78547.c
      pr78575.c
      pr78644-1.c
      pr78644-2.c
      pr81281-3.c
      pr82274-1.c
      pr82274-2.c
      pr83424.c
      pr84068.c
      pr84614.c
      pr84670-1.c
      pr85195.c
      pr85257.c
      pr85376.c
      pr85412.c
      pr85414.c
      pr85467.c
      pr87047.c
      pr87054.c
      pr87874.c
      pr88563.c
      pr88594.c
      pr89037.c
      pr91860-4.c
      pr93210.c
      pr93376.c
      pr93412.c
      wide-shift-128.c
      atomic-exchange-5.c
      pr64807.c


      # No support for __atomic_exchange_8 on rv32
      atomic-exchange-4.c
      di-longlong64-sync-1.c
      di-sync-multithread.c
      atomic-compare-exchange-4.c
      atomic-load-4.c
      atomic-store-4.c
      atomic-op-4.c

      # Array too large
      pr82389.c
    )

    list(APPEND RISCVTestsToSkip ${RISCV32TestsToSkip})
  endif()

  list(APPEND TestsToSkip ${RISCVTestsToSkip})
endif()

# x86-only Tests
if(NOT ARCH MATCHES "x86")
  file(GLOB X86OnlyTests CONFIGURE_DEPENDS
    zero_bits_compound-1.c
    zero_bits_compound-2.c
    wrapped-binop-simplify.c
    visibility-11.c
    asm-b.c
    union-5.c
    pr56990.c
    pr59020.c
    pr34351.c
    pr85388-1.c
    pr85388-2.c
    pr85388-3.c
    pr85388-4.c
    pr85388-5.c
    pr85388-6.c
    profile-update-warning.c
    atomic-store-5.c
    atomic-load-5.c
    attr-ms_struct-1.c
    attr-ms_struct-2.c
    macro-fusion-1.c
    macro-fusion-2.c
    bf-ms-layout.c
    bf-ms-layout-4.c
  )

  list(APPEND TestsToSkip ${X86OnlyTests})
endif()

# arm-only Tests
if(NOT ARCH MATCHES "arm")
  file(GLOB armOnlyTests CONFIGURE_DEPENDS
    pr94269.c
    pr106621.c
  )

  list(APPEND TestsToSkip ${armOnlyTests})
endif()

# aarch64-only Tests
if(NOT ARCH MATCHES "aarch64")
  file(GLOB aarch64OnlyTests CONFIGURE_DEPENDS
    pr94784.c
  )

  list(APPEND TestsToSkip ${aarch64OnlyTests})
endif()

# mips-only Tests
if(NOT ARCH MATCHES "mips")
  file(GLOB mipsOnlyTests CONFIGURE_DEPENDS
    delay-slot-1.c
  )

  list(APPEND TestsToSkip ${mipsOnlyTests})
endif()

# powerpc-only Tests
if(NOT ARCH MATCHES "powerpc")
  file(GLOB POWERPCOnlyTests CONFIGURE_DEPENDS
    var-expand3.c
  )

  list(APPEND TestsToSkip ${POWERPCOnlyTests})
endif()

# mmix-only Tests
if(NOT ARCH MATCHES "mmix")
  file(GLOB mmixOnlyTests CONFIGURE_DEPENDS
    mmix-1.c
  )

  list(APPEND TestsToSkip ${mmixOnlyTests})
endif()

# Skip the test cases non-supported for non-linux targets
if (NOT CMAKE_SYSTEM_NAME MATCHES "Linux")
  file(GLOB TestsToSkipForNonLinux
    struct-ret-3.c
    20050826-1.c
    20030711-1.c
    strncmp-2.c
    di-sync-multithread.c
    atomic-exchange-5.c
    pr55430.c
    pr59833.c
    pr65408.c
    pr78185.c
    pr83047.c
    pr85388-1.c
    pr85388-3.c
    pr85388-4.c
    split-1.c
    split-3.c
    split-4.c
    pthread-init-1.c
    pthread-init-2.c
    pie-link.c
    # Picolibc not support print format with %n.
    pr78965.c
  )
  list(APPEND TestsToSkip ${TestsToSkipForNonLinux})
endif()

if (CMAKE_SYSTEM_NAME MATCHES "Linux")
  file(GLOB TestsToSkipForLinux
    # PIE defined
    pie-6.c
  )
  list(APPEND TestsToSkip ${TestsToSkipForLinux})
endif()

if(FEATURE_ATOMIC MATCHES "OFF")
  file(GLOB TestsToSkipForNonAtomic
    pr37908.c
    atomic-compare-exchange-1.c
    atomic-compare-exchange-2.c
    atomic-compare-exchange-3.c
    atomic-exchange-1.c
    atomic-exchange-2.c
    atomic-exchange-3.c
    atomic-fence.c
    atomic-flag.c
    atomic-load-1.c
    atomic-load-2.c
    atomic-load-3.c
    atomic-op-1.c
    atomic-op-2.c
    atomic-op-3.c
    atomic-op-optimize.c
    atomic-store-1.c
    atomic-store-2.c
    atomic-store-3.c
    ia64-sync-1.c
    ia64-sync-2.c
    ia64-sync-3.c
    ia64-sync-4.c
    sync-1.c
    sync-2.c
    sync-3.c
    pr54087.c
    pr86314.c
    pr94368.c
    predict-18.c
    20061124-1.c
  )
  list(APPEND TestsToSkip ${TestsToSkipForNonAtomic})
endif()

if (NOT MARCH MATCHES "f")
  file (GLOB TestsToSkipForNonFPU
    complex-5.c
    c99-math-float-1.c
    c99-math-double-1.c
    c99-math-long-double-1.c
  )
  list(APPEND TestsToSkip ${TestsToSkipForNonFPU})
endif()

##
## Tests that require extra CFLAGS in Clang
##

# Tests that require libm (-lm ldflag)
file(GLOB TestRequiresLibM CONFIGURE_DEPENDS
  pow-sqrt-1.c
  pow-sqrt-2.c
  pow-sqrt-3.c
  sinatan-1.c
  pr43419.c
  pr36017.c
  pr82004.c
  pr91734.c
  pr41963.c
  builtins-6.c
)

# Tests that require libatomic (-latomic ldflag)
file(GLOB TestRequiresLibAtomic CONFIGURE_DEPENDS
  atomic-exchange-5.c
)

# Tests that require '__declspec' attributes
file(GLOB TestRequiresDECLSPEC CONFIGURE_DEPENDS
  dll-10a.c
  dll-11.c
  dll-1.c
  dll-4.c
  dll-6.c
  dll-8.c
  dll-10.c
  dll-12a.c
  dll-2.c
  dll-5.c
  dll-7a.c
  dll-9a.c
  dll-11a.c
  dll-12.c
  dll-3.c
  dll-6a.c
  dll-7.c
  dll-9.c
  visibility-10.c
)

if (CMAKE_C_COMPILER_ID MATCHES "GNU")
  list(APPEND TestsToSkip ${TestRequiresDECLSPEC})
endif()

# Skip time consumed tests
if(TEST_SUITE_TEST_MODE MATCHES "fast-run")
  file(GLOB TimeConsumingTests CONFIGURE_DEPENDS
    pr43058.c
    unroll-and-jam.c
    pr83323.c
    cdce1.c
    pow-sqrt-1.c
    pow-sqrt-2.c
    pow-sqrt-3.c
  )

  list(APPEND TestsToSkip ${TimeConsumingTests})
endif()

# Skip fixed opt level tests when there are extra cflags
if(EXTRA_CFLAGS MATCHES "")
  file(GLOB OptFixedTests CONFIGURE_DEPENDS
    # opts-2.c expect -O0 but --extra-cflags may change the opt level.
    opts-2.c
  )

  list(APPEND TestsToSkip ${OptFixedTests})
endif()

# Tests that require -Wno-return-type
file(GLOB TestRequiresWNoReturnType CONFIGURE_DEPENDS
  pr83585.c
)

# Tests that require -ffixed-point
file (GLOB TestRequiresFFixedPoint CONFIGURE_DEPENDS
  pr103248.c
)

# Tests that use varargs on segmented stacks, and are not supported by
# the platform
if(ARCH MATCHES "x86" OR ARCH MATCHES "arm")
  file(GLOB UnsupportedTests CONFIGURE_DEPENDS
    split-6.c
    split-3.c
    pr85388-5.c
    pr85388-3.c
  )
endif()

list(APPEND TestsToSkip ${UnsupportedTests})

##
## Test target setup
##

file(GLOB TestFiles CONFIGURE_DEPENDS
  *.c
)
foreach(TestToSkip ${TestsToSkip})
  list(REMOVE_ITEM TestFiles ${TestToSkip})
endforeach()

foreach(File ${TestFiles})
  set(MaybeCFlags)
  set(MaybeLDFlags)

  # Add Test-specific CFLAGS/LDFLAGS here

  if(${File} IN_LIST TestRequiresLibM)
    list(APPEND MaybeLDFlags "-lm")
  endif()

  if(${File} IN_LIST TestRequiresLibAtomic)
    list(APPEND MaybeLDFlags "-latomic")
  endif()

  if(${File} IN_LIST TestRequiresDECLSPEC)
    list(APPEND MaybeCFlags "-fdeclspec")
  endif()

  if(${File} IN_LIST TestRequiresWNoReturnType)
    list(APPEND MaybeCFlags "-Wno-return-type")
  endif()

  if(${File} IN_LIST TestRequiresFFixedPoint)
    list(APPEND MaybeCFlags "-ffixed-point")
  endif()

  # Add Test Target
  gcc_torture_execute_test(${File}
                           PREFIX "GCC-DG"
                           CFLAGS ${MaybeCFlags}
                           LDFLAGS ${MaybeLDFlags})

endforeach()

