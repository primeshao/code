#include "CommonDef.h"

typedef struct
{
    char vexs[MAX];
    int vexnum;
    int edgnum;
    int matrix[MAX][MAX];
}AMGraph;

/* 返回顶点的位置 */
int PositionVex(AMGraph g,char ch);

/* 构造无向图(邻接矩阵) */
AMGraph* CreateAdjMatrix();

/* 输出无向图(邻接矩阵) */
void PrintAdjMatrix(AMGraph G);