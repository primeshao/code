#include<stdio.h>
#include<string.h>
int main()
{
	int i;
	int n;
	char str[101];
	char max;
	while(gets(str)!=NULL)
	{
		max = str[0];
		n = strlen(str);
		for(i=0;i<n;i++)
		{
			max=str[i]>max?str[i]:max;	
		}
		for(i=0;i<n;i++)
		{
			printf("%c",str[i]);
			if(str[i]==max) printf("(max)");
		}
		printf("\n");
	}
	return 0;
}