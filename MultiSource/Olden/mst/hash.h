/* For copyright information, see olden_v1.0/COPYRIGHT */

#include "stdio.h"

typedef struct hash_entry {
  unsigned int key;
  void *entry;
  struct hash_entry *next;
#ifdef JUMP
  struct hash_entry *pf_ptr;
#endif
} *HashEntry;

typedef struct hash {
  HashEntry *array;
  int (*mapfunc)(unsigned int);
  int size;
} *Hash;

Hash MakeHash(int size, int (*map)(unsigned int));
void *HashLookup(unsigned int key, Hash hash);
void HashInsert(void *entry,unsigned int key, Hash hash);
void HashDelete(unsigned int key, Hash hash);
