#include <stdio.h>
int main()
{
	int a;
	printf("Please input the exam score:");
	scanf("%d",&a);
	if(a<0||a>100)
		printf("ERROR!!!\n");
	else
	{if(a>=90) printf("You grade is \"Excellent\"!\n");
	 else
	 {if(a>=80) printf("You grade is \"Good\"!\n");
	  else
	  {if(a>=70) printf("You grade is \"Medium\"!\n");
	   else
	   {if(a>=60) printf("You grade is \"Pass\"!\n");
	    else printf("You grade is \"Fail\"!\n");
	   }
	  }
	 }
	}
	return 0;
}
