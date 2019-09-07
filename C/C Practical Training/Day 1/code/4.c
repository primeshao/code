#include<stdio.h>
int main()
{
	int i;
	int N = 0;
	long X;
	int a[40];
	scanf("%d",&X);
	for(i=0;i<40;i++)
	{
		a[i] = 0;
	}
	for(i=0;X!=0;i++)
	{
		a[39-i] = X%2;
		X = X/2;
	}
	for(i=0;i<40;i++)
	{
		if(a[i]!=0) break;
	}
	for(;i<40;i++)
	{
		printf("%d",a[i]);
		if(a[i]==1) N++;
	}
	if(N==0) printf("0,0");
	else printf(",%d",N);
	return 0;
}
