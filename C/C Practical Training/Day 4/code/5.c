#include<stdio.h>
#include<string.h>
int main()
{
	char str[200];
	int LEN;
	int n,i;
	int count;
	scanf("%d%*c",&n);
	while(n--)
	{
		count=0;
		scanf("%s",str);
		LEN = strlen(str);
		for(i=0;i<LEN;i++)
		{
			if(str[i]<0) count++;
		}
		printf("%d\n",count/2);
	}
	return 0;
}