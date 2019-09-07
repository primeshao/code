#include <stdio.h>
int main()
{
	int num[10],i,a;
	for(i=0;i<=9;i++)
	{
		printf("Num %d:",i+1);
		scanf("%d",&num[i]);
	}
	a=num[0];
	for(i=1;i<=9;i++)
		if(a>num[i]) a=num[i];
	printf("The minimum number: %d\n",a);
	printf("Its subscript:");
	for(i=0;i<=9;i++)
		if(a==num[i]) printf("%d ",i);
	printf("\n");
	return 0;
}