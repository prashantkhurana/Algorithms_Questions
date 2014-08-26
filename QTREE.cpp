//TLE , but code should work

#include<iostream>
#include<vector>
using namespace std;


struct node
{
	int max;
	int l_range;
	int r_range;
};

typedef struct node node;

int max(int a, int b)
{
	if(a>=b)
		return a;
	else
		return b;
}

vector<int> adj[10009],cost[10009];
vector<std::pair<int, int> > edge;
int visited[10009],parent[10009],size[10009],head[10009],heavy[10009],depth[10009],chain[10009],heavycost[10009],
segposition[10009],segtree[10009];

node tree[40027];
int N;




node buildTree(int start, int end,int i)
{
	if(start==end)
	{
		tree[i].max=segtree[start];
		tree[i].l_range=start;
		tree[i].r_range=end;
		return tree[i];
	}
	else
	{
		int mid=(start+end)>>1;
		tree[2*i]=buildTree(start,mid,2*i);
		tree[2*i+1]=buildTree(mid+1,end,2*i+1);
		tree[i].l_range=start;
		tree[i].r_range=end;
		tree[i].max=max(tree[2*i].max,tree[2*i+1].max);
		return tree[i];
	}
}

node query(int i, int start, int end)
{

	if(tree[i].l_range>=start && tree[i].r_range<=end)
		return tree[i];
	else
	{
		int mid=(tree[i].l_range+tree[i].r_range)/2;
		if(end<=mid)
		return query(2*i,start,end);
		if(start>=(mid+1))
		return query(2*i+1,start,end);
		else
		{
			node x;
			node a=query(2*i,start,end);
			node b=query(2*i+1,start,end);
			x.max=max(a.max,b.max);
			return x;
		}
	}
}


node modify(int i, int idx, int val)
{
	
		if(tree[i].l_range==tree[i].r_range)
		{
			tree[i].max=val;
			return tree[i];
		}
		else
		{
			int mid=(tree[i].l_range+tree[i].r_range)/2;
			if(idx<=mid)
			{
				node x=modify(2*i,idx,val);
				tree[i].max=max(x.max,tree[2*i+1].max);
				return tree[i];
			}
			if(idx>=mid+1)
			{
				node x=modify(2*i+1,idx,val);
				tree[i].max=max(x.max,tree[2*i].max);
				return tree[i];
			}
		}
}


void doDFS(int i)
{
	visited[i]=1;
	int maxsize=-1;
	int maxchild=-1;
	int heavyc=-1;
	for(int j=0;j<adj[i].size();j++)
	{
		int child=adj[i][j];
		
		if(visited[child]==0)
		{
			parent[child]=i;
			depth[child]=depth[i]+1;
			doDFS(child);
			size[i]+=size[child];
			if(size[child]>maxsize)
			{	
				maxsize=size[child];
				maxchild=child;
				heavyc=cost[i][j];
			}
		}
	}
	heavy[i]=maxchild;
}

int LCS(int u, int v)
{
	while(chain[u]!=chain[v])
	{
		if(depth[head[u]]>depth[head[v]])
		u=parent[head[u]];
		else
		v=parent[head[v]];
	}
	return depth[u]>depth[v]?v:u;
}

void DFSHLD()
{
	for(int i=1;i<=N;i++)
	{
		visited[i]=0;
		size[i]=1;
		parent[i]=-1;
		head[i]=-1;
		heavy[i]=-1;
		depth[i]=-1;
	}
	depth[1]=0;
	head[1]=-1;
	for(int i=1;i<=N;i++)
	{
		if(visited[i]==0)
		doDFS(i);
	}
	
	int c=1;
	int s=1;
	for(int i=1;i<=N;i++)
	{
		if(parent[i]==-1 || heavy[parent[i]]!=i)
		{
			for(int l=i;l!=-1;l=heavy[l])
			{
				chain[l]=c;
				head[l]=i;
				segtree[s]=heavycost[l];
				segposition[l]=s;
				s++;
			}
		}
		c++;
	}
}

node query_tree(int a, int b)
{
	node c;
	c.max=-1;
	while(1)
	{
		if(chain[a]==chain[b])
		{
			if(a==b)
			{
				return c;
			}
			else
			{
				node d=query(1,segposition[a]+1,segposition[b]);
				return c.max>d.max?c:d;
			}
			
		}
		else
		{
		node x= query(1,segposition[head[b]],segposition[b]);
		b=parent[head[b]];
		if(x.max>c.max)
		c=x;
		}
	}
}


int main()
{
	int t,a,b,c;
	char s[100];
	scanf("%d",&t);
	while(t--)
	{
		
		scanf("%d",&N);
		for(int i=1;i<=N;i++)
		{
			adj[i].clear();
			heavycost[i]=-1;
		}
		edge.resize(N+1);
		for(int i=1;i<=N-1;i++)
		{
			scanf("%d %d %d",&a,&b,&c);
			adj[a].push_back(b);
			adj[b].push_back(a);
			cost[a].push_back(c);
			cost[b].push_back(c);
			std::pair<int,int> nm=std::pair<int,int>(a,b);
			edge[i]=nm;
			heavycost[b]=c;
		}
		DFSHLD();
		buildTree(1,N,1);
		while(1) {
			
			scanf("%s", s);
			if(s[0]=='D') {
				break;
			}
			int a, b;
			scanf("%d %d", &a, &b);
			if(s[0]=='Q') {
				int x=LCS(a,b);
				//node y=query_tree(x,a);
				//node z=query_tree(x,b);
				//node y=query_tree(segposition[x],segposition[a]);
				//node z=query_tree(1,segposition[x],segposition[b]);
				//printf("%d\n",max(y.max,z.max));
				printf("%d\n",max(query_tree(x,a).max,query_tree(x,b).max));
			} else {
				//std::pair<int,int> p=edge[a];
				modify(1,segposition[edge[a].second], b);
			}
		}
	}
}
