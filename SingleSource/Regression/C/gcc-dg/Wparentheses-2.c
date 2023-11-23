/* Test operation of -Wparentheses.  Warnings for X<=Y<=Z should be
   there rather than hidden in -Wextra.  */
/* Origin: Joseph Myers <jsm@polyomino.org.uk> */

/* { dg-do compile } */
/* { dg-options "-Wparentheses" } */

int foo (int);

int
bar (int a, int b, int c)
{
  foo (a <= b <= c); /* { dg-warning "mathematical meaning" "correct warning" } */
  foo ((a <= b) <= c);
  foo (a <= (b <= c));
  foo (1 <= 2 <= c); /* { dg-warning "mathematical meaning" "correct warning" } */
  foo ((1 <= 2) <= c);
  foo (1 <= (2 <= c));
  foo (1 <= 2 <= 3); /* { dg-warning "mathematical meaning" "correct warning" } */
  foo ((1 <= 2) <= 3);
  foo (1 <= (2 <= 3));
  foo (a > b > c); /* { dg-warning "mathematical meaning" "correct warning" } */
  foo ((a > b) > c);
  foo (a > (b > c));
  foo (1 > 2 > c); /* { dg-warning "mathematical meaning" "correct warning" } */
  foo ((1 > 2) > c);
  foo (1 > (2 > c));
  foo (1 > 2 > 3); /* { dg-warning "mathematical meaning" "correct warning" } */
  foo ((1 > 2) > 3);
  foo (1 > (2 > 3));
  foo (a < b <= c); /* { dg-warning "mathematical meaning" "correct warning" } */
  foo ((a < b) <= c);
  foo (a < (b <= c));
  foo (1 < 2 <= c); /* { dg-warning "mathematical meaning" "correct warning" } */
  foo ((1 < 2) <= c);
  foo (1 < (2 <= c));
  foo (1 < 2 <= 3); /* { dg-warning "mathematical meaning" "correct warning" } */
  foo ((1 < 2) <= 3);
  foo (1 < (2 <= 3));
  foo (a <= b > c); /* { dg-warning "mathematical meaning" "correct warning" } */
  foo ((a <= b) > c);
  foo (a <= (b > c));
  foo (1 <= 2 > c); /* { dg-warning "mathematical meaning" "correct warning" } */
  foo ((1 <= 2) > c);
  foo (1 <= (2 > c));
  foo (1 <= 2 > 3); /* { dg-warning "mathematical meaning" "correct warning" } */
  foo ((1 <= 2) > 3);
  foo (1 <= (2 > 3));
  foo (a <= b == c); /* { dg-warning "suggest parentheses around comparison" "correct warning" } */
  foo ((a <= b) == c);
  foo (a <= (b == c));
  foo (1 <= 2 == c); /* { dg-warning "suggest parentheses around comparison" "correct warning" } */
  foo ((1 <= 2) == c);
  foo (1 <= (2 == c));
  foo (1 <= 2 == 3); /* { dg-warning "suggest parentheses around comparison" "correct warning" } */
  foo ((1 <= 2) == 3);
  foo (1 <= (2 == 3));
  foo (a != b != c); /* { dg-warning "suggest parentheses around comparison" "correct warning" } */
  foo ((a != b) != c);
  foo (a != (b != c));
  foo (1 != 2 != c); /* { dg-warning "suggest parentheses around comparison" "correct warning" } */
  foo ((1 != 2) != c);
  foo (1 != (2 != c));
  foo (1 != 2 != 3); /* { dg-warning "suggest parentheses around comparison" "correct warning" } */
  foo ((1 != 2) != 3);
  foo (1 != (2 != 3));
  foo (a < b == c);  /* { dg-warning "suggest parentheses around comparison" "correct warning" } */
  foo ((a < b) == c);
  foo (a < (b == c));
  foo (a > b == c);  /* { dg-warning "suggest parentheses around comparison" "correct warning" } */
  foo ((a > b) == c);
  foo (a > (b == c));
  foo (a == b < c);  /* { dg-warning "suggest parentheses around comparison" "correct warning" } */
  foo ((a == b) < c);
  foo (a == (b < c));
  foo (a == b > c);  /* { dg-warning "suggest parentheses around comparison" "correct warning" } */
  foo ((a == b) > c);
  foo (a == (b > c));
  foo (a == b == c);  /* { dg-warning "suggest parentheses around comparison" "correct warning" } */
  foo ((a == b) == c);
  foo (a == (b == c));
  foo (1 == 2 == 3);  /* { dg-warning "suggest parentheses around comparison" "correct warning" } */
  foo ((1 == 2) == 3);
  foo (1 == (2 == 3));
  foo (1 < 2 == 3);  /* { dg-warning "suggest parentheses around comparison" "correct warning" } */
  foo ((1 < 2) == 3);
  foo (1 < (2 == 3));
  foo (1 > 2 == 3);  /* { dg-warning "suggest parentheses around comparison" "correct warning" } */
  foo ((1 > 2) == 3);
  foo (1 > (2 == 3));
  foo (1 == 2 < 3);  /* { dg-warning "suggest parentheses around comparison" "correct warning" } */
  foo ((1 == 2) < 3);
  foo (1 == (2 < 3));
  foo (1 == 2 > 3);  /* { dg-warning "suggest parentheses around comparison" "correct warning" } */
  foo ((1 == 2) > 3);
  foo (1 == (2 > 3));
  foo (a < b != c);  /* { dg-warning "suggest parentheses around comparison" "correct warning" } */
  foo ((a < b) != c);
  foo (a < (b != c));
  foo (a > b != c);  /* { dg-warning "suggest parentheses around comparison" "correct warning" } */
  foo ((a > b) != c);
  foo (a > (b != c));
  foo (a != b < c);  /* { dg-warning "suggest parentheses around comparison" "correct warning" } */
  foo ((a != b) < c);
  foo (a != (b < c));
  foo (a != b > c);  /* { dg-warning "suggest parentheses around comparison" "correct warning" } */
  foo ((a != b) > c);
  foo (a != (b > c));
  foo (1 < 2 != 3);  /* { dg-warning "suggest parentheses around comparison" "correct warning" } */
  foo ((1 < 2) != 3);
  foo (1 < (2 != 3));
  foo (1 > 2 != 3);  /* { dg-warning "suggest parentheses around comparison" "correct warning" } */
  foo ((1 > 2) != 3);
  foo (1 > (2 != 3));
  foo (1 != 2 < 3);  /* { dg-warning "suggest parentheses around comparison" "correct warning" } */
  foo ((1 != 2) < 3);
  foo (1 != (2 < 3));
  foo (1 != 2 > 3);  /* { dg-warning "suggest parentheses around comparison" "correct warning" } */
  foo ((1 != 2) > 3);
  foo (1 != (2 > 3));
}
