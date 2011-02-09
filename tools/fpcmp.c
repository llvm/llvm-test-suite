/*===-- timeit.c - LLVM Test Suite Timing Tool ------------------*- C++ -*-===*\
|*                                                                            *|
|*                     The LLVM Compiler Infrastructure                       *|
|*                                                                            *|
|* This file is distributed under the University of Illinois Open Source      *|
|* License. See LICENSE.TXT for details.                                      *|
|*                                                                            *|
\*===----------------------------------------------------------------------===*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *load_file(const char *path, long *size_out) {
  FILE *fp;
  long size;
  char *data;

  /* Open the file... */
  fp = fopen(path, "rb");
  if (!fp) {
    fprintf(stderr, "error: unable to open '%s'\n", path);
    exit(2);
  }

  /* Determine the file size. */
  if (fseek(fp, 0, SEEK_END) == -1) {
    fprintf(stderr, "error: unable to seek '%s'\n", path);
    exit(2);
  }
  size = ftell(fp);
  if (fseek(fp, 0, SEEK_SET) == -1) {
    fprintf(stderr, "error: unable to seek '%s'\n", path);
    exit(2);
  }

  /* Avoid malloc(0). */
  if (size == 0) {
    *size_out = 0;
    return 0;
  }

  /* Allocate a buffer for the data. */
  data = malloc(size);
  if (!data) {
    fprintf(stderr, "error: unable to allocate buffer for '%s'\n", path);
    exit(2);
  }

  /* Read in the file contents. */
  if (fread(data, size, 1, fp) != 1) {
    fprintf(stderr, "error: unable to read data for '%s'\n", path);
    exit(2);
  }

  /* Close the file and return the data. */
  fclose(fp);
  *size_out = size;
  return data;
}

int diff_files_with_tolerance(const char *path_a, const char *path_b,
                              double absolute_tolerance,
                              double relative_tolerance) {
  /* First, load the file buffers completely into memory. */
  long size_a, size_b;
  char *data_a = load_file(path_a, &size_a);
  char *data_b = load_file(path_b, &size_b);

  /* Fast path equivalent buffers. */
  if (size_a == size_b && memcmp(data_a, data_b, size_a) == 0)
    return 0;

  /* Otherwise, if our tolerances are 0 then we are done. */
  if (relative_tolerance == 0.0 && absolute_tolerance == 0.0)
    return 1;

  /* FIXME: Implement support for relative tolerances. */
  fprintf(stderr, "FIXME: this version of fcmp doesn't "
          "support relative tolerances yet.\n");
  return 2;
}

void usage(const char *program) {
  fprintf(stderr, "usage: %s [-a VALUE] [-r VALUE] <path-A> <path-B>\n\n",
          program);
  fprintf(stderr, "Compare two files using absolute and relative tolerances\n");
  fprintf(stderr, "when comparing differences between two character\n");
  fprintf(stderr, "which could be real numbers\n");
  exit(2);
}

int main(int argc, char * const argv[]) {
  double relative_tolerance = 0.0;
  double absolute_tolerance = 0.0;
  int i;

  for (i = 1; i != argc; ++i) {
    const char *arg = argv[i];
    if (arg[0] != '-')
        break;

    if (strlen(arg) != 2) {
      fprintf(stderr, "error: invalid argument '%s'\n\n", arg);
      usage(argv[0]);
    }

    switch (arg[1]) {
    case 'a':
    case 'r':
      if (i + 1 == argc) {
        fprintf(stderr, "error: missing argument to '%s'\n\n", arg);
        usage(argv[0]);
      } else {
        char *endp = 0;
        double value = strtod(argv[++i], &endp);
        if (endp == 0 || *endp != '\0') {
          fprintf(stderr, "error: invalid argument to '%s': '%s'\n\n", arg,
                  argv[i]);
          usage(argv[0]);
        }
        if (arg[1] == 'a')
          absolute_tolerance = value;
        else
          relative_tolerance = value;
      }
      break;

    default:
      fprintf(stderr, "error: invalid argument '%s'\n\n", arg);
      usage(argv[0]);
    }
  }

  if (i + 2 != argc) {
    fprintf(stderr, "error: invalid number of arguments\n\n");
    usage(argv[0]);
  }

  return diff_files_with_tolerance(argv[i], argv[i + 1],
                                   absolute_tolerance, relative_tolerance);
}
