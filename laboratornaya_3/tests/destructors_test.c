#include "../destructors.h"
#include <assert.h>
#include <string.h>

int destructor_called = 0;

typedef struct {
  int x;
  char name[16];
} MyObject;

void my_object_destructor(void *obj) {
  (void)((MyObject *)obj);
  destructor_called = 1;
}

void test_with_destructor(PoolAllocator *allocator) {
  destructor_called = 0;
  ref_count_ext_t *ref =
      ref_create_ext(allocator, sizeof(MyObject), my_object_destructor);
  assert(ref != NULL);

  MyObject *obj = (MyObject *)ref->object;
  obj->x = 42;
  strcpy(obj->name, "TestObj");

  ref_retain_ext(ref);
  ref_release_ext(allocator, ref);
  ref_release_ext(allocator, ref);
  assert(destructor_called == 1);
}

void test_without_destructor(PoolAllocator *allocator) {
  ref_count_ext_t *ref = ref_create_ext(allocator, sizeof(int), NULL);
  assert(ref != NULL);
  int *value = (int *)ref->object;
  *value = 123;
  ref_release_ext(allocator, ref);
}

void test_retain_release(PoolAllocator *allocator) {
  destructor_called = 0;
  ref_count_ext_t *ref =
      ref_create_ext(allocator, sizeof(MyObject), my_object_destructor);
  assert(ref != NULL);

  ref_retain_ext(ref);
  ref_retain_ext(ref);
  ref_release_ext(allocator, ref);
  ref_release_ext(allocator, ref);
  assert(destructor_called == 0);
  ref_release_ext(allocator, ref);
  assert(destructor_called == 1);
}

int main() {
  PoolAllocator *allocator = pool_allocator_create(128, 20);
  assert(allocator != NULL);

  test_with_destructor(allocator);
  test_without_destructor(allocator);
  test_retain_release(allocator);

  pool_allocator_destroy(allocator);
  return 0;
}
