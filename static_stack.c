#include <stdio.h>
#include <stdlib.h>

#define BUFFSIZE 1024

struct Stack{
	int* items;
	int top;
};
int StackSize = -1;

void init_stack(struct Stack* stack, int size){
	stack->items = malloc(size * sizeof(int));
	stack->top = -1;
}

void push(struct Stack* stack, int val){
	if(stack->top >= StackSize){
		printf("Stack limit reached\n");
		return;
	}
	stack->top++;
	stack->items[stack->top] = val;
}

int pop(struct Stack* stack){
	if(stack->top == -1){
		puts("Stack is empty");
		return -1;
	}
	int val = stack->items[stack->top];
	stack->items[stack->top] = 0;
	stack->top--;
	return val;
}

void peek(struct Stack* stack){
	if(stack->top == -1){
		puts("Stack is empty");
		return;
	}
	printf("%d\n", stack->items[stack->top]);
}

void clear(struct Stack* stack){
	stack->top = -1;
}

void delete(struct Stack* stack){
	printf("Cleaning..\n");
	free(stack->items);
	stack->items = NULL;
	stack->top = -1;
	return;
}

int main(){
	char buf[BUFFSIZE];
	
	puts("Enter stack size");
	fgets(buf,BUFFSIZE,stdin);
	int n = atoi(buf);
	StackSize = n;
	struct Stack stack;
	init_stack(&stack, n);
	
	int val;
	int op = 1;
	while(op){
		puts("Enter operation");
		puts("1. push to stack");
		puts("2. pop from stack");
		puts("3. peek at stack");
		puts("4. clear stack");
		puts("0. exit");
		fflush(stdout);
		
		scanf("%d",&op);
		switch(op){
			case 0:
				delete(&stack);
				break;
			case 1:
				puts("Enter value to push onto stack");
				fflush(stdout);
				scanf("%d", &val);
				push(&stack, val);
				break;
			case 2:
				val = pop(&stack);
				printf("%d\n", val);
				break;
			case 3:
				peek(&stack);
				break;
			case 4:
				clear(&stack);
				break;
		}
	}
	return 0;
}