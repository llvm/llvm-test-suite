/* { dg-do compile } */
/* { dg-options "-Wunused" } */
/* { dg-final { scan-assembler "string_to_look_for" } } */
/* nvptx outputs strings as array of ints.  */
/* { dg-skip-if "" { nvptx-*-* } } */

/* 'volatile' variables get output and don't produce a warning about being
   unused.  */
static volatile char string[] 
  = "string_to_look_for";  /* { dg-bogus "not used" } */
