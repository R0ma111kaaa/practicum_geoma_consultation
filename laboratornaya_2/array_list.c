#include "array_list.h"
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void arraylist_init(ArrayList *list, PoolAllocator *allocator,
                    size_t capacity) {
  list->allocator = allocator;
  list->capacity = capacity;
  list->size = 0;

  list->items = (void **)malloc(sizeof(void *) * capacity);
  assert(list->items != NULL);
}

void arraylist_add(ArrayList *list, void *data, size_t index) {
  if (index > list->size || list->size >= list->capacity) {
    return;
  }

  for (size_t i = list->size; i > index; --i) {
    list->items[i] = list->items[i - 1];
  }

  void *new_block = pool_alloc(list->allocator);
  if (!new_block) {
    return;
  }

  memcpy(new_block, data, list->allocator->block_size);
  list->items[index] = new_block;
  list->size++;
}

void *arraylist_get(ArrayList *list, size_t index) {
  if (index >= list->size) {
    return NULL;
  }
  return list->items[index];
}

void arraylist_del(ArrayList *list, size_t index) {
  if (index >= list->size || index < 0) {
    return;
  }

  pool_free(list->allocator, list->items[index]);

  for (size_t i = index; i < list->size - 1; ++i) {
    list->items[i] = list->items[i + 1];
  }

  list->size--;
}

void arraylist_free(ArrayList *list) {
  if (!list)
    return;

  for (size_t i = 0; i < list->size; ++i) {
    pool_free(list->allocator, list->items[i]);
  }

  free(list->items);
  list->items = NULL;
  list->size = 0;
}
