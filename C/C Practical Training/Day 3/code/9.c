#include<stdio.h>
#include<string.h>
int main()
{
	int AL;
	int sum = 0;
	int i = 0;
	int j,k;
	char temp[20];
	char a[1000][20];
	scanf("%s",temp);
	while(strcmp(temp,"#"))
	{
		strcpy(a[i],temp);
		i++;
		scanf("%s",temp);
	}
	for(j=0;j<i-1;j++)
	{
		AL = 1;
		for(k=j+1;k<i;k++)
		{
			if(strcmp(a[j],a[k])==0) {AL = 0;break;}
		}
		if(AL) sum++;	
	}
	sum++;
	printf("%d\n",sum);
	return 0;
}