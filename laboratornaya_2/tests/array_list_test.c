#include "../array_list.h"
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
  size_t block_size = sizeof(int);
  size_t block_count = 5;

  PoolAllocator *allocator = pool_allocator_create(block_size, block_count);
  ArrayList list;
  arraylist_init(&list, allocator, block_count);

  int a = 5, b = 10, c = 15, d = 20, e = 25;
  arraylist_add(&list, &a, 0);
  arraylist_add(&list, &b, 1);
  arraylist_add(&list, &c, 1);
  arraylist_add(&list, &d, 3);
  arraylist_add(&list, &e, 4);

  assert(*(int *)arraylist_get(&list, 0) == 5);
  assert(*(int *)arraylist_get(&list, 1) == 15);
  assert(*(int *)arraylist_get(&list, 2) == 10);
  assert(*(int *)arraylist_get(&list, 3) == 20);
  assert(*(int *)arraylist_get(&list, 4) == 25);

  arraylist_del(&list, 1);

  assert(*(int *)arraylist_get(&list, 0) == 5);
  assert(*(int *)arraylist_get(&list, 1) == 10);
  assert(*(int *)arraylist_get(&list, 2) == 20);
  assert(*(int *)arraylist_get(&list, 3) == 25);

  int f = 30;
  arraylist_add(&list, &f, 4);
  assert(list.size == 5);

  arraylist_free(&list);

  return 0;
}
