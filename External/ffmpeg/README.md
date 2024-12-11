ffmpeg
======

ffmpeg is a highly optimized multimedia processing framework.


Setup
-----

This integration of ffmpeg into llvm-test-suite works with ffmpeg 7.1
(but it requires a version from the 7.1 branch past the initial
7.1 release tag).

To include the ffmpeg library in llvm-test-suite, run
`git clone -b release/7.1 https://git.ffmpeg.org/ffmpeg.git`
within the `llvm-test-suite/test-suite-externals` directory, or
set `TEST_SUITE_FFMPEG_ROOT` to point to a similar checkout, in the
CMake configuration. (As this is a branch, not a tag, you may wish
to check out e.g. the commit
`10aaf84f855dbcedb8ee2e3fce307e9b98320946`, in case the branch
changes further.)

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

The integration of ffmpeg into llvm-test-suite builds two targets;
the `ffmpeg` command line executable (which can decode/encode between
a large number of audio/video formats), and `ffmpeg_checkasm`, a testing
tool. The latter is executed as part of running the llvm-test-suite tests.


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
one full run of the `ffmpeg_checkasm` binary, and compare that between
different builds - however this is far from ideal; it only runs each
function a couple of times (as it only runs a correctness test), and
the total runtime depends on the number of SIMD implementations and
which of those implementations are supported by the current CPU.

The ideal use of the checkasm tool is for microbenchmarking
individual functions.

As an initial entry level case, one can benchmark all included functions
by running `External/ffmpeg/ffmpeg_checkasm --bench 0`. As each benchmarked
function is run a large number of times, this can take a long time
(a couple of minutes). To reduce the runtime of it, one can pass the
parameter e.g. `--run=8`, making checkasm run 256 (2^8) iterations of
each function, rather than the default of 1024 iterations.

The last argument, `0`, sets the random seed for the execution. All
tests run with random input data; in many tests, the actual values of
the input data doesn't affect the runtime, but some tests can be
affected; therefore, it's good practice to run all benchmarks in a
comparison with the same seed.

An example of parts of the output of such a benchmark looks like this:

```
vp9_put_8tap_smooth_4hv_8bpp_c:                          9.0 ( 1.00x)
vp9_put_8tap_smooth_4hv_8bpp_neon:                       1.8 ( 5.14x)
[...]
vp9_put_8tap_smooth_64h_8bpp_c:                        173.5 ( 1.00x)
vp9_put_8tap_smooth_64h_8bpp_neon:                      68.2 ( 2.54x)
[...]
vp9_put_8tap_smooth_64hv_8bpp_c:                       408.8 ( 1.00x)
vp9_put_8tap_smooth_64hv_8bpp_neon:                    145.8 ( 2.80x)
```

This is a case where the same function, `vp9_put_8tap_smooth`, has been
executed with a number of different cases that are relevant for
use in the video decoder; `4` and `64` mean that it was run on a block
of width 4 or 64 pixels, and the suffixes `h` or `hv` indicates different
parameters that usually pick different codepaths within the
function. (To be precise, in this case it indicates whether the
function does horizontal filter, vertical or both.) Each function may
have different specialized cases that are benchmarked separately.

The numbers indicate that e.g. the reference C version of
`vp9_put_8tap_smooth_64hv_8bpp` executed in 408 timer units, while
the handwritten NEON version took 145 timer units. The handwritten
versions usually exploit a lot of extra knowledge about the functions
and their uses, that the reference C implementation and the compiler
lack. However they indicate a potential best case target for what the
compiler could do, in ideal circumstances.

The various functions are grouped into different areas; one can
choose to run only one or some groups, by adding a parameter like
`--test=vp9dsp` or `--test=vp*`.

While benchmarking, one can also limit the benchmarking to a smaller
set of functions, by adding a value to the `--bench` parameter, like
`--bench=vp9_*_8tap_smooth_64*_8bpp`.


Benchmarking on AArch64
-----------------------

The upstream checkasm tool is meant for benchmarking and finetuning
assembly implementations. Therefore, it uses the `pmccntr_el0` register
for high precision timing on Linux and Windows. Unfortunately, this register
is normally not accessible from userspace in Linux. One can enable access
from userspace by building and loading a kernel module, e.g.
https://code.videolan.org/janne/arm64-cycle-cnt.

Alternatively, the `ffmpeg/libavutil/aarch64/timer.h` source file can be
edited, adjusting the `#if defined(__ANDROID__) || defined(__APPLE__)`
condition to also cover Linux, either by appending `|| defined(__linux__)`
or by changing the whole line into `#if 1`. This makes it use the
timer `cntvct_el0` instead of `pmccntr_el0`. `cntvct_el0` is usually
accessible from userspace, but it has much lower precision - making it
less suitable for finetuning assembly functions, but it is still good
enough for coarse performance comparisons.

On macOS, `cntvct_el0` is used by default.

On Windows, `pmccntr_el0` is used; this register should always be
accessible from userspace on Windows.


Evaluating vectorization effectiveness
--------------------------------------

For evaluating e.g. the effectiveness of compiler autovectorization,
do two separate builds of `ffmpeg_checkasm`, e.g. one set up with
`-DCMAKE_C_FLAGS_RELEASE="-O3"` and one with
`-DCMAKE_C_FLAGS_RELEASE="-O3 -fno-vectorize -fno-slp-vectorize"`.
Then run benchmarks for relevant parts, and compare the measured
runtimes for the `_c` suffixed versions. If the vectorized version is
faster (lower benchmark numbers) than the non-vectorized, the compiler
handled the function well. If the vectorized version is slower than
the non-vectorized version, we have found a case that probably should be
investigated, and where compiler autovectorization is hurting the
performance of ffmpeg.

As a concrete example, running
`./External/ffmpeg/ffmpeg_checkasm --test=vp9dsp --bench=vp9_avg_*_64h_8bpp 0`
in both a vectorized and non-vectorized build, we'd get the following numbers:

Vectorization disabled:
```
vp9_avg_8tap_smooth_64h_8bpp_c:                        367.2 ( 1.00x)
vp9_avg_8tap_smooth_64h_8bpp_neon:                      68.5 ( 5.36x)
vp9_avg_bilin_64h_8bpp_c:                              145.8 ( 1.00x)
```

Vectorization enabled:
```
vp9_avg_8tap_smooth_64h_8bpp_c:                        182.5 ( 1.00x)
vp9_avg_8tap_smooth_64h_8bpp_neon:                      68.5 ( 2.66x)
vp9_avg_bilin_64h_8bpp_c:                               19.5 ( 1.00x)
```

Here, the compiler vectorized of `vp9_avg_8tap_smooth_64h_8bpp` was
around 1.4x as fast as the non-vectorized version; not great, but at
least faster than with vectorization disabled. It still takes 2.6x
as long as the handwritten version. For `vp9_avg_bilin_64h_8bpp`,
the vectorized version is over 7x as fast as the non-vectorized one.


A different example of the effect of vectorization can be found
by benchmarking with `./External/ffmpeg/ffmpeg_checkasm --test=vp9dsp --bench=vp9_put_8tap_smooth_4hv_8bpp 0`.
There we can get the following numbers:

Vectorization disabled:
```
vp9_put_8tap_smooth_4hv_8bpp_c:                          4.5 ( 1.00x)
vp9_put_8tap_smooth_4hv_8bpp_neon:                       1.8 ( 2.57x)
```

Vectorization enabled:
```
vp9_put_8tap_smooth_4hv_8bpp_c:                          9.0 ( 1.00x)
vp9_put_8tap_smooth_4hv_8bpp_neon:                       1.8 ( 5.14x)
```

Here, the overhead of vectorization (or potentially deciding not to
go with a vectorized implementation, but falling back on a scalar
loop) makes the function slower, for these small block sizes (operating
on a 4 pixel wide block).


Locating the source and generated code for tests
------------------------------------------------

Some parts of the ffmpeg decoder is templated C code, which is
compiled or included multiple times, with varying data type definitions
- once for `8bpp` (8 bit per pixel) and once for e.g. `10bpp`. Code in files
named `*_template.c` is usually compiled in such a way.

To investigate the behaviour behind one individual benchmark result,
the mapping from benchmark case names to actual source code isn't
always trivial. It may be easiest to start out with the definition
of the test itself, within e.g. `ffmpeg/tests/checkasm/*.c`, looking
for which function it actually calls.

As an example, one function observed above,
`vp9_avg_8tap_smooth_64h_8bpp`, gets tested in
`ffmpeg/tests/checkasm/vp9dsp.c`, in the `check_mc` function. The
individual test variant gets set up in this function call:

```
    if (dx || dy) {
        snprintf(str, sizeof(str),
                 "%s_%s_%d%s", op_names[op],
                 filter_names[filter], size,
                 subpel_names[dy][dx]);
    } else {
        snprintf(str, sizeof(str),
                 "%s%d", op_names[op], size);
    }
    if (check_func(dsp.mc[hsize][filter][op][dx][dy],
                   "vp9_%s_%dbpp", str, bit_depth)) {
```

This means that the tested function is `dsp.mc[hsize][filter][op][dx][dy]`.
In this case, the function pointer gets set by `ff_vp9dsp_init`, which
is implemented in `ffmpeg/libavcodec/vp9dsp.c`. For the case of
`vp9_avg_8tap_smooth_64h_8bpp`, this maps to the function
`avg_8tap_smooth_64h_c` (which is defined via macro expansion, so it's not
easily greppable) in `ffmpeg/libavcodec/vp9dsp_template.c`, which calls the
function `avg_8tap_1d_h_c`, which calls `do_8tap_1d_c` which contains the
actual core loops of the function.

The generated code for e.g. those functions can be found in the object file
`External/ffmpeg/CMakeFiles/avcodec.dir/__/__/test-suite-externals/ffmpeg/libavcodec/vp9dsp_8bpp.c.o`.
