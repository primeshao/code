#include "AdjList.h"

/* ���ض����λ�� */
int LocateVex(ALGraph G , char v)
{
	int i;
	for(i = 0;v != G.vertices[i].data && i < G.vexnum; i++);
	if(i >= G.vexnum)
		return -1; 
	return i;
}

/* ��������ͼ(�ڽ�����) */
ALGraph CreateAdjList()
{
	ALGraph G;
	int i,j,k;
	char v1, v2;
	ArcNode *s, *t;
	printf("���붥����:");
	scanf("%d", &G.vexnum);
	printf("�������:");
	scanf("%d", &G.arcnum);
	getchar();
	
	printf("���붥��:");
	for(i = 0; i < G.vexnum; i++)
	{
		scanf("%c", &G.vertices[i].data); //���춥������
		G.vertices[i].firstarc = 0;
		
	}
	getchar();
	
	printf("�����(��:AB):\n");
	for(k = 0; k < G.arcnum; k++)
	{
		scanf("%c", &v1);
		scanf("%c", &v2);
		getchar();
		i = LocateVex(G , v1);
		j = LocateVex(G , v2); //ȷ�� v1 , v2�� G �е�λ��
		s = (ArcNode*) malloc (sizeof(ArcNode));
		t = (ArcNode*) malloc (sizeof(ArcNode));
		s->adjvex = j; //�ñ���ָ��Ķ����λ��Ϊ j
		s->nextarc = G.vertices[i].firstarc;
		G.vertices[i].firstarc =s; 
		t->adjvex = i; //�ñ���ָ��Ķ����λ��Ϊ j
		t->nextarc = G.vertices[j].firstarc;
		G.vertices[j].firstarc =t;
	}
	return G;
}

/* �������ͼ(�ڽ�����) */
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