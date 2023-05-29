#include<stdio.h>
#include <stdlib.h>
typedef struct Tree{
	char data;
	struct Tree *lchild, *rchild;
}BiTree; 

//ʹ�ö���ָ�봴���� ���� 
int create(BiTree **T) //����Ķ���ָ��ָ���һ��ָ���ֵ 
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
		(*T)=(BiTree *)malloc(sizeof(BiTree)); //�����ǰ�ڵ���ֵ��ָ��һ���¿ռ� 
		(*T)->data=ch;
		create(&((*T)->lchild)); //ȡ��ַ 
		create(&((*T)->rchild)); 
	}
	return 0;
}

//ʹ��һ��ָ�봴����  ���� 
BiTree *create2()  //ʹ��һ��ָ�봴���� 
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
 
 //ǰ�� 
void preorder(BiTree* T)
{
	if (T)
	{
		printf("%c", T->data);
		preorder(T->lchild);
		preorder(T->rchild);
	}
}

//���� 
void inorder(BiTree* T)
{
	if (T)
	{
		inorder(T->lchild);
		printf("%c", T->data);
		inorder(T->rchild);
	}
}

//���� 
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
//ͳ��Ҷ���ĸ���
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
