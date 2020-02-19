//忽略加减乘除优先级，从左到右累次计算，以"="为结束标志
#define error -1

#include <stdio.h>

int main()
{
	int goOn = 1;
	double answer = 0;
	double temp = 0;
	char input = '0';
	char symbol = '0';
	scanf("%c",&input);
	while('0'<=input && input <= '9')
	{
		answer = answer * 10 + (input-'0');
		scanf("%c",&input);
	}
	switch(input)
	{
		case '+' :
		case '-' :
		case '*' :
		case '/' : symbol = input;break;
		default: printf("ERROR!\n");return error;
	}
	scanf("%c",&input);
	while(goOn)
	{
		if('0'<=input && input <= '9') temp = temp * 10 + (input-'0');
		else
		{
			switch(input)
			{
				case '=' : goOn = 0;
				case '+' :
				case '-' :
				case '*' :
				case '/' : 
				{
					switch(symbol)
					{
						case '+' : answer+=temp;break;
						case '-' : answer-=temp;break;
						case '*' : answer*=temp;break;
						case '/' : answer/=temp;break;
					}
					temp = 0;
					symbol = input;
					break;
				}				
				default: printf("ERROR!\n");return error;
			}
		}
		scanf("%c",&input);
	}
	printf("%f\n",answer);
	return 0;
}