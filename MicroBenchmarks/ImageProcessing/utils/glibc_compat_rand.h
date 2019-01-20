/*===------------- glibc_compat_rand.h- glibc rand emulation --------------===*\
|*
|* Part of the LLVM Project, under the Apache License v2.0 with LLVM Exceptions.
|* See https://llvm.org/LICENSE.txt for license information.
|* SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception
|*
\*===----------------------------------------------------------------------===*/

#ifndef GLIBC_COMPAT_RAND_H
#define GLIBC_COMPAT_RAND_H
#ifdef __cplusplus
extern "C" {
#endif
int glibc_compat_rand(void);
void glibc_compat_srand(unsigned int seed);
#ifdef __cplusplus
}
#endif
#endif /* GLIBC_COMPAT_RAND_H */
