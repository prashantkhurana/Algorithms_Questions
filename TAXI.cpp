#include<iostream>
#include<queue>
#include<math.h>
#include<vector>
#include<map>
#include<stdio.h>
#include<string.h>
using namespace std;
#define NILL 0
#define INF (1<<28)
queue<int> q;
int n,m;
vector<int> g[202];
int match[609];
int layer[609];
int matching;


bool bfs()
{
	for(int i=1;i<=n;i++)
	{
		if(match[i]==NILL)
		{
				q.push(i);
				layer[i]=0;
		}
		layer[i]=INF;
	}
	
	layer[0]=INF;
	
	while(!q.empty())
	{
		int u=q.front();
		q.pop();
		if(u!=NILL)
		{
			for(int i=0;i<g[u].size();i++)
		{	
			int v=g[u][i];
			
			if(layer[match[v]]==INF)
			{
				q.push(match[v]);
				layer[match[v]]=layer[u]+1;
			}
		}
		}
		
	}
	if(layer[NILL]==INF)
	return false;
	else
	return true;
}


bool dfs(int p)
{
	if(p==NILL)
	return true;
	
	for(int i=0;i<g[p].size();i++)
	{
		int q=g[p][i];
		if(layer[match[q]]==layer[p]+1)
		{
			if(dfs(match[q]))
			{
				match[p]=q;
				match[q]=p;
				return true;
			}
		}
	}
	layer[p]=INF;
	return false;
}


int hopcroft()
{
	matching=0;
	while(bfs())
	{
		for(int i=1;i<=n;i++)
		{
			if(match[i]==NILL && dfs(i))
			{
				matching++;
			}
		}
	}
	return matching;
}

int main()
{
	int m3,p,x,y,t,s,time;
	scanf("%d",&t);
	while(t--)	
	{
		map<int, std::pair<int,int> > m;
		map<int, std::pair<int,int> > m1;
		memset(match,0,sizeof(match));
		scanf("%d %d %d %d",&m3,&n,&s,&time);
		for(int i=1;i<=m3;i++)
		{
			scanf("%d %d",&x,&y);
			m[i]=std::pair<int,int>(x,y);
			//cout<<m[i].first;
		}
		
		for(int i=1;i<=n;i++)
		{
			g[i].clear();
			scanf("%d %d",&x,&y);
			m1[i]=make_pair(x,y);
		}
		int dist;
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=m3;j++)
			{
				dist=0;
				dist=abs(m1[i].first-m[j].first)*200+abs(m1[i].second-m[j].second)*200;
				if(dist<=time*s)
				{
					g[i].push_back(n+j);
				}
			}
		}
		printf("%d\n",hopcroft());
	}
	return 0;
}
