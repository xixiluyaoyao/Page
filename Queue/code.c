#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "head.h"
int main() {
    Queue queue;
    initQueue(&queue);
    enqueue(&queue, 10);
    enqueue(&queue, 20);
    enqueue(&queue, 30);
    printQueue(&queue);

    printf("%d\n",dequeue(&queue));
	printQueue(&queue);
    printf("%d\n", peek(&queue));

    
    return 0;
}