#include<iostream>
#include<algorithm>
#include<string>
#include<list>
#include<queue>
#include<map>
#include<string.h>
using namespace std;

#define MAX 10009
int primes[MAX];

int powers[MAX][MAX];
int done[MAX];

int n;




void mark(int j)
{
	int p=2*j;
	int z=2;
	while(p<MAX)
	{
		primes[p]=1;
		p+=j;	
	}
}

int seive()
{
	for(int i=2;i<MAX;i++)
	{
		if(primes[i]==0)
		{
			mark(i);
		}
	}
}


void addpowers(int n, int m)
{
	for(int i=1;i<=m;i++)
	{
		powers[n][i]+=powers[m][i];
	}
}


void fill()
{
	for(int i=2;i<MAX;i++)
	{
		if(primes[i]==0)
		{
			powers[i][i]=1;
		}
		else
		{
			for(int j=2;j*j<=i;j++)
			{
				if(primes[j]==0&&i%j==0)
				{
					powers[i][j]=1;
					addpowers(i,i/j);
					break;
				}
			}
		}
	}

}


int main()
{
	
	memset(primes,0,sizeof(primes));
	
	seive();
	fill();
	cin>>n;
	
	
	int powe[MAX]={0};
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=i;j++)
		{
			powe[j]+=powers[i][j];
		}
	}
	
	for(int i=2;i<n+1;i++)
	{
		if(powe[i]!=0)
		{
			cout<<i<<"^"<<powe[i]<<"*";
		}
	}
	return 0;
}
