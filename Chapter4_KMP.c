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
//���ǰx�ͺ�x����ͬ���ַ�����û�������ʾû��ƥ�� 
int output(char *S,int *next)
{
	int i=0,j=0,m=0;
	for(i=0;i<strlen(S);i++)
	{
		j=0;
		printf("**");//������**��û���ַ������˵��û��ƥ����ַ� 
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
			j=next[j]; //Ϊʲô��j=next[j],���� 
		
		}
		printf("%d %d\n",i,j);
	}
	return 0;
}
int main()
{
	char S[]="abcaabbabcabaacbacba";//����
	char P[]="abcabaa"; //ģʽ�� 
	int next[500]={-1};
	int m;
//	printf("---%d\n",strlen(S));
	get_next(S,next);
	output(S,next);
	printf("\n");
	m=match(S,P,next);
	if(m)
	{
		printf("ƥ��ɹ����ڵ�%d��λ�ã���1��ʼ��",m);
	}
	else
	{
		printf("ƥ��ʧ�ܣ�������û�и�ģʽ��");
	}
	return 0;
}
