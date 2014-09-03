#include<iostream>
#include<queue>
#include<vector>
#include<string.h>
using namespace std;
#define NILL 0
#define INF (1<<28)
queue<int> q;
int n,m,t;
vector<int> g[90002];
int match[180002];
int layer[180002];
int matching;



struct node1
{

	int column1,colum2,row1;
};



struct node2
{

	int row1,row2,colum1;
	
};

typedef struct node1 node1;

typedef struct node2 node2;

bool bfs()
{
	for(int i=1;i<=n;i++)
	{
		if(match[i]==NILL)
		{
				q.push(i);
				layer[i]=0;
		}
		layer[i]=INF;
	}
	
	layer[0]=INF;
	
	while(!q.empty())
	{
		int u=q.front();
		q.pop();
		if(u!=NILL)
		{
			for(int i=0;i<g[u].size();i++)
		{	
			int v=g[u][i];
			
			if(layer[match[v]]==INF)
			{
				q.push(match[v]);
				layer[match[v]]=layer[u]+1;
			}
		}
		}
		
	}
	if(layer[NILL]==INF)
	return false;
	else
	return true;
}


bool dfs(int p)
{
	if(p==NILL)
	return true;
	
	for(int i=0;i<g[p].size();i++)
	{
		int q=g[p][i];
		if(layer[match[q]]==layer[p]+1)
		{
			if(dfs(match[q]))
			{
				match[p]=q;
				match[q]=p;
				return true;
			}
		}
	}
	layer[p]=INF;
	return false;
}


int hopcroft()
{
	matching=0;
	memset(match,0,sizeof(match));
	while(bfs())
	{
		for(int i=1;i<=n;i++)
		{
			if(match[i]==NILL && dfs(i))
			{
				matching++;
			}
		}
	}
	return matching;
}

int main()
{
	char c;
	scanf("%d",&t);
	
	while(t--)
	{
		scanf("%d %d",&n,&m);
		int k=0;
		vector<node1> rows;
		vector<node2> columns;
		char m4[300][300];
		int last;
		for(int i=0;i<=90000;i++)
		{
			g[i].clear();
		}
		
		for(int i=0;i<n;i++)
		{
			last=0;
			
			for(int j=0;j<m;j++)
			{
				scanf(" %c",&m4[i][j]);
				c=m4[i][j];
				if(c=='A')
				{
					//node1 b={last,j-1,i};
					node1 x;
				x.column1=last;
				x.colum2=j-1;
				x.row1=i;
									rows.push_back(x);

					last=j+1;
				}
			}
			//if(last==0)
			{
				node1 x;
				x.column1=last;
				x.colum2=m-1;
				x.row1=i;
				rows.push_back(x);
				//cout<<rows[0].colum2<<rows[0].column1<<rows[0].row1;	
			}
		}
		
		for(int i=0;i<rows.size();i++)
		{
			//cout<<rows[i].colum2;
		}
		
		for(int i=0;i<m;i++)
		{
			last=0;
			for(int j=0;j<n;j++)
			{
				c=m4[j][i];
				if(c=='A')
				{
					node2 x;
				x.row1=last;
				x.row2=j-1;
				x.colum1=i;
					columns.push_back(x);
					last=j+1;
				}
			}
			//if(last==0)
			{
					node2 x;
				x.row1=last;
				x.row2=n-1;
				x.colum1=i;
					columns.push_back(x);
			}
		}
		
		for(int i=0;i<rows.size();i++)
		{
			node1 a=rows[i];
			for(int j=0;j<columns.size();j++)
			{
				node2 b=columns[j];
				if(a.colum2>=0 && a.column1>=0 && a.row1>=0 && b.colum1>=0&& b.row1>=0 && b.row2>=0)
				{
					if(a.column1<=b.colum1 && a.colum2>=b.colum1 && b.row1<=a.row1 && b.row2>=a.row1)
					{
						if(m4[a.row1][b.colum1]!='D')
						g[i+1].push_back(90000+j+1);
					}
				}
			}
		}
		
		n=rows.size();
		printf("%d\n",hopcroft());
	}
	return 0;
}
