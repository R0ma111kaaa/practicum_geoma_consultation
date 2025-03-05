#include "list.h"

Node *createNode(int data) {
  Node *newNode = (Node *)malloc(sizeof(Node));
  if (!newNode) {
    printf("Ошибка выделения памяти\n");
    exit(1);
  }
  newNode->data = data;
  newNode->next = NULL;
  return newNode;
}

void initList(LinkedList *list) {
  list->head = NULL;
  list->size = 0;
}

void addToBeginning(LinkedList *list, int data) {
  Node *newNode = createNode(data);
  newNode->next = list->head;
  list->head = newNode;
  list->size++;
}

void addToEnd(LinkedList *list, int data) {
  Node *newNode = createNode(data);
  if (list->head == NULL) {
    list->head = newNode;
  } else {
    Node *current = list->head;
    while (current->next != NULL) {
      current = current->next;
    }
    current->next = newNode;
  }
  list->size++;
}

void addAtIndex(LinkedList *list, int data, int index) {
  if (index < 0 || index > list->size) {
    printf("Некорректный индекс\n");
    return;
  }
  if (index == 0) {
    addToBeginning(list, data);
  } else if (index == list->size) {
    addToEnd(list, data);
  } else {
    Node *newNode = createNode(data);
    Node *current = list->head;
    for (int i = 0; i < index - 1; i++) {
      current = current->next;
    }
    newNode->next = current->next;
    current->next = newNode;
    list->size++;
  }
}

void deleteAtIndex(LinkedList *list, int index) {
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

Node *findAtIndex(LinkedList *list, int index) {
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

int getSize(LinkedList *list) { return list->size; }

void printList(LinkedList *list) {
  Node *current = list->head;
  printf("[");
  while (current != NULL) {
    if (current->next != NULL) {
      printf("%d, ", current->data);
    } else {
      printf("%d", current->data);
    }
    current = current->next;
  }
  printf("]\n");
}