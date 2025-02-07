#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "head.h"
Stack* initStack();
bool isEmpty(Stack* p);
void push(Stack* p, int num);
int pop(Stack* p);
int peek(Stack* p);
void Print_stack(Stack *p);

int main() {
	Stack* stack = initStack();
	push(stack, 1);
	push(stack, 2);
	push(stack, 3);
	push(stack, 4);
	push(stack, 5);
	push(stack, 6);
	printf("%d\n",peek(stack));
	Print_stack(stack);
	pop(stack);
	printf("%d\n", peek(stack));
	while (!isEmpty(stack)) {
		pop(stack);
	}
	free(stack);

	return 0;
}
