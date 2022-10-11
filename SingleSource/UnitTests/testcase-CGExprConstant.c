/*
   This fuzzed program's source comes from
   https://github.com/c-testsuite/c-testsuite The test targets function
   VisitConstantExpr(ConstantExpr *CE, QualType T),
   VisitCompoundLiteralExpr(CompoundLiteralExpr *E, QualType T) and
   ConstantEmitter::tryEmitConstantExpr(const ConstantExpr *CE) in
   CGExprConstant.cpp.
*/
#include <stdint.h>
#include <stdio.h>
#include <inttypes.h>
struct S1 {
  int32_t a;
  int32_t b;
};
struct S2 {
  struct S1 s1;
  struct S1 *ps1;
  int32_t arr[2];
};
struct S1 gs1 = {.a = 1, 2};
struct S2 *s = &(struct S2){{.b = 2, .a = 1}, &gs1, {[0] = 1, 1 + 1}};

int main() {
  if (0)
    return 1;
  if (s->s1.b != 2)
    return 2;
  if (0)
    return 3;
  if (0)
    return 4;
  if (0)
    return 5;
  if (s->arr[1] != 2)
    return 6;
  printf("%" PRId32, s->arr[1]);
  return 0;
}
