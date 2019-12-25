#include "CommonDef.h"

typedef struct ArcNode
{
	int adjvex;	//�ñ���ָ�Ķ����λ��
	struct ArcNode *nextarc;	//ָ����һ���ߵ�ָ��
}ArcNode;	//��Ľ��

typedef struct VNode
{
	char data;	//������Ϣ�������ݵȣ�
	ArcNode *firstarc;	//ָ���һ�������ö���ıߵĻ�ָ��
}VNode,AdjList[MAX];	//ͷ���

typedef struct ALGraph
{
	AdjList vertices;
	int vexnum, arcnum; //ͼ�ĵ�ǰ�������ͻ���
}ALGraph;

/* ���ض����λ�� */
int LocateVex(ALGraph G , char v);

/* ��������ͼ(�ڽ�����) */
ALGraph CreateAdjList();

/* �������ͼ(�ڽ�����) */
void PrintAdjList(ALGraph G);