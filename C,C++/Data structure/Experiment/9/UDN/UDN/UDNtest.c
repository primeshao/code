#include "AdjMatrix.h"
#include "AdjList.h"

/* 主函数 */

int main()
{
	AMGraph *G1;
	ALGraph G2;
	printf("********************\n无向图的邻接矩阵存储\n********************\n");
	G1=CreateAdjMatrix();
	PrintAdjMatrix(*G1);
	DFStraverse(*G1);
	BFSTraverse(*G1);
	printf("********************\n无向图的邻接链表存储\n********************\n");
	G2 = CreateAdjList();
	PrintAdjList(G2);
	DFSL(G2);
	BFSL(G2);
	return 0;
}