#include <stdio.h>
int main()
{
	float score[10];
	int i,j;float a;int b=1;
	for(i=0;i<=9;i++)
	{
		printf("Student %d:",i+1);
		scanf("%f",&score[i]);
	}
	a=score[0];
	printf("NO.1:");
	for(i=1;i<=9;i++)
	{
		if(a<score[i]) 
		{
			a=score[i];
			b=i+1;
		}
	}
	printf(" Student %d",b);
	for(j=0;j<=9;j++)
	{
		if(a==score[j])
			if(i==j);
			else printf(",Student %d",j+1);
	}
	printf("\nScore:%.1f\n",a);
	return 0;
}



	    

	
