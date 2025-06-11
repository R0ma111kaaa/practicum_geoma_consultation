#include "hashtable.h"
#include "pool_allocator.h"

#include <stdlib.h>
#include <string.h>

static size_t hash_string(const char *str, size_t capacity) {
  size_t hash = 5631;
  while (*str) {
    hash = (hash << 5) + hash + (unsigned char)(*str++);
  }
  return hash % capacity;
}

void hashtable_init(HashTable *table, size_t capacity, void *allocator) {
  table->capacity = capacity;
  table->allocator = allocator;
  table->buckets = (HashNode **)calloc(capacity, sizeof(HashNode *));
}

void hashtable_insert(HashTable *table, const char *key, const void *value,
                      size_t value_size) {
  size_t index = hash_string(key, table->capacity);
  HashNode *node = table->buckets[index];

  while (node) {
    if (strcmp(node->key, key) == 0) {
      void *new_value = malloc(value_size);
      if (!new_value)
        return;

      memcpy(new_value, value, value_size);
      free(node->value);
      node->value = new_value;
      return;
    }
    node = node->next;
  }

  HashNode *new_node = (HashNode *)pool_alloc(table->allocator);
  if (!new_node)
    return;

  size_t key_len = strlen(key) + 1;
  char *key_copy = (char *)malloc(key_len);
  if (!key_copy) {
    pool_free(table->allocator, new_node);
    return;
  }
  memcpy(key_copy, key, key_len);

  void *value_copy = malloc(value_size);
  if (!value_copy) {
    free(key_copy);
    pool_free(table->allocator, new_node);
    return;
  }
  memcpy(value_copy, value, value_size);

  new_node->key = key_copy;
  new_node->value = value_copy;
  new_node->next = table->buckets[index];
  table->buckets[index] = new_node;
}

void *hashtable_get(HashTable *table, const char *key) {
  size_t index = hash_string(key, table->capacity);
  HashNode *node = table->buckets[index];

  while (node) {
    if (strcmp(node->key, key) == 0) {
      return node->value;
    }
    node = node->next;
  }
  return NULL;
}

void hashtable_del(HashTable *table, const char *key) {
  size_t index = hash_string(key, table->capacity);
  HashNode *node = table->buckets[index];
  HashNode *prev = NULL;

  while (node) {
    if (strcmp(node->key, key) == 0) {
      if (prev)
        prev->next = node->next;
      else
        table->buckets[index] = node->next;

      free(node->key);
      pool_free(table->allocator, node);
      return;
    }
    prev = node;
    node = node->next;
  }
}

void hashtable_free(HashTable *table) {
  for (size_t i = 0; i < table->capacity; ++i) {
    HashNode *node = table->buckets[i];
    while (node) {
      HashNode *next = node->next;
      free(node->key);
      pool_free(table->allocator, node);
      node = next;
    }
  }
  free(table->buckets);
}
