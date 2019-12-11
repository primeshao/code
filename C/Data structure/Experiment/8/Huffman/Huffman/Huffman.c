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
	HT = (HuffmanTree)malloc((m+1) * sizeof(HTNode)); //0�ŵ�Ԫδ��
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
		// ����������
		// �� HT[1..i-1] ��ѡ�� parent Ϊ 0 �� weight ��С��������㣬
		// ����ŷֱ�Ϊ s1 �� s2��
		Select(HT, i-1);
		HT[s1].parent = i; HT[s2].parent = i;
		HT[i].lchild = s1; HT[i].rchild = s2;
		HT[i].weight = HT[s1].weight + HT[s2].weight;
	}
	printf("Huffman������\n");
	for(j=1; j<=m; j++)
		printf("<%2d>%3d%3d%3d%3d\n",j,HT[j].weight,
		HT[j].parent,HT[j].lchild, HT[j].rchild);
	//------ ��ջ�ǵݹ�������������������������
	cd = (char *)malloc(n*sizeof(char)); // ���������Ĺ����ռ�
	p = m; cdlen = 0;
	for(i=1; i<=m; ++i)//������������ʱ�������״̬��־
		HT[i].weight = 0;
	while (p)
	{
		if(HT[p].weight==0)
		{//����
			HT[p].weight = 1;
			if(HT[p].lchild != 0)
			{
				p = HT[p].lchild;
				cd[cdlen++] ='0';
			}
			else if(HT[p].rchild == 0)
			{//�Ǽ�Ҷ�ӽ����ַ��ı���
				HC[p] = (char *)malloc((cdlen+1) * sizeof(char));
				cd[cdlen] ='\0'; strcpy(HC[p], cd); // ���Ʊ��� (��)
			}
		}
		else if (HT[p].weight==1)
		{ // ����
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
	puts("��Ӧ�Ĺ�������������:");
	for(i = 1;i <= n;i++)
		printf("��%2d���ַ���Ӧ��Huffman����%s\n",i,HC[i]);
}