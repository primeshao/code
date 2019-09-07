#include <stdio.h>
int main()
{
 float f,t;
 printf("please input the Fahrenheit num:");
 scanf("%f",&f);
 t=5.0/9*(f-32);
 printf("The degree centigrade num is %f.\n",t);
 return 0;
}