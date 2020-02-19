#include <stdio.h>
int main()
{
	int sum_4x4(int x[][4]);
	void input_4x4(int x[][4]);
	int a[4][4];
	input_4x4(a);
	printf("Diagonal sum is %d.\n",sum_4x4(a));
	return 0;
}
void input_4x4(int x[][4])
{
	int j,k;
	for(j=0;j<4;j++)
		for(k=0;k<4;k++)
		{
			printf("(%d,%d):",j+1,k+1);
			scanf("%d",*(x+j)+k);
		}
}
int sum_4x4(int x[][4])
{
	int i,z=0; 
	for(i=0;i<=3;i++) z+=*(*(x+i)+i);
	for(i=0;i<=3;i++) z+=*(*(x+i)+3-i);
	return (z);
}