#include<iostream>
#include<queue>
using namespace std;

int visited[1000];



struct compare  
{  
  bool operator()(const std::pair<int,int>& a, const std::pair<int,int>& b )  
  {  
  	return a.second>b.second;
  }  
};  


int doMST(vector<std::pair<int,int> > g[1000], 	std::priority_queue<std::pair<int,int> ,vector<std::pair<int,int> >,compare > pq)
{
	int ans=0;
	while(!pq.empty())
	{
		std::pair<int,int> x=pq.top();
		pq.pop();
		if(visited[x.first]==0)
		{
			for(int i=0;i<g[x.first].size();i++)
			{
			pq.push(std::pair<int,int>(g[x.first][i].first,g[x.first][i].second));
			}
			ans+=x.second;
			visited[x.first]=1;
		}
	}
	return ans;
}


int MST(vector<std::pair<int,int> > g[1000], int size)
{
	std::priority_queue<std::pair<int,int> ,vector<std::pair<int,int> >,compare > pq;
	for(int i=1;i<size;i++)
	{
		visited[size]=0;
	}
	int ans=0;
	for(int i=1;i<size;i++)
	{
		if(visited[i]==0)
		{
			pq.push(std::pair<int,int>(i,0));
			ans+=doMST(g,pq);
		}
	}
	return ans;
}


int main()
{
	
	int t,p,n,m,a,b,c,x;
	scanf("%d",&t);
	while(t--)
	{
		vector<std::pair<int,int> >g[1000];
		scanf("%d",&p);
		scanf("%d",&n);
		scanf("%d",&m);
		x=m;
		while(m--)
		{
			scanf("%d %d %d",&a,&b,&c);
			g[a].push_back(std::pair<int,int>(b,c));
			g[b].push_back(std::pair<int,int>(a,c));
		}
		printf("%d\n",MST(g,n+1)*p);
	}
}
