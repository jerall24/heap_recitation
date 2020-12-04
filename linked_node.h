typedef struct linked_node {
	char* content ;
	struct linked_node *next ;
} linked_node ;

int add_to_list(linked_node** head, char* content);
void print_list(linked_node* head);
int delete_list(linked_node** head);
