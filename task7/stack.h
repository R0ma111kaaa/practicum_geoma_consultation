#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 5

typedef struct {
  int arr[MAX_SIZE];
  int top;
} Stack;

void initStack(Stack *stack);

int isEmpty(Stack *stack);

int isFull(Stack *stack);

void push(Stack *stack, int value);

int pop(Stack *stack);