#include "huffman.h"

int * Input(int * num)
{
	int *w;
	char a[100];
	int result[26] = {0};
	int i,j;
	*num = 0;
	puts("����Ҫ������ַ���");
	scanf("%s",a);
	for(i=0;i<strlen(a);i++)
		result[a[i]-'a']++;
	puts("�ַ���Ӧ��Ȩֵ����");
	for(i=0;i<26;i++)
	{
		if(result[i]>0)
		{
			printf("%c %d\n",'a'+i,result[i]);
			(*num) ++;
		}
	}
	w = (int *)malloc((*num)*sizeof(int));
	for(i=0,j=0;i<26;i++)
	{
		if(result[i]>0)
		{
			*(w+j) = result[i];
			j++;
		}
	}
	return w;
}