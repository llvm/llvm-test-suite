dnl Configure location of f2c binary, include file, and library
AC_DEFUN([CHECK_F2C_ALL],
[AC_ARG_WITH(f2c,
  AC_HELP_STRING([--with-f2c=DIR], [Use f2c with install prefix DIR]),
  f2cdir=$withval)
AC_MSG_CHECKING([for installed f2c components])
if test -d "$f2cdir" && 
   test -d "$f2cdir/bin" && test -f "$f2cdir/bin/f2c" &&
   test -d "$f2cdir/include" && test -f "$f2cdir/include/f2c.h" &&
   test -d "$f2cdir/lib" && test -f "$f2cdir/lib/libf2c.a"
then
    AC_SUBST(F2C,[$f2cdir/bin/f2c])
    AC_SUBST(F2C_INC,[$f2cdir/include])
    AC_SUBST(F2C_LIB,[$f2cdir/lib])
    checkresult="yes, all 3 found"
    AC_SUBST(USE_F2C,[USE_F2C=1])
else
    AC_SUBST(F2C,[[]])
    AC_SUBST(F2C_INC,[[]])
    AC_SUBST(F2C_LIB,[[]])
    AC_SUBST(USE_F2C,[[]])
    checkresult="no"
fi
AC_MSG_RESULT($checkresult)
])

dnl Check for f2c components individually if they're not installed together
dnl
dnl Check for f2c binary
AC_DEFUN([CHECK_F2C_BIN],
[AC_ARG_WITH(f2cbin,
  AC_HELP_STRING([--with-f2cbin=DIR], [Find f2c binary in DIR]),
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
  AC_HELP_STRING([--with-f2cinc=DIR], [Find f2c.h in DIR]),
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
  AC_HELP_STRING([--with-f2clib=DIR], [Find libf2c.a in DIR]),
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
