#include <stdio.h>
#define MAX 10
//��ջ
int push(int V[],int i,int a,int top[])
{
	if(top[0]==top[1])
	{
		printf("��������\n");
	}
	else
	{
		switch(i)
		{
			case 1: V[top[0]++]=a;break;
			case 2: V[top[1]--]=a;break;
		}
		printf("����ɹ�\n");	
	}
	
	return 0;
} 
//��ջ 
void pop(int V[],int i,int top[])
{
	
	if(i==1)
	{
		if(top[0] != -1)
		{
			printf("����%d\n",V[--top[0]]);
			V[top[0]]=0; 
		}
		else printf("ջ1�ѿ�\n");
	}
	else if(i==2)
	{
		if(top[1] != MAX)
		{
			printf("����%d\n",V[++top[1]]);
			V[top[1]]=0; 
		}
		else printf("ջ2�ѿ�\n");
	}
}
int main()
{
	int V[MAX]={0};
	int top[2];
	int j,a;
	top[0]=0;
	top[1]=MAX-1;
	int i=0;
	printf("���ĸ�ջ����1,2\n");
	scanf("%d",&j);
	printf("����ֵΪ��\n");
	scanf("%d",&a);
	while(a != -1 && j != -1)
	{
		push(V,j,a,top);
		printf("���ĸ�ջ����1,2\n");
		scanf("%d",&j);
		printf("����ֵΪ��\n");
		scanf("%d",&a);
	}
	for(;i<MAX;i++)
	{
		printf("%d\n",V[i]);
	}
	pop(V,1,top);
	pop(V,2,top);
	printf("\n");
	for(i=0;i<MAX;i++)
	{
		printf("%d\n",V[i]);
	}
	return 0;
}

