#include <stdio.h>
int main()
{
	int a[10],b[10],i;
	for(i=0;i<=9;i++)
	{
		printf("Input num %d:",i+1);
		scanf("%d",&a[i]);
	}
    for(i=0;i<=9;i++) b[9-i]=a[i];
	for(i=0;i<=9;i++) a[i]=b[i];
	for(i=0;i<=9;i++) printf("%d ",a[i]);
	printf("\n");
    return 0;
}
