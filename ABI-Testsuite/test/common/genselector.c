// This file is distributed under the University of Illinois Open Source License.
// See LICENSE.TXT for details.
#include <stdio.h>

int main()
{
  FILE *fp = fopen("nselector.h", "w");
  if (sizeof(long) == 8)
    fprintf(fp, "#define ABI_SELECTOR(a,b,c,d,e) a // LP64\n");
  else
    fprintf(fp, "#define ABI_SELECTOR(a,b,c,d,e) b // ILP32 \n");
  return 0;
}
