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

int main(void)
{
    int size;
    do
    {
        printf("Size of list: ");
        scanf("%i", &size);
    }
    while (size <= 0);

    node *list = createList(size);
    printList(list);

    // Asking user if they want to append a number to the list
    char append_a_number;
    printf("Do you want to append a number? (Y/N): ");
    scanf(" %c", &append_a_number);
    if (tolower(append_a_number) == 'y')
    {
        int append_number;
        printf("Number to append: ");
        scanf("%i", &append_number);
        appendList(&list, append_number);
    }

    printList(list);
    unloadList(list);
}

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