#include "../gc.h"
#include <assert.h>

typedef struct {
  int value;
} Data;

void test_ref_counting(PoolAllocator *allocator) {
  ref_count_t *ref = ref_create(allocator, sizeof(Data));
  assert(ref != NULL);
  assert(ref->object != NULL);
  assert(ref->count == 1);

  Data *d = (Data *)ref->object;
  d->value = 123;

  ref_retain(ref);
  assert(ref->count == 2);

  ref_retain(ref);
  assert(ref->count == 3);

  ref_release(allocator, ref);
  assert(ref->count == 2);

  ref_release(allocator, ref);
  assert(ref->count == 1);

  ref_retain(ref);
  assert(ref->count == 2);

  ref_release(allocator, ref);
  assert(ref->count == 1);

  ref_retain(ref);
  assert(ref->count == 2);

  ref_retain(ref);
  assert(ref->count == 3);

  ref_release(allocator, ref);
  assert(ref->count == 2);

  ref_release(allocator, ref);
  assert(ref->count == 1);

  ref_release(allocator, ref);
}

int main() {
  size_t block_size =
      sizeof(ref_count_t) > sizeof(Data) ? sizeof(ref_count_t) : sizeof(Data);
  PoolAllocator *allocator = pool_allocator_create(block_size, 50);

  test_ref_counting(allocator);

  pool_allocator_destroy(allocator);
  return 0;
}
