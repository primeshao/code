#include "MatrixSearch.h"
#include "Queue.h"

//深度优先递归算法
void DFS2(AMGraph G,int i)
{
	int j;
	visited[i]=1;   //被访问的标记 
	printf("%c ",G.vexs[i]);
	for(j=0;j<G.vexnum;j++)
		if(G.matrix[i][j]==1 && !visited[j])   //边(i,j)存在且j顶点未被访问，递归 
			DFS2(G,j);
}
 
//深度优先遍历
void DFStraverse(AMGraph G)
{
	
	int i;
	for(i=0;i<G.vexnum;i++)
		visited[i]=0;
	printf("DFS: ");
	for(i=0;i<G.vexnum;i++)
		if(!visited[i])
			DFS2(G,i);
	printf("\n");
} 

//广度优先
void BFSTraverse(AMGraph G)
{
    int i;
    int v;
    CirQueue Q;
    InitQueue(&Q);
    for(i =0;i<G.vexnum;i++)
		visited[i]=0;
	printf("BFS: ");
    for(v =0;v<G.vexnum;v++)
    {
        if(!visited[v])
        {
            visited[v]=1;
            printf("%c ",G.vexs[v]);
            EnQueue(&Q,v);
            while(!QueueEmpty(&Q))
            {
                int u = DeQueue(&Q);
                for(i=0;i<G.vexnum;i++)
                {
                    if(G.matrix[u][i]&&visited[i]==0)
                    {
                        visited[i]=1;
                        printf("%c ",G.vexs[i]);
                        EnQueue(&Q,i);
                    }/*if*/
                }
            }/*WHILE*/
 
        }/*IF*/
 
    }/*FOR*/
	printf("\n");
}