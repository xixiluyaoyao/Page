#include"Link.h"
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

struct Linknode* init_list() {
	struct Linknode* header = malloc(sizeof(struct Linknode));//头节点
	//最开始可能会疑惑为什么头节点是一个指针，主要是因为malloc返回的类型是指针，所以强制让header也变成指针
	header->data = -1;
	header->next = NULL;
	int num;
	struct Linknode* pointnode = header;//节点指针，用于找到各个节点，方便对节点进行操作
	while (true) {
		scanf_s("%d", &num);
		if (num == -1) {
			break;
		}
		struct Linknode* newnode = malloc(sizeof(struct Linknode));//生成新节点用于存放数据
		newnode->data = num;
		newnode->next = NULL;

		pointnode->next = newnode;
		pointnode = pointnode->next;

	}
	return header;
};
 void Printnode(struct Linknode* header) {
	 if (header==NULL) {
		 printf("这是一个空节点\n");//不知道为什么在vs里的中文提交上来后变成了一串乱码，这边手动更正了
		 return;
	 }
	 struct Linknode* pointnode = header->next;
	 while (pointnode != NULL){
		 printf("%d\n", pointnode->data);
		 pointnode = pointnode->next;//最后一个节点的next指向NULL，于是循环结束
	 } 
};
 void Insertnode(struct Linknode* header, int insert_num, int search_num) {
	 struct Linknode* pointpre = header;
	 struct Linknode* pointnext = header->next;//引入两个指针，一个用于找到对应的节点，一个用于记录该节点的前一个节点
	 while (pointnext != NULL) {
		 if (pointnext->data == search_num) {
			 break;//如果找到了对应节点，循环停止
		 }
		 else {
			 pointpre = pointnext;
			 pointnext = pointnext->next;//如果没找到，指针移动到下一个节点
		 }
	 }
	 if (pointnext == NULL) {
		 printf("没有目标数据");
	 }
	 else {
		 struct Linknode* newnode = malloc(sizeof(struct Linknode));
		 newnode->data = insert_num;
		 newnode->next = pointnext;
		 pointpre->next = newnode;//找到了，则让前一个节点指向新节点，再让新节点指向后一个节点
	 }
 };
 void Clear(struct Linknode* header) {
	 struct Linknode* pointnode = header->next;
	 while (pointnode->next != NULL) {
		 if (header == NULL) {
			 break;
		 }
		 struct Linknode* nextpoint = pointnode->next;
		 free(pointnode);//循环，free掉除header外的每一个节点
		 pointnode = nextpoint;
	 }
	 header->next = NULL;
 };
