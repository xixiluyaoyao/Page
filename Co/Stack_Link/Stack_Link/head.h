#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#ifndef HEAD_H
#define HEAD_H
typedef struct Node {
	int data;
	struct Node* next;
} Node;

typedef struct {
	Node* top;
} Stack;

Stack* initStack();

bool isEmpty(Stack* p);

void push(Stack* p, int num);

int pop(Stack* p);

int peek(Stack* p);

void Print_stack(Stack* p);
#endif 