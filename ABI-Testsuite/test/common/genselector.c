// Part of the LLVM Project, under the Apache License v2.0 with LLVM Exceptions.
// See https://llvm.org/LICENSE.txt for license information.
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception
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
