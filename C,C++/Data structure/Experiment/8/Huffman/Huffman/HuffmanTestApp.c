#include "huffman.h"

int main()
{
	HuffmanTree HT = NULL;
	HuffmanCode *HC;
	int n = 0;
	int *w;
	HC = (HuffmanCode *)malloc(n*sizeof(HuffmanCode));
	w = Input(&n);
	HuffmanCoding(HT,HC,w,n);
	printCode(n,HC);
	return 0;
}