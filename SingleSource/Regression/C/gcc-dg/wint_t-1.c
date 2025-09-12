/* { dg-do compile { target wchar } } */
/* { dg-options "-Wall" } */

/* Compile with -Wall to get a warning if built-in and system wint_t don't
   match.  */

#define _STDDEF_H
#include <wchar.h>

__WINT_TYPE__ __wi_t__;
wint_t *wi_t_p;

void
wit (void)
{
  wi_t_p = &__wi_t__;
}
