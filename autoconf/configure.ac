dnl Initialize autoconf
AC_INIT([[LLVM-TEST]],[[1.4]],[llvmbugs@cs.uiuc.edu])

dnl Place all of the extra autoconf files into the config subdirectory
AC_CONFIG_AUX_DIR([autoconf])

dnl Verify that the source directory is valid
AC_CONFIG_SRCDIR(["Makefile.common.in"])

dnl Do special configuration of Makefiles
AC_CONFIG_MAKEFILE(Makefile)
AC_CONFIG_MAKEFILE(Makefile.tests)
AC_CONFIG_MAKEFILE(Makefile.programs)
AC_CONFIG_MAKEFILE(SingleSource/Makefile)
AC_CONFIG_MAKEFILE(SingleSource/Makefile.singlesrc)
AC_CONFIG_MAKEFILE(MultiSource/Makefile)
AC_CONFIG_MAKEFILE(MultiSource/Makefile.multisrc)
AC_CONFIG_MAKEFILE(External/Makefile)

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

AC_DEFUN(EXTERNAL_BENCHMARK,
[m4_define([allcapsname],translit($1,a-z,A-Z))
 AC_ARG_ENABLE($1,
 AC_HELP_STRING([--enable-$1=ARG], 
                [Use $1 as a benchmark (srcs in DIR)]),
 checkresult=$enableval,
 checkresult=auto)
AC_MSG_CHECKING([for $1 benchmark sources])
case "$checkresult" in
auto|yes)
    defaultdir=$2
	if test -d "$defaultdir"
	then
		AC_SUBST(allcapsname()[_ROOT],[$defaultdir])
		AC_SUBST([USE_]allcapsname(),[USE_]allcapsname()=1)
        checkresult="yes, found in $defaultdir"
    else
        checkresult=no
    fi
    ;;
no)
    AC_SUBST(allcapsname()[_ROOT],[])
    AC_SUBST([USE_]allcapsname(),[])
    checkresult=no
    ;;
*)  if test -d "$checkresult"
    then
        AC_SUBST(allcapsname()[_ROOT],"$checkresult")
        AC_SUBST([USE_]allcapsname(),[USE_]allcapsname()=1)
        checkresult="yes, in $checkresult"
    else
        AC_SUBST(allcapsname()[_ROOT],[])
        AC_SUBST([USE_]allcapsname(),[])
        checkresult="no, not found in $checkresult"
    fi
    ;;
esac
AC_MSG_RESULT($checkresult)
m4_undefine([allcapsname])
])

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
AC_OUTPUT(Makefile.common)
