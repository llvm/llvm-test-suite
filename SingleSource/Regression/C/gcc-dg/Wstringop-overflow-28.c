/* PR middle-end/91582 - missing heap overflow detection for strcpy
   { dg-do compile }
   { dg-options "-O2 -Wall -Wno-array-bounds -ftrack-macro-expansion=0" } */

#include "range.h"

#define INT_MAX     __INT_MAX__
#define INT_MIN     (-INT_MAX - 1)

#define ATTR(...)   __attribute__ ((__VA_ARGS__))
#define NOIPA       ATTR (noipa)

extern void* alloca (size_t);
extern void* calloc (size_t, size_t);
extern void* malloc (size_t);

extern ATTR (alloc_size (1), malloc) char* alloc1 (size_t);
extern ATTR (alloc_size (1, 2), malloc) char* alloc2 (size_t, size_t);

extern char* strcpy (char*, const char*);

void sink (void*, ...);


/* Verify warning in stores to an object of variable size N in a known
   range, at an offset (N + I) with a constant I.  */

void same_size_and_offset_idx_cst (void)
{
#define T(size, off, idx) do {			\
    size_t n_ = size;				\
    ptrdiff_t i_ = idx;				\
    char *p_ = alloc1 (n_);			\
    p_ += off;					\
    p_[i_] = 0;					\
    sink (p_);					\
  } while (0)

  {
    const size_t n = UR (2, 3);

    T (n, n, -4);   // { dg-warning "writing 1 byte into a region of size 0" }
                    // { dg-message "at offset \\\[-2, -1] into destination object of size \\\[2, 3] allocated by 'alloc1'" "note" { target *-*-* } .-1 }
    T (n, n, -3);
    T (n, n, -2);
    T (n, n, -1);
    T (n, n,  0);
    T (n, n,  1);   // { dg-warning "writing 1 byte into a region of size 0" }
                    // { dg-message "at offset 3 into destination object of size \\\[2, 3] allocated by 'alloc1'" "note" { target *-*-* } .-1 }
  }

  {
    const size_t n = UR (3, 4);

    T (n, n, -5);   // { dg-warning "writing 1 byte into a region of size 0" }
                    // { dg-message "at offset \\\[-2, -1] into destination object of size \\\[3, 4] allocated by 'alloc1'" "note" { target *-*-* } .-1 }
    T (n, n, -4);
    T (n, n, -3);
    T (n, n, -2);
    T (n, n, -1);
    T (n, n,  0);
    T (n, n,  1);   // { dg-warning "writing 1 byte into a region of size 0" }
                    // { dg-message "at offset 4 into destination object of size \\\[3, 4] allocated by 'alloc1'" "note" { target *-*-* } .-1 }
  }

  {
    const size_t n = UR (5, SIZE_MAX - 2);
    T (n, n, -1);
    T (n, n, -1);
    T (n, n, -1);
    T (n, n, -1);
  }
}


/* Verify warning in stores to an object of variable size N in a known
   range, at an offset (M + I) with a variable M in some range and
   constant I.  */

void different_size_and_offset_idx_cst (void)
{
  {
    const size_t n = UR (2, 3);
    const size_t i = UR (1, 2);

    T (n, i, -4);   // { dg-warning "writing 1 byte into a region of size 0" }
                    // { dg-message "at offset \\\[-3, -2] into destination object of size \\\[2, 3] allocated by 'alloc1'" "note" { target *-*-* } .-1 }
    T (n, i, -3);   // { dg-warning "writing 1 byte into a region of size 0" }
                    // { dg-message "at offset \\\[-2, -1] into destination object of size \\\[2, 3] allocated by 'alloc1'" "note" { target *-*-* } .-1 }
    T (n, i, -2);
    T (n, i, -1);
    T (n, i,  0);
    T (n, i,  1);
    T (n, i,  2);   // { dg-warning "writing 1 byte into a region of size 0" }
                    // { dg-message "at offset 3 into destination object of size \\\[2, 3] allocated by 'alloc1'" "note" { target *-*-* } .-1 }
  }

  {
    const size_t n = UR (3, 4);
    const size_t i = UR (2, 5);

    T (n, i, -6);   // { dg-warning "writing 1 byte into a region of size 0" }
                    // { dg-message "at offset \\\[-4, -2] into destination object of size \\\[3, 4] allocated by 'alloc1'" "note" { target *-*-* } .-1 }

    /* The offset -5 is necessarily invalid even if the sum (i - 5) is (or
       could be) in bounds because it implies that the intermediate offset
       (p + i) is out of bounds.  */
    T (n, i, -5);   // { dg-warning "writing 1 byte into a region of size 0 " }
    T (n, i, -4);
    T (n, i, -3);
    T (n, i, -2);
    T (n, i, -1);
    T (n, i,  0);
    T (n, i,  1);
    T (n, i,  2);   // { dg-warning "writing 1 byte into a region of size 0" }
                    // { dg-message "at offset 4 into destination object of size \\\[3, 4] allocated by 'alloc1'" "note" { target *-*-* } .-1 }
  }
}


/* Verify warning in stores to an object of variable size N in a known
   range, at an offset (M + I) with a variable M in some range and
   constant I.  */
void different_size_and_offset_idx_var (void)
{
  {
    const size_t n = UR (3, 4);
    const size_t i = UR (1, 2);

    T (n, i, SR (DIFF_MIN, 0));
    T (n, i, SR (      -3, 0));
    T (n, i, SR (      -1, 0));
    T (n, i, SR (       0, 1));
    T (n, i, SR (       1, 2));
    T (n, i, SR (       2, 3));
    T (n, i, SR (       3, 4));    // { dg-warning "\\\[-Wstringop-overflow" }
                                   // { dg-message "at offset 4 into destination object of size \\\[3, 4] allocated by 'alloc1'" "pr92940 note: offset addition" { target *-*-* } .-1 }
 }
}


void ptr_add_2 (int n, int i0, int i1)
{
  if (n < 1 || 2 < n) n = 2;

  if (i0 < 0 || 1 < i0) i0 = 0;
  if (i1 < 1 || 2 < i1) i1 = 1;

  char *p = (char*)__builtin_malloc (n);
  char *q = p;

  q += i0;
  q[0] = 0;   // p[0]
  q += i1;
  q[0] = 1;   // p[1]     // { dg-warning "\\\[-Wstringop-overflow" "" { target { vect_slp_v2qi_store_unalign } } }
  q[1] = 2;   // p[2]     // { dg-warning "\\\[-Wstringop-overflow" "" { xfail { vect_slp_v2qi_store_unalign } } }

  sink (p, q);
}

void ptr_add_3 (int n, int i0, int i1, int i2)
{
  if (n < 3 || 4 < n) n = 3;

  if (i0 < 0 || 1 < i0) i0 = 0;
  if (i1 < 1 || 2 < i1) i1 = 1;
  if (i2 < 2 || 3 < i2) i2 = 2;

  char *p = (char*)__builtin_malloc (n);
  char *q = p;

  q += i0;
  q[0] = 0;   // p[0]
  q += i1;
  q[0] = 1;   // p[1]
  q[1] = 2;   // p[2]
  q += i2;
  q[0] = 3;   // p[3]     // { dg-warning "\\\[-Wstringop-overflow" "" { target { vect_slp_v2qi_store_unalign } } }
  q[1] = 4;   // p[4]     // { dg-warning "\\\[-Wstringop-overflow" "" { xfail { vect_slp_v2qi_store_unalign } } }

  sink (p, q);
}

void ptr_add_4 (int n, int i0, int i1, int i2, int i3)
{
  if (n < 7 || 8 < n) n = 7;

  if (i0 < 0 || 1 < i0) i0 = 0;
  if (i1 < 1 || 2 < i1) i1 = 1;
  if (i2 < 2 || 3 < i2) i2 = 2;
  if (i3 < 3 || 4 < i3) i3 = 3;

  char *p = (char*)__builtin_malloc (n);
  char *q = p;

  q += i0;
  q[0] = 0;   // p[0]
  q += i1;
  q[0] = 1;   // p[1]
  q[1] = 2;   // p[2]
  q += i2;
  q[0] = 3;   // p[3]
  q[1] = 4;   // p[4]
  q[2] = 5;   // p[5]
  q += i3;
  q[0] = 6;   // p[6]
  q[1] = 7;   // p[7]
  q[2] = 8;   // p[8]     // { dg-warning "\\\[-Wstringop-overflow" }

  sink (p, q);
}

void ptr_sub_from_end (int n, int i0, int i1, int i2, int i3)
{
  if (n < 1 || 2 < n) n = 2;

  char *p = (char*)__builtin_malloc (n);
  char *q = p;

  // The following isn't diagnosed due to a bug/limitation.
  q += n;      //  N=1     N=2
  q[-1] = 0;   // p[0]    p[1]
  q[-2] = 1;   // p[-1]   p[0]
  q[-3] = 2;   // p[-2]   p[-1]   // { dg-warning "\\\[-Wstringop-overflow" "pr92939: negative offset from end" }

  /* The following isn't diagnosed because the warning doesn't recognize
     the index below as necessarily having the same value as the size
     argument to malloc.  All it considers is the range.  */
  q[0] = 2;                       // { dg-warning "\\\[-Wstringop-overflow" "pr92937: store just past the end" { xfail *-*-* } }
  q[1] = 3;                       // { dg-warning "\\\[-Wstringop-overflow" }

  sink (p, q);
}
