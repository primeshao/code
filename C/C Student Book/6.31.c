#include <stdio.h>
int main()
{
	float score[10];
	int i;float a;
	for(i=0;i<=9;i++)
	{
		printf("Student %d:",i+1);
		scanf("%f",&score[i]);
	}
	a=score[0];
	for(i=1;i<=9;i++)
		if(a<score[i]) a=score[i];
	printf("NO.1: ");
	for(i=0;i<=9;i++)
		if(a==score[i]) printf("Student %d;",i+1);
	printf("\nScore:%.1f\n",a);
	return 0;
}