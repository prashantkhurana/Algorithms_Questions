#include<iostream>
#include<algorithm>
#include<string>
#include<list>
#include<queue>
#include<map>
#include<string.h>
#include<stdio.h>
using namespace std;

vector<pair<int,int> > tree[50005];
int n;
int d[50005];
int visited[500005];

void dfs(int start)
{
	
	for(int i=0;i<tree[start].size();i++)
	{
		if(visited[tree[start][i].first]==0)
		{
			d[tree[start][i].first]=d[start]+tree[start][i].second;
			visited[tree[start][i].first]=1;
			dfs(tree[start][i].first);
		}
	}
}

int main()
{
	int t;
	scanf("%d",&t);
	int a,b,c;
	while(t--)
	{
		scanf("%d",&n);
		for(int i=0;i<=n;i++)
		{
			tree[i].clear();
		}
		for(int i=0;i<n-1;i++)
		{
			scanf("%d %d %d",&a,&b,&c);
			tree[a].push_back(pair<int,int>(b,c));
			tree[b].push_back(pair<int,int>(a,c));
		//	cout<<tree[a].size();			
		}
		memset(d,0,sizeof(d));
		memset(visited,0,sizeof(visited));
		dfs(1);
		int max=0;
		int maxi=0;
		for(int i=1;i<=n;i++)
		{
			if(d[i]>max)
			{
				max=d[i];
				maxi=i;
			}
		}
		memset(d,0,sizeof(d));
		memset(visited,0,sizeof(visited));
		dfs(maxi);
		max=0;
		maxi=0;
		for(int i=1;i<=n;i++)
		{
			if(d[i]>max)
			{
				max=d[i];
				maxi=i;
			}
		}
		printf("%d\n",max);
	}

	return 0;
}
