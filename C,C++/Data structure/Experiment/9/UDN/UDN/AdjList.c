#include "AdjList.h"

/* 返回顶点的位置 */
int LocateVex(ALGraph G , char v)
{
	int i;
	for(i = 0;v != G.vertices[i].data && i < G.vexnum; i++);
	if(i >= G.vexnum)
		return -1; 
	return i;
}

/* 构造无向图(邻接链表) */
ALGraph CreateAdjList()
{
	ALGraph G;
	int i,j,k;
	char v1, v2;
	ArcNode *s, *t;
	printf("输入顶点数:");
	scanf("%d", &G.vexnum);
	printf("输入边数:");
	scanf("%d", &G.arcnum);
	getchar();
	
	printf("输入顶点:");
	for(i = 0; i < G.vexnum; i++)
	{
		scanf("%c", &G.vertices[i].data); //构造顶点向量
		G.vertices[i].firstarc = 0;
		
	}
	getchar();
	
	printf("输入边(例:AB):\n");
	for(k = 0; k < G.arcnum; k++)
	{
		scanf("%c", &v1);
		scanf("%c", &v2);
		getchar();
		i = LocateVex(G , v1);
		j = LocateVex(G , v2); //确定 v1 , v2在 G 中的位置
		s = (ArcNode*) malloc (sizeof(ArcNode));
		t = (ArcNode*) malloc (sizeof(ArcNode));
		s->adjvex = j; //该边所指向的顶点的位置为 j
		s->nextarc = G.vertices[i].firstarc;
		G.vertices[i].firstarc =s; 
		t->adjvex = i; //该边所指向的顶点的位置为 j
		t->nextarc = G.vertices[j].firstarc;
		G.vertices[j].firstarc =t;
	}
	return G;
}

/* 输出无向图(邻接链表) */
void PrintAdjList(ALGraph G)
{
	int i;
	ArcNode *p;
	printf("Adjacency List:\n");
	for(i = 0; i < G.vexnum; i++)
	{
		printf("%d%4c", i, G .vertices[i].data);
		for(p = G.vertices[i].firstarc; p; p = p->nextarc)
			printf(" ->%2d", p->adjvex);
		printf("\n");
	}
}