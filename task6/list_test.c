#include "list.h"
#include <assert.h>
#include <stdio.h>

void test_init_list() {
  LinkedList list;
  init_list(&list);
  assert(get_size(&list) == 0);
  assert(list.head == NULL);
}

void test_add_elements() {
  LinkedList list;
  init_list(&list);

  add_to_end(&list, 10);
  assert(get_size(&list) == 1);
  assert(list.head->data == 10);

  add_to_beginning(&list, 5);
  assert(get_size(&list) == 2);
  assert(list.head->data == 5);

  add_at_index(&list, 7, 1);
  assert(get_size(&list) == 3);
  assert(find_at_index(&list, 1)->data == 7);

  add_to_end(&list, 20);
  assert(get_size(&list) == 4);
  assert(find_at_index(&list, 3)->data == 20);
}

void test_find_and_delete() {
  LinkedList list;
  init_list(&list);
  add_to_end(&list, 10);
  add_to_end(&list, 20);
  add_to_end(&list, 30);

  assert(find_at_index(&list, 1)->data == 20);

  delete_at_index(&list, 1);
  assert(get_size(&list) == 2);
  assert(find_at_index(&list, 1)->data == 30);
}

int main() {
  test_init_list();
  test_add_elements();
  test_find_and_delete();
  return 0;
}
