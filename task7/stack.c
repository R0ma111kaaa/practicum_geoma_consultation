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

void push(Stack *stack, int value) {
  if (!is_full(stack)) {
    stack->arr[++stack->top] = value;
  }
}

int pop(Stack *stack) {
  if (is_empty(stack)) {
    return -1;
  } else {
    int poppedValue = stack->arr[stack->top--];
    return poppedValue;
  }
}
