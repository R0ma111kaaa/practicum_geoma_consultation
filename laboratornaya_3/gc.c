#include "gc.h"
#include <string.h>

ref_count_t *ref_create(PoolAllocator *allocator, size_t size) {
  ref_count_t *ref = (ref_count_t *)pool_alloc(allocator);
  if (!ref)
    return NULL;

  ref->object = pool_alloc(allocator);
  if (!ref->object) {
    pool_free(allocator, ref);
    return NULL;
  }

  ref->count = 1;
  memset(ref->object, 0, size);
  return ref;
}

void ref_retain(ref_count_t *ref) {
  if (ref)
    ref->count++;
}

void ref_release(PoolAllocator *allocator, ref_count_t *ref) {
  if (!ref)
    return;
  if (--ref->count == 0) {
    pool_free(allocator, ref->object);
    pool_free(allocator, ref);
  }
}
