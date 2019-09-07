#include <stdio.h>
int main()
{
	int score,n;
	char g;
	printf("Please input the score of a student:");
	scanf("%d",&score);
	n=score/10;
	if(score<10||score>100)
	 printf("ERROR!!!\n");
	else
	{
		switch(n)
		{
		 case 10:
		 case  9: g='A';break;
		 case  8: g='B';break;
		 case  7: g='C';break;
		 case  6: g='D';break;
		 case  5:
		 case  4:
		 case  3:
		 case  2:
		 case  1:
		 case  0: g='E';break;
		}
		printf("The grade of this student is %c.\n",g);
	}
	return 0;
}