/*===-- timeit.c - LLVM Test Suite Timing Tool ------------------*- C++ -*-===*\
|*                                                                            *|
|* Part of the LLVM Project, under the Apache License v2.0 with LLVM          *|
|* Exceptions.                                                                *|
|* See https://llvm.org/LICENSE.txt for license information.                  *|
|* SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception                    *|
|*                                                                            *|
\*===----------------------------------------------------------------------===*/

/* Note that this file is essentially a bastardized C version of
 * FileUtilities.cpp from LLVM. */

#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

const char *g_program;

/* *** */

typedef int bool;
#define true ((bool) 1)
#define false ((bool) 0)

static bool isSignedChar(char C) {
  return (C == '+' || C == '-');
}

static bool isExponentChar(char C) {
  switch (C) {
  case 'D':  // Strange exponential notation.
  case 'd':  // Strange exponential notation.
  case 'e':
  case 'E': return true;
  default: return false;
  }
}

static bool isNumberChar(char C) {
  switch (C) {
  case '0': case '1': case '2': case '3': case '4':
  case '5': case '6': case '7': case '8': case '9':
  case '.': return true;
  default: return isSignedChar(C) || isExponentChar(C);
  }
}

static const char *BackupNumber(const char *Pos, const char *FirstChar,
                                const char *End) {
  // If already at the very beginning, we cannot go back further.
  // It ensures that the access Pos[-1] is valid.
  // This also handles the case where the file is empty (FirstChar == End).
  if (Pos == FirstChar)
    return Pos;

  // If we didn't stop in the middle of a number, don't backup.
  if (!(Pos == End || isNumberChar(*Pos)) && !isNumberChar(Pos[-1]))
    return Pos;

  // If we're one past the number, the two numbers can have different number
  // of digits. Even if we're wrong, and we get the previous number, the
  // comparison should have failed anyway.
  if (Pos == End || !isNumberChar(*Pos))
    Pos--;

  // Otherwise, return to the start of the number.
  bool HasPeriod = false;
  while (Pos > FirstChar && isNumberChar(Pos[-1])) {
    // Backup over at most one period.
    if (Pos[-1] == '.') {
      if (HasPeriod)
        break;
      HasPeriod = true;
    }

    --Pos;
    if (Pos > FirstChar && isSignedChar(Pos[0]) && !isExponentChar(Pos[-1]))
      break;
  }
  return Pos;
}

/// EndOfNumber - Return the first character that is not part of the specified
/// number.  This assumes that the buffer is null terminated, so it won't fall
/// off the end.
static const char *EndOfNumber(const char *Pos) {
  while (isNumberChar(*Pos))
    ++Pos;
  return Pos;
}

static bool skip_whitespace(const char **FP, const char *FEnd) {
  bool skipped_some = false;
  while (*FP < FEnd && isspace((unsigned char)**FP)) {
    skipped_some = true;
    ++*FP;
  }
  return skipped_some;
}

/// CompareNumbers - compare two numbers, returning true if they are different.
static bool CompareNumbers(const char **F1PP, const char **F2PP,
                           const char *F1End, const char *F2End,
                           double AbsTolerance, double RelTolerance) {
  const char *F1P = *F1PP;
  const char *F2P = *F2PP;
  const char *F1NumEnd, *F2NumEnd;
  double V1 = 0.0, V2 = 0.0;

  // If one of the positions is at a space and the other isn't, chomp up 'til
  // the end of the space.
  skip_whitespace(&F1P, F1End);
  skip_whitespace(&F2P, F2End);

  if (F1P == F1End || F2P == F2End) {
    fprintf(stderr, ("%s: FP Comparison failed, reached end of file\n"),
            g_program);
    return true;
  }

  // If we stop on numbers, compare their difference.
  if (!isNumberChar(*F1P) || !isNumberChar(*F2P)) {
    // The diff failed.
    F1NumEnd = F1P;
    F2NumEnd = F2P;
  } else {
    // Note that some ugliness is built into this to permit support for numbers
    // that use "D" or "d" as their exponential marker, e.g. "1.234D45".  This
    // occurs in 200.sixtrack in spec2k.
    V1 = strtod(F1P, (char**)(&F1NumEnd));
    V2 = strtod(F2P, (char**)(&F2NumEnd));

    if (*F1NumEnd == 'D' || *F1NumEnd == 'd') {
      // Copy string into tmp buffer to replace the 'D' with an 'e'.
      char StrTmp[200];
      memcpy(StrTmp, F1P, EndOfNumber(F1NumEnd)+1 - F1P);
      // Strange exponential notation!
      StrTmp[(unsigned)(F1NumEnd-F1P)] = 'e';

      V1 = strtod(&StrTmp[0], (char**)(&F1NumEnd));
      F1NumEnd = F1P + (F1NumEnd-&StrTmp[0]);
    }

    if (*F2NumEnd == 'D' || *F2NumEnd == 'd') {
      // Copy string into tmp buffer to replace the 'D' with an 'e'.
      char StrTmp[200];
      memcpy(StrTmp, F2P, EndOfNumber(F2NumEnd)+1 - F2P);
      // Strange exponential notation!
      StrTmp[(unsigned)(F2NumEnd-F2P)] = 'e';

      V2 = strtod(&StrTmp[0], (char**)(&F2NumEnd));
      F2NumEnd = F2P + (F2NumEnd-&StrTmp[0]);
    }
  }

  if (F1NumEnd == F1P || F2NumEnd == F2P) {
    fprintf(stderr, ("%s: FP Comparison failed, not a numeric difference "
                     "between '%c' and '%c'\n"), g_program, F1P[0], F2P[0]);
    return true;
  }

  // Check to see if these are inside the absolute tolerance
  if (AbsTolerance < fabs(V1-V2)) {
    // Nope, check the relative tolerance...
    double Diff;
    if (V2)
      Diff = fabs(V1/V2 - 1.0);
    else if (V1)
      Diff = fabs(V2/V1 - 1.0);
    else
      Diff = 0;  // Both zero.
    if (Diff > RelTolerance) {
      fprintf(stderr, ("%s: Compared: %e and %e\n"
                       "abs. diff = %e rel.diff = %e\n"
                       "Out of tolerance: rel/abs: %e/%e\n"),
              g_program, V1, V2, fabs(V1-V2), Diff, RelTolerance, AbsTolerance);
      return true;
    }
  }

  // Otherwise, advance our read pointers to the end of the numbers.
  *F1PP = F1NumEnd;  *F2PP = F2NumEnd;
  return false;
}

/* *** */

char *load_file(const char *path, long *size_out) {
  FILE *fp;
  long size;
  char *data;

  /* Open the file... */
  fp = fopen(path, "rb");
  if (!fp) {
    fprintf(stderr, "%s: error: unable to open '%s'\n", g_program, path);
    exit(2);
  }

  /* Determine the file size. */
  if (fseek(fp, 0, SEEK_END) == -1) {
    fprintf(stderr, "%s: error: unable to seek '%s'\n", g_program, path);
    exit(2);
  }
  size = ftell(fp);
  if (fseek(fp, 0, SEEK_SET) == -1) {
    fprintf(stderr, "%s: error: unable to seek '%s'\n", g_program, path);
    exit(2);
  }

  /* Avoid malloc(0). */
  if (size == 0) {
    *size_out = 0;
    return 0;
  }

  /* Allocate a buffer for the data. */
  data = malloc(size + 1);
  if (!data) {
    fprintf(stderr, "%s: error: unable to allocate buffer for '%s'\n",
            g_program, path);
    exit(2);
  }

  /* Read in the file contents. */
  data[size] = 0;
  if (fread(data, size, 1, fp) != 1) {
    fprintf(stderr, "%s: error: unable to read data for '%s'\n",
            g_program, path);
    exit(2);
  }

  /* Close the file and return the data. */
  fclose(fp);
  *size_out = size;
  return data;
}

int diff_files_with_tolerance(const char *path_a, const char *path_b,
                              double absolute_tolerance,
                              double relative_tolerance,
                              bool ignore_whitespace) {
  /* First, load the file buffers completely into memory. */
  long A_size, B_size;
  char *data_a = load_file(path_a, &A_size);
  char *data_b = load_file(path_b, &B_size);

  /* Fast path equivalent buffers. */
  if (A_size == B_size && memcmp(data_a, data_b, A_size) == 0)
    return 0;

  /* Otherwise, if our tolerances are 0 then we are done. */
  if (relative_tolerance == 0.0 && absolute_tolerance == 0.0 &&
      !ignore_whitespace) {
    fprintf(stderr, "%s: files differ without tolerance allowance\n",
            g_program);
    return 1;
  }

  /* *** */

  // Okay, now that we opened the files, scan them for the first difference.
  const char *File1Start = data_a;
  const char *File2Start = data_b;
  const char *File1End = data_a + A_size;
  const char *File2End = data_b + B_size;
  const char *F1P = File1Start;
  const char *F2P = File2Start;

  while (1) {
    // Scan for the end of file or next difference.
    while (F1P < File1End && F2P < File2End) {
      if (*F1P == *F2P) {
        ++F1P, ++F2P;
        continue;
      }

      // With whitespace ignored, skip whitespace chars (if any) and recheck for
      // the next difference.
      if (ignore_whitespace) {
        if (skip_whitespace(&F1P, File1End) | skip_whitespace(&F2P, File2End))
          continue;
      }

      break;
    }

    if (F1P >= File1End || F2P >= File2End) break;

    // BackupNumber will also backup when at the first char after a number. This
    // is to catch when one of the number has more trailing floating-point zeros
    // than the other. However, when this is the case in both buffers, we'd
    // repeat the most recent number forever.
    // Therefore, we fast-stop if both buffers have no number at the current
    // position.
    if (!isNumberChar(*F1P) && !isNumberChar(*F2P)) {
      fprintf(stderr, "%s: FP Comparison failed, not a numeric difference "
                      "between '%c' and '%c'\n",
              g_program, F1P[0], F2P[0]);
      return 1;
    }

    // Okay, we must have found a difference.  Backup to the start of the
    // current number each stream is at so that we can compare from the
    // beginning.
    F1P = BackupNumber(F1P, File1Start, File1End);
    F2P = BackupNumber(F2P, File2Start, File2End);

    // Now that we are at the start of the numbers, compare them, exiting if
    // they don't match.
    if (CompareNumbers(&F1P, &F2P, File1End, File2End,
                       absolute_tolerance, relative_tolerance))
      return 1;
  }

  // Skip any whitespace at the end of the file.
  if (ignore_whitespace) {
    skip_whitespace(&F1P, File1End);
    skip_whitespace(&F2P, File2End);
  }

  // Okay, we reached the end of file.  If both files are at the end, we
  // succeeded.
  bool F1AtEnd = F1P >= File1End;
  bool F2AtEnd = F2P >= File2End;
  if (!F1AtEnd || !F2AtEnd) {
    // Else, we might have run off the end due to a number: backup and retry.
    F1P = BackupNumber(F1P, File1Start, File1End);
    F2P = BackupNumber(F2P, File2Start, File2End);

    // Now that we are at the start of the numbers, compare them, exiting if
    // they don't match.
    if (CompareNumbers(&F1P, &F2P, File1End, File2End,
                       absolute_tolerance, relative_tolerance))
      return 1;

    // There might be more whitespace after the number.
    if (ignore_whitespace) {
      skip_whitespace(&F1P, File1End);
      skip_whitespace(&F2P, File2End);
    }

    // If we found the end, we succeeded.
    if (F1P < File1End || F2P < File2End)
      return 1;
  }

  return 0;
}

void usage() {
  fprintf(stderr, "usage: %s [-a VALUE] [-r VALUE] [-i] <path-A> <path-B>\n\n",
          g_program);
  fprintf(stderr, "Compare two files using absolute and relative tolerances\n");
  fprintf(stderr, "when comparing differences between two character\n");
  fprintf(stderr, "which could be real numbers\n");
  fprintf(stderr, "The -i switch ignores whitespace differences\n");
  exit(2);
}

int main(int argc, char * const argv[]) {
  double relative_tolerance = 0.0;
  double absolute_tolerance = 0.0;
  bool ignore_whitespace = false;
  int i;

  g_program = argv[0];
  for (i = 1; i != argc; ++i) {
    const char *arg = argv[i];
    if (arg[0] != '-')
        break;

    if (strlen(arg) != 2) {
      fprintf(stderr, "error: invalid argument '%s'\n\n", arg);
      usage();
    }

    switch (arg[1]) {
    case 'a':
    case 'r':
      if (i + 1 == argc) {
        fprintf(stderr, "error: missing argument to '%s'\n\n", arg);
        usage();
      } else {
        char *endp = 0;
        double value = strtod(argv[++i], &endp);
        if (endp == 0 || *endp != '\0') {
          fprintf(stderr, "error: invalid argument to '%s': '%s'\n\n", arg,
                  argv[i]);
          usage();
        }
        if (arg[1] == 'a')
          absolute_tolerance = value;
        else
          relative_tolerance = value;
      }
      break;

    case 'i':
      ignore_whitespace = true;
      break;

    default:
      fprintf(stderr, "error: invalid argument '%s'\n\n", arg);
      usage();
    }
  }

  if (i + 2 != argc) {
    fprintf(stderr, "error: invalid number of arguments\n\n");
    usage();
  }

  return diff_files_with_tolerance(argv[i], argv[i + 1], absolute_tolerance,
                                   relative_tolerance, ignore_whitespace);
}
