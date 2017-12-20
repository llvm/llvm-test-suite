dnl This macro checks features using gcc and cpuinit
dnl Set variables HAVE_X86_$feature_INSTRUCTIONS into 
dnl the configure.config.
dnl Based on ax_gcc_x86_cpu_support and ax_check_x86_features.

AC_DEFUN_ONCE([CPU_INIT],
 [AC_LANG_PUSH([C])
  AC_CACHE_CHECK([for gcc __builtin_cpu_init function],
    [ax_cv_check_x86_cpu_init],
    [AC_RUN_IFELSE(
      [AC_LANG_PROGRAM([#include <stdlib.h>],
        [__builtin_cpu_init ();])
      ],
      [ax_cv_check_x86_cpu_init=yes],
      [ax_cv_check_x86_cpu_init=no])])
  AS_IF([test "X$ax_cv_check_x86_cpu_init" = "Xno"],
    [AC_MSG_ERROR([Need GCC to support X86 CPU features tests])])
])

AC_DEFUN([CPU_SUPPORTS],
  [AC_REQUIRE([AC_PROG_CC])
   AC_REQUIRE([CPU_INIT])
   AC_LANG_PUSH([C])
   AS_VAR_PUSHDEF([feature], [AS_TR_SH([ax_cv_cpu_supports_$1])])
   AC_CACHE_CHECK([for x86 $1 instruction support],
     [feature],
     [AC_RUN_IFELSE(
       [AC_LANG_PROGRAM( [#include <stdlib.h> ],
       [ __builtin_cpu_init ();
         if (__builtin_cpu_supports("$1"))
           return 0;
         return 1;
        ])],
        [feature=yes],
        [feature=no]
     )]
   )
   AC_LANG_POP([C])
   AS_IF([test "$feature" = "yes"],
         [AC_SUBST(
           AS_TR_CPP([HAVE_X86_$1_INSTRUCTIONS]),
           [1],
           [Define if $1 instructions are supported])
         ],
          [AC_SUBST(
           AS_TR_CPP([HAVE_X86_$1_INSTRUCTIONS]),
           [0])
          ]
         )
   AS_VAR_POPDEF([feature])
])


AC_DEFUN([CHECK_X86_FEATURES],
 [m4_foreach_w(
   [feature],
   [mmx popcnt sse sse2 sse3 sse4.1 sse4.2 avx avx2 avx512f avx512vl avx512bw avx512dq fma fma4 bmi bmi2],
   [CPU_SUPPORTS(feature)])
  $2
])

