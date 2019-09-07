#include <stdio.h>
int main()
{
	void rearrange(int *p,int m,int n);
	int a[10]={1,2,3,4,5,6,7,8,9,10},i;
	rearrange(a,4,7);
	for(i=0;i<10;i++)
		printf("%d ",a[i]);
	printf("\n");
	return 0;
}
void rearrange(int *p,int m,int n)
{
	int temp;
	int *r=p;
	int *q=p;
	for(r+=m,q+=n;r<=q;r++,q--)
	{
		temp=*r;
		*r=*q;
		*q=temp;
	}
}