#include"Link.h"
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
struct Linknode* init_list();
void Printnode(struct Linknode* header);
void Insertnode(struct Linknode* header, int insert_num, int search_num);
void Clear(struct Linknode* header);
int main(void) {
	struct Linknode* header=init_list();
	Printnode(NULL);//测试对于空节点的if能否顺利输出

	Printnode(header);//测试是否正常初始化节点并正常遍历输出节点

	Insertnode(header, 15, 20);//如果链表中的数据里有20，则在其之前插入15

	Printnode(header);//测试插入节点后是否正常输出

	Clear(header);//清空链表

	Printnode(header);//测试清空链表后是否正常输出

	return 0;
}
