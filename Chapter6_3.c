#include<stdio.h>
#include <stdlib.h>
//ƽ������� ���Ҳ��� 
typedef struct Tree{
	char data;
	int count;
	struct Tree * lchild;
	struct Tree * rchild;
}BiTree;

static BiTree *pre=NULL;
static int flag=1;
int create(BiTree **T)
{
	char ch;
	scanf("%c",&ch);
	if(ch == '#')
	{
		(*T)=NULL;
	}
	else
	{
		(*T)=(BiTree *)malloc(sizeof(BiTree));
		(*T)->data=ch;
		(*T)->count=0;
		create(&((*T)->lchild));
		create(&((*T)->rchild));
	}
	return 0;
}

BiTree *searchBST(BiTree *T)
{
	char x;
	scanf(" %c",&x);  //Ϊ�˲������������Ļس�����x��%cǰ��һ���ո� 
	BiTree *p=T; 
	BiTree *s,*q;
	while(p)
	{
		if(p->data == x)
		{
			
			p->count+=1;
			printf("���ҵ�\n");
			return T;
		}
		q=p;
		if(p->data > x)
		{
			p=p->lchild;
		}
		else
		{
			p=p->rchild;
		}
	}
	s=(BiTree *)malloc(sizeof(BiTree));
	s->data=x;
	s->count=0;
	s->lchild=NULL;
	s->rchild=NULL;
	if(q->data > x)
	{
		q->lchild=s;
	}
	else
	{
		q->rchild=s;
	}
	
	
	return T;
}

int inorder(BiTree *T)
{
	if(T)
	{
		inorder(T->lchild);
		printf("%c %d\n",T->data,T->count);
//		printf("%c",T->data);
		inorder(T->rchild);
	}
	return 0;
}
int main()
{
	BiTree *T;
	T=(BiTree*)malloc(sizeof(BiTree));
	create(&T);
	printf("�������\n");
	T=searchBST(T);
	inorder(T);
}
