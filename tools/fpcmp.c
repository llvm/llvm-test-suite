/*===-- fpcmp.c - LLVM Floating point comparison tool ---------------------===*\
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
#include <stddef.h>
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

static bool isDigitChar(char C) {
  switch (C) {
  case '0': case '1': case '2': case '3': case '4':
  case '5': case '6': case '7': case '8': case '9':
    return true;
  default:
    return false;
  }
}

static bool isPossibleStartOfNumber(char C) {
  return isDigitChar(C) || isSignedChar(C) || C == '.';
}

static const char *AdvanceNumber(const char *StartPos, const char *End) {
  const char *Pos = StartPos;
  const char *EndOfNumber = NULL;

  // Sign character (optional)
  if (Pos < End && isSignedChar(*Pos))
    ++Pos;

  // Pre-decimal digits (optional)
  while (Pos < End && isDigitChar(*Pos)) {
    ++Pos;
    EndOfNumber = Pos;
  }

  // Decimal separator
  if (Pos < End && *Pos == '.') {
    ++Pos;

    // Post-decimal digits (require at least one when period present)
    bool HasPostDecimalDigit = false;
    while (Pos < End && isDigitChar(*Pos)) {
      HasPostDecimalDigit = true;

      ++Pos;
      EndOfNumber = Pos;
    }
    if (!HasPostDecimalDigit)
      return EndOfNumber;
  }

  // Require a valid number before the exponent.
  // (e.g. don't recognize '+e1' as a number)
  if (!EndOfNumber)
    return EndOfNumber;

  // Exponent separator
  if (Pos < End && isExponentChar(*Pos)) {
    ++Pos;

    // Exponent sign (optional)
    if (Pos < End && isSignedChar(*Pos))
      ++Pos;

    // Exponent digits (require at least one when 'e' present)
    while (Pos < End && isDigitChar(*Pos)) {
      ++Pos;
      EndOfNumber = Pos;
    }
  }

  return EndOfNumber;
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
static bool CompareNumbers(const char *F1P, const char *F2P, const char *F1End,
                           const char *F2End, double AbsTolerance,
                           double RelTolerance) {
  const char *F1NumEnd, *F2NumEnd;
  const ptrdiff_t F1Len = F1End - F1P;
  const ptrdiff_t F2Len = F2End - F2P;
  double V1 = 0.0, V2 = 0.0;

  // Fast character-by-character comparison of the numbers.
  if (F1Len == F2Len && memcmp(F1P, F2P, F1Len) == 0)
    return false;

  // Note that some ugliness is built into this to permit support for numbers
  // that use "D" or "d" as their exponential marker, e.g. "1.234D45".  This
  // occurs in 200.sixtrack in spec2k.
  V1 = strtod(F1P, (char **)(&F1NumEnd));
  V2 = strtod(F2P, (char **)(&F2NumEnd));

  if (*F1NumEnd == 'D' || *F1NumEnd == 'd') {
    // Copy string into tmp buffer to replace the 'D' with an 'e'.
    char *StrTmp = malloc(F1Len + 1);
    memcpy(StrTmp, F1P, F1Len + 1);

    // Strange exponential notation!
    StrTmp[(unsigned)(F1NumEnd - F1P)] = 'e';

    V1 = strtod(&StrTmp[0], (char **)(&F1NumEnd));
    F1NumEnd = F1P + (F1NumEnd - &StrTmp[0]);

    free(StrTmp);
  }

  if (*F2NumEnd == 'D' || *F2NumEnd == 'd') {
    // Copy string into tmp buffer to replace the 'D' with an 'e'.
    char *StrTmp = malloc(F2Len + 1);
    memcpy(StrTmp, F2P, F2Len + 1);

    // Strange exponential notation!
    StrTmp[(unsigned)(F2NumEnd - F2P)] = 'e';

    V2 = strtod(&StrTmp[0], (char **)(&F2NumEnd));
    F2NumEnd = F2P + (F2NumEnd - &StrTmp[0]);

    free(StrTmp);
  }

  if (F1NumEnd == F1P || F2NumEnd == F2P) {
    fprintf(stderr, ("%s: FP Comparison failed, not a numeric difference "
                     "between '%c' and '%c'\n"), g_program, F1P[0], F2P[0]);
    return true;
  }

  // Quick check for identical values
  if (V1 == V2)
    return false;

  // Check to see if these are inside the absolute tolerance
  if (AbsTolerance == 0.0 || AbsTolerance < fabs(V1 - V2)) {
    // Nope, check the relative tolerance...
    double Diff;
    if (V2)
      Diff = fabs(V1/V2 - 1.0);
    else if (V1)
      Diff = fabs(V2/V1 - 1.0);
    else
      Diff = 0;  // Both zero.
    if (RelTolerance == 0.0 || Diff > RelTolerance) {
      fprintf(stderr, ("%s: Compared: %e and %e\n"
                       "abs. diff = %e rel.diff = %e\n"
                       "Out of tolerance: rel/abs: %e/%e\n"),
              g_program, V1, V2, fabs(V1-V2), Diff, RelTolerance, AbsTolerance);
      return true;
    }
  }

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

int diff_file(const char *path_a, const char *path_b, bool parse_fp,
              double absolute_tolerance, double relative_tolerance,
              bool ignore_whitespace) {
  /* First, load the file buffers completely into memory. */
  long A_size, B_size;
  char *data_a = load_file(path_a, &A_size);
  char *data_b = load_file(path_b, &B_size);

  /* Fast path equivalent buffers. */
  if (A_size == B_size && memcmp(data_a, data_b, A_size) == 0) {
    free(data_a);
    free(data_b);
    return 0;
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
    // Reached the end of at least one file?
    if (F1P >= File1End || F2P >= File2End) {
      // Skip any whitespace at the end of the file.
      if (ignore_whitespace) {
        skip_whitespace(&F1P, File1End);
        skip_whitespace(&F2P, File2End);
      }
      break;
    }

    // Scan for the end of file or next difference.
    if (*F1P == *F2P && (!parse_fp || !isPossibleStartOfNumber(*F1P))) {
      ++F1P, ++F2P;
      continue;
    }

    // With whitespace ignored, skip whitespace chars (if any) and recheck for
    // the next difference. Otherwise, only ignore whitespace before numbers.
    const char *F1NumStart = F1P;
    const char *F2NumStart = F2P;
    if (ignore_whitespace) {
      if (skip_whitespace(&F1P, File1End) | skip_whitespace(&F2P, File2End))
        continue;
    } else if (parse_fp) {
      skip_whitespace(&F1NumStart, File1End);
      skip_whitespace(&F2NumStart, File2End);
    }

    if (!parse_fp) {
      // In non-floating point mode, recheck for character difference after
      // skipping whitespace.
      if (F1P < File1End && F2P < File2End && *F1P == *F2P) {
        ++F1P, ++F2P;
        continue;
      }
      break;
    }

    const char *F1NumEnd = AdvanceNumber(F1NumStart, File1End);
    const char *F2NumEnd = AdvanceNumber(F2NumStart, File2End);

    // If one side is a number, but not the other, we found a difference.
    if (!F1NumEnd || !F2NumEnd) {
      // If there is no number starting at the current position, it might be a
      // non-numeric difference.
      if (*F1P != *F2P)
        break;

      // Otherwise, try over with the next pair to eventually find the
      // difference or a matching number. Consider:
      //
      //     +1.0
      //     ++1.0
      //
      // Starting with the first + characters, the first will be recognized as a
      // number, but not the second. Only when comparing the second characters
      // both will be recognized as numbers.
      ++F1P, ++F2P;
      continue;
    }

    // Now that we are at the start of the numbers, compare them, exiting if
    // they don't match.
    if (CompareNumbers(F1NumStart, F2NumStart, F1NumEnd, F2NumEnd,
                       absolute_tolerance, relative_tolerance)) {
      free(data_a);
      free(data_b);
      return 1;
    }

    // Numbers compare equal, continue after the numbers.
    F1P = F1NumEnd;
    F2P = F2NumEnd;
  }

  // Okay, we reached the end of file.  If both files are at the end, we
  // succeeded.
  bool F1AtEnd = F1P >= File1End;
  bool F2AtEnd = F2P >= File2End;
  if (!F1AtEnd && !F2AtEnd) {
    fprintf(stderr,
            "%s: Comparison failed, textual difference between '%c' and '%c'\n",
            g_program, F1P[0], F2P[0]);
    free(data_a);
    free(data_b);
    return 1;
  }
  if (!F1AtEnd || !F2AtEnd) {
    fprintf(stderr,
            "%s: Comparison failed, unexpected end of one of the files\n",
            g_program);
    free(data_a);
    free(data_b);
    return 1;
  }

  free(data_a);
  free(data_b);

  return 0;
}

void usage() {
  fprintf(stderr, "usage: %s [-a VALUE] [-r VALUE] [-i] <path-A> <path-B>\n\n",
          g_program);
  fprintf(stderr, "Search two text files for differences.\n"
                  "If either -a or -r is specified (even if zero), floating "
                  "numbers are parsed and considered equal if neither the "
                  "absolute nor relative tolerance is exceeded.\n"
                  "The -i switch also ignores whitespace differences.\n");
  exit(2);
}

int main(int argc, char * const argv[]) {
  double relative_tolerance = 0.0;
  double absolute_tolerance = 0.0;
  bool parse_fp = false;
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
        parse_fp = true;
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

  return diff_file(argv[i], argv[i + 1], parse_fp, absolute_tolerance,
                   relative_tolerance, ignore_whitespace);
}
