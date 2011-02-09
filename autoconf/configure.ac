dnl Initialize autoconf
AC_INIT([[LLVM-TEST]],[[2.8svn]],[llvmbugs@cs.uiuc.edu])

dnl Place all of the extra autoconf files into the config subdirectory
AC_CONFIG_AUX_DIR([autoconf])

dnl Verify that the source directory is valid
AC_CONFIG_SRCDIR([SingleSource/Benchmarks/Makefile])

dnl Do special configuration of Makefiles
AC_CONFIG_COMMANDS([setup],,[llvm_src="${srcdir}"])
AC_CONFIG_FILES([Makefile.config])
AC_CONFIG_MAKEFILE(Makefile)
AC_CONFIG_MAKEFILE(Makefile.common)
AC_CONFIG_MAKEFILE(Makefile.nagfortran)
AC_CONFIG_MAKEFILE(Makefile.f2c)
AC_CONFIG_MAKEFILE(Makefile.programs)
AC_CONFIG_MAKEFILE(Makefile.tests)
AC_CONFIG_MAKEFILE(TEST.aa.Makefile)
AC_CONFIG_MAKEFILE(TEST.aa.report)
AC_CONFIG_MAKEFILE(TEST.example.Makefile)
AC_CONFIG_MAKEFILE(TEST.nightly.Makefile)
AC_CONFIG_MAKEFILE(TEST.buildrepo.Makefile)
AC_CONFIG_MAKEFILE(TEST.jit.Makefile)
AC_CONFIG_MAKEFILE(TEST.nightly.report)
AC_CONFIG_MAKEFILE(TEST.jit.report)
AC_CONFIG_MAKEFILE(TEST.typesafe.Makefile)
AC_CONFIG_MAKEFILE(TEST.vtl.Makefile)
AC_CONFIG_MAKEFILE(External/Makefile)
AC_CONFIG_MAKEFILE(External/Makefile.external)
AC_CONFIG_MAKEFILE(External/Povray/Makefile)
AC_CONFIG_MAKEFILE(External/SPEC/Makefile)
AC_CONFIG_MAKEFILE(External/SPEC/Makefile.spec)
AC_CONFIG_MAKEFILE(External/SPEC/Makefile.spec.config)
AC_CONFIG_MAKEFILE(External/SPEC/Makefile.spec2006)
AC_CONFIG_MAKEFILE(External/SPEC/Makefile.spec2000)
AC_CONFIG_MAKEFILE(External/SPEC/Makefile.spec95)
AC_CONFIG_MAKEFILE(External/SPEC/CFP2006/Makefile)
AC_CONFIG_MAKEFILE(External/SPEC/CINT2006/Makefile)
AC_CONFIG_MAKEFILE(External/SPEC/CFP2000/Makefile)
AC_CONFIG_MAKEFILE(External/SPEC/CINT2000/Makefile)
AC_CONFIG_MAKEFILE(External/SPEC/CFP95/Makefile)
AC_CONFIG_MAKEFILE(External/SPEC/CINT95/Makefile)
AC_CONFIG_MAKEFILE(External/skidmarks10/Makefile)
AC_CONFIG_MAKEFILE(MultiSource/Makefile)
AC_CONFIG_MAKEFILE(MultiSource/Makefile.multisrc)
AC_CONFIG_MAKEFILE(SingleSource/Makefile)
AC_CONFIG_MAKEFILE(SingleSource/Makefile.singlesrc)
AC_CONFIG_MAKEFILE(tools/Makefile)

dnl **************************************************************************
dnl * Get command line options
dnl **************************************************************************

dnl Location of LLVM source code
AC_ARG_WITH(llvmsrc,
  AS_HELP_STRING([--with-llvmsrc=DIR],Location of LLVM Source Code),
  AC_SUBST(LLVM_SRC,[$withval]),
  AC_SUBST(LLVM_SRC,[`cd ${srcdir}/../..; pwd`]))

dnl Location of LLVM object code
AC_ARG_WITH(llvmobj,
  AS_HELP_STRING([--with-llvmobj=DIR],Location of LLVM Object Code),
  AC_SUBST(LLVM_OBJ,[$withval]),
  AC_SUBST(LLVM_OBJ,[`cd ../..; pwd`]))

dnl Location of the parent directory of the external tests
AC_ARG_WITH(externals,
  AS_HELP_STRING([--with-externals=DIR],Location of External Test code),
  AC_SUBST(LLVM_EXTERNALS,[$withval]),
  AC_SUBST(LLVM_EXTERNALS,[$LLVM_SRC/projects/test-suite-externals]))

dnl Configure the default locations of the external benchmarks
EXTERNAL_BENCHMARK(spec95,${LLVM_EXTERNALS}/spec95/benchspec)
EXTERNAL_BENCHMARK(spec2000,${LLVM_EXTERNALS}/speccpu2000/benchspec,[CINT2000])
EXTERNAL_BENCHMARK(spec2006,${LLVM_EXTERNALS}/speccpu2006/benchspec,[CPU2006])
EXTERNAL_BENCHMARK(povray,${LLVM_EXTERNALS}/povray31)
EXTERNAL_BENCHMARK(namd,${LLVM_EXTERNALS}/spec_namd)
EXTERNAL_BENCHMARK(sweep3d,${LLVM_EXTERNALS}/sweep3d)
EXTERNAL_BENCHMARK(fpgrowth,${LLVM_EXTERNALS}/fpgrowth)
EXTERNAL_BENCHMARK(alp,${LLVM_EXTERNALS}/alp)
EXTERNAL_BENCHMARK(nurbs,${LLVM_EXTERNALS}/nurbs)
EXTERNAL_BENCHMARK(hmmer,${LLVM_EXTERNALS}/hmmer)
EXTERNAL_BENCHMARK(skidmarks10,${LLVM_EXTERNALS}/skidmarks10)

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
if test -z "$llvm_cv_gnu_make_command" ; then
  AC_MSG_ERROR([GNU Make required but not found])
fi

dnl Checks for other tools
AC_PROG_LIBTOOL

dnl Check for GNU f2c FORTRAN -> C translator
FIND_STD_PROGRAM(f2c,f2c.h,libf2c.a)
dnl Check for the NAG f95 FORTRAN -> C translator
FIND_STD_PROGRAM(f95,,libf97.dylib,[nag fortran])
CHECK_PROGRAM_SANITY([f95],[-V],[NAGWare Fortran 95],1)
if test -z "$sanity" ; then
  AC_SUBST(USE_F95,[[]])
else
  if test "$sanity" -eq "0" ; then
    AC_SUBST(USE_F95,[[]])
  else
    AC_SUBST(USE_F95,[USE_F95=1])
  fi
fi

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

dnl Get the extension used for shared libraries
AC_LTDL_SHLIBEXT
AC_SUBST(SHLIBEXT,$libltdl_cv_shlibext)

dnl Create the output files
AC_OUTPUT
