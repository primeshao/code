#include <stdio.h>
int main()
{
	int sum1(int),sum2(int);
	printf("sum=%d\n",sum1(100));
    printf("sum=%d\n",sum2(100));
	return 0;
}
int sum1(int x)
{
	int i,z=0;
	for(i=1;i<=x;i++) z+=i;
	return (z);
}
int sum2(int x)
{
	int z=0;
	if(x==1) z=1;
	else z=x+sum2(x-1);
	return (z);
}
