#include <stdio.h>
int main()
{
	int a,b,result;
	char ch;
	scanf("%d%c%d",&a,&ch,&b);
	switch(ch)
	{
	   case '+': result=a+b;break;
	   case '-': result=a-b;break;
       case '*': result=a*b;break;
	   case '/': result=a/b;break;
	}
	printf("%d%c%d=%d\n",a,ch,b,result);
	return 0;
}
