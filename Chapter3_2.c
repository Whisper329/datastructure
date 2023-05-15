#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 100
typedef struct STACK{
	char ch[MAX];
	int top;
	int bottom;
}stack;
//判断回文 
int push(stack *head,char j)
{
	if(head->top != MAX)
	{
		head->ch[head->top++]=j;
//		printf("%c\n",j);
	}
	
	else printf("栈已满");
//	printf("%d",head->top);
	return 0;
}

char pop(stack *head)
{
	char j;
	if(head->top != -1)
	{
		j=head->ch[--head->top];
	}
//	printf("%c",j);
	return j;
}
int judge(stack *head,char buff[])
{
	int m;
	char i;
	if(strlen(buff)%2)
	{
		for(m=strlen(buff)/2+1;m<strlen(buff);m++)
		{
//			printf("%d\n",m); 
			i=pop(head);
//			printf("%c",i);
			if(i!=buff[m])
			{
				return 1;
			}
			
		}
	}
	else
	{
		
		for(m=strlen(buff)/2;m<strlen(buff);m++)
		{
			i=pop(head);
			if(i!=buff[m]) 
			{
				return 1;
			}
		}
	}
	return 0;
}
int main()
{
	stack *head;
	char i;
	char buff[MAX];
	int m,j=0;
	head = (stack *)malloc(sizeof(stack));
//	printf("%d",sizeof(stack));
	head->bottom=0;
	head->top=0;
	scanf("%s",&buff);
	for(;j<strlen(buff)/2;j++)
	{
//		printf("%c\n",buff[j]);
		push(head,buff[j]);
	}
	m=judge(head,buff);
	if(m==0)
	{
		printf("回文");
	}
	else printf("不是回文");
	return 0;
}
