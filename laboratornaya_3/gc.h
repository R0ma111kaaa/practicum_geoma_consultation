
#include "../laboratornaya_2/pool_allocator.h"
#include <stddef.h>

typedef struct {
  size_t count;
  void *object;
} ref_count_t;

ref_count_t *ref_create(PoolAllocator *allocator, size_t size);
void ref_retain(ref_count_t *ref);
void ref_release(PoolAllocator *allocator, ref_count_t *ref);
