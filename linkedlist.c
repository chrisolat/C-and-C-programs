#include <stdio.h>
#include <stdlib.h>

void add_value();
void reverse_list();
void print_list();
void clear_list();

struct node {
	int value;
	struct node* next;
};
struct node* HEAD = NULL;

void add_value(){
	puts("Enter num to add");
	int val;
	scanf("%d", &val);
	struct node* newnode = malloc(sizeof(struct node));
	newnode->value = val;
	newnode->next = NULL;
	if(HEAD == NULL){
		HEAD = newnode;
		HEAD->next = NULL;
		return;
	}
	struct node* curr = HEAD;
	while(curr->next != NULL){
		curr = curr->next;
	}
	curr->next = newnode;
	return;
}

void reverse_list(){
	struct node* prev = NULL;
	struct node* curr = HEAD;
	
	while(curr != NULL){
		struct node* next = curr->next;
		curr->next = prev;
		prev = curr;
		curr = next;
	}
	HEAD = prev;
	return;
}

void print_list(){
	struct node* curr = HEAD;
	while(curr != NULL){
		printf("%d ", curr->value);
		curr = curr->next;
	}
	puts("\n");
	return;
}

void clear_list(){
	struct node* curr = HEAD;
	while(curr != NULL){
		struct node* prev = curr;
		curr = curr->next;
		free(prev);
	}
	HEAD = curr;
	return;
}

int main(int argc, char* argv[]){
	while(1){
		puts("Enter operation 1 - 3");
		puts("1. Add to list");
		puts("2. Reverse list");
		puts("3. Print list");
		puts("4. Clear list");
		
		int operation;
		if((scanf("%d", &operation)) != 1){
			puts("Invalid option\n");
			while(getchar() != '\n');
		}
		switch(operation){
			case 1:
				add_value();
				break;
			case 2:
				reverse_list();
				break;
			case 3:
				print_list();
				break;
			case 4:
				clear_list();
				break;
			default:
				puts("Invalid operation");
				break;
		}
	}
	return 0;
}