#include<iostream>
#include<string.h>
#include<queue>
using namespace std;
int n,t1,p,t2,dist,last,first;
queue<std::pair<int, int> > q;
int BFS(int visited[], vector<int> b[])
{
	while(!q.empty())
		{
			std::pair<int, int> z=q.front();
			p=z.first;
			dist=z.second;
			q.pop();
			visited[p]=1;
			for(int i=0;i<b[p].size();i++)
			{
				if(visited[b[p][i]]!=1)
				{
					q.push(std::pair<int, int>(b[p][i],dist+1));	
				}
			}
		}
}
int main()
{
		
		scanf("%d",&n);

		vector<int> b[n+1];
		int visited[n];
		memset(visited,0,sizeof(visited));
		for(int i=0;i<n-1;i++)
		{
			scanf("%d %d",&t1,&t2);
				b[t1].push_back(t2);
				b[t2].push_back(t1);
		}
		q.push(std::pair<int,int>(1,0));
		BFS(visited,b);
		q.push(std::pair<int, int>(p,0));
		memset(visited,0,sizeof(visited));
		BFS(visited,b);
		printf("%d",dist);
		return 0;
}
