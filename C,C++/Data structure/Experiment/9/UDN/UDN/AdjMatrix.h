#include "CommonDef.h"

typedef struct
{
    char vexs[MAX];
    int vexnum;
    int edgnum;
    int matrix[MAX][MAX];
}AMGraph;

/* ���ض����λ�� */
int PositionVex(AMGraph g,char ch);

/* ��������ͼ(�ڽӾ���) */
AMGraph* CreateAdjMatrix();

/* �������ͼ(�ڽӾ���) */
void PrintAdjMatrix(AMGraph G);