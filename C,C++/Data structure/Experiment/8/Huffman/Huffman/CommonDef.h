#include<string.h>
#include<stdlib.h>
#include<stdio.h>

int m,s1,s2;

typedef struct
{
	int weight;
	int parent,lchild,rchild;
}HTNode,*HuffmanTree; // ��̬��������洢��������

typedef char *HuffmanCode; // ��̬��������洢�����������
