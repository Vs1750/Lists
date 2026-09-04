#ifndef LIST_H
#define LIST_H

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

typedef struct node
{
    int number;
    struct node *next;
    struct node *prev;
}
node;

node *createList(int size);
void printList(node *list);
void unloadList(node *list);
void appendList(node **list, int number);

#endif // LIST_H