#include  <stdio.h>
int main()
{
 long a,b,c,d;
 printf("plaese input num a:");
 scanf("%ld",&a);
 printf("plaese input num b:");
 scanf("%ld",&b);
 printf("please input num c:");
 scanf("%ld",&c);
 if(a>b)d=b;
 else d=a;
 if(d>c)d=c;
 printf("min=%ld\n",d);
 return 0;
}