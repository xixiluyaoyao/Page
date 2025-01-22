#include"Link.h"
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
struct Linknode* init_list();
void Printnode(struct Linknode* header);
int main(void) {
	struct Linknode* header=init_list();
	Printnode(NULL);
	Printnode(header);
	return 0;
}