#ifndef LINKED_LIST_H
#define LINKED_LIST_H

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

Node *createNode(int data);
void initList(LinkedList *list);
void addToBeginning(LinkedList *list, int data);
void addToEnd(LinkedList *list, int data);
void addAtIndex(LinkedList *list, int data, int index);
void deleteAtIndex(LinkedList *list, int index);
Node *findAtIndex(LinkedList *list, int index);
int getSize(LinkedList *list);
void printList(LinkedList *list);

#endif