#include <stddef.h>

typedef struct PoolAllocator {
  void *memory;
  void *free_list;
  size_t block_size;
  size_t block_count;
} PoolAllocator;

PoolAllocator *pool_allocator_create(size_t block_size, size_t block_count);
void *pool_alloc(void *allocator);
void pool_free(void *allocator, void *ptr);
void pool_allocator_destroy(PoolAllocator *allocator);
