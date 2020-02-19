#include <stdio.h>
int main()
{
	int a,b,c,d;
	for(a=1;a<=9;a++)
		for(b=0;b<=9;b++)
			for(c=0;c<=9;c++)
			{
				d=a*a*a+b*b*b+c*c*c;
				if(100*a+10*b+c==d)
					printf("Narcissistic number: %d.\n",d);
			}
	return 0;
}


