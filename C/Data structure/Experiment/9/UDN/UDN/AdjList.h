#include "CommonDef.h"

typedef struct ArcNode
{
	int adjvex;	//该边所指的顶点的位置
	struct ArcNode *nextarc;	//指向下一条边的指针
}ArcNode;	//表的结点

typedef struct VNode
{
	char data;	//顶点信息（如数据等）
	ArcNode *firstarc;	//指向第一条依附该顶点的边的弧指针
}VNode,AdjList[MAX];	//头结点

typedef struct ALGraph
{
	AdjList vertices;
	int vexnum, arcnum; //图的当前顶点数和弧数
}ALGraph;

/* 返回顶点的位置 */
int LocateVex(ALGraph G , char v);

/* 构造无向图(邻接链表) */
ALGraph CreateAdjList();

/* 输出无向图(邻接链表) */
void PrintAdjList(ALGraph G);