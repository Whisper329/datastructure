#include <stdio.h>
#define MAX 10
//入栈
int push(int V[],int i,int a,int top[])
{
	if(top[0]==top[1])
	{
		printf("数组已满\n");
	}
	else
	{
		switch(i)
		{
			case 1: V[top[0]++]=a;break;
			case 2: V[top[1]--]=a;break;
		}
		printf("插入成功\n");	
	}
	
	return 0;
} 
//出栈 
void pop(int V[],int i,int top[])
{
	
	if(i==1)
	{
		if(top[0] != -1)
		{
			printf("弹出%d\n",V[--top[0]]);
			V[top[0]]=0; 
		}
		else printf("栈1已空\n");
	}
	else if(i==2)
	{
		if(top[1] != MAX)
		{
			printf("弹出%d\n",V[++top[1]]);
			V[top[1]]=0; 
		}
		else printf("栈2已空\n");
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
	printf("在哪个栈插入1,2\n");
	scanf("%d",&j);
	printf("插入值为：\n");
	scanf("%d",&a);
	while(a != -1 && j != -1)
	{
		push(V,j,a,top);
		printf("在哪个栈插入1,2\n");
		scanf("%d",&j);
		printf("插入值为：\n");
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

