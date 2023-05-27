#include<stdio.h>
#include<string.h>
void get_next(char *S,int *next)
{
	int i=0,j=-1;
	int len;
	len=strlen(S);
	while(i<len && j<len)
	{
		if(j==-1 || S[i]==S[j])
		{
			next[++i]=++j;
		}
		else
		{
			j=next[j];
		}
	}
}
//输出前x和后x个相同的字符串，没有输出表示没有匹配字符
int output(char *S,int *next)
{
	int i=0,j=0,m=0;
	for(i=0;i<strlen(S);i++)
	{
		j=0;
		printf("**");//如果输出**但没有字符输出，说明没有匹配的字符 
		while(j<next[i])
		{
			printf("%c",S[j++]);
		}
		printf("\t"); 
		m=i-next[i];
		while(m<i)
		{
			printf("%c",S[m++]);
		}
		printf("\n");
	}
	for(i=0;i<strlen(S);i++)
	{
		printf("%d %d\n",next[i],i);
	}
	return 0;
}
//KMP
int match(char *S, char *P, int *next)
{
	int i=0,j=0;
	while(i<strlen(S))
	{
//		if(j==0 && S[i]!=P[j])
//		{
//			i++;
//		}
		if(S[i]==P[j] || j==-1)
		{
			i++;
			j++;
			if(j==strlen(P))
			{
				return i-j+1;
			}
		}
		else
		{
			j=next[j]; //为什么是j=next[j],不是 
		
		}
		printf("%d %d\n",i,j);
	}
	return 0;
}
int main()
{
	char S[]="abcaabbabcabaacbacba";//主串
	char P[]="abcabaa"; //模式串 
	int next[500]={-1};
	int m;
//	printf("---%d\n",strlen(S));
	get_next(S,next);
	output(S,next);
	printf("\n");
	m=match(S,P,next);
	if(m)
	{
		printf("匹配成功，在第%d个位置（从1开始）",m);
	}
	else
	{
		printf("匹配失败，主串中没有该模式串");
	}
	return 0;
}
