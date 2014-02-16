#include<iostream>
#include<string.h>
#include<vector>
#include<stack>
using namespace std;



void TopologicalSort(vector<int> tree[], int i, stack<int> &topo, int visited[])
{
	visited[i]=1;
	for(int j=0;j<tree[i].size();j++)
	{
		int next=tree[i][j];
		if(visited[next]==0)
		TopologicalSort(tree,next,topo,visited);
	}
	topo.push(i);
}


void doTopologicalSort(vector<int> tree[],int n)
{
	int visited[n+1];
	memset(visited,0,sizeof(visited));
	stack<int> topo;
	for(int i=1;i<=n;i++)
	{
		if(visited[i]==0)
		TopologicalSort(tree,i,topo,visited);
	}
	int x=topo.top();
	visited[x]=0;
	topo.pop();
	while(topo.size())
	{
		int y=topo.top();
		visited[y]=x;
		x=y;
		topo.pop();
	}
	for(int i=1;i<=n;i++)
	{
		printf("%d\n",visited[i]);
	}
}
int main()
{
	int n, node,k,m;
	scanf("%d %d",&n,&k);
	vector<int> tree[n+1];
	for(int i=1;i<=k;i++)
	{
		scanf("%d",&m);
		for(int j=1;j<=m;j++)
		{
			scanf("%d",&node);
			tree[i].push_back(node);
		}
	}
	doTopologicalSort(tree,n);
	return 0;
}
