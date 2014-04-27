#include<iostream>
#include<stdio.h>
using namespace std;

int P[13][99];

int getP(int n, int k)
{
	if(P[n][k]!=-1)
	return P[n][k];
	else
	{
		P[n][k]=0;
		for(int i=k;i>=0;i--)
		{
			if(i+n-1<k)
			break;
			P[n-1][i]=getP(n-1,i);
			P[n][k]+=P[n-1][i];
		}
	}
	return P[n][k];
}

int main()
{

	
	int t,n,k;	
	for(int i=0;i<=12;i++)
	{
		for(int j=0;j<=98;j++)
		{
			if(i==0)
			P[i][j]=0;
			else if(j==0)
			P[i][j]=1;
			else
			P[i][j]=-1;
		}
	}
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d %d",&n,&k);
		printf("%d\n",getP(n,k));
	}
}
