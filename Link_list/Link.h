#pragma once
#include<stdio.h>
#ifndef LINK_H
#define LINK_H
struct Linknode
{
	int data;
	struct Linknode* next;
};

struct Linknode* init_list();
void Printnode(struct Linknode* header);

#endif 