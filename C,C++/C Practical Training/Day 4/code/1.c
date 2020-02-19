#include<stdio.h>
int main()
{
	int sum = 0;
	int AL;
	int n;
	int i,j;
	int count;
	int a[1000];
	scanf("%d",&n);
	for(i=1;i<=n;i++)
	{
		count = 0;
		for(j=1;j<=i;j++)
		{
			if(i%j==0) count++;
		}
		a[i-1] = count;
	}
	for(i=0;i<n-1;i++)
	{
		AL = 1;
		for(j=i+1;j<n;j++)
		{
			if(a[i]==a[j]){AL=0;break;}
		}
		if(AL) sum++;
	}
	sum++;
	printf("%d",sum);
	return 0;
}