#include "../laboratornaya_2/pool_allocator.h"
#include <stddef.h>

typedef void (*destructor_fn)(void *);

typedef struct {
  size_t count;
  void *object;
  destructor_fn dtor;
} ref_count_ext_t;

ref_count_ext_t *ref_create_ext(PoolAllocator *allocator, size_t size,
                                destructor_fn dtor);

void ref_retain_ext(ref_count_ext_t *ref);

void ref_release_ext(PoolAllocator *allocator, ref_count_ext_t *ref);
