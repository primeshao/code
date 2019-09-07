#include<stdio.h>
#include<math.h>
int main()
{
	int d,n;
	long double temp;
	long double min;
	int rn,rd;
	long double offset;
	long double A;
	int L;
	scanf("%Lf%d",&A,&L);
	min = L+1;
	for(d=1;d<=L;d++)
	{
		n = (int)(d*A);
		if(n>L) n=L;
		if(n<1) n=1;
		temp = n*1.0;
		offset = fabs(A-(temp/d));
		if(offset<min)
		{
			rd = d;
			rn = n;
			min = offset;
		}
	}
	printf("%d %d",rn,rd);
	return 0;
}
