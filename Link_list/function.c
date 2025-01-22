#include"Link.h"
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

struct Linknode* init_list() {
	struct Linknode* header = malloc(sizeof(struct Linknode));
	header->data = -1;
	header->next = NULL;
	int num;
	struct Linknode* pointnode = header;
	while (true) {
		scanf_s("%d", &num);
		if (num == -1) {
			break;
		}
		struct Linknode* newnode = malloc(sizeof(struct Linknode));
		newnode->data = num;
		newnode->next = NULL;

		pointnode->next = newnode;
		pointnode = pointnode->next;

	}
	return header;
};
 void Printnode(struct Linknode* header) {
	 if (header==NULL) {
		 printf("这是一个空节点\n");
		 return;
	 }
	 struct Linknode* pointnode = header->next;
	 while (pointnode != NULL){
		 printf("%d\n", pointnode->data);
		 pointnode = pointnode->next;
	 } 
};