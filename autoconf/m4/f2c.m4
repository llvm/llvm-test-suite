dnl Configure location of f2c binary, include file, and library
dnl Parameters:
dnl   $1 - prefix directory to check
AC_DEFUN([CHECK_F2C],
[
if test -d "$1" && 
   test -d "$1/bin" && test -f "$1/bin/f2c" &&
   test -d "$1/include" && test -f "$1/include/f2c.h" &&
   test -d "$1/lib" && test -f "$1/lib/libf2c.a"
then
  AC_SUBST(F2C,[$1/bin/f2c])
  AC_SUBST(F2C_INC,[$1/include])
  AC_SUBST(F2C_LIB,[$1/lib])
  AC_SUBST(USE_F2C,[USE_F2C=1])
  AC_SUBST(F2C_DIR,[$1])
fi
])

AC_DEFUN([CHECK_F2C_ALL],
[AC_ARG_WITH(f2c,
  AS_HELP_STRING(--with-f2c=DIR,[Use f2c with install prefix DIR]),
  [f2cdir=$withval],[f2cdir=notfound])
AC_MSG_CHECKING([for installed f2c components])
if test "$f2cdir" = "notfound" ; then
 f2cdir=`which f2c`
 if test "$f2cdir"x  != "x" ; then 
   if test -d "${f2cdir%*f2c}" -a -d "${f2cdir%*f2c}/.." ; then
     f2cdir=`cd "${f2cdir%*f2c}/.." ; pwd`
     if test ! -d "$f2cdir" ; then
       f2cdir="notfound";
     fi
   fi
 fi
fi
CHECK_F2C($f2cdir)
if test "x$F2C" = "x"; then
  CHECK_F2C("/usr")
  if test "x$F2C" = "x"; then
    CHECK_F2C("/usr/local")
    if test "x$F2C" = "x"; then
      CHECK_F2C("/sw")
      if test "x$F2C" = "x"; then
        CHECK_F2C("/opt")
        if test "x$F2C" = "x"; then
          AC_SUBST(F2C,[[]])
          AC_SUBST(F2C_INC,[[]])
          AC_SUBST(F2C_LIB,[[]])
          AC_SUBST(USE_F2C,[[]])
          checkresult="no"
        else
          checkresult="yes, all 3 found"
        fi
      else
        checkresult="yes, all 3 found"
      fi
    else
      checkresult="yes, all 3 found"
    fi
  else
    checkresult="yes, all 3 found"
  fi
else
  checkresult="yes, all 3 found"
fi
AC_MSG_RESULT($checkresult)
])

dnl Check for f2c components individually if they're not installed together
dnl
dnl Check for f2c binary
AC_DEFUN([CHECK_F2C_BIN],
[AC_ARG_WITH(f2cbin,
  AS_HELP_STRING(--with-f2c-bin=DIR,Find f2c binary in DIR),
  f2cbin=$withval)
AC_MSG_CHECKING([for f2c binary])
if test -d "$f2cbin" && test -f "$f2cbin/f2c"; then
    AC_SUBST(F2C,[$f2cbin/f2c])
    checkresult="yes"
else
    checkresult="no"
fi
AC_MSG_RESULT($checkresult)
])

dnl Check for f2c.h
AC_DEFUN([CHECK_F2C_H],
[AC_ARG_WITH(f2cinc,
  AS_HELP_STRING(--with-f2c-inc=DIR,Find f2c.h in DIR),
  f2cinc=$withval)
AC_MSG_CHECKING([for f2c.h])
if test -d "$f2cinc" && test -f "$f2cinc/f2c.h"; then
    AC_SUBST(F2C_INC,[$f2cinc])
    checkresult="yes"
else
    checkresult="no"
fi
AC_MSG_RESULT($checkresult)
])

dnl Check for libf2c.a
AC_DEFUN([CHECK_F2C_LIB],
[AC_ARG_WITH(f2clib,
  AS_HELP_STRING(--with-f2c-lib=DIR,Find libf2c.a in DIR),
  f2clib=$withval)
AC_MSG_CHECKING([for libf2c.a])
if test -d "$f2clib" && test -f "$f2clib/libf2c.a"; then
    AC_SUBST(F2C_LIB,[$f2clib])
    checkresult="yes"
else
    checkresult="no"
fi
AC_MSG_RESULT($checkresult)
])

dnl Final wrap-up check: to f2c or not to f2c?
AC_DEFUN([CHECK_F2C_ENABLE],
[AC_MSG_CHECKING([whether f2c install is complete])
if test -f "$F2C" && test -d "$F2C_INC" && test -d "$F2C_LIB"; then
    AC_SUBST(USE_F2C,[USE_F2C=1])
    checkresult="yes"
else
    AC_SUBST(USE_F2C,[[]])
    checkresult="no"
fi
AC_MSG_RESULT($checkresult)
])
