#include "Huffman.h"

void Select(HuffmanTree HT,int n)
{
	int i,j;
	for(i = 1;i <= n;i++)
		if(!HT[i].parent)
		{
			s1 = i;
			break;
		}
	for(j = i+1;j <= n;j++)
		if(!HT[j].parent)
		{
			s2 = j;
			break;
		}
	for(i = 1;i <= n;i++)
		if((HT[s1].weight>HT[i].weight)&&(!HT[i].parent)&&(s2!=i))
			s1=i;
	for(j = 1;j <= n;j++)
		if((HT[s2].weight>HT[j].weight)&&(!HT[j].parent)&&(s1!=j))
			s2=j;
}

void HuffmanCoding(HuffmanTree HT, HuffmanCode HC[], int *w, int n) 
{
	int i, j;
	char *cd;
	int p;
	int cdlen;
	if (n<=1) 
		return;
	m = 2 * n - 1;
	HT = (HuffmanTree)malloc((m+1) * sizeof(HTNode)); //0号单元未用
	for(i=1; i<=n; i++)
	{
		HT[i].weight=w[i-1];
		HT[i].parent=0;
		HT[i].lchild=0;
		HT[i].rchild=0;
	}
	for (i=n+1; i<=m; i++)
	{
		HT[i].weight=0; 
		HT[i].parent=0;
		HT[i].lchild=0;
		HT[i].rchild=0;
	}
	for (i=n+1; i<=m; i++)
	{
		// 建哈夫曼树
		// 在 HT[1..i-1] 中选择 parent 为 0 且 weight 最小的两个结点，
		// 其序号分别为 s1 和 s2。
		Select(HT, i-1);
		HT[s1].parent = i; HT[s2].parent = i;
		HT[i].lchild = s1; HT[i].rchild = s2;
		HT[i].weight = HT[s1].weight + HT[s2].weight;
	}
	printf("Huffman表如下\n");
	for(j=1; j<=m; j++)
		printf("<%2d>%3d%3d%3d%3d\n",j,HT[j].weight,
		HT[j].parent,HT[j].lchild, HT[j].rchild);
	//------ 无栈非递归遍历哈夫曼树，求哈夫曼编码
	cd = (char *)malloc(n*sizeof(char)); // 分配求编码的工作空间
	p = m; cdlen = 0;
	for(i=1; i<=m; ++i)//遍历哈夫曼树时用作结点状态标志
		HT[i].weight = 0;
	while (p)
	{
		if(HT[p].weight==0)
		{//向左
			HT[p].weight = 1;
			if(HT[p].lchild != 0)
			{
				p = HT[p].lchild;
				cd[cdlen++] ='0';
			}
			else if(HT[p].rchild == 0)
			{//登记叶子结点的字符的编码
				HC[p] = (char *)malloc((cdlen+1) * sizeof(char));
				cd[cdlen] ='\0'; strcpy(HC[p], cd); // 复制编码 (串)
			}
		}
		else if (HT[p].weight==1)
		{ // 向右
			HT[p].weight = 2;
			if (HT[p].rchild != 0) { p = HT[p].rchild; cd[cdlen++] ='1'; }
		} 
		else
		{
			HT[p].weight = 0;
			p = HT[p].parent;
			--cdlen;
		}
	} 
}
void printCode(int n,HuffmanCode HC[])
{
	int i;
	puts("对应的哈夫曼编码如下:");
	for(i = 1;i <= n;i++)
		printf("第%2d个字符对应的Huffman编码%s\n",i,HC[i]);
}