#include<stdio.h>
static int m=0;
int *storage(int *num, int i)
{
	int j;
	if(i == -999)
	{
		return num;
	}
	if(i >= 0)
	{
		num[m++]=i;
		scanf("%d",&j);
		storage(num,j);
	}
	else
	{
		scanf("%d",&j);
		storage(num,j);
		num[m++]=i;
	}
	return num;
}
int main()
{
	int num[10];
	int i,j=0;
	scanf("%d",&i);
	if(i != -999)
	{
		storage(num,i);
	}
	for(j=0;j<m;j++)
	{
		printf("%d\t",num[j]);
	}
	return 0;
 } 
