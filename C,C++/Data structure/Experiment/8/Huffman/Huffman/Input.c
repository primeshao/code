#include "huffman.h"

int * Input(int * num)
{
	int *w;
	char a[100];
	int result[26] = {0};
	int i,j;
	*num = 0;
	puts("输入要编码的字符串");
	scanf("%s",a);
	for(i=0;i<strlen(a);i++)
		result[a[i]-'a']++;
	puts("字符对应的权值如下");
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