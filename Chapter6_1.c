#include<stdio.h>
//折半查找 
int search(int *a,int x,int low,int high)//递归方法 
{
	int mid;
	
	if(high>=low)
	{
		mid=(high+low)/2;
		printf("\n%d %d %d\n",low,mid,high);
		if(a[mid]==x)
		{
			printf("在第%d个位置\n",mid);
		}
		else if(a[mid]>x)
		{
			high = mid-1;
			search(a,x,low,high);
		}
		else if(a[mid]<x)
		{
			low = mid+1;
			search(a,x,low,high);
		}
	}
	else
	{
		printf("没有该数字\n");
	}
	return 0;
}
int search2(int a[], int x,int high) //非递归 
{
	int mid,low=0;
//	high =sizeof(a)/sizeof(int);   //a是地址无法使用这个计算数组长度 
	while(high>=low)
	{
		mid=(high+low)/2;
		printf("\n%d %d %d\n",low,mid,high);
		if(a[mid]==x)
		{
			printf("在第%d个位置\n",mid);
			break;
		}
		else if(a[mid]>x)
		{
			high = mid-1;
		}
		else if(a[mid]<x)
		{
			low = mid+1;
		}
	}
	if(high<low)
	{
		printf("没有\n");
	}
	return 0;
}
int main()
{
	int a[]={0,1,3,5,7,9,11,13,15};
	int x;
	int low=0,high;
	scanf("%d",&x);
	high =sizeof(a)/sizeof(int);
//	search(a,x,low,high);
	search2(a,x,high);
	return 0;
 } 
