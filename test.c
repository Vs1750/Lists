#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#include "list.h"

int main(void)
{
    node *list = NULL;
    appendList(&list, 1);
    printList(list);
}