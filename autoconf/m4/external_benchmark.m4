dnl This macro allows an external benchmark to be added
dnl into the configure.ac script more easily. The
dnl arguments are:
dnl   $1 short name of benchmark (e.g. spec95)
dnl   $2 full path to benchmark source
AC_DEFUN([EXTERNAL_BENCHMARK],
[m4_define([allcapsname],translit($1,a-z,A-Z))
 AC_ARG_WITH($1,
 AS_HELP_STRING([--with-$1=DIR],[Use $1 as a benchmark (srcs in DIR)]),
 checkresult=$withval,
 checkresult=auto)
AC_MSG_CHECKING([for $1 benchmark sources])
case "$checkresult" in
auto|yes)
  defaultdir=$2
  if test -d "$defaultdir";  then
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
*)
  if test -d "$checkresult" ; then
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

