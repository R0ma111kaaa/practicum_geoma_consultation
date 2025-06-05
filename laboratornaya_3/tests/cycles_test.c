#include "../cycles.h"
#include <assert.h>

int main() {
  PoolAllocator *allocator = pool_allocator_create(128, 100);
  assert(allocator != NULL);

  GCObject *a = gc_object_create(allocator, sizeof(int));
  GCObject *b = gc_object_create(allocator, sizeof(int));
  assert(a != NULL && b != NULL);

  gc_object_add_child(a, b);
  gc_object_add_child(b, a);

  ref_release(allocator, a->ref);
  ref_release(allocator, b->ref);

  GCObject *objects[0];

  gc_collect(allocator, objects, 0);

  pool_allocator_destroy(allocator);
  return 0;
}
