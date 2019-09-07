#include<stdio.h>
int main()
{
	int N;
	int i,j;
	int a[100];
	int b[100];
	for(i=0;i<100;i++)
	{
		a[i]=0;
		b[i]=0;
	}
	scanf("%d",&N);
	while(N!=0)
	{
		for(i=0;i<N;i++)
		{
			scanf("%d",&a[i]);
		}
		for(i=0;i<N;i++)
		{
			for(j=0;j<N;j++)
			{
				if(a[j]*a[j]>=b[i]*b[i])
				{
					b[i] = a[j];
				}
			}
			for(j=0;j<N;j++)
			{
				if(a[j]==b[i])
				{
					a[j] = 0;
					break;
				}
			}
		}
		printf("%d",b[0]);
		for(i=1;i<N;i++)
		{
			printf(" %d",b[i]);
		}
		printf("\n");
		for(i=0;i<100;i++)
		{
			a[i]=0;
			b[i]=0;
		}
		scanf("%d",&N);
	}
	return 0;
}
