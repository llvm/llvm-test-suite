/*===-- macho_arch.c - LLVM Test Suite Mach-O Support Tool ------*- C++ -*-===*\
|*                                                                            *|
|* Part of the LLVM Project, under the Apache License v2.0 with LLVM          *|
|* Exceptions.                                                                *|
|* See https://llvm.org/LICENSE.txt for license information.                  *|
|* SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception                    *|
|*                                                                            *|
\*===----------------------------------------------------------------------===*/

#include <errno.h>
#include <mach-o/ldsyms.h>
#include <mach-o/utils.h>
#include <mach/machine.h>
#include <stdio.h>
#include <string.h>
#include <sys/sysctl.h>

int main(int argc, const char **argv) {
  if (__builtin_available(macOS 13.0, iOS 16.0, tvOS 16.0, watchOS 9.0, *)) {
    if (argc > 2 && strcmp(argv[1], "--is-supported") == 0) {
      cpu_type_t cpu_type;
      cpu_subtype_t cpu_subtype;
      return macho_cpu_type_for_arch_name(argv[2], &cpu_type, &cpu_subtype) ? 0 : 1;
    }

    const char *arch_name = macho_arch_name_for_mach_header(NULL);
    if (!arch_name) {
      fprintf(stderr, "error: unknown cpu type for current process\n");
      return 1;
    }
    printf("%s\n", arch_name);
    return 0;
  }
  fprintf(stderr, "error: requires macOS 13.0, iOS 16.0, tvOS 16.0, or watchOS 9.0\n");
  return 1;
}
