#define PI 3.14159
#include <stdio.h>
int main()
{
 float r,c,a;
 printf("Please input radius here ");
 scanf("%f",&r);
 c=2*PI*r;
 a=PI*r*r;
 printf("Circumference is %f, area is %f\n",c,a);
 return 0;
}