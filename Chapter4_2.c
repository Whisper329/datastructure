#include<stdio.h>
//ͳ��0-9��A-Z���ֵĴ��� 
int tongji()
{
	char i;
	int num[36],j;
	for(j=0;j<36;j++)
	{
		num[j]=0;
	}
	scanf("%c",&i);
	while(i!='#')
	{
//		printf("%c %d\n",i,i);
		if(i>='1' &&i<='9')
		{
			num[i-48]+=1;
		}
		else if(i>='A' &&i<='Z')
		{
			num[i-65+10]+=1;
		}
		scanf("%c",&i);
	}
	for(j=0;j<10;j++)
	{
		printf("%c����%d��\n",j+48,num[j]);
	}
	for(j=10;j<36;j++)
	{
		printf("%c����%d��\n",j-10+65,num[j]);
	}
	return 0;
}
//��ʹ�ö���ռ�ʵ������洢 
void reverse_storage(char num[])
{
	char i;
	static int x=0;
	scanf("%c",&i);
	if(i != '#')
	{
		reverse_storage(num);
		num[x++]=i;
	}
	num[x]='\0';

}
void output(char *num)
{
	int m=0;
	while(num[m]!='\0')
	{
		printf("%c\n",num[m]);
		m++;
	}
}
void main()
{
//	tongji();
	
	char num[200];
	reverse_storage(num);
	output(num);
}
