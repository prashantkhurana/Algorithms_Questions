#include<stdio.h>
#include<iostream>
#include<vector>
#include<string.h>
using namespace std;


void DFS_Node(vector<int> v[], int start, int visited[])
{
	visited[start]=1;
	while(v[start].size())
	{
		int x=v[start].back();
		v[start].pop_back();
		if(visited[x]==0)
		DFS_Node(v,x,visited);
	}
	
}


int DFS(vector<int> v[], int n)
{
	int connect=0;
	int visited[n];
	memset(visited,0,sizeof(visited));
	for(int i=0;i<n;i++)
	{
		if(visited[i]==0)
		{
			connect++;
			DFS_Node(v,i,visited);
		}
	}
	return connect;
}

int main()
{
int i,j,n,t,e,x,y,res,k,count=1,a[100000];

scanf("%d",&t);

for(i=0;i<t;i++)
	{

	scanf("%d",&n);
	vector<int> v[n];
	
	
	scanf("%d",&e);

	for(j=0;j<e;j++)
		{
			scanf("%d %d",&x,&y);
			v[x].push_back(y);
			v[y].push_back(x);
		}
		printf("%d\n",DFS(v,n));

	
	}

return 0;
}
