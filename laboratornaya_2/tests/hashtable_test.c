#include "../hashtable.h"
#include "../pool_allocator.h"
#include <assert.h>

int main() {
  size_t capacity = 128;

  PoolAllocator *allocator = pool_allocator_create(sizeof(HashNode), capacity);
  HashTable table;
  hashtable_init(&table, capacity, allocator);

  int value1 = 42;
  hashtable_insert(&table, "key1", &value1, sizeof(HashNode));
  int *result1 = (int *)hashtable_get(&table, "key1");
  assert(result1 != NULL);
  assert(*result1 == 42);

  int value2 = 100;
  hashtable_insert(&table, "key1", &value2, sizeof(HashNode));
  int *result2 = (int *)hashtable_get(&table, "key1");
  assert(result2 != NULL);
  assert(*result2 == 100);

  hashtable_del(&table, "key1");
  int *result3 = (int *)hashtable_get(&table, "key1");
  assert(result3 == NULL);

  int value3 = 15;
  hashtable_insert(&table, "", &value3, sizeof(HashNode));
  int *result4 = (int *)hashtable_get(&table, "");
  assert(result4 != NULL);
  assert(*result4 == 15);

  hashtable_free(&table);
  pool_allocator_destroy(allocator);

  return 0;
}
