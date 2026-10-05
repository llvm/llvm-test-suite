# Chromium

9 translation units of Chromium's Linux `chrome` build (x86-64, release), compiled but not
linked, with Chromium's own command lines: one for each kind of C++ code that most of
Chromium's build time goes to. They are C++23 with libc++, and use Chromium's base library,
mojo IPC, Blink's garbage collector and V8's internals, which the other CTMark programs and
building LLVM itself don't cover.

## How the translation units were picked

From a sample of 60 translation units of the build (stratified by whether the Mac build
compiles them too, and evenly spaced over compile time), this keeps one translation unit of
Chromium's own code per kind. C code and third-party libraries (ICU, BoringSSL, Skia, ...)
are left out: CTMark covers C well, and those libraries are mostly older-style C++.

| kind | translation unit | compile time |
|---|---|---|
| Blink | `third_party/blink/renderer/core/exported/web_input_element.cc` | 2.0 s |
| Blink's V8 bindings (generated) | `gen/third_party/blink/renderer/bindings/modules/v8/v8_video_frame_buffer_init.cc` | 1.1 s |
| mojo bindings (generated) | `gen/components/content_settings/core/common/content_settings.mojom.cc` | 0.8 s |
| protobuf (generated) | `gen/third_party/perfetto/protos/perfetto/config/profiling/perf_event_config.pb.cc` | 1.0 s |
| V8 | `v8/src/compiler/turbofan-types.cc` | 2.8 s |
| `chrome/browser` | `chrome/browser/component_updater/subresource_filter_component_installer.cc` | 1.1 s |
| `components/` | `components/metrics/metrics_service.cc` | 1.8 s |
| `ui/` | `ui/views/controls/editable_combobox/editable_combobox.cc` | 2.4 s |
| `services/` | `services/network/public/cpp/cert_verifier/cert_verifier_mojom_traits.cc` | 1.6 s |

(Compile times: CPU time with a release clang on an M4 Mac; 14.6 s in total.) Within each
kind, translation units are much alike: they include the same libc++, base, abseil and mojo
headers, so one per kind covers most of what the compiler does for that kind. Since this
isn't a statistical sample anymore, the sum of the compile times doesn't estimate the build's
compile time; it's a mix of the kinds of code Chromium compiles.

## Files

- `src/`: the files the translation units read (3954 files, 36 MB), in Chromium's layout:
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
  allow_unsafe_buffers` silences) are emitted everywhere: about 3800 warnings. Disabling
  them makes compiling about 4% faster, but that includes the analysis behind them, which
  Chromium's build does too. Chromium builds without warnings otherwise, but a newer clang
  can have new ones; `-Werror` isn't used.
- The files are from Chromium and its third-party dependencies (Blink partly under the
  LGPL, headers from the sysroot under the LGPL and the GPL with the Linux syscall note);
  see `LICENSE.txt`.
