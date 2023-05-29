#include<stdio.h>
#include <stdlib.h>
typedef struct Tree{
	char data;
	struct Tree *lchild, *rchild;
}BiTree; 

//使用二级指针创建树 先序 
int create(BiTree **T) //方便改二级指针指向的一级指针的值 
{
	char ch;
	
	scanf("%c",&ch);
	if(ch == '#')
	{
		(*T)=NULL;
		return 0;
	}
	else
	{
		(*T)=(BiTree *)malloc(sizeof(BiTree)); //如果当前节点有值则指向一段新空间 
		(*T)->data=ch;
		create(&((*T)->lchild)); //取地址 
		create(&((*T)->rchild)); 
	}
	return 0;
}

//使用一级指针创建树  先序 
BiTree *create2()  //使用一级指针创建树 
{
	char ch;
	BiTree *T;
	scanf("%c",&ch);
	if(ch == '#')
	{
		T=NULL;
	}
	else
	{
		T=(BiTree *)malloc(sizeof(BiTree));
		T->data=ch;
		T->lchild=create2();
		T->rchild=create2();
	}
	return T;
 } 
 
 //前序 
void preorder(BiTree* T)
{
	if (T)
	{
		printf("%c", T->data);
		preorder(T->lchild);
		preorder(T->rchild);
	}
}

//中序 
void inorder(BiTree* T)
{
	if (T)
	{
		inorder(T->lchild);
		printf("%c", T->data);
		inorder(T->rchild);
	}
}

//后序 
void postorder(BiTree* T)
{
	if (T)
	{
		postorder(T->lchild);
		postorder(T->rchild);
		printf("%c", T->data);
	}
}

static int num=0;
//统计叶结点的个数
int tongji(BiTree *T)
{
//	int num=0;
	if(T)
	{
		if((T->lchild == NULL) && (T->rchild == NULL))
		{
			num++;
		}
		tongji(T->lchild);
		tongji(T->rchild);
	}
	return 0;
 } 
int main()
{
	BiTree *T;
	T=(BiTree *)malloc(sizeof(BiTree));
//	create(&T);
	T=create2();
//	printf("%c\n",T->lchild->data);
	preorder(T);
	printf("\n");
	inorder(T);
	printf("\n");
	postorder(T);
	printf("\n");
	tongji(T);
	printf("%d\n",num);
	return 0;
}
