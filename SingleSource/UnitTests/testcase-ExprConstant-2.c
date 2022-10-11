/*
   This fuzzed program's source comes from
   https://github.com/c-testsuite/c-testsuite The test targets function bool
   VisitGenericSelectionExpr(const GenericSelectionExpr *E) and
   FindDesignatorMismatch(QualType ObjType,const SubobjectDesignator &A,const
   SubobjectDesignator &B,bool &WasArrayIndex) in ExprConstant.cpp.
*/
#include <stdio.h>

// Macro is needed for necessary coverage

#define gen_sw(a) _Generic(a, const char * : 1, default : 8, int : 123);

int main() {
  int i = 0;
  printf("%s\n", _Generic(i + (2L + 42), long
                          : "long", int
                          : "int", long long
                          : "long long"));
  return 0;
}
