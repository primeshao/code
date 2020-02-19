#include <stdio.h>
int main()
{
	char x,y,z;
	int index(char *str,char ch);
	char a[100];
	printf("Please input string:");
	gets(a);
	printf("Please input char1,char2,char3:");
	x=getchar();
	y=getchar();
    z=getchar();
	printf("The adress of %c is %d.\n",x,index(a,x));
	printf("The adress of %c is %d.\n",y,index(a,y));
	printf("The adress of %c is %d.\n",z,index(a,z));
	return 0;
}
int index(char *str,char ch)
{
	int i;
	for(i=0;1;i++)
	{
		if(str[i]==ch) return (i+1);
		if(str[i]=='\0') return -1;
	}
}
