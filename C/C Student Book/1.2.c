#include <stdio.h>
int main()
{
	int a,b,c,d,e;
	printf("*****************************************\n");
	printf("*******welcome to use my program*********\n");
	printf("*****************************************\n");
	printf("please input a:");
	scanf("%d",&a);
	printf("please input b:");
	scanf("%d",&b);
	printf("please input c:");
	scanf("%d",&c);
	if(a>b) d = a;
	else d = b;
	if(d<c) d = c;
	printf("max=%d\n",d);
	printf("please input any num to quit:  ");
	scanf("%d",&e);
	return 0;
}

