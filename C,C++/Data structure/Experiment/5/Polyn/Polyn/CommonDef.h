#include <stdio.h>
#include <malloc.h>

typedef struct node
{
	float coef;			//ϵ��
    int exp;			//ָ��
    struct node *next;	//ָ����һ�ڵ�
}polynode;

typedef polynode * LinkList; 