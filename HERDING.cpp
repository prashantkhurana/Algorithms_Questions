#include<iostream>
#include<algorithm>
#include<string>
#include<list>
#include<queue>
#include<map>
#include<string.h>
#include<stdio.h>
using namespace std;

int new1=1;

char a[1001][1001];
int visited[1001][1001];
int ans[1001][1001];
int n,m;


void dfs(int i1, int j1)
{
	visited[i1][j1]=1;
	
	int tempi=i1;
	int tempj=j1;
	
	if(a[i1][j1]=='S')
	{
		tempi=i1+1;
	}
	
	
	if(a[i1][j1]=='N')
	{
		tempi=i1-1;
	}
	
	if(a[i1][j1]=='E')
	{
		tempj=j1+1;
	}
	
	if(a[i1][j1]=='W')
	{
		tempj=j1-1;
	}
	
	if(visited[tempi][tempj]==0)
	{
		dfs(tempi,tempj);
		visited[i1][j1]=2;
		ans[i1][j1]=ans[tempi][tempj];
		return;
	}
	if(visited[tempi][tempj]==2)
	{
		visited[i1][j1]=2;
		ans[i1][j1]=ans[tempi][tempj];
		return;
	}
	if(visited[tempi][tempj]==1)
	{
		visited[i1][j1]=2;
		ans[i1][j1]=new1++;
		return;
	}
}
int main()
{
	
	cin>>n>>m;
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			cin>>a[i][j];
		}
	}
	
	
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			if(visited[i][j]==0)
			{
				dfs(i,j);
			}
		}
	}
	cout<<new1-1;
	return 0;
}
