dnl Initialize autoconf
AC_INIT([[LLVM-TEST]],[[1.4]],[llvmbugs@cs.uiuc.edu])

dnl Place all of the extra autoconf files into the config subdirectory
AC_CONFIG_AUX_DIR([autoconf])

dnl Verify that the source directory is valid
AC_CONFIG_SRCDIR(["Makefile.config.in"])

dnl Do special configuration of Makefiles
AC_CONFIG_MAKEFILE(Makefile)
AC_CONFIG_MAKEFILE(Makefile.common)
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
AC_CONFIG_MAKEFILE(External/SPEC/CINT95/Makefile)
AC_CONFIG_MAKEFILE(MultiSource/Makefile)
AC_CONFIG_MAKEFILE(MultiSource/Makefile.multisrc)
AC_CONFIG_MAKEFILE(SingleSource/Makefile)
AC_CONFIG_MAKEFILE(SingleSource/Makefile.singlesrc)

dnl **************************************************************************
dnl * Set the location of various third-party software packages
dnl **************************************************************************

dnl Location of LLVM source code
AC_ARG_WITH(llvmsrc,AC_HELP_STRING([--with-llvmsrc],[Location of LLVM Source Code]),AC_SUBST(LLVM_SRC,[$withval]),AC_SUBST(LLVM_SRC,[`cd ${srcdir}/../..; pwd`]))

dnl Location of LLVM object code
AC_ARG_WITH(llvmobj,AC_HELP_STRING([--with-llvmobj],[Location of LLVM Object Code]),AC_SUBST(LLVM_OBJ,[$withval]),AC_SUBST(LLVM_OBJ,[`cd ../..; pwd`]))

dnl **************************************************************************
dnl * Check for things needed by the test suite programs
dnl **************************************************************************

dnl Check for compilation tools
AC_PROG_CXX
AC_PROG_CC(gcc)
AC_PROG_CPP

dnl Verify that GCC is version 3.0 or higher
gccmajor=`$CC --version | head -n 1 | awk '{print $NF;}' | cut -d. -f1`
if test "$gccmajor" -lt "3"
then
	AC_MSG_ERROR([gcc 3.x required, but you have a lower version])
fi

dnl Check for GNU Make.  We use its extensions too, so don't build without it
CHECK_GNU_MAKE
if test -z "$_cv_gnu_make_command"
then
	AC_MSG_ERROR([GNU Make required but not found])
fi

dnl Checks for other tools
AC_PROG_FLEX
AC_PROG_BISON
AC_PROG_LIBTOOL

AC_PATH_PROG(PYTHON,[python],[true python])
if test "$PYTHON" = "false"
then
	AC_MSG_WARN([Python is required for the test suite, but it was not found])
fi
dnl Verify that the version of python available is high enough for qmtest
pyversion=`$PYTHON -V 2>&1 | cut -d\  -f2`
pymajor=`echo $pyversion | cut -d. -f1`
pyminor=`echo $pyversion | cut -d. -f2`

if test "$pymajor" -ge "2"
then
	if test "$pymajor" -eq "2"
	then
		if test "$pyminor" -lt "2"
		then
			AC_MSG_WARN([QMTest requires Python 2.2 or later])
		fi
	fi
else
	AC_MSG_WARN([QMTest requires Python 2.2 or later])
fi

dnl Checks for header files.
dnl We don't check for ancient stuff or things that are guaranteed to be there
dnl by the C++ standard. We always use the <cfoo> versions of <foo.h> C headers.
AC_HEADER_STDC
AC_HEADER_SYS_WAIT

dnl Determine if the linker supports the -R option.
AC_LINK_USE_R

dnl Configure the default locations of the external benchmarks
EXTERNAL_BENCHMARK(spec95,/home/vadve/shared/benchmarks/spec95/benchspec)
EXTERNAL_BENCHMARK(spec2000,/home/vadve/shared/benchmarks/speccpu2000/benchspec)
EXTERNAL_BENCHMARK(povray,/home/vadve/shared/benchmarks/povray31)

dnl Precompiled Bytecode Option
AC_ARG_ENABLE(precompiled_bytecode,AC_HELP_STRING([--enable-precompiled_bytecode],[Use pre-compiled bytecode (default is NO)]),,enableval=no)
if test ${enableval} = "no"
then
	AC_SUBST(UPB,[[]])
else
	AC_SUBST(UPB,[[USE_PRECOMPILED_BYTECODE=1]])
fi

dnl Location of the bytecode repository
AC_ARG_WITH(bcrepos,AC_HELP_STRING([--with-bcrepos],[Location of Bytecode Repository]),AC_SUBST(BCR,[$withval]),AC_SUBST(BCR,[/home/vadve/lattner/LLVMPrograms]))

dnl Location of PAPI
AC_ARG_WITH(papi,AC_HELP_STRING([--with-papi],[Location of PAPI]),AC_SUBST(PAPIDIR,[$withval]),AC_SUBST(PAPIDIR,[/home/vadve/shared/Sparc/papi-2.3.4.1]))

dnl Create the output files
AC_OUTPUT(Makefile.config)
