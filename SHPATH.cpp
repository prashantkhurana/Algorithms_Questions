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


void Djkstra(vector<std::pair<int,int> > g[1000], int s, int dest,int size)
{
	std::priority_queue<std::pair<int,int> ,vector<std::pair<int,int> >,compare > pq;
	
	for (int i = 0; i<=size;++i){
		d[i] = INT_MAX;
	}
	d[s] = 0;
	
	
	
	pq.push(std::pair<int,int>(s,0));
	while(!pq.empty())
	{
		std::pair<int,int> x=pq.top();
		if(x.first==dest)
		{
		    break;
		} 
		pq.pop();
		if(d[x.first]>=x.second)
		{
			for(int i=0;i<g[x.first].size();i++)
			{
				if(d[g[x.first][i].first]>g[x.first][i].second+x.second)
				{
					pq.push(std::pair<int,int>(g[x.first][i].first,g[x.first][i].second+x.second));
					d[g[x.first][i].first]=g[x.first][i].second+x.second;
				}
			
			}
			visited[x.first]=1;
		}
	}
	printf("%d\n",d[dest]);
	
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
		scanf("%d",&r);
		for (int i = 0; i<r;i++){
			cin >> name1 >> name2;
			Djkstra(g,name.find(name1)->second,name.find(name2)->second,n);
		}
	}
	return 0;
}
