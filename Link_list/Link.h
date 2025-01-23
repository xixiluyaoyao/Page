#pragma once
#include<stdio.h>
#ifndef LINK_H
#define LINK_H
struct Linknode
{
	int data;
	struct Linknode* next;
};//定义一个节点

struct Linknode* init_list();//接口1，用于初始化节点

void Printnode(struct Linknode* header);//接口2，用于遍历链表

void Insertnode(struct Linknode* header, int insert_num, int search_num);//接口3，用于插入节点

void Clear(struct Linknode* header);//接口4，用于清空链表

void Delete(struct Linknode* header, int data);//接口5，用于删除节点

void Delete_all(struct Linknode* header, int data);//接口6，用于删除所有符合要求的节点

void Destroy(struct Linknode** header);//接口7，用于销毁链表

#endif 
