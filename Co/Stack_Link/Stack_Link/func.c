#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "head.h"
Stack* initStack() {//初始化堆栈的栈顶指针
	Stack* p = malloc(sizeof(Stack));
	if (p != NULL) {
		p->top = NULL;
	}
	return p;
}

bool isEmpty(Stack *p) {
	return p->top == NULL;
}

void push(Stack* p,int num) {
	Node *newnode = malloc(sizeof(Node));
	newnode->data = num;
	if (p->top == NULL) {
		newnode->next = NULL;
	}
	else {
		newnode->next = p->top;
	}
	p->top = newnode;
}

int pop(Stack* p) {
	if (p->top == NULL) {
		printf("It is an empty stack");
		return -1;
	}
	Node* pfront = p->top;
	int pop_num = p->top->data;
	p->top = p->top->next;
		free(pfront);
	return pop_num;
}

int peek(Stack* p) {
	if (isEmpty(p)) {
		printf("Error because stack is empty");
		exit(1);
	}
	return p->top->data;
}

void Print_stack(Stack* p) {
	if (p->top == NULL) {
		printf("Error because stack is empty");
		return;
	}
	Node* current = p->top;
	while (current != NULL) {
		printf("%d ", current->data);
		current = current->next;
	}
	printf("\n");
}

