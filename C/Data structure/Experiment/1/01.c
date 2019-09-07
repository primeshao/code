#define N 10

#include <stdio.h>
#include <string.h>

struct student
{
	char num[6];
	char name[8];
	int score[4];
};

void input(struct student *stu,int n)
{
	int i;
	for(i = 0;n != 0;i++,n--)
	{
		getchar();
		printf("student number:");
		gets(stu[i].num);
		printf("student name:");
		gets(stu[i].name);
		printf("score1:");
		scanf("%d",&stu[i].score[0]);
		printf("score2:");
		scanf("%d",&stu[i].score[1]);
		printf("score3:");	
		scanf("%d",&stu[i].score[2]);
		printf("score4:");
		scanf("%d",&stu[i].score[3]);
		printf("\n");
	}	
}
void print(struct student *stu,int n)
{
	int i;
	printf("number\tname\tscore1\tscore2\tscore3\tscore4\n");
	for(i = 0;n != 0;i++,n--)
	{
		printf("%s\t%s\t%d\t%d\t%d\t%d\n",stu[i].num,stu[i].name,stu[i].score[0],stu[i].score[1],stu[i].score[2],stu[i].score[3]);
	}	
}
int main()
{
	int n;
	struct student stu[N];
	printf("intput the number of the students:");
	scanf("%d",&n);
	input(stu,n);
	print(stu,n);
}