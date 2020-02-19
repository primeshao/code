/*
题目描述
写一个迭代算法计算二项式系数：c(n,m)=c(n-1,m)+c(n-1,m-1)。
输入
二个正整数，分别表示n和m(0<m<=n<35)。
输出
一个整数，表示二项式系数。
样例输入
2 1
样例输出
2
*/
#include <stdio.h>
int c(int n,int m)
{
	if((m == 0)||(m == n))
		return 1;
	else
		return c(n-1,m)+c(n-1,m-1);
}
int main()
{
	int m,n;
	scanf("%d %d",&n,&m);
	printf("%d",c(n,m));
	return 0;
}