#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "linked_node.h"


// RECITATION TODO: Fill out these functions

int add_to_list(linked_node** head, char* content)
{

	linked_node* node = malloc(sizeof(linked_node));

	node->content = content;

	if (*head == NULL) {
		*head = node;
		printf("Added the node with string %s to our linked list as the head\n", node->content);
		return 0;
	}

	linked_node* current_node = *head;

	while(current_node->next != NULL){
		current_node = current_node->next;
	}

	current_node->next = node;

	return 0;
}


void print_list (linked_node* head)
{
  if (head == NULL) {
		printf("Head is null\n");
		return;
	}

	linked_node* current_node = head;
	printf("linked_node -> content\n");
	while (current_node != NULL) {
		printf("%p, %s, %p\n", current_node, current_node->content, current_node->content);
		current_node = current_node->next;
	}
	return ;
}


int delete_list(linked_node** head)
{
	if(*head == NULL) return -1;

	linked_node* current_node = *head;
	linked_node* next_node = current_node->next;

	while(next_node != NULL) {
		printf("Current node to delete: %p, %s\n", &(current_node->content), current_node->content);
		free(current_node->content);
		free(current_node);
		current_node = next_node;
		next_node = next_node->next;
	}
	// We've freed everything except for the last node, so we have to free what's inside of it now
	printf("Current node to delete: %p, %s\n", &(current_node->content), current_node->content);
	free(current_node->content);
	free(current_node);

	// We have ot set the head to null because we have to remove the reference to the location in memory
	// even if there is no room allocated in memory for it.
	*head = NULL;

	return 0;


}
