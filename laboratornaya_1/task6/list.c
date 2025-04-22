#include "list.h"

Node *create_node(int data) {
  Node *new_node = (Node *)malloc(sizeof(Node));
  if (!new_node) {
    printf("Ошибка выделения памяти\n");
    exit(1);
  }
  new_node->data = data;
  new_node->next = NULL;
  return new_node;
}

void init_list(LinkedList *list) {
  list->head = NULL;
  list->size = 0;
}

void add_to_beginning(LinkedList *list, int data) {
  Node *new_node = create_node(data);
  new_node->next = list->head;
  list->head = new_node;
  list->size++;
}

void add_to_end(LinkedList *list, int data) {
  Node *new_node = create_node(data);
  if (list->head == NULL) {
    list->head = new_node;
  } else {
    Node *current = list->head;
    while (current->next != NULL) {
      current = current->next;
    }
    current->next = new_node;
  }
  list->size++;
}

void add_at_index(LinkedList *list, int data, int index) {
  if (index < 0 || index > list->size) {
    printf("Некорректный индекс\n");
    return;
  }
  if (index == 0) {
    add_to_beginning(list, data);
  } else if (index == list->size) {
    add_to_end(list, data);
  } else {
    Node *new_node = create_node(data);
    Node *current = list->head;
    for (int i = 0; i < index - 1; i++) {
      current = current->next;
    }
    new_node->next = current->next;
    current->next = new_node;
    list->size++;
  }
}

void delete_at_index(LinkedList *list, int index) {
  if (index < 0 || index >= list->size) {
    printf("Некорректный индекс\n");
    return;
  }
  Node *temp;
  if (index == 0) {
    temp = list->head;
    list->head = list->head->next;
  } else {
    Node *current = list->head;
    for (int i = 0; i < index - 1; i++) {
      current = current->next;
    }
    temp = current->next;
    current->next = temp->next;
  }
  free(temp);
  list->size--;
}

Node *find_at_index(LinkedList *list, int index) {
  if (index < 0 || index >= list->size) {
    printf("Некорректный индекс\n");
    return NULL;
  }
  Node *current = list->head;
  for (int i = 0; i < index; i++) {
    current = current->next;
  }
  return current;
}

int get_size(LinkedList *list) { return list->size; }
