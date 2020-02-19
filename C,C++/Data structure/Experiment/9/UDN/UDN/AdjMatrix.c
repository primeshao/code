#include "AdjMatrix.h"

/* 返回顶点的位置 */
int PositionVex(AMGraph g,char ch)
{
    int i;
    for(i=0;i<g.vexnum;i++)
        if(g.vexs[i]==ch)
            return i;
    return -1;
}

/* 构造无向图(邻接矩阵) */
AMGraph* CreateAdjMatrix()
{
	int vlen;
	int elen;
	int i,p1,p2;
	char *vexs;
	char (*edges)[2];
	AMGraph *pG;

	//获取顶点数和边数
	printf("输入顶点数:");
	scanf("%d",&vlen);
	printf("输入边数:");
	scanf("%d",&elen);
	getchar();
	//开辟空间用于储存点和边
	vexs = (char *)malloc(sizeof(char) * vlen);
	edges = (char(*)[2])malloc(sizeof(char)*elen*2);
	//获得顶点和边的信息
	printf("输入顶点:");
	for(i = 0;i < vlen;i++)
		scanf("%c",&vexs[i]);
	getchar();
	printf("输入边(例:AB):\n");
	for(i = 0;i < elen;i++)
	{
		scanf("%c%c",&edges[i][0],&edges[i][1]);
		getchar();
	}	   

	//根据点和边的信息，以邻接矩阵构造无向图
	if((pG=(AMGraph*)malloc(sizeof(AMGraph)))==NULL)
			return NULL;
	memset(pG,0,sizeof(AMGraph));
	pG->vexnum=vlen;
	pG->edgnum=elen;
	for(i=0;i<pG->vexnum;i++)
	{
		pG->vexs[i]=vexs[i];
	}
	for(i=0;i<pG->edgnum;i++)
	{
		p1=PositionVex(*pG,edges[i][0]);
		p2=PositionVex(*pG,edges[i][1]);
		pG->matrix[p1][p2]=1;
		pG->matrix[p2][p1]=1;
	}
	return pG;
}

/* 输出无向图(邻接矩阵) */
void PrintAdjMatrix(AMGraph G)
{
    int i,j;
    printf("Adjacency Matrix:\n");
    for(i=0;i<G.vexnum;i++)
    {
        for(j=0;j<G.vexnum;j++)
            printf("%d ",G.matrix[i][j]);
        printf("\n");
    }
}