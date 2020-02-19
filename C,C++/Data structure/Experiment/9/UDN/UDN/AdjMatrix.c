#include "AdjMatrix.h"

/* ���ض����λ�� */
int PositionVex(AMGraph g,char ch)
{
    int i;
    for(i=0;i<g.vexnum;i++)
        if(g.vexs[i]==ch)
            return i;
    return -1;
}

/* ��������ͼ(�ڽӾ���) */
AMGraph* CreateAdjMatrix()
{
	int vlen;
	int elen;
	int i,p1,p2;
	char *vexs;
	char (*edges)[2];
	AMGraph *pG;

	//��ȡ�������ͱ���
	printf("���붥����:");
	scanf("%d",&vlen);
	printf("�������:");
	scanf("%d",&elen);
	getchar();
	//���ٿռ����ڴ����ͱ�
	vexs = (char *)malloc(sizeof(char) * vlen);
	edges = (char(*)[2])malloc(sizeof(char)*elen*2);
	//��ö���ͱߵ���Ϣ
	printf("���붥��:");
	for(i = 0;i < vlen;i++)
		scanf("%c",&vexs[i]);
	getchar();
	printf("�����(��:AB):\n");
	for(i = 0;i < elen;i++)
	{
		scanf("%c%c",&edges[i][0],&edges[i][1]);
		getchar();
	}	   

	//���ݵ�ͱߵ���Ϣ�����ڽӾ���������ͼ
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

/* �������ͼ(�ڽӾ���) */
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