#include "linear_allocator.h"

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

LinearAllocator *linear_allocator_create(size_t size) {
  LinearAllocator *allocator =
      (LinearAllocator *)malloc(sizeof(LinearAllocator));
  if (!allocator)
    return NULL;

  allocator->memory = malloc(size);
  if (!allocator->memory) {
    free(allocator);
    return NULL;
  }

  allocator->capacity = size;
  allocator->offset = 0;
  return allocator;
}

void *linear_alloc(void *allocator_ptr, size_t size) {
  LinearAllocator *allocator = (LinearAllocator *)allocator_ptr;

  if (allocator->offset + size > allocator->capacity) {
    return NULL;
  }

  void *ptr = (char *)allocator->memory + allocator->offset;
  allocator->offset += size;
  return ptr;
}

void linear_reset(void *allocator_ptr) {
  LinearAllocator *allocator = (LinearAllocator *)allocator_ptr;
  if (allocator) {
    free(allocator->memory);
    free(allocator);
  }
}
