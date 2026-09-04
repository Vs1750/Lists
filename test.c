#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#include "list.h"

int main(void)
{
    // A test of the library and the functions if the list is empty
    
    node *list = NULL;
    appendList(&list, 1);
    printList(list);
}
