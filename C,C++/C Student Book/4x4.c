#include <stdio.h>
int main()
{
	int sum_4x4(int x[]);
	void input_4x4(int x[]);
	int a[16];
	input_4x4(a);
	printf("Diagonal sum is %d.\n",sum_4x4(a));
	return 0;
}
void input_4x4(int x[])
{
	int i=0,j,k;
	for(j=1;j<=4;j++)
		for(k=1;k<=4;k++)
		{
			printf("(%d,%d):",j,k);
			scanf("%d",x+i);
			i++;
		}
}
int sum_4x4(int x[])
{
	int i,z=0;
	for(i=1;i<=4;i++) z+=*(x+4*(i-1)+i-1);
	for(i=4;i>=1;i--) z+=*(x+4*(i-1)+(5-i)-1);
	return (z);
}