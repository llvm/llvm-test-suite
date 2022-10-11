/*
   The test targets function operator<(const PHIUsageRecord &RHS) in
   InstCombinePHI.cpp.
*/
#include <stdint.h>
#include <stdio.h>
#pragma pack(1)
struct S {
  int32_t a : 18;
  int32_t b : 1;
  int32_t c : 24;
  int32_t d : 15;
  int32_t e : 14;
} h;
int f;
int main(void) {
  for (; f; f++) {
    struct S m = {5, 0, -5, 9, 5};
    h = m;
  }
  if (h.d != (long)0 - h.d * h.d)
    printf("1");
  return 0;
}
