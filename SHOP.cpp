#include <iostream>
#include<vector>
#include<queue>
#include<map>
#include <climits>
using namespace std;

int h,w;

struct node
{
	int i;
	int j;
};

typedef struct node node;



int equals(node source, node dest)
{
	if(source.i!=dest.i || source.j!=dest.j)
	return 0;
	else 
	return 1;
}

int visited[26][26];
int d[26][26];
int dist[26][26];
struct compare  
{  
  bool operator()(const std::pair<node,int>& a, const std::pair<node,int>& b )  
  {  
  	return a.second>b.second;
  }  
};  



int Djkstra(node source, node dest)
{
	std::priority_queue<std::pair<node,int> , vector<std::pair<node,int> >, compare > pq;
	
	for(int i;i<26;i++)
	{
		for(int j=0;j<26;j++)
		{
			d[i][j]=INT_MAX;
			visited[i][j]=0;
		}
	}
	d[source.i][source.j]=0;
	pq.push(std::pair<node,int>(source,0));
	while(!pq.empty())
	{
		std::pair<node,int> x=pq.top();
		if(equals(x.first,dest))
		{
			return x.second;
		    break;
		} 
		pq.pop();
		if(!visited[x.first.i][x.first.j])
		{
			visited[x.first.i][x.first.j]=1;
			if(x.first.i-1>=0)
			{
				node n={x.first.i-1,x.first.j};
				pq.push(std::pair<node,int>(n,x.second+dist[x.first.i-1][x.first.j]));
			}
			if(x.first.i+1<h)
			{
				node n={x.first.i+1,x.first.j};
				pq.push(std::pair<node,int>(n,x.second+dist[x.first.i+1][x.first.j]));
			}
			
			if(x.first.j-1>=0)
			{
				node n={x.first.i,x.first.j-1};
				pq.push(std::pair<node,int>(n,x.second+dist[x.first.i][x.first.j-1]));
			}
			
			if(x.first.j+1<w)
			{
				node n={x.first.i,x.first.j+1};
				pq.push(std::pair<node,int>(n,x.second+dist[x.first.i][x.first.j+1]));
			}

		}
	}
	
}





int main() {
	node source;
	node dest;
	char x;
	while(scanf("%d %d\n", &w, &h)==2 && (w||h)) 
	{
		for(int i=0;i<h;i++)
		{
			for(int j=0;j<w;j++)
			{
				scanf("%c\n",&x);
				if(x=='X')
				dist[i][j]=15645;
				else if(x=='S')
				{
					source.i=i;
					source.j=j;
					dist[i][j]=0;
				}
				else if(x=='D')
				{
					dest.i=i;
					dest.j=j;
					dist[i][j]=0;
				}
				else
				{
					dist[i][j]=x-'0';
				}
				
			}
		}
		printf("%d\n", Djkstra(source,dest));
	}
	return 0;
}

