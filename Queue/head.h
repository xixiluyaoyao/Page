#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#ifndef HEAD_H
#define HEAD_H
#define MAX_SIZE 100 // 定义队列的最大容量
typedef struct {
    int queue[MAX_SIZE];
    int front;
    int rear;
    int size;
}Queue;
    
void initQueue(Queue* p);
bool isEmpty(Queue* p);
bool isFull(Queue* p);
void enqueue(Queue* p, int value);
int dequeue(Queue* p);
void printQueue(Queue* p);
int peek(Queue* p);
#endif
