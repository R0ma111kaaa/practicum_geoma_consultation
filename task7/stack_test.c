#include "stack.h"

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

void test_initStack() {
  Stack stack;
  init_stack(&stack, 50);
  assert(stack.top == -1);
  free_stack(&stack);
}

void test_push() {
  Stack stack;
  init_stack(&stack, 5);

  push(&stack, 10);
  assert(stack.top == 0);
  assert(stack.arr[stack.top] == 10);

  push(&stack, 20);
  assert(stack.top == 1);
  assert(stack.arr[stack.top] == 20);

  push(&stack, 30);
  assert(stack.top == 2);
  assert(stack.arr[stack.top] == 30);
  free_stack(&stack);
}

void test_pop() {
  Stack stack;
  init_stack(&stack, 5);

  push(&stack, 10);
  push(&stack, 20);
  push(&stack, 30);

  int element;
  assert(pop(&stack, &element) && element == 30);
  assert(stack.top == 1);

  assert(pop(&stack, &element) && element == 20);
  assert(stack.top == 0);

  assert(pop(&stack, &element) && element == 10);
  assert(stack.top == -1);
  free_stack(&stack);
}

void test_push_after_pop() {
  Stack stack;
  init_stack(&stack, 5);

  push(&stack, 10);
  push(&stack, 20);

  int element;
  pop(&stack, &element);

  push(&stack, 40);
  assert(stack.top == 1);
  assert(stack.arr[stack.top] == 40);

  push(&stack, 50);
  assert(stack.top == 2);
  assert(stack.arr[stack.top] == 50);

  push(&stack, 60);
  assert(stack.top == 3);
  assert(stack.arr[stack.top] == 60);
  free_stack(&stack);
}

int main() {
  test_initStack();
  test_push();
  test_pop();
  test_push_after_pop();
  return 0;
}
