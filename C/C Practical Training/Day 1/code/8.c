#include<stdio.h>
int main()
{
	int n;
	int a[101];
	int temp,min,i;
	int count = 0;
	scanf("%d",&n);
	while(n!=0)
	{
		for(i=0;i<n;i++)
		{
			scanf("%d",&a[i]);
		}
		min = a[0];
		for(i=1;i<n;i++)
		{
			if(a[i]<=min)
			{
				min = a[i];
			}
		}
		temp = a[0];
		for(i=0;i<n;i++)
		{
			if(a[i]==min)
			{
				count = i;
			}
		}
		a[0] = min;
		a[count] = temp;
		printf("%d",a[0]);
		for(i=1;i<n;i++)
		{
			printf(" %d",a[i]);
		}
		printf("\n");
		scanf("%d",&n);
	}
	return 0;
}
