#include "AdjMatrix.h"
#include "AdjList.h"

/* ������ */

int main()
{
	AMGraph *G1;
	ALGraph G2;
	printf("********************\n����ͼ���ڽӾ���洢\n********************\n");
	G1=CreateAdjMatrix();
	PrintAdjMatrix(*G1);
	DFStraverse(*G1);
	BFSTraverse(*G1);
	printf("********************\n����ͼ���ڽ�����洢\n********************\n");
	G2 = CreateAdjList();
	PrintAdjList(G2);
	DFSL(G2);
	BFSL(G2);
	return 0;
}