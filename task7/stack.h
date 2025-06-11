#include <stdbool.h>

typedef struct {
  int *arr;
  int size;
  int top;
} Stack;

void init_stack(Stack *stack, int size);
bool is_empty(Stack *stack);
bool is_full(Stack *stack);
bool push(Stack *stack, int value);
bool pop(Stack *stack, int *outValue);
void free_stack(Stack *stack);
