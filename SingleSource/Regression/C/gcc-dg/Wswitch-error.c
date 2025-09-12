
/* { dg-do compile } */
/* { dg-options "-Werror=switch -Wswitch-enum" } */

enum e { e1, e2 };

int
foo (int i, int j, enum e ei, enum e ej, enum e ek, enum e el,
     enum e em, enum e en, enum e eo, enum e ep)
{
  switch (i)
    {
    case 1: return 1;
    case 2: return 2;
    }
  switch (j)
    {
    case 3: return 4;
    case 4: return 3;
    default: break;
    }
  switch (ei) /* { dg-error "enumeration value 'e1' not handled in switch" "enum e1" } */
    { /* { dg-error "enumeration value 'e2' not handled in switch" "enum e2" { target *-*-* } .-1 } */
    }
  switch (ej) /* { dg-warning "enumeration value 'e1' not handled in switch" "enum e1" } */
    { /* { dg-warning "enumeration value 'e2' not handled in switch" "enum e2" { target *-*-* } .-1 } */
    default: break;
    }
  switch (ek) /* { dg-error "enumeration value 'e2' not handled in switch" "enum e2" } */
    {
    case e1: return 1;
    }
  switch (el) /* { dg-warning "enumeration value 'e2' not handled in switch" "enum e2" } */
    {
    case e1: return 1;
    default: break;
    }
  switch (em)
    {
    case e1: return 1;
    case e2: return 2;
    }
  switch (en)
    {
    case e1: return 1;
    case e2: return 2;
    default: break;
    }
  switch (eo)
    {
    case e1: return 1;
    case e2: return 2;
    case 3: return 3; /* { dg-error "case value '3' not in enumerated type 'enum e'" "excess 3" } */
    }
  switch (ep)
    {
    case e1: return 1;
    case e2: return 2;
    case 3: return 3; /* { dg-error "case value '3' not in enumerated type 'enum e'" "excess 3" } */
    default: break;
    }
  return 0;
}
/* { dg-message "some warnings being treated as errors" "" {target "*-*-*"} 0 } */
