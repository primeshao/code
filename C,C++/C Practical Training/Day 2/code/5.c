#include<stdio.h>
int main()
{
	int a[100];
	int n,m,i;
	scanf("%d%d",&n,&m);
	while(!(n==0&&m==0))
	{
		for(i=0;i<n;i++) scanf("%d",&a[i]);
		if(m<a[0])
		{
			printf("%d",m);
			for(i=0;i<n;i++) printf(" %d",a[i]);
		}
		else 
		{
			printf("%d",a[0]);
			for(i=1;i<n;i++)
			{
				if(m<a[i])
				{
					printf(" %d",m);
					break;
				}
				else printf(" %d",a[i]);
			}
			if(i==n) printf(" %d",m);
			for(;i<n;i++)
			{
				printf(" %d",a[i]);
			}	
		}
		printf("\n");
		scanf("%d%d",&n,&m);
	}
	return 0;
}