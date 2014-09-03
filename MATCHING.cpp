#include<iostream>
#include<queue>
#include<vector>
using namespace std;
#define NILL 0
#define INF (1<<28)
queue<int> q;
int n,m;
vector<int> g[50052];
int match[100009];
int layer[50009];
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
	int m,p,x,y;
	scanf("%d %d %d",&n,&m,&p);
	for(int i=0;i<p;i++)
	{
		scanf("%d %d",&x,&y);
		g[x].push_back(n+y);
		//g[y].push_back(x);
	}
	printf("%d\n",hopcroft());
	return 0;
}
