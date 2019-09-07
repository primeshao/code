#include<stdio.h>
int f(int x)
{
	int sum = 0;
	while(x!=0)
	{
		sum+=x%10;
		x/=10;
	}
	return sum;
}
int g(int x)
{
	int sum = 0;
	while(x!=0)
	{
		sum+=x%2;
		x/=2;
	}
	return sum;
}
int main()
{
	int count = 0;
	int n;
	int i;
	scanf("%d",&n);
	for(i=1;i<=n;i++)
	{
		if(f(i)==g(i)) count++;
	}
	printf("%d",count);
	return 0;
}