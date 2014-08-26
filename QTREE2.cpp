#include<iostream>
#include<vector>
#include<math.h>
using namespace std;
long long visited[10009],size[10009],dist[10009],depth[10009];
vector<std::pair<int,int> > adj[10009];
int parent[10009][15];
int N;

void doDFS(int i)
{
	visited[i]=1;
	for(int j=0;j<adj[i].size();j++)
	{
		int child=adj[i][j].first;
		
		if(visited[child]==0)
		{
			parent[child][0]=i;
			depth[child]=depth[i]+1;
			dist[child]=dist[i]+adj[i][j].second;
			doDFS(child);
		}
	}
}


void DFS()
{
	for(int i=1;i<=N;i++)
	{
		visited[i]=0;
		depth[i]=-1;
		dist[i]=0;
	}
	depth[1]=0;
	dist[1]=0;
	for(int i=1;i<=N;i++)
	{
		if(visited[i]==0)
		doDFS(i);
	}
}

void constructLCS()
{
	for(int j=1;pow(2,j)<N;j++)
	{
		for(int i=1;i<=N;i++)
		{
			if(parent[i][j-1]!=-1)
			parent[i][j]=parent[parent[i][j-1]][j-1];
		}
	}
}

void init()
{
	for(int i=0;i<=N;i++)
		{
			adj[i].clear();
		}
		for(int i=0;i<=N;i++)
		{
			for(int j=0;j<15;j++)
			{
				parent[i][j]=-1;
			}
		}
}


int LCS(int u, int v)
{
	if(depth[u]<depth[v])
	{
		int temp=u;
		u=v;
		v=temp;
	}
	int log;
	
	for(log=1;pow(2,log)<=depth[u];log++);
	
	log--;
	
	if(depth[u]>depth[v])
	for(int i=log;i>=0;i--)
	{
		if(depth[u]-(1<<i) >=depth[v])
		u=parent[u][i];
	}
	
	if(u==v)
	return u;
	
	for(int i=log;i>=0;i--)
	{
		if(parent[u][i]!=-1 && parent[u][i]!=parent[v][i])
		{
			u=parent[u][i];
			v=parent[v][i];
		}
	}
	return parent[u][0];
}

int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		
		scanf("%d",&N);
		init();
		int a,b,c;
		for(int i=1;i<=N-1;i++)
		{
			scanf("%d %d %d",&a,&b,&c);
			adj[a].push_back(std::pair<int,int>(b,c));
			adj[b].push_back(std::pair<int,int>(a,c));
		}
		DFS();
		constructLCS();
		char s[10];
		long long roota,rootb,rootLCS;
		while(1){
			scanf("%s",s);
		if(s[1]=='I')
		{
			scanf("%d %d",&a,&b);
			roota=dist[a];
			rootb=dist[b];
			rootLCS=dist[LCS(a,b)];
			printf("%lld\n",roota+rootb-2*rootLCS);
		}
		else if(s[1]=='T')
		{
			scanf("%d %d %d",&a,&b,&c);
			roota=depth[a];
			int count;
			rootb=depth[b];
			rootLCS=depth[LCS(a,b)];
			if(roota-rootLCS+1>=c)
			{
				c--;
				count=0;
				int i;
				while(c)
				{
					i=c%2;
					if(i)
					{
						a=parent[a][count];
					}
					count++;
					c/=2;
				}
				printf("%d\n",a);
			}
			else
			{
				c=(rootb-rootLCS+1)-(c-(roota-rootLCS+1));
				c--;
				count=0;
				int i;
				while(c)
				{
					i=c%2;
					if(i)
					{
						b=parent[b][count];
					}
					count++;
					c/=2;
				}
				printf("%d\n",b);
			}
		}
		else
		break;
	}
	}
	return 0;
}
