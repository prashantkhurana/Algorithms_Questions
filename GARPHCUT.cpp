#include<stdio.h>
#include<string.h>
#include<vector>
using namespace std;

int checkincut(vector<int> cut_g[], int i, int j)
{
	for(int k=0;k<cut_g[i].size();k++)
	{
		if(cut_g[i][k]==j)
		return 1;
	}
	return 0;
}

int DFS(vector<int> *full_g,vector<int> *cut_g,int *visited,int *color, int i ,int c)
{
	visited[i]=1;
	color[i]=c;
	for(int j=0;j<full_g[i].size();j++)
	{
		int next=full_g[i][j];
		int c2;
		if(visited[next]==0)
		{
			if(checkincut(cut_g,i,next)==1)
			c2=!c;
			else c2=c;
			int x=DFS(full_g,cut_g,visited,color,next,c2);
			if(x==-1)
			return -1;
		}
		else
		{
			if(checkincut(cut_g,i,next)==1)
			{
				if(color[next]==c)
				return -1;
			}
			else
			{
				if(color[next]!=c)
				return -1;
			}
			
		}
	}
	return 1;
}







int do_DFS(vector<int> *cut_g,vector<int> *full_g, int n)
{
	int visited[n+1];
	int color[n+1];
	memset(visited,0,sizeof(visited));
	memset(color,0,sizeof(color));
	for(int i=1;i<=n;i++)
	{
		if(visited[i]==0)
		{
			int y=DFS(full_g,cut_g,visited,color,i,0);
			if(y==-1)
			return -1;
		}
	}
	return 1;
}

int main()
{
int t,n,e,k,i,j;
int e1,e2;
scanf("%d",&t);

for(i=0;i<t;i++)
	{
	scanf("%d %d %d",&n,&e,&k);
	vector<int> cut_g[n+1];
	vector<int> full_g[n+1];
	for(j=1;j<=k;j++)
		{
		scanf("%d %d",&e1,&e2);
		cut_g[e1].push_back(e2);
		full_g[e1].push_back(e2);
		cut_g[e2].push_back(e1);
		full_g[e2].push_back(e1);
		}

	for(j=k+1;j<=e;j++)
		{
		scanf("%d %d",&e1,&e2);
		full_g[e1].push_back(e2);
		full_g[e2].push_back(e1);
		}
		int bn=do_DFS(cut_g,full_g,n);
		if(bn==1)
		printf("YES\n");
		else
		printf("NO\n");
}
return 0;
}
