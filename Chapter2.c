#include <stdio.h>
#include <stdlib.h>

typedef struct LIST
{
	int n;
	struct LIST *next;
 } list;

//链表的创建
list * creat(list * head, int n)
{
	int i=0;
    list *x,*x1;
    x = (list*)malloc(sizeof(list));
    scanf("%d",&x->n);
    x->next= NULL;
    head=x;
	for(;i<n-1;i++)
	{
		x1 = (list*)malloc(sizeof(list));
		scanf("%d",&x1->n);
		x1->next=NULL;
		x->next=x1;
		x=x1;
	}
	

    return head;
}
//链表输出 
int output(list *head)
{
	list *point;
	point = head;
	while(point != NULL)
	{
		printf("%p,%d\n",point,point->n);
		point=point->next;
	}
	return 0;
}
//递增链表合并 放在head1 (丢失较大栈的第一个值 
list *hebing(list* head1,list* head2) 
{
	list *head3,*p1,*p2,*p3,*q;
	p1=head1->next; //为什么p1=head1不行 
	p2=head2->next;
	head3=head1->n<head2->n?head1:head2;
	p3=head3;
	while(p1 && p2)
	{
		if(p1->n == p2->n)
		{
			p3->next=p1;
			p3=p1;
			p1=p1->next;
			p2=p2->next;
		}
		else if(p1->n < p2->n)
		{
			p3->next=p1;
			p3=p1;
			p1=p1->next;
		}
		else if(p1->n > p2->n)
		{
			p3->next=p2;
			p3=p2;
			p2=p2->next;
		}
	}
	p3->next=p1?p1:p2;
	return head3;
}

//求交集 放在head1 
list *inboth(list *head1,list *head2) 
{
	list *head3,*p1,*p2,*p3;
	p1=p3=head1; //为什么这个可以 
	p2=head2;
	head3=p3=NULL;
	while(p1 && p2)
	{
		if(p1->n < p2->n)
		{
			p1=p1->next;
		}
		else if(p1->n > p2->n)
		{
			p2=p2->next;
		}
		else if(p1->n == p2->n)
		{
			if (!head3)
			{
				head3=p3=p1;
				p1=p1->next;
				p2=p2->next;
			}
			else
			{
				p3->next=p1;
				p3=p1;
				p1=p1->next;
				p2=p2->next;
			}
			
		}
	}
	p3->next=NULL;
	return head3;
}
int main()
{
	int n=4;
	list *head1, *head2,*point, *head3;
	head1 = creat(head1,n);
	printf("list1 finish\n");
	head2 = creat(head2,n);
	printf("list2 finish\n");
//	output(head1);
//	output(head2);

	head3 = hebing(head1,head2);
//	head3 = inboth(head1,head2);
	output(head3);

//	output(head1);
	return 0;
}
