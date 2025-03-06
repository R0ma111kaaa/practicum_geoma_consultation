#include <stdio.h>
#include <stdlib.h>

#include "stack.h"

void initStack(Stack *stack) { stack->top = -1; }

int isEmpty(Stack *stack) { return stack->top == -1; }

int isFull(Stack *stack) { return stack->top == MAX_SIZE - 1; }

void push(Stack *stack, int value) {
  if (isFull(stack)) {
  } else {
    stack->arr[++stack->top] = value;
  }
}

int pop(Stack *stack) {
  if (isEmpty(stack)) {
    return -1;
  } else {
    int poppedValue = stack->arr[stack->top--];
    return poppedValue;
  }
}

