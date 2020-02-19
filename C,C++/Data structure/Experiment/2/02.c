#define N 10
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct student
{
	char num[6];
	char name[8];
	int score[4];
};
void input(struct student *stu,int n)
{
	int i,j;
	int temp_n;
	temp_n = n;
	for(i = 0;temp_n != 0;i++,temp_n--)
	{
		getchar();
		printf("Input students\' information(%d/%d)...\n",i+1,n);
		printf("student number:");
		gets((stu+i)->num);
		printf("student name:");
		gets((stu+i)->name);
		for(j = 0;j<4;j++)
		{
			printf("score%d:",j+1);
			scanf("%d",&(stu+i)->score[j]);
		}
		printf("\n");
	}
	system("cls");
}
void print(struct student *stu,int n)
{
	int i;
	printf("number\tname\tscore1\tscore2\tscore3\tscore4\n");
	for(i = 0;n !=0;i++,n--)
	{
		printf("%s\t%s\t%d\t%d\t%d\t%d\n",(stu+i)->num,(stu+i)->name,(stu+i)->score[0],(stu+i)->score[1],(stu+i)->score[2],(stu+i)->score[3]);
	}
	printf("press anykey to continue\n");
	getchar();
	getchar();
	system("cls");
}
int main()
{
	int ifExit = 0;
	int select;
	int n;
	struct student stu[N];
	while(!ifExit)
	{
		printf("==============================================\n");
		printf("\t1.Input students\' information\n");
		printf("\t2.Output students\' information\n");
		printf("\t3.Exit\n");
		printf("==============================================\n");
		printf("Input your choice(1/2/3):");
		scanf("%d",&select);
		system("cls");
		switch(select)
		{
		case 1:
			{
				printf("input the number of the students:");
				scanf("%d",&n);
				input(stu,n);
				break;
			}
		case 2:print(stu,n);break;
		case 3:ifExit = 1;break;
		default:printf("ERROR!please input 1,2 or 3.\n");break;
		}
	}	
}