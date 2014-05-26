#include<iostream>
#include<vector>
#include<stdio.h>
#include<string.h>
using namespace std;


void doDFS(vector<int> g[],int start, int visited[])
{
	visited[start]=1;
	for(int i=0;i<g[start].size();i++)
	{
		int x=g[start][i];
		if(visited[x]==1)
		continue;
		else
		doDFS(g,x,visited);
	}
}

int DFS(vector<int> g[])
{
	int visited[26]={0};
	int last;
	for(int i=0;i<=25;i++)
	{
		if(visited[i]==0 && g[i].size()!=0)
		{
			doDFS(g,i,visited);
			last=i;
		}
	}
	for(int i=0;i<26;i++)
	visited[i]=0;
	doDFS(g,last,visited);
	for(int i=0;i<=25;i++)
	{
		if(visited[i]==0 && g[i].size()!=0)
		{
			return 0;
		}
	}
	return 1;
}
void eulerpath(int degree[26][2])
{
	int counta=0,countb=0;
	for(int i=0;i<26;i++)
		{
			if(degree[i][0]==degree[i][1]+1)
			counta++;
			else if(degree[i][1]==degree[i][0]+1)
			countb++;
			else if(degree[i][0]!=degree[i][1])
			{
				printf("The door cannot be opened.\n");
				return;
			}
		}
		if(counta==0 && countb==0)
			printf("Ordering is possible.\n");
		else if(counta==1 && countb==1)
		printf("Ordering is possible.\n");
		else printf("The door cannot be opened.\n");
		return;		
}
int main()
{
	int t,n,m;
	char v1[1002];
	scanf("%d",&t);
	for(int j=1;j<=t;j++)
	{
		scanf("%d",&n);
		int degree[26][2];
		vector<int> g[26];
		for(int i=0;i<26;i++)
		{
			for(int j=0;j<2;j++)
			{
				degree[i][j]=0;
			}
		}
		for(int i=0;i<n;i++)
		{
			scanf("%s",&v1);
			
			degree[v1[0]-'a'][1]++;
			g[v1[0]-'a'].push_back(v1[strlen(v1)-1]-'a');
			degree[v1[strlen(v1)-1]-'a'][0]++;
		}
		if(!DFS(g))
		{
			printf("The door cannot be opened.\n");
			continue;
		}
		eulerpath(degree);
		
	}
	return 0;
}
