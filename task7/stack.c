#include <stdio.h>
#include <stdlib.h>

#include "stack.h"

void init_stack(Stack *stack, int size) {
  stack->size = size;
  stack->arr = (int *)malloc(size * sizeof(int));
  stack->top = -1;
}

int is_empty(Stack *stack) { return stack->top == -1; }

int is_full(Stack *stack) { return stack->top == stack->size - 1; }

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
