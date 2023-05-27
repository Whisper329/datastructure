#include<stdio.h>
#define m 2
#define n 3
int equal(int num[][n+1])
{
	int i,j,k,q;
	for(i=1;i<m+1;i++) //与本行对比 
	{
		for(j=1;j<n+1;j++)
		{
			for(k=j+1;k<n+1;k++)
			{
				printf("%d %d\n",num[i][j],num[i][k]);
				if(num[i][j]==num[i][k])
				{
					printf("no");
					return 0;
				}
			}
		}
	}
	for(i=1;i<m+1;i++) //其他行对比 
	{
		for(j=1;j<n+1;j++)
		{
			for(k=i+1;k<m+1;k++)
			{
				for(q=j+1;q<n+1;q++)
				{
					printf("%d %d\n",num[i][j],num[k][q]);
					if(num[i][j]==num[k][q])
					{
						printf("no");
						return 0;
					}
				}
				
			}
		}
	}
	printf("yes");
	return 0;
}
int main()
{
	int num[m+1][n+1];
	int i,j,q,k;
	for(i=1;i<m+1;i++)
	{
		for(j=1;j<n+1;j++)
		{
			scanf("%d",&num[i][j]);
		}
	}
//	for(i=1;i<m+1;i++)
//	{
//		for(j=1;j<n+1;j++)
//		{
//			printf("%d\t",num[i][j]);
//		}
//		printf("\n");
//	}
	equal(num);
//	equal(num[m+1][n+1]); //这样num输出的值不对？？ 
	return 0;
}

