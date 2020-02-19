#include<stdio.h>
#include<string.h>
int main()
{
	int LEN_a,LEN_b;
	int i,j,k,m;
	int plus[300][300];
	char temp1[300];
	char temp2[300];
	int a[300];
	int b[300];
	int temp[300];
	scanf("%s",temp1);
	scanf("%s",temp2);
	for(i=0;i<300;i++) for(j=0;j<300;j++) plus[i][j] = 0;
	for(i=0;i<300;i++) {a[i]=0;b[i]=0;}
	for(i=0,j=299;i<strlen(temp1);i++,j--) a[j] = temp1[i]-'0';
	for(i=0,j=299;i<strlen(temp2);i++,j--) b[j] = temp2[i]-'0';
	//for(i=0;i<300;i++) printf("%d",a[i]);
	//for(i=0;a[i]==0;i++) LEN_a = i;
	//for(i=0;b[i]==0;i++) LEN_b = i;
	LEN_a = 299-strlen(temp1);
	LEN_b = 299-strlen(temp2);


	for(i=299,m=0;i>LEN_b;i--,m++)
	{
		for(j=0;j<300;j++) temp[j] = 0;
		for(j=299,k=i;j>LEN_a;j--,k--) temp[k] = a[j]*b[i];
		for(j=0;j<300;j++) plus[m][j] = temp[j];
	}
	for(j=0;j<300;j++) temp[j] = 0;
	for(i=0;i<300;i++)
	{
		for(j=0;j<300;j++) temp[i] = temp[i]+plus[j][i];
	}
	for(i=0;i<300;i++) a[i] = temp[i];
	for(j=0;j<300;j++) temp[j] = 0;
	for(i=0;a[i]==0;i++);
	for(j=0;i<300;i++,j++) temp[j] = a[i];
	for(i=0;i<300;i++) a[i] = temp[299-i];
	for(i=0;i<300;i++) temp[i] = a[i];
	for(i=299;i>=1;i--)
	{
		temp[i-1]+=(temp[i]/10);
		temp[i] = temp[i]%10;
	}
	for(i=0;i<300;i++)
	{
		if(temp[i]!=0) break;
	}
	if(i==300) printf("0");
	for(;i<300;i++) printf("%d",temp[i]);
	return 0;
}