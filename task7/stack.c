#include <stdio.h>
#include <stdlib.h>

#include "stack.h"

void init_stack(Stack *stack, int size) {
  stack->size = size;
  stack->arr = (int *)malloc(size * sizeof(int));
  stack->top = -1;
}

bool is_empty(Stack *stack) { return stack->top == -1; }

bool is_full(Stack *stack) { return stack->top == stack->size - 1; }

bool push(Stack *stack, int value) {
  if (is_full(stack)) {
    return false;
  }
  stack->arr[++stack->top] = value;
  return true;
}

bool pop(Stack *stack, int *outValue) {
  if (is_empty(stack)) {
    return false;
  } else {
    *outValue = stack->arr[stack->top--];
    return true;
  }
}

void free_stack(Stack *stack) {
  if (stack->arr != NULL) {
    free(stack->arr);
    stack->arr = NULL;
  }
  stack->size = 0;
  stack->top = -1;
}
