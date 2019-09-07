#include <stdio.h>
int main()
{
	int n;
	long fib,fib1=1,fib2=1;
	printf("%ld %ld ",fib1,fib2);
	for(n=3;n<=20;n++)
	{
		fib=fib1+fib2;
		fib1=fib2;
		fib2=fib;
		printf("%ld ",fib);
	}
	putchar('\n');
	return 0;
}