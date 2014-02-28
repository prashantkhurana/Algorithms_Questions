#include<iostream>
#include<string.h>
#include<queue>
using namespace std;


int main()
{
	int t,n,m;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d %d",&n,&m);
		queue<std::pair<int,int> > q;
		int b[n][m];
		int visited[n][m];
		int ans[n][m];
		char s[m+1];
		memset(ans,0,sizeof(ans));
		memset(visited,0,sizeof(visited));
		for(int i=0;i<n;i++)
		{
			scanf("%s",&s);
			for(int j=0;j<m;j++)
			{
				b[i][j]=s[j]-'0';
				if(b[i][j]==1)
				{
					q.push(std::pair<int,int>(i,j));
					visited[i][j]=1;
					ans[i][j]=0;
				}
			}
		}
		while(!q.empty())
		{
			std::pair<int, int> p=q.front();
			q.pop();
			int i=p.first;
			int j=p.second;
			if(j-1>=0 && visited[i][j-1]==0)
			{
				q.push(std::pair<int,int>(i,j-1));
				ans[i][j-1]=ans[i][j]+1;
				visited[i][j-1]=1;
			}
			if(j+1<m && visited[i][j+1]==0)
			{
				q.push(std::pair<int,int>(i,j+1));
				ans[i][j+1]=ans[i][j]+1;
				visited[i][j+1]=1;
			}
			if(i-1>=0 && visited[i-1][j]==0)
			{
				q.push(std::pair<int,int>(i-1,j));
				ans[i-1][j]=ans[i][j]+1;
				visited[i-1][j]=1;
			}
			if(i+1<n && visited[i+1][j]==0)
			{
				q.push(std::pair<int,int>(i+1,j));
				ans[i+1][j]=ans[i][j]+1;
				visited[i+1][j]=1;
			}
		}
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<m;j++)
			{
				printf("%d ",ans[i][j]);
			}
			printf("\n");
		}
	}
}
