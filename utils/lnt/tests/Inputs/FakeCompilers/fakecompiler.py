#!/usr/bin/env python3

"""
Utilities for "faking" a compiler response.
"""
import inspect
import os
import sys

g_program = None


class FakeCompiler(object):
    compiler_name = None

    def print_verbose_info(self):
        raise NotImplementedError

    def print_dumpmachine(self):
        raise NotImplementedError

    def print_llvm_target(self, args):
        raise NotImplementedError

    def print_as_version(self):
        print("""(assembler version goes here)""", file=sys.stderr)

    def print_ld_version(self):
        print("""(linker version goes here)""", file=sys.stderr)


class ICCv12_1_3(FakeCompiler):
    compiler_name = "icc-12.1.3"

    def print_verbose_info(self):
        print("""\
icc: command line warning #10006: ignoring unknown option '-###'
icc version 12.1.3 (gcc version 4.2.1 compatibility)
/usr/bin/icc-2011-base/bin/intel64/mcpcom    -_g -mP3OPT_inline_alloca -D__HONOR_STD -D__ICC=1210 -D__INTEL_COMPILER=1210 "-_Acpu(x86_64)" "-_Amachine(x86_64)" -D__BLOCKS__ -D__PTRDIFF_TYPE__=long "-D__SIZE_TYPE__=unsigned long" -D__WCHAR_TYPE__=int -D__WINT_TYPE__=int "-D__INTMAX_TYPE__=long int" "-D__UINTMAX_TYPE__=long unsigned int" -D__LONG_MAX__=9223372036854775807L -D__QMSPP_ -D__OPTIMIZE__ -D__NO_MATH_INLINES -D__NO_STRING_INLINES -D__NO_INLINE__ -D__GNUC_GNU_INLINE__ -D__GNUC__=4 -D__GNUC_MINOR__=2 -D__GNUC_PATCHLEVEL__=1 -D__APPLE_CC__=5658 -D__ENVIRONMENT_MAC_OS_X_VERSION_MIN_REQUIRED__=1073 -D__LITTLE_ENDIAN__ -D__DYNAMIC__ "-D__private_extern__=__attribute__((visibility("hidden")))" -D__LP64__ -D_LP64 -D__GXX_ABI_VERSION=1002 -D__USER_LABEL_PREFIX__=_ -D__REGISTER_PREFIX__= -D__INTEL_RTTI__ -D__x86_64 -D__x86_64__ -D_MT -D__INTEL_COMPILER_BUILD_DATE=20120130 -D__PIC__ -D__APPLE__ -D__MACH__ -D__pentium4 -D__pentium4__ -D__tune_pentium4__ -D__SSE2__ -D__SSE3__ -D__SSSE3__ -D__SSE__ -D__MMX__ -_k -_8 -_l -_D -_a -_b -E --gnu_version=421 -_W5 --gcc-extern-inline --multibyte_chars --blocks --array_section --simd --simd_func -mP1OPT_print_version=FALSE -mP1OPT_version=12.1-intel64 -mGLOB_diag_use_message_catalog=FALSE /dev/null
... more boring stuff here ...
""", file=sys.stderr)  # noqa

    def print_llvm_target(self, args):
        print("""\
icc: command line warning #10006: ignoring unknown option '-flto'
	.file "null"
	.section	__DATA, __data
# End
	.subsections_via_symbols
""")  # noqa

    def print_dumpmachine(self):
        print("""i686-apple-darwin11""")


class LLVMCompiler(FakeCompiler):
    def print_llvm_target(self, args):
        target = "x86_64-apple-darwin11.0.0"
        for arg in args:
            if arg.startswith("--target="):
                target = arg[len("--target="):]
        print("""\
; ModuleID = '/dev/null'
target datalayout = "e-p:64:64:64-i1:8:8-i8:8:8-i16:16:16-i32:32:32-i64:64:64-\
f32:32:32-f64:64:64-v64:64:64-v128:128:128-a0:0:64-s0:64:64-f80:128:128-\
n8:16:32:64"
target triple = "%s"
""" % target)

    def print_dumpmachine(self):
        print("""x86_64-apple-darwin11.0.0""")


# Clang build at r154331 (for example).
class Clang_r154331(LLVMCompiler):
    compiler_name = "clang-r154331"

    def print_verbose_info(self):
        print("""\
clang version 3.1 (trunk 154331) (llvm/trunk 154329)
Target: x86_64-apple-darwin11.3.0
Thread model: posix
InstalledDir: /home/foo/bin
""", file=sys.stderr)
        print("""\
 "%s" "-cc1" "-E" ... more boring stuff here ...""" % (
            g_program,), file=sys.stderr)


class Clang_r154332(LLVMCompiler):
    compiler_name = "clang-r154332"

    def print_verbose_info(self):
        print("""\
clang version 3.1 (trunk 154332) (llvm/trunk 154329)
Target: x86_64-apple-darwin11.3.0
Thread model: posix
InstalledDir: /home/foo/bin
""", file=sys.stderr)
        print("""\
 "%s" "-cc1" "-E" ... more boring stuff here ...""" % (
            g_program,), file=sys.stderr)


# Monorepo clang build
class Clang_monorepo(LLVMCompiler):
    compiler_name = "clang-monorepo"

    def print_verbose_info(self):
        print("""\
clang version 1.2.3 (ssh://something.com/llvm-project.git 597522d740374f093a089a2acbec5b20466b2f34)
Target: arm-apple-darwin11.4.0
Thread model: posix
InstalledDir: /home/foo/bin
""", file=sys.stderr)
        print("""\
 "%s" "-cc1" "-E" ... more boring stuff here ...""" % (
            g_program,), file=sys.stderr)


# Monorepo clang build with some extra stuff after the version string
class Clang_monorepo2(LLVMCompiler):
    compiler_name = "clang-monorepo2"

    def print_verbose_info(self):
        print("""\
clang version 1.2.3 (ssh://something.com/llvm-project.git \
597522d740374f093a089a2acbec5b20466b2f34) (extra) (stuff) (here)
Thread model: posix
InstalledDir: /home/foo/bin
""", file=sys.stderr)
        print("""\
 "%s" "-cc1" "-E" ... more boring stuff here ...""" % (
            g_program,), file=sys.stderr)


class AppleClang_138_1(LLVMCompiler):
    compiler_name = "apple-clang-138.1"

    def print_verbose_info(self):
        print("""\
Apple clang version 2.0 (tags/Apple/clang-138.1) (based on LLVM 2.9svn)
Target: x86_64-apple-darwin11.3.0
Thread model: posix
InstalledDir: /home/foo/bin""", file=sys.stderr)
        print("""\
 "%s" "-cc1" "-E" ... more boring stuff here ...""" % (
            g_program,), file=sys.stderr)


class ClangNoInfo(LLVMCompiler):
    compiler_name = "clang-no-info"

    def print_verbose_info(self):
        print("""\
clang version 3.2
Target: x86_64-bla-bla
Thread model: posix""", file=sys.stderr)
        print("""\
 "%s" "-cc1" "-E" ... more boring stuff here ...""" % (
            g_program,), file=sys.stderr)


class GCCDebian(FakeCompiler):
    compiler_name = "gcc-debian"

    def print_verbose_info(self):
        print("""\
Target: x86_64-linux-gnu
gcc version 12.2.0 (Debian 12.2.0-14+deb12u1)""", file=sys.stderr)

    def print_dumpmachine(self):
        print("x86_64-linux-gnu")


class GCCTrunk(FakeCompiler):
    compiler_name = "gcc-trunk"

    def print_verbose_info(self):
        print("""\
Target: x86_64-linux-gnu
gcc version 16.0.0 20250807 (experimental) (GCC)""", file=sys.stderr)

    def print_dumpmachine(self):
        print("x86_64-linux-gnu")


fake_compilers = dict((value.compiler_name, value)
                      for key, value in locals().items()
                      if inspect.isclass(value) and issubclass(value, FakeCompiler))


def main():
    global g_program
    g_program = sys.argv[0]

    compiler_name = os.path.basename(sys.argv[0])
    compiler_class = fake_compilers.get(compiler_name)
    if compiler_class is None:
        raise SystemExit("unknown fake compiler %r" % (compiler_name,))

    # Instantiate the compiler class.
    compiler_instance = compiler_class()

    def args_contained_in(a, b):
        """Return true if every element of tuple b is contained in
        tuple a."""
        return all([bi in a for bi in b])

    # Search in the arguments to determine what kind of response to fake.
    args = tuple(sys.argv[1:])
    if '-dumpmachine' in args:
        compiler_instance.print_dumpmachine()
    elif args_contained_in(args, ('-v', '-###')):
        compiler_instance.print_verbose_info()
    elif 'Wa,-v' in args:
        compiler_instance.print_as_version()
    elif 'Wl,-v' in args:
        compiler_instance.print_ld_version()
    elif args_contained_in(args, ('-S', '-flto', '-o', '-', '/dev/null')):
        compiler_instance.print_llvm_target(args)
    else:
        raise SystemExit("unrecognized argument vector: %r" % (
            args,))


if __name__ == '__main__':
    main()
