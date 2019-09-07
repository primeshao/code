#include <stdio.h>
int main()
{
	int i,sum;
	i=1;sum=0;
	do
	{
		sum=sum+i;
		i=i+2;
	}while(i<=99);
	printf("sum=%d\n",sum);
	return 0;
}