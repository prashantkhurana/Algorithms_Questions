#include<iostream>
#include<algorithm>
#include<string.h>
#include<stdio.h>
using namespace std;

int N,gap,pos[1002],sa[1002],lcp[1002];

bool cmp(int i, int j)
{
	if(pos[i]!=pos[j])
		return pos[i]<pos[j];
	else
	{
		i+=gap;
		j+=gap;
		if(i<N&&j<N)
		{
			return pos[i]<pos[j];
		}
		else
			if(i>j)
				return true;
			else
				return false;
	}
}




void suffixarray(char s[])
{
	for(int i=0;i<strlen(s);i++)
		sa[i]=i,pos[i]=s[i];
	int temp[1002];
	temp[0]=0;
	for(gap=1;;gap=2*gap)
	{
		sort(sa,sa+strlen(s),cmp);
		for(int i=1;i<N;i++)
		{
			temp[i]=temp[i-1] +cmp(sa[i-1],sa[i]);
		}
		for(int i=0;i<N;i++)
			pos[sa[i]]=temp[i];
		if(temp[N-1]==N-1)
			break;
	}
}


int buildLCP(char s[])
	{
	int sum=0;
		for (int i = 0, k = 0; i < N; ++i) if (pos[i] != N - 1)
		{
			for (int j = sa[pos[i] + 1]; s[i + k] == s[j + k];)
			++k;
			lcp[pos[i]] = k;
			sum=sum+k;
			//printf("%d \n",sum);
			if (k)--k;
		}
		return sum;
	}
int main()
{
	char s[1002];
	int t;
	scanf("%d",&t);
	while(t--)
	{
			scanf("%s",s);
			N=strlen(s);
			suffixarray(s);
			//buildLCP(s);
			printf("%d\n",N*(N+1)/2-buildLCP(s));
	}


	return 0;
}
