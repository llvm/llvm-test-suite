#ifndef MVSSUPPORT_H
#define MVSSUPPORT_H

/*
  A function to mirror what posix_memalign does. This function aligns
  allocated memory to a specific alignment. This is needed on z/OS, as
  malloc by defaults aligns memory to 16-byte boundaries. 

  Use this function only in scenarios where you absolutely have to 
  provide an alternate to posix_memalign/aligned_alloc/memalign etc. 
  
  Most benchmarks have alternate options. Eg: foregoing heap allocation 
  in favour of stack allocation, using regular malloc calls as opposed to 
  an aligned malloc call etc.
*/
static void *allocateAlignedMemory(size_t allocation_size, size_t alignment) {
  void *mem_default;
  void **mem_aligned;
  int extra_size = alignment - 1 + sizeof(void *);
  mem_default = (void *)malloc(allocation_size + extra_size);
  mem_aligned = (void **)(((size_t)(mem_default) + extra_size) & ~(alignment - 1));
  mem_aligned[-1] = mem_default;
  return mem_aligned;
}

/*
 free() also deallocates memory allocated by posix_memalign/aligned_alloc etc
 However, in this case we need to explicitly free the memory malloc'd by 
*/

static void freeAlignedMemory(void *memory) {
  free(((void **)memory)[-1]);
}
#endif // MVSSUPPORT_H 
