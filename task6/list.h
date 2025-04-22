#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
  int data;
  struct Node *next;
} Node;

typedef struct {
  Node *head;
  int size;
} LinkedList;

Node *create_node(int data);
void init_list(LinkedList *list);
void add_to_beginning(LinkedList *list, int data);
void add_to_end(LinkedList *list, int data);
void add_at_index(LinkedList *list, int data, int index);
void delete_at_index(LinkedList *list, int index);
Node *find_at_index(LinkedList *list, int index);
int get_size(LinkedList *list);
