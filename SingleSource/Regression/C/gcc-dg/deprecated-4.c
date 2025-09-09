/* Test __attribute__ ((deprecated("message"))) */
/* { dg-do compile } */
/* { dg-options "-Wdeprecated-declarations" } */

typedef int INT1 __attribute__((deprecated("Please avoid INT1")));
typedef INT1 INT2 __attribute__ ((__deprecated__("Please avoid INT2")));

typedef INT1 INT1a; 			/* { dg-warning "'INT1' is deprecated: Please avoid INT1" } */
typedef INT1 INT1b __attribute__ ((deprecated("Please avoid INT1b")));

INT1 should_be_unavailable; 		/* { dg-warning "'INT1' is deprecated: Please avoid INT1" } */
INT1a should_not_be_deprecated;

INT1 f1(void) __attribute__ ((deprecated("Please avoid f1"))); 
INT1 f2(void) { return 0; }		/* { dg-warning "'INT1' is deprecated: Please avoid INT1" } */

INT2 f3(void) __attribute__ ((__deprecated__("Please avoid f3"))); 
INT2 f4(void) { return 0; }		/* { dg-warning "'INT2' is deprecated: Please avoid INT2" } */
int f5(INT2 x);				/* { dg-warning "'INT2' is deprecated: Please avoid INT2" } */
int f6(INT2 x) __attribute__ ((__deprecated__("Please avoid f6"))); /* { dg-warning "'INT2' is deprecated: Please avoid INT2" } */

typedef enum {red, green, blue} Color __attribute__((deprecated("Please avoid Color")));

int g1;
int g2 __attribute__ ((deprecated("Please avoid g2")));
int g3 __attribute__ ((__deprecated__("Please avoid g3")));
Color k;				/* { dg-warning "'Color' is deprecated: Please avoid Color" } */

typedef struct {
  int field1;
  int field2 __attribute__ ((deprecated("Please avoid field2")));
  int field3;
  int field4 __attribute__ ((__deprecated__("Please avoid field4")));
  union {
    int field5;
    int field6 __attribute__ ((deprecated("Please avoid field6")));
  } u1;
  int field7:1;
  int field8:1 __attribute__ ((deprecated("Please avoid field8")));
  union {
    int field9;
    int field10;
  } u2 __attribute__ ((deprecated("Please avoid u2")));
} S1;

int func1()
{
   INT1 w;				/* { dg-warning "'INT1' is deprecated: Please avoid INT1" } */
   int x __attribute__ ((deprecated("Avoid x")));
   int y __attribute__ ((__deprecated__("Bad y")));
   int z;
   int (*pf)() = f1;			/* { dg-warning "'f1' is deprecated: Please avoid f1" } */

   z = w + x + y + g1 + g2 + g3;	/* { dg-warning "'x' is deprecated: Avoid x" } */
					/* { dg-warning "'y' is deprecated: Bad y" "y" { target *-*-* } .-1 } */
					/* { dg-warning "'g2' is deprecated: Please avoid g2" "g2" { target *-*-* } .-2 }  */
					/* { dg-warning "'g3' is deprecated: Please avoid g3" "g3" { target *-*-* } .-3 } */
   return f1(); 			/* { dg-warning "'f1' is deprecated: Please avoid f1" } */
}

int func2(S1 *p)
{
  S1 lp;
  
  if (p->field1)
     return p->field2;			/* { dg-warning "'field2' is deprecated: Please avoid field2" } */
  else if (lp.field4)			/* { dg-warning "'field4' is deprecated: Please avoid field4" } */
     return p->field3;
  
  p->u1.field5 = g1 + p->field7;
  p->u2.field9;				/* { dg-warning "'u2' is deprecated: Please avoid u2" } */
  return p->u1.field6 + p->field8;	/* { dg-warning "'field6' is deprecated: Please avoid field6" } */
					/* { dg-warning "'field8' is deprecated: Please avoid field8" "field8" { target *-*-* } .-1 } */
}

struct SS1 {
  int x;
  INT1 y; 				/* { dg-warning "'INT1' is deprecated: Please avoid INT1" } */
} __attribute__ ((deprecated("Please avoid SS1")));

struct SS1 *p1;				/* { dg-warning "'SS1' is deprecated: Please avoid SS1" } */

struct __attribute__ ((__deprecated__("Please avoid SS2"))) SS2 {
  int x;
  INT1 y; 				/* { dg-warning "'INT1' is deprecated: Please avoid INT1" } */
};

struct SS2 *p2;				/* { dg-warning "'SS2' is deprecated: Please avoid SS2" } */
