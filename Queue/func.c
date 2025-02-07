#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "head.h"
// 初始化队列
void initQueue(Queue* p) {
    p->front = 0;
    p->rear = -1;
    p->size = 0;
}

// 检查队列是否为空
bool isEmpty(Queue* p) {
    return p->rear == -1;
}

// 检查队列是否已满
bool isFull(Queue* p) {
    return p->size == MAX_SIZE;
}

// 入队操作
void enqueue(Queue* p,int value) {
    if (isFull(p)) {
        return;
    }
    p->size++;
    p->rear = (p->rear + 1) % MAX_SIZE;// 循环队列，队尾指针循环移动
    p->queue[p->rear] = value;
}

// 出队操作
int dequeue(Queue* p) {
    if (isEmpty(p)) {
        return -1;
    }
    p->size--;
    int value = p->queue[p->front];
    p->front = (p->front + 1) % MAX_SIZE;// 循环队头，队尾指针循环移动
    return value;
}
void printQueue(Queue* p) {
    if (isEmpty(p)) {
        printf("队列为空！\n");
        return;
    }
    int i = p->front;
    int cnt = 0;
    while (cnt < p->size) {
        printf("%d ", p->queue[i]);
        i = (i + 1) % MAX_SIZE;
        cnt++;
    }
    printf("\n");
}

int peek(Queue* p) {
    if (isEmpty(p)) {
        printf("队列为空，无队首元素！\n");
        return -1; // 返回一个错误值
    }
    return p->queue[p->front];
}



