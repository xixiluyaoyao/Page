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
void Printnode(struct Linknode* header);//接口2，用于遍历链表。

#endif 
