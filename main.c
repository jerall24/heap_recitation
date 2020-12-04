#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "linked_node.h"

int main() {
  // getchar();

  /*
    Dynamic memory versus static memory

    Different data structures - arrays versus linked lists
  */
  int len = strlen("This string is not malloced.")+1;
  printf("%d\n", len);
  char array1[100] = "This string is not malloced.";
  for(int i  = 0; i < 10; i++ ) {
    printf("Address of %c: %p\n", array1[i], &array1[i]);
    // printf("Address of %c: %s\n", array1[i], &array1[i]);
    // We get a fun output when we change the %x to an %s
    // Why is that the ouput?
  }

  // getchar();
  /*
  It's a waste of space to always create a string using: char string[100]
  If the string will not be 99 characters long right?
  So we use malloc (memory allocate) to allocate space in the HEAP
  */

  // For my recitation, the reason we were having an issue is because by using:
  // list1 = "FARMER2024" we are overwriting the char* list pointer to be somewhere
  // in static memory, aka memory that wasn't malloced. This was causing us to get
  // the error. To get around this, we need to modify the malloced memory by using
  // sprintf() function.

  // Old code that wasn't working:
  // char* list1 = malloc(sizeof(char)*11);
  // list1 = "FARMER2024";

  char* list1 = malloc(sizeof(char)*11);
  sprintf(list1, "%s", "FARMER2024");
  char* list2 = malloc(sizeof(char)*11);
  sprintf(list2, "%s", "FARMER2025");
  char* list3 = malloc(sizeof(char)*11);
  sprintf(list3, "%s", "FARMER2026");

  printf("list1: %p, &list1: %p\n", list1, &list1);
  for(int i = 0; i < 11; i++){
    printf("Address in list: %c, %p\n", list1[i], &list1[i]);
  }

  // getchar();

  linked_node* head = NULL;

  // TODO: Why am I passing a  &head instead of just head?
  add_to_list(&head, list1);
  add_to_list(&head, list2);
  add_to_list(&head, list3);

  printf("Before delete call\n");
  print_list(head);

  // getchar();

  delete_list(&head);

  printf("After delete call\n");
  print_list(head);

  return 0;
}
