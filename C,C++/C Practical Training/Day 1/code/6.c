#include<stdio.h>
int main()
{
	int i,j;
	int N;
	int a[1000];
	for(i=0;i<1000;i++) 
	{
		a[i] = 0;
	}
	a[0] = 1;
	scanf("%d",&N);
	for(i=1;i<=N;i++)
	{
		for(j=0;j<1000;j++) a[j] = a[j]*2;
		for(j=0;j<1000;j++)
		{
			a[j+1] = a[j+1]+(a[j]/10);
			a[j] = a[j]%10;
		}
	}
	for(i=999;i>=0;i--)
	{
		if(a[i]!=0) break;
	}
	for(;i>=0;i--)
	{
		printf("%d",a[i]);
	}
	return 0;
}
