#include<stdio.h>
#include<string.h>
int main()
{
	int AL;
	int i,j;
	int n;
	char t[40];
	char str[5000][40];
	scanf("%d%*c",&n);
	for(i=0;i<n;i++)
	{
		scanf("%s",str[i]);
	}
	for(i=0;i<n-1;i++)
	{
		for(j=i+1;j<n;j++)
		{
			if(strcmp(str[i],str[j])>0)
			{
				strcpy(t,str[i]);
				strcpy(str[i],str[j]);
				strcpy(str[j],t);
			}
		}
	}
	/*for(i=0;i<n;i++)
	{
		AL = 1;
		for(j=0;j<i;j++)
		{
			if(strcmp(str[i],str[j])==0) {AL = 0;break;}
		}
		if(AL) printf("%s\n",str[i]);
	}*/
	for(i=0;i<n;i++) printf("%s\n",str[i]);
}