#include"Link.h"
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
struct Linknode* init_list();
void Printnode(struct Linknode* header);
int main(void) {
	struct Linknode* header=init_list();
	Printnode(NULL);//测试对于空节点的if能否顺利输出
	Printnode(header);//测试是否正常初始化节点并正常遍历输出节点
	return 0;
}
