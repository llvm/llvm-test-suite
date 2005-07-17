dnl Initialize autoconf
AC_INIT([[LLVM-TEST]],[[1.6cvs]],[llvmbugs@cs.uiuc.edu])

dnl Place all of the extra autoconf files into the config subdirectory
AC_CONFIG_AUX_DIR([autoconf])

dnl Verify that the source directory is valid
AC_CONFIG_SRCDIR([SingleSource/Benchmarks/Makefile])

dnl Do special configuration of Makefiles
AC_CONFIG_COMMANDS([setup],,[llvm_src="${srcdir}"])
AC_CONFIG_FILES([Makefile.config])
AC_CONFIG_MAKEFILE(Makefile)
AC_CONFIG_MAKEFILE(Makefile.common)
AC_CONFIG_MAKEFILE(Makefile.f2c)
AC_CONFIG_MAKEFILE(Makefile.programs)
AC_CONFIG_MAKEFILE(Makefile.tests)
AC_CONFIG_MAKEFILE(TEST.aa.Makefile)
AC_CONFIG_MAKEFILE(TEST.dsgraph.report)
AC_CONFIG_MAKEFILE(TEST.aa.report)
AC_CONFIG_MAKEFILE(TEST.example.Makefile)
AC_CONFIG_MAKEFILE(TEST.nightly.Makefile)
AC_CONFIG_MAKEFILE(TEST.buildrepo.Makefile)
AC_CONFIG_MAKEFILE(TEST.jit.Makefile)
AC_CONFIG_MAKEFILE(TEST.nightly.report)
AC_CONFIG_MAKEFILE(TEST.dsgraph.Makefile)
AC_CONFIG_MAKEFILE(TEST.jit.report)
AC_CONFIG_MAKEFILE(TEST.typesafe.Makefile)
AC_CONFIG_MAKEFILE(TEST.dsgraph.gnuplot)
AC_CONFIG_MAKEFILE(TEST.vtl.Makefile)
AC_CONFIG_MAKEFILE(External/Makefile)
AC_CONFIG_MAKEFILE(External/Makefile.external)
AC_CONFIG_MAKEFILE(External/Povray/Makefile)
AC_CONFIG_MAKEFILE(External/SPEC/Makefile)
AC_CONFIG_MAKEFILE(External/SPEC/Makefile.spec)
AC_CONFIG_MAKEFILE(External/SPEC/Makefile.spec2000)
AC_CONFIG_MAKEFILE(External/SPEC/Makefile.spec95)
AC_CONFIG_MAKEFILE(External/SPEC/CFP2000/Makefile)
AC_CONFIG_MAKEFILE(External/SPEC/CINT2000/Makefile)
AC_CONFIG_MAKEFILE(External/SPEC/CFP95/Makefile)
AC_CONFIG_MAKEFILE(External/SPEC/CINT95/Makefile)
AC_CONFIG_MAKEFILE(MultiSource/Makefile)
AC_CONFIG_MAKEFILE(MultiSource/Makefile.multisrc)
AC_CONFIG_MAKEFILE(SingleSource/Makefile)
AC_CONFIG_MAKEFILE(SingleSource/Makefile.singlesrc)

dnl **************************************************************************
dnl * Get command line options
dnl **************************************************************************

dnl Location of LLVM source code
AC_ARG_WITH(llvmsrc,AS_HELP_STRING(--with-llvmsrc,Location of LLVM Source Code),AC_SUBST(LLVM_SRC,[$withval]),AC_SUBST(LLVM_SRC,[`cd ${srcdir}/../..; pwd`]))

dnl Location of LLVM object code
AC_ARG_WITH(llvmobj,AS_HELP_STRING(--with-llvmobj,Location of LLVM Object Code),AC_SUBST(LLVM_OBJ,[$withval]),AC_SUBST(LLVM_OBJ,[`cd ../..; pwd`]))

dnl LLC Diff Option
AC_ARG_ENABLE(llc_diffs,
  AS_HELP_STRING(--enable-llc_diffs,
                 [Enable LLC Diffs when testing (default is YES)]),,
              enableval=yes)
if test ${enableval} = "no"
then
      AC_SUBST(DISABLE_LLC_DIFFS,[DISABLE_LLC_DIFFS:=1])
else
      AC_SUBST(DISABLE_LLC_DIFFS,[[]])
fi

dnl **************************************************************************
dnl * Check for things needed by the test suite programs
dnl **************************************************************************

dnl Check for compilation tools
AC_PROG_CXX
AC_PROG_CC(gcc)
AC_PROG_CPP

dnl Verify that GCC is version 3.0 or higher

dnl Check for GNU Make.  We use its extensions too, so don't build without it
AC_CHECK_GNU_MAKE
if test -z "$llvm_cv_gnu_make_command"
then
	AC_MSG_ERROR([GNU Make required but not found])
fi

dnl Checks for other tools
AC_PROG_FLEX
AC_PROG_BISON
AC_PROG_LIBTOOL

dnl Check for GNU f2c FORTRAN -> C translator
FIND_STD_PROGRAM(f2c,f2c.h,libf2c.a)
dnl Check for the NAG f95 FORTRAN -> C translator
FIND_STD_PROGRAM(f95,,libf97.dylib,[NAG Fortran])
CHECK_PROGRAM_SANITY([f95],[-V],[NAGWare Fortran 95])

dnl Checks for header files.
dnl We don't check for ancient stuff or things that are guaranteed to be there
dnl by the C++ standard. We always use the <cfoo> versions of <foo.h> C headers.
AC_HEADER_STDC
AC_HEADER_SYS_WAIT

dnl Determine if the linker supports the -R option.
AC_LINK_USE_R

dnl Check for needed functions
AC_CHECK_FUNC([re_comp],[AC_SUBST(HAVE_RE_COMP,[HAVE_RE_COMP:=1])],
                        [AC_SUBST(HAVE_RE_COMP,[[]])])

dnl Configure the default locations of the external benchmarks
EXTERNAL_BENCHMARK(spec95,/home/vadve/shared/benchmarks/spec95/benchspec)
EXTERNAL_BENCHMARK(spec2000,/home/vadve/shared/benchmarks/speccpu2000/benchspec)
EXTERNAL_BENCHMARK(povray,/home/vadve/shared/benchmarks/povray31)
EXTERNAL_BENCHMARK(namd,/home/vadve/shared/benchmarks/spec_namd)
EXTERNAL_BENCHMARK(sweep3d,/home/vadve/criswell/umt2k)
EXTERNAL_BENCHMARK(fpgrowth,/home/vadve/shared/benchmarks/fpgrowth)

dnl Create the output files
AC_OUTPUT
