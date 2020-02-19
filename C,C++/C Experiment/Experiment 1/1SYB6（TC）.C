#include <stdio.h>
int main()
{
 int a,b,c;
 printf("please input num a:");
 scanf("%d",&a);
 printf("plaese input num b:");
 scanf("%d",&b);
 c=a;
 a=b;
 b=c;
 printf("a=%d,b=%d.\n",a,b);
 return 0;
}