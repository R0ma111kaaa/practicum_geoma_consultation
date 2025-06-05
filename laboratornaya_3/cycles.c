#include "cycles.h"
#include <stddef.h>

GCObject *gc_object_create(PoolAllocator *allocator, size_t size) {
  GCObject *obj = (GCObject *)pool_alloc(allocator);
  if (!obj)
    return NULL;

  obj->ref = ref_create(allocator, size);
  if (!obj->ref) {
    pool_free(allocator, obj);
    return NULL;
  }

  obj->child_count = 0;
  obj->marked = 0;

  for (size_t i = 0; i < MAX_CHILDREN; ++i) {
    obj->children[i] = NULL;
  }

  return obj;
}

void gc_object_add_child(GCObject *parent, GCObject *child) {
  if (parent->child_count >= MAX_CHILDREN)
    return;

  parent->children[parent->child_count++] = child;
  ref_retain(child->ref);
}

static void gc_mark(GCObject *obj) {
  if (!obj || obj->marked)
    return;

  obj->marked = 1;

  for (size_t i = 0; i < obj->child_count; ++i) {
    gc_mark(obj->children[i]);
  }
}

static void gc_sweep(PoolAllocator *allocator, GCObject **objects,
                     size_t count) {
  for (size_t i = 0; i < count; ++i) {
    GCObject *obj = objects[i];
    if (!obj)
      continue;

    if (!obj->marked && obj->ref->count > 0) {
      for (size_t j = 0; j < obj->child_count; ++j) {
        GCObject *child = obj->children[j];
        if (child)
          ref_release(allocator, child->ref);
      }

      ref_release(allocator, obj->ref);
      pool_free(allocator, obj);
      objects[i] = NULL;
    } else {
      obj->marked = 0;
    }
  }
}

void gc_collect(PoolAllocator *allocator, GCObject **objects, size_t count) {
  for (size_t i = 0; i < count; ++i) {
    if (objects[i] && objects[i]->ref->count > 0) {
      gc_mark(objects[i]);
    }
  }

  gc_sweep(allocator, objects, count);
}
