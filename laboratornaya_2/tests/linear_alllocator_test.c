#include "../linear_allocator.h"
#include <assert.h>
#include <stdio.h>

int main() {
  LinearAllocator *allocator = linear_allocator_create(128);
  assert(allocator != NULL);
  assert(allocator->memory != NULL);
  assert(allocator->capacity == 128);
  assert(allocator->offset == 0);

  void *ptr1 = linear_alloc(allocator, 32);
  assert(ptr1 != NULL);
  assert(allocator->offset == 32);

  void *ptr2 = linear_alloc(allocator, 96);
  assert(ptr2 != NULL);
  assert(allocator->offset == 128);

  void *ptr3 = linear_alloc(allocator, 1);
  assert(ptr3 == NULL);

  linear_reset(allocator);

  return 0;
}
