#include<stdio.h>
#include <stdlib.h>
//判断是否是排序二叉树 
typedef struct Tree{
	int data;
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
		create(&((*T)->lchild));
		create(&((*T)->rchild));
	}
	return 0;
}
int JudgeBST(BiTree *T)
{
	
	if(T)
	{
		JudgeBST(T->lchild);
		if(pre==NULL || T->data>pre->data)
		{
			pre=T;
		}
		else
		{
			flag=0;
		}
		JudgeBST(T->rchild);
	}
	return flag;
}
int main()
{
	BiTree *T;
	int x;
	T=(BiTree *)malloc(sizeof(BiTree));
	create(&T);
	x=JudgeBST(T);
	x==1?printf("是排序二叉树"):printf("不是排序二叉树");
	return 0;
}
