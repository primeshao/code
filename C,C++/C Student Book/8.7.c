#include <stdio.h>
int main()
{
	void f(char x[],char y[]);
	char a[]={"My name is Li jilin."};
	char b[]={"Mr. Zhang Haoling is very happy."};
	f(a,b);
	puts(a);
	printf("\n");
	return 0;
}
void f(char x[],char y[])
{
	int i;
	for(i=0;i<=12;i++)
		*(x+i+11)=*(y+i+4);
	*(x+24)='.';
	*(x+25)='\0';
}