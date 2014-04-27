#include<iostream>
#include<vector>
#include<stdio.h>
using namespace std;


vector<int> g[2001];
int visited[2001];



int doDFS(int start,int scolor)
{
	visited[start]=scolor;
	for(int i=0;i<g[start].size();i++)
	{
		int x=g[start][i];
		if(visited[x]!=-1 && visited[x]==scolor)
		return 1;
		else
		visited[x]=scolor^1;
	}
	return 0;
}

int DFS(int n)
{
	
	
	for(int i=1;i<=n;i++)
	{
			if(visited[i]==-1)
			{
				if(doDFS(i,0)==1)
				return 1;
			}
			else
			{
				if(doDFS(i,visited[i])==1)
				return 1;
			}
	}
	return 0;
}
int main()
{
	int t,n,m,v1,v2;
	scanf("%d",&t);
	for(int j=1;j<=t;j++)
	{
		scanf("%d %d",&n,&m);
		for(int i=1;i<=n;i++)
		g[i].clear(),visited[i]=-1;
		for(int i=0;i<m;i++)
		{
			scanf("%d %d",&v1,&v2);
			g[v1].push_back(v2);
			g[v2].push_back(v1);
		}
		printf("Scenario #%d:\n",j);
		if(DFS(n))
		printf("Suspicious bugs found!\n");
		else
		printf("No suspicious bugs found!\n");
	}
}
