#include <stddef.h>

typedef struct HashNode {
  char *key;
  void *value;
  struct HashNode *next;
} HashNode;

typedef struct HashTable {
  HashNode **buckets;
  size_t capacity;
  void *allocator;
} HashTable;

void hashtable_init(HashTable *table, size_t capacity, void *allocator);
void hashtable_insert(HashTable *table, const char *key, const void *value,
                      size_t value_size);
void *hashtable_get(HashTable *table, const char *key);
void hashtable_del(HashTable *table, const char *key);
void hashtable_free(HashTable *table);
