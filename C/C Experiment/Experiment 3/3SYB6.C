#include <stdio.h>
int main()
{
	long m,i;
	printf("Please input num m:");
	scanf("%ld",&m);
	for(i=1;i<=m;i++)
	{
		if(m%i==0)
			printf("%ld ",i);
	}
	return 0;
}