typedef struct TreeNode *HuffmanTree;
struct TreeNode
{
	int Weight;
	HuffmanTree Left, Right;
}
HuffmanTree Huffman( MinHeap H )//����С�Ѷѽ�����������
{ /* ����H->Size��Ȩֵ�Ѿ�����H->Elements[]->Weight�� */
	int i;
	HuffmanTree T;
	BuildMinHeap(H); /*��H->Elements[]��Ȩֵ����Ϊ��С��*/
	for (i = 1; i < H->Size; i++) //����ֻʣһ��Ԫ�ؼ����
	{	/*��H->Size-1�κϲ�*/
		T = malloc( sizeof( struct TreeNode) ); /*�����½��*/
		T->Left = DeleteMin(H);
		/*����С����ɾ��һ����㣬��Ϊ��T�����ӽ��*/
		T->Right = DeleteMin(H);
		/*����С����ɾ��һ����㣬��Ϊ��T�����ӽ��*/
		T->Weight = T->Left->Weight+T->Right->Weight;
		/*������Ȩֵ*/
		Insert( H, T ); /*����T������С��*/
	}
T = DeleteMin(H);
return T;
}
