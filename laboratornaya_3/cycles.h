#pragma once
#include "gc.h"
#define MAX_CHILDREN 8

typedef struct GCObject {
  ref_count_t *ref;
  struct GCObject *children[MAX_CHILDREN];
  size_t child_count;
  int marked;
} GCObject;

GCObject *gc_object_create(PoolAllocator *allocator, size_t size);
void gc_object_add_child(GCObject *parent, GCObject *child);
void gc_collect(PoolAllocator *allocator, GCObject **objects, size_t count);
