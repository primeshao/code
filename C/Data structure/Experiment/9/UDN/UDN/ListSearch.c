#include "ListSearch.h"
#include "Queue.h"

//深度优先搜索
void DFS(ALGraph G,int i) 
{
	ArcNode *p;
	printf("%c ",G.vertices[i].data); //访问顶点 vi
	visited[i]=1; // 标记 vi 已访问
	p=G.vertices[i].firstarc; // 取 vi 边表的头指针
	while(p)
	{
		// 依次搜索 vi 的邻接点 vj，这里 j=p->adjvex
		if(!visited[p->adjvex]) //若vi尚未被访问
		DFS(G,p->adjvex); // 则以vj为出发点向纵深搜索
		p=p->nextarc; // 找 vi 的下一邻接点
	}
}
void DFSL(ALGraph G)
{
	int i;
	printf("DFS: ");
	for(i=0;i<G.vexnum;i++)
		visited[i]=0;
	for(i=0;i<G.vexnum;i++)
		if(!visited[i])
			DFS(G,i);
	printf("\n");
}

//广度优先搜索
void BFS(ALGraph G,int k)
{
	int i;
	CirQueue Q; // 须将队列定义中 DataType 改为 int
	ArcNode *p;
	InitQueue(&Q); // 队列初始化
	printf("%c ",G.vertices[k].data); // 访问源点 vk
	visited[k]=1;
	EnQueue(&Q,k); //vk已访问，将其人队。（实际上是将其序号人队）
	while(!QueueEmpty(&Q))
	{
		// 队非空则执行
		i=DeQueue(&Q); // 相当于 vi 出队
		p=G.vertices[i].firstarc; // 取 vi 的边表头指针
		while(p)
		{
			// 依次搜索 vi 的邻接点 vj( 令 p->adjvex=j)
			if(!visited[p->adjvex]) 
			{
				// 若 vj 未访问过
				printf("%c ",G.vertices[p->adjvex].data); // 访问 vj
				visited[p->adjvex]=1;
				EnQueue(&Q,p->adjvex); // 访问过的 vj 人队
			}
			p=p->nextarc; // 找 vi 的下一邻接点
		}
	}
}

void BFSL(ALGraph G)
{
	int i;
	printf("BFS: ");
	for(i=0;i<G.vexnum;i++)
		visited[i]=0;
	for(i=0;i<G.vexnum;i++)
		if(!visited[i])
			BFS(G,i);
	printf("\n");
}