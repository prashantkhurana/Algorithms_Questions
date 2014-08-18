#include <iostream>
#include<vector>
#include<queue>
#include<map>
#include <climits>
using namespace std;



int visited[10001];
int d[10001];


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
		visited[i]=0;
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
	
	int s,n,p,nr,cost,number,r;
	string city,name1,name2;
	vector<std::pair<int,int> >g[10001];
	scanf("%d",&s);
	while(s--){
		scanf("%d",&n);
		map <string,int> name;
		number = 0;
		
		for (int i = 0; i<=n;++i) g[i].clear();
		for (int i = 0; i<n;i++){
			number++;
			cin >> city;
			name.insert(pair<string,int>(city,number));
			scanf("%d",&p);
			for (int j = 0; j<p;j++){
				scanf("%d %d",&nr,&cost);
				g[number].push_back(std::pair<int,int>(nr,cost));
			}
		}
		
		printf("%d\n",MST(g,n+1));
		
	}
	return 0;
}
