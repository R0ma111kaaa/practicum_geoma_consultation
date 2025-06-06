#include "destructors.h"
#include <string.h>

ref_count_ext_t *ref_create_ext(PoolAllocator *allocator, size_t size,
                                destructor_fn dtor) {
  ref_count_ext_t *ref = (ref_count_ext_t *)pool_alloc(allocator);
  if (!ref)
    return NULL;

  ref->object = pool_alloc(allocator);
  if (!ref->object) {
    pool_free(allocator, ref);
    return NULL;
  }

  ref->count = 1;
  ref->dtor = dtor;
  memset(ref->object, 0, size);

  return ref;
}

void ref_retain_ext(ref_count_ext_t *ref) {
  if (ref)
    ref->count++;
}

void ref_release_ext(PoolAllocator *allocator, ref_count_ext_t *ref) {
  if (!ref)
    return;

  if (--ref->count == 0) {
    if (ref->dtor)
      ref->dtor(ref->object);
    pool_free(allocator, ref->object);
    pool_free(allocator, ref);
  }
}
