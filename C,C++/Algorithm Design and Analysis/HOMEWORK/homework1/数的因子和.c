/*
题目描述
编写一个递归程序求解下列问题：给定正整数n，确定n是否是它所有因子（不包括n）之和。
输入
正整数n
输出
若n是它所有因子之和，输出Yes，否则输出No
样例输入
6
样例输出
Yes
*/
#include <stdio.h>
int factorSum(int n,int m)//n>m
{
	if(m)
	{
		if(n%m)
			return factorSum(n,m-1);
		else
			return m + factorSum(n,m-1);
	}
	return 0;
}
int main()
{
	int n;
	scanf("%d",&n);
	if(n == factorSum(n,n-1))
		printf("Yes\n");
	else
		printf("No\n");
	return 0;
}