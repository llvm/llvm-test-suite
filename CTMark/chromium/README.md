# Chromium

60 translation units of Chromium's Linux `chrome` build (x86-64, release), compiled but
not linked, with Chromium's own command lines. Compiling them takes about as long as the
other CTMark programs together (about 72 s of CPU time with a release clang on an M4 Mac,
vs. 75 s for the rest of CTMark at -O3), and their total compile time tracks the compile
time of the whole `chrome` build.

## How the translation units were picked

`chrome` on Linux compiles 55640 distinct source files: 45275 that the Mac build compiles
too, and 10365 that only the Linux build compiles. The translation units are a stratified
sample: 49 of the former and 11 of the latter (proportional to the two groups), each picked
from a uniform random sample of its group, evenly spaced over the sorted compile times
within the group. So every translation unit here stands for about 930 of the build, and the
sum of their compile times, which is what lit reports, is an estimate of the build's.
(Picking with probability proportional to compile time would overweight slow translation
units in that sum.)

They range from 0.01 s to 7.5 s of compile time (median 0.85 s); 9 of them are generated
sources.

## Files

- `src/`: the files the translation units read (8716 files, 89 MB), in Chromium's layout:
  sources and headers, Chromium's generated headers in `src/out/gnlinux/gen/`, libc++, and
  the parts of the Debian bullseye sysroot (`src/build/linux/`) they include. The compiler's
  own builtin headers aren't included.
- `tus.cmake`: one `chromium_tu()` per translation unit, with its flags.
- `main.c`, `chromium.reference_output`: a trivial program that carries the lit test. lit's
  compile time metric sums all `*.o.time` files in the test's directory, which includes the
  translation units.
- `LICENSE.txt`, `licenses/`: the licenses of the files in `src/`.
- `make_benchmark.py`: regenerates `src/`, `tus.cmake`, `LICENSE.txt` and `licenses/` from a
  Chromium compile-time benchmark bundle and a Chromium checkout.

## Notes

- The flags are hardcoded: they are Chromium's command lines from its `out/gnlinux` build
  directory (`--target=x86_64-unknown-linux-gnu`, `-O2`, `-g1 -gsplit-dwarf`, `-std=c++23`,
  `--sysroot`, `-nostdinc++` with libc++ from `src/`, ...). So the translation units are
  cross-compiled for x86-64 Linux on every host, and CMAKE_C_FLAGS / CMAKE_CXX_FLAGS (and so
  the test-suite's -O3, -O0 -g, LTO, ... caches) don't apply to them. The compiler needs the
  X86 target, and needs to be recent enough to understand Chromium's flags (Chromium builds
  with a clang close to trunk).
- Compared to Chromium's command lines, the compiler (CMAKE_C_COMPILER / CMAKE_CXX_COMPILER
  instead), Chromium's clang plugins (`-Xclang -add-plugin ...`, `-Xclang -plugin-arg-...`),
  the dependency file flags and the output file are left out.
- The compiler runs in `src/out/gnlinux`, since the flags have paths relative to it. The
  object files (and the `.dwo` files from `-gsplit-dwarf`) go to the build directory.
- Without the plugins, the `-Wunsafe-buffer-usage` warnings that Chromium's
  find-bad-constructs plugin limits to some directories (and that `#pragma
  allow_unsafe_buffers` silences) are emitted everywhere: about 13000 warnings. Disabling
  them changes the compile time by less than 2%. Chromium builds without warnings otherwise,
  but a newer clang can have new ones; `-Werror` isn't used.
- The files are from Chromium and its third-party dependencies (Blink partly under the
  LGPL, headers from the sysroot under the LGPL and the GPL with the Linux syscall note);
  see `LICENSE.txt`.
