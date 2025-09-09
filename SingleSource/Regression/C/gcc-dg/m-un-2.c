/* { dg-do compile } */
/* { dg-options "-W -Wall" } */

typedef __SIZE_TYPE__ size_t;
extern void* malloc (size_t);
extern void free (void*);
extern void* realloc (void*, size_t);

struct vtable {
  void* (* _malloc) (size_t);
  void (* _free) (void*);
  void* (* _realloc) (void*, size_t); /* { dg-line vtable_realloc } */
};

struct vtable mtable = {
  malloc,
  free
}; /* { dg-warning "missing initializer" "warning regression" } */
   /* { dg-message "declared here" "warning regression 2" { target *-*-* } vtable_realloc } */

/* With designated initializers, we assume you meant to leave out the
   initialization of any blank fields.  */
struct vtable mtable2 = {
  ._malloc = malloc,
  ._realloc = realloc
};

struct vtable mtable3 = {
  ._free = free,
  ._malloc = malloc,
  ._realloc = realloc
};
