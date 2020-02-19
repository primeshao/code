#include<string.h>
#include<stdlib.h>
#include<stdio.h>

int m,s1,s2;

typedef struct
{
	int weight;
	int parent,lchild,rchild;
}HTNode,*HuffmanTree; // 动态分配数组存储哈夫曼树

typedef char *HuffmanCode; // 动态分配数组存储哈夫曼编码表
