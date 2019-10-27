#include <stdio.h>
#include <malloc.h>

typedef struct node
{
	float coef;			//系数
    int exp;			//指数
    struct node *next;	//指向下一节点
}polynode;

typedef polynode * LinkList; 