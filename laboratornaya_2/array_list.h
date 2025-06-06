#include "pool_allocator.h"
#include <stddef.h>

typedef struct {
  void **items;
  size_t capacity;
  size_t size;
  PoolAllocator *allocator;
} ArrayList;

void arraylist_init(ArrayList *list, PoolAllocator *allocator, size_t capacity);
void arraylist_add(ArrayList *list, void *data, size_t index);
void *arraylist_get(ArrayList *list, size_t index);
void arraylist_del(ArrayList *list, size_t index);
void arraylist_free(ArrayList *list);
