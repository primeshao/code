#include <stdio.h>
int main()
{
	char a;
	printf("Please input char:");
	a=getchar();
	if(65<=a&&a<=90)
	 printf("%c\n",a+32);
	else
	{
	 if(0<=a&&a<10)
	 printf("%d\n",(int)a);
	 else
	 printf("%c\n",a);
	}
	return 0;
}