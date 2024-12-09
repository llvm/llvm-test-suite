dav1d
=====

dav1d is a highly optimized video decoding library for the AV1 video format.


Setup
-----

This integration of dav1d into llvm-test-suite works with dav1d 1.5.0.

To include the dav1d library in llvm-test-suite, run
`git clone -b 1.5.0 https://code.videolan.org/videolan/dav1d.git`
within the `llvm-test-suite/test-suite-externals` directory, or
set `TEST_SUITE_DAV1D_ROOT` to point to a similar checkout, in the
CMake configuration.

For x86 targets, the `nasm` tool is used for building assembly, if
the tool is found at configure time. If not found, the assembly is
omitted. The project also contains assembly for ARM and AArch64, but
that doesn't require any separate tool for building, it is built by
the regular GAS style assembler (via the compiler driver).

The upstream project also contains some amount of assembly for other
architectures, but that is not currently hooked up in the integration
into llvm-test-suite.


Build targets
-------------

The integration of dav1d into llvm-test-suite builds two targets;
the `dav1d` command line executable (which can decode AV1 video from
`.ivf` files), and `dav1d_checkasm`, a testing tool. The latter is
executed as part of running the llvm-test-suite tests.


checkasm
--------

The checkasm tool is originally intended for developing handwritten
SIMD optimized versions of functions - both for testing their
correctness and for benchmarking them.

The correctness tests work by comparing the outputs of a reference C
implementation of each function with the outputs of handwritten SIMD
optimized versions. The same comparison also works in reverse; if the
reference C code gets miscompiled, the correctness test should point out
a discrepancy. By just running this executable without any arguments,
it tests all variants of all enabled functions.

If there is only one implementation of a function (i.e. only the
reference C implementation), there is nothing to compare against, so
such miscompilations wouldn't be caught.

However, miscompilations that show up as failed asserts within LLVM
when generating code are caught even if there is no assembly
available.


Benchmarking with checkasm
--------------------------

If benchmarking on AArch64 on Linux, see the section below for
gotchas regarding that.

While the checkasm tool primarily is intended for benchmarking and
developing handwritten SIMD implementations, it can also be used
for benchmarking and evaluating the performance of the compiler
generated code for the reference C implementations.

The most highlevel benchmark would be to record the runtime of
one full run of the `dav1d_checkasm` binary, and compare that between
different builds - however this is far from ideal; it only runs each
function a couple of times (as it only runs a correctness test), and
the total runtime depends on the number of SIMD implementations and
which of those implementations are supported by the current CPU.

The ideal use of the checkasm tool is for microbenchmarking
individual functions.

As an initial entry level case, one can benchmark all included functions
by running `External/dav1d/dav1d_checkasm --bench 0`. As each benchmarked
function is run a large number of times, this can take a long time
(a couple of minutes). To reduce the runtime of it, one can edit
`dav1d/tests/checkasm/checkasm.h` and change
`#define BENCH_RUNS (1 << 12)` into e.g. `#define BENCH_RUNS (1 << 10)`
to reduce the number of iterations.

The last argument, `0`, sets the random seed for the execution. All
tests run with random input data; in many tests, the actual values of
the input data doesn't affect the runtime, but some tests can be
affected; therefore, it's good practice to run all benchmarks in a
comparison with the same seed.

An example of parts of the output of such a benchmark looks like this:

```
mc_8tap_regular_w4_hv_8bpc_c:                    15.3 ( 1.00x)
mc_8tap_regular_w4_hv_8bpc_neon:                  1.8 ( 8.44x)
mc_8tap_regular_w4_hv_8bpc_dotprod:               1.4 (11.22x)
[...]
mc_8tap_regular_w128_h_8bpc_c:                  394.5 ( 1.00x)
mc_8tap_regular_w128_h_8bpc_neon:               121.4 ( 3.25x)
mc_8tap_regular_w128_h_8bpc_dotprod:             68.2 ( 5.78x)
mc_8tap_regular_w128_hv_8bpc_c:                 702.3 ( 1.00x)
mc_8tap_regular_w128_hv_8bpc_neon:              289.2 ( 2.43x)
mc_8tap_regular_w128_hv_8bpc_dotprod:           183.1 ( 3.84x)
```

This is a case where the same function, `mc_8tap_regular`, has been
executed with a number of different cases that are relevant for
use in the video decoder; `w4` means that it was run on a block
of width 4 pixels, and the suffixes `h` or `hv` indicates different
parameters that usually pick different codepaths within the
function. (To be precise, in this case it indicates whether the
function does horizontal filter, vertical, both, or no filtering at
all.) Each function may have different specialized cases that are
benchmarked separately.

The numbers indicate that e.g. the reference C version of
`mc_8tap_regular_w128_hv` executed in 702 timer units, while
the handwritten NEON and DotProd versions took 289 and 183 timer
units each, respectively. The handwritten versions usually exploit
a lot of extra knowledge about the functions and their uses, that the
reference C implementation and the compiler lack. However they
indicate a potential best case target for what the compiler could
do, in ideal circumstances.

The various functions are grouped into different areas; one can
choose to run only one or some groups, by adding a parameter like
`--test=mc_8bpc` or `--test=mc_*`.

While benchmarking, one can also limit the benchmarking to a smaller
set of functions, by adding a parameter like
`--function=mc_8tap_regular_w*_hv_*`.


Benchmarking on AArch64
-----------------------

The upstream checkasm tool is meant for benchmarking and finetuning
assembly implementations. Therefore, it uses the `pmccntr_el0` register
for high precision timing on Linux and Windows. Unfortunately, this register
is normally not accessible from userspace in Linux. One can enable access
from userspace by building and loading a kernel module, e.g.
https://code.videolan.org/janne/arm64-cycle-cnt.

Alternatively, the `dav1d/tests/checkasm/checkasm.h` source file can be
edited, changing references to `pmccntr_el0` into `cntvct_el0`. That
timer is usually accessible from userspace, but it has much lower
precision - making it less suitable for finetuning assembly functions,
but it is still good enough for coarse performance comparisons.

On macOS, a coarse timer that always is accessible, is used by default.

On Windows, `pmccntr_el0` is used; this register should always be
accessible from userspace on Windows.


Evaulating vectorization effectiveness
--------------------------------------

For evaluating e.g. the effectiveness of compiler autovectorization,
do two separate builds of `dav1d_checkasm`, e.g. one set up with
`-DCMAKE_C_FLAGS_RELEASE="-O3"` and one with
`-DCMAKE_C_FLAGS_RELEASE="-O3 -fno-vectorize -fno-slp-vectorize"`.
Then run benchmarks for relevant parts, and compare the measured
runtimes for the `_c` suffixed versions. If the vectorized version is
faster (lower benchmark numbers) than the non-vectorized, the compiler
handled the function well. If the vectorized version is slower than
the non-vectorized version, we have found a case that probably should be
investigated, and where compiler autovectorization is hurting the
performance of dav1d.

As a concrete example, running
`./External/dav1d/dav1d_checkasm --bench --test=mc_8bpc --function=mct_8tap_regular_w128_0_8bpc 0` in both a vectorized and non-vectorized build,
we'd get the following numbers:

Vectorization disabled:
```
mct_8tap_regular_w128_0_8bpc_c:          180.9 ( 1.00x)
mct_8tap_regular_w128_0_8bpc_neon:        10.8 (16.69x)
mct_8tap_regular_w128_0_8bpc_dotprod:     10.8 (16.74x)
```

Vectorization enabled:
```
mct_8tap_regular_w128_0_8bpc_c:           18.1 ( 1.00x)
mct_8tap_regular_w128_0_8bpc_neon:        10.8 ( 1.68x)
mct_8tap_regular_w128_0_8bpc_dotprod:     10.8 ( 1.67x)
```

Here, the compiler vectorized version was almost 10x as fast as the
non-vectorized version, reaching close to the performance of the
handwritten implementation.


A different example of the effect of vectorization can be found
by benchmarking with `./External/dav1d/dav1d_checkasm --bench --test=cdef_8bpc 0`.
There we can get the following numbers:

Vectorization disabled:
```
cdef_filter_4x8_10_8bpc_c:         7.4 ( 1.00x)
cdef_filter_4x8_10_8bpc_neon:      1.6 ( 4.51x)
```

Vectorization enabled:
```
cdef_filter_4x8_10_8bpc_c:        11.3 ( 1.00x)
cdef_filter_4x8_10_8bpc_neon:      1.7 ( 6.84x)
```

Here, the code generated by vectorization is not beneficial, and
ends up slowing down this particular testcase.


Locating the source and generated code for tests
------------------------------------------------

Large parts of the dav1d decoder is templated C code, which is
compiled twice, with varying data type definitions - once for
`8bpc` (8 bit per component) and once for `16bpc`. Code in files
named `*_tmpl.c` is compiled in such a way.

To investigate the behaviour behind one individual benchmark result,
the mapping from benchmark case names to actual source code isn't
always trivial. It may be easiest to start out with the definition
of the test itself, within e.g. `dav1d/tests/checkasm/*.c`, looking
for which function it actually calls.

As an example, one function observed above,
`mct_8tap_regular_w128_0_8bpc`, gets tested in `dav1d/tests/checkasm/mc.c`,
in the `check_mct` function. The individual test variant gets set up
in this function call:

```
    if (check_func(c->mct[filter], "mct_%s_w%d_%s_%dbpc",
        filter_names[filter], w, mxy_names[mxy], BITDEPTH))
```

This means that the tested function is `c->mct[filter]`. In this case,
the function pointer gets set by `bitfn(dav1d_mc_dsp_init)(&c)`, which
is implemented in `dav1d/src/mc_tmpl.c`. For the case of
`mct_8tap_regular_w128_0_8bpc`, this maps to the function
`prep_8tap_regular_c` (which is defined via macro expansion, so it's not
easily greppable), which calls the function `prep_8tap_c`. Within the
function `prep_8tap_c`, there are four different cases, switched between
based on whether the input parameters `mx` and `my` are zero or nonzero.
In the case of the `_0_` variant, both `mx` and `my` would be zero, and
the called code is in the function `prep_c`.

The generated code for e.g. those functions can be found in the object file
`External/dav1d/CMakeFiles/dav1d_bitdepth_8.dir/__/__/test-suite-externals/dav1d/src/mc_tmpl.c.o`.
