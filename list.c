#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#include "list.h"

// Type this into the terminal
// gcc -c list.c -o list.o
// ar rcs liblist.a list.o
// gcc <file.c> -L. -llist -o <file>

node *createList(int size)
{
    node *lifoList = NULL;

    for (int i = 0; i < size; i++)
    {
        node *n = malloc(sizeof(node));
        if (n == NULL)
        {
            return NULL;
        }
          
        printf("Number: ");
        scanf("%i", &n->number);
        n->next = NULL;
        n->prev = NULL;

        // Prepend node to lists
        n->prev = lifoList;
        lifoList = n;

        node *track = lifoList;
        // Creating a doubly linked list
        if (track->prev != NULL)
        {
            track = track->prev;
            track->next = lifoList;
        }
    }

    node *fifoList = lifoList;
    // Creating a FIFO list,
    while (fifoList->prev != NULL)
    {
        fifoList = fifoList->prev;
    }

    return fifoList;
}

void printList(node *list)
{
    // Counting the size of list
    int size = 0;
    for (node *ptr = list; ptr != NULL; ptr = ptr->next, size++);

    // Printing the numbers
    printf("[");
    int i = 0;
    for (node *ptr = list; ptr != NULL; ptr = ptr->next, i++)
    {
        printf("%i", ptr->number);
        if (i != size - 1)
        {
            printf(", ");
        }
    }
    printf("]\n");
}

void unloadList(node *list)
{
    // Free memory
    node *ptr = list;
    while (ptr != NULL)
    {
        node *tmp = ptr->next;
        free(ptr);
        ptr = tmp;
    }
}

void appendList(node **list, int number)
{
    node *n = malloc(sizeof(node));
    if (n == NULL)
    {
        return;
    }
    
    n->number = number;
    n->next = NULL;
    n->prev = NULL;

    if (*list == NULL)
    {
        *list = n;
        return;
    }

    node *tmp = *list;
    while (tmp->next != NULL)
    {
        tmp = tmp->next;
    }

    tmp->next = n;
    n->prev = tmp;
}
