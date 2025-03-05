#include "list.h"
#include <assert.h>
#include <stdio.h>

void testInitList() {
  LinkedList list;
  initList(&list);
  assert(getSize(&list) == 0);
  assert(list.head == NULL);
}

void testAddElements() {
  LinkedList list;
  initList(&list);

  addToEnd(&list, 10);
  assert(getSize(&list) == 1);
  assert(list.head->data == 10);

  addToBeginning(&list, 5);
  assert(getSize(&list) == 2);
  assert(list.head->data == 5);

  addAtIndex(&list, 7, 1);
  assert(getSize(&list) == 3);
  assert(findAtIndex(&list, 1)->data == 7);

  addToEnd(&list, 20);
  assert(getSize(&list) == 4);
  assert(findAtIndex(&list, 3)->data == 20);
}

void testFindAndDelete() {
  LinkedList list;
  initList(&list);
  addToEnd(&list, 10);
  addToEnd(&list, 20);
  addToEnd(&list, 30);

  assert(findAtIndex(&list, 1)->data == 20);

  deleteAtIndex(&list, 1);
  assert(getSize(&list) == 2);
  assert(findAtIndex(&list, 1)->data == 30);
}

int main() {
  testInitList();
  testAddElements();
  testFindAndDelete();
  return 0;
}
