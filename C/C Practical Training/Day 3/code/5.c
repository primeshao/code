#include<stdio.h>
int main()
{
	int N,R,i;
	int a[40];
	int count = 1;
	while(scanf("%d%d",&N,&R)!=EOF)
	{
	count = 1;
	if(N == 0)
	{
		printf("0\n");
		continue;
	}
	if(N<0) 
	{
		N = (-N);
		count = 0;
	}
	for(i=0;i<40;i++) a[i] = 0;
	for(i=0;N;i++)
	{
		a[i] = N%R;
		N = N/R;
	}
	if(!count) printf("-");
	for(i=39;i>=0;i--)
	{
		if(a[i]!=0) break;
	}
	for(;i>=0;i--) 
	{
		switch(a[i])
		{
		case 10: printf("A");break;
		case 11: printf("B");break;
		case 12: printf("C");break;
		case 13: printf("D");break;
		case 14: printf("E");break;
		case 15: printf("F");break;
		default :  printf("%d",a[i]);
		}
	}
	printf("\n");
	}
	return 0;
}