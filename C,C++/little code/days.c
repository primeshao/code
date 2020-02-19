//输入年月日后，输出该日期为该年的第几天
#include <stdio.h>
int main()
{
	int y,m,d;
	int m_temp;
	int days = 0;
	int days_Feb = 28;
	int isTrue = 1;
	printf("Input year:");
	scanf("%d",&y);
	printf("Input mouth:");
	scanf("%d",&m);
	printf("Input day:");
	scanf("%d",&d);
	if(y%100 == 0)
	{
		if(y%400 == 0)
			days_Feb = 29;
	}
	else
	{
		if(y%4 == 0)
			days_Feb = 29;
	}
	if(d <= 0)
		isTrue = 0;
	if(m == 1)
	{
		if(d > 31)
			isTrue = 0;
	}
	if(m == 3)
	{
		if(d > 31)
			isTrue = 0;
	}
	if(m == 5)
	{
		if(d > 31)
			isTrue = 0;
	}
	if(m == 7)
	{
		if(d > 31)
			isTrue = 0;
	}
	if(m == 8)
	{
		if(d > 31)
			isTrue = 0;
	}
	if(m == 10)
	{
		if(d > 31)
			isTrue = 0;
	}
	if(m == 12)
	{
		if(d > 31)
			isTrue = 0;
	}
	if(m == 4)
	{
		if(d > 30)
			isTrue = 0;
	}
	if(m == 6)
	{
		if(d > 30)
			isTrue = 0;
	}
	if(m == 9)
	{
		if(d > 30)
			isTrue = 0;
	}
	if(m == 11)
	{
		if(d > 30)
			isTrue = 0;
	}
	if(m == 2)
	{
		if(d > days_Feb)
			isTrue = 0;
	}
	if(!isTrue)
	{
		printf("日期错误！\n");
		return 0;
	}
	m_temp = m;
	while(--m_temp)
	{
		if(m_temp == 1)
			days+=31;//这一句相当于 days = days + 31；
		if(m_temp == 3)
			days+=31;
		if(m_temp == 5)
			days+=31;
		if(m_temp == 7)
			days+=31;
		if(m_temp == 8)
			days+=31;
		if(m_temp == 10)
			days+=31;
		if(m_temp == 12)
			days+=31;
		if(m_temp == 4)
			days+=30;
		if(m_temp == 6)
			days+=30;
		if(m_temp == 9)
			days+=30;
		if(m_temp == 11)
			days+=30;
		if(m_temp == 2)
			days+=days_Feb;
	}
	days+=d;
	printf("%d年%d月%d日是该年的第%d天.\n",y,m,d,days);
	return 0;
}