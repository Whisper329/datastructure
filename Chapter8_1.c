#include<stdio.h>

struct employee
{
	char name[20];
	int age;
	int sa;
};
int straight_insert_sort(int *num,int n)  //直接插入排序 
{
	int i;
	int j;
	for(i=2;i<n;i++)
	{
		if(num[i]<num[i-1])
		{
			num[0]=num[i];
			num[i]=num[i-1];
			for(j=i-2;num[0]<num[j];j--)
			{
				num[j+1]=num[j];
			}
			num[j+1]=num[0];
		}
	}
	return 0;
 } 
 
int Binary_insert_sort(int *num, int n) //折半插入排序 在已排好序的数组中插入 
{
	int mid,high,low=1;
	int i=high,j;
	for(i=2;i<n;i++)
	{
		low=1;
		high=i-1;
		num[0]=num[i];
		while(low<=high)
		{
			mid=(low+high)/2;
			if(num[mid]<num[0])
			{
				low=mid+1;
			}
			else
			{
				high=mid-1;
			}
		}
		for(j=i-1;j>high;j--)
		{
			num[j+1]=num[j];
		}
		num[j+1]=num[0];
	}
		
}
int shell_sort(int *num,int n)   //希尔排序 不会 
{
	int i,j,k;
	int d=n/2;
//	for(i=0;i<t;i++)
	while(d>0)
	{
//		printf("i:%d %d\n",i,dk[i]);
		for(j=d+1;j<=2*d;j++)
		{
			if(num[j-d]>num[j])
			{
//				printf("j:%d\n",j);
				num[0]=num[j];
				for(k=j-d;k>0;k-=d)
				{
//					printf("k:%d\n",k);
					if(num[0]<num[k])
					{
						num[k+d]=num[k];
					}
				}	
				num[k+d]=num[0];
			}
			
		}
		d=d/2;
	}
	return 0;
}

int bubble_sort(int *num,int n)  //冒泡排序 
{
	int i,j,temp;
	for(i=0;i<n-1;i++)
	{
		for(j=0;j<n-1-i;j++)
		{
			if(num[j]>num[j+1])
			{
				temp=num[j];
				num[j]=num[j+1];
				num[j+1]=temp;
			}
		}
	}
	return 0;
 } 

int quick_sort(int *num,int low,int high)  //快速排序 
{
	int i=low,j=high,temp,poi;
	if(low<high)
	{
		temp=num[low];
		while(low<high)
		{
			while(high>low&&num[high]>=temp)
			{
				high--;
			}
			num[low]=num[high];
			while(high>low&&num[low]<temp)
			{
				low++;
			}
			num[high]=num[low];
		}
		num[low]=temp;
		quick_sort(num,i,low-1);
		quick_sort(num,low+1,j);
	}
	return 0;
}

int heapadjust(int *num,int start,int end)  //调整堆 
{
	int i;
	int temp;
	temp=num[start];
	for(i=2*start+1;i<=end;i=i*2+1)
	{
		if(i<end&&num[i]<num[i+1])
		{
			i++;
		}
		if(temp>=num[i])
		{
			break;
		}
		num[start]=num[i];
		start=i;
	}
	num[start]=temp;
	return 0;
}
int heap_sort(int *num,int n)  //堆排序 
{
	int i,temp;
	for(i=n/2-1;i>=0;i--) //建初堆 
	{
		heapadjust(num,i,n-1);
	}
	for(i=n-1;i>0;i--)
	{
		temp=num[0];
		num[0]=num[i];
		num[i]=temp;
		heapadjust(num,0,i-1);
	 } 
	 
	return 0; 
}

int merge(int num[],int temp[],int low,int high)
{
	//  >>的优先级低于+，所以加括号 
	int mid=low+((high-low)>>1);      //防止整数溢出 (low+high)/2;

	int pos=low;
	int p1=low,p2=mid+1;
	if(low<high)
	{
		merge(num,temp,low,mid);
		merge(num,temp,mid+1,high);
		while(p1<=mid&&p2<=high)
		{
			if(num[p1]<=num[p2])
			{
				temp[pos++]=num[p1++];
			}
			else
			{
				temp[pos++]=num[p2++];
			}
		}
		while(p1<=mid)
		{
			temp[pos++]=num[p1++];
		}
		while(p2<=high)
		{
			temp[pos++]=num[p2++];
		}
	
		while(low<=high)
		{
			num[low]=temp[low];
			low++;
	}
		
	}
	return 0;
}
int merge_sort(int *num,int n)
{
	int temp[n];
	merge(num,temp,0,n-1);
	return 0;
}
int main()
{
	int num[]={17,7,6,8,9,77,2,5,4,1,15,52,67,35,25,6};
	int n,i;
	n=sizeof(num)/sizeof(int);
//	printf("%d\n\n",n);                 
//	straight_insert_sort(num,n);
//	Binary_insert_sort(num,n);
//	shell_sort(num,n);
	bubble_sort(num,n);
//	quick_sort(num,0,n-1);
//	heap_sort(num,n);
//	merge_sort(num,n);
	for(i=0;i<n;i++)
	{
		printf("%d\n",num[i]);
	}
	struct employee a={"aa",23,57};
	printf("%s %d %d",a.name,a.age,a.sa); 
	return 0;
	
}
