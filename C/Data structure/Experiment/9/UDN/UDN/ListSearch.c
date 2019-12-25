#include "ListSearch.h"
#include "Queue.h"

//�����������
void DFS(ALGraph G,int i) 
{
	ArcNode *p;
	printf("%c ",G.vertices[i].data); //���ʶ��� vi
	visited[i]=1; // ��� vi �ѷ���
	p=G.vertices[i].firstarc; // ȡ vi �߱��ͷָ��
	while(p)
	{
		// �������� vi ���ڽӵ� vj������ j=p->adjvex
		if(!visited[p->adjvex]) //��vi��δ������
		DFS(G,p->adjvex); // ����vjΪ����������������
		p=p->nextarc; // �� vi ����һ�ڽӵ�
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

//�����������
void BFS(ALGraph G,int k)
{
	int i;
	CirQueue Q; // �뽫���ж����� DataType ��Ϊ int
	ArcNode *p;
	InitQueue(&Q); // ���г�ʼ��
	printf("%c ",G.vertices[k].data); // ����Դ�� vk
	visited[k]=1;
	EnQueue(&Q,k); //vk�ѷ��ʣ������˶ӡ���ʵ�����ǽ�������˶ӣ�
	while(!QueueEmpty(&Q))
	{
		// �ӷǿ���ִ��
		i=DeQueue(&Q); // �൱�� vi ����
		p=G.vertices[i].firstarc; // ȡ vi �ı߱�ͷָ��
		while(p)
		{
			// �������� vi ���ڽӵ� vj( �� p->adjvex=j)
			if(!visited[p->adjvex]) 
			{
				// �� vj δ���ʹ�
				printf("%c ",G.vertices[p->adjvex].data); // ���� vj
				visited[p->adjvex]=1;
				EnQueue(&Q,p->adjvex); // ���ʹ��� vj �˶�
			}
			p=p->nextarc; // �� vi ����һ�ڽӵ�
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