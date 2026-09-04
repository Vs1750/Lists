# Lists
Linked lists in C that behave like Python's lists, without having the need to recreate one on your own.

This repository consists of the library "list.h", the source file "list.c", a separate program that uses the library "test.c", and the file that I originally wrote my code in "original_list.c".

A description of each of the function:
1. node *createList(int size)
   
   This function creates a linked list, where the user has to input the size of the list. Unlike the usual linked lists in C, this function creates a first-in-first-out (FIFO) linked list. This function will return a list of type node*.
   
2. void printList(node *list)

   This function prints the list out. e.g.: If the list consists of 1, 2 and 3, then it will print out [1, 2, 3].

3. void unloadList(node *list)

   This function frees the memory to prevent memory leak.

4. void appendList(node **list, int number)

   This function prepends an integer at the end of the list. This function takes in the ***address*** of the list, and also the number to append.
