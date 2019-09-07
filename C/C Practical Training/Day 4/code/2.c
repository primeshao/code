#include<stdio.h>
#include<string.h>
int main()
{
	int i;
	int count = 0;
	int a[10],b[10];
	int k1;
	for(i=0;i<10;i++) 
	{
		scanf("%d",&a[i]);
		b[9-i] = a[i];
	}
	k1 = a[0];
	for(i=0;i<9;i++)
	{
		if(b[i]<k1) 
		{
			printf("%d",b[i]);
			count=1;
			i++;
			break;
		}
	}
	for(;i<9;i++) 
	{
		if(b[i]<k1) printf(" %d",b[i]);
	}
	if(count) printf(" ");
	printf("%d",k1);
	for(i=0;i<10;i++)
	{
		if(a[i]>k1) printf(" %d", a[i]);
	}
	return 0;
}