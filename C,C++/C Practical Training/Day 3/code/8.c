#include<stdio.h>
int main()
{
	double x;
	int count = 1;
	double a1=1,a2,temp;
	scanf("%lf",&x);
	while(count)
	{
		a2 = (a1+x/a1)/2;
		temp = a2 - a1;
		if(temp>=(-0.00001)&&temp<=0.00001) count = 0;
		else count = 1;
		a1 = a2;
	}
	printf("%.3f",a1);
	return 0;
}