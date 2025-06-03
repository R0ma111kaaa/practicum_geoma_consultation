#include "pool_allocator.h"

#include <stdlib.h>
#include <string.h>

PoolAllocator *pool_allocator_create(size_t block_size, size_t block_count) {
  if (block_size < sizeof(void *)) {
    block_size = sizeof(void *);
  }

  PoolAllocator *allocator = (PoolAllocator *)malloc(sizeof(PoolAllocator));
  if (!allocator)
    return NULL;

  allocator->memory = malloc(block_size * block_count);
  if (!allocator->memory) {
    free(allocator);
    return NULL;
  }

  allocator->block_size = block_size;
  allocator->block_count = block_count;
  allocator->free_list = allocator->memory;

  char *current = (char *)allocator->memory;
  for (size_t i = 0; i < block_count - 1; ++i) {
    *(void **)current = current + block_size;
    current += block_size;
  }
  *(void **)current = NULL;

  return allocator;
}

void *pool_alloc(void *allocator_ptr) {
  PoolAllocator *allocator = (PoolAllocator *)allocator_ptr;

  if (!allocator->free_list)
    return NULL;

  void *block = allocator->free_list;
  allocator->free_list = *(void **)block;
  return block;
}

void pool_free(void *allocator_ptr, void *ptr) {
  PoolAllocator *allocator = (PoolAllocator *)allocator_ptr;

  *(void **)ptr = allocator->free_list;
  allocator->free_list = ptr;
}

void pool_allocator_destroy(PoolAllocator *allocator) {
  if (allocator) {
    free(allocator->memory);
    free(allocator);
  }
}
