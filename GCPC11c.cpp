#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stack>
#include<vector>
#include<queue>
using namespace std;

int s,e;
struct node
{
	int start;
	int end;
};
typedef struct node node;



stack<int> q;
queue<int> q2;

int DFS(vector<int> a[], int i, int visited[], int processing[] , node v[])
{
	int x=0;
	processing[i]=1;
	v[i].start=s++;
	for(int m=0;m<a[i].size();m++)
	{
		int nvnv=a[i].at(m);
		if(visited[nvnv]==0 && processing[nvnv]==0)
		{
			x=DFS(a,nvnv,visited,processing,v);
			if(x==-1)
			return -1;
		}
		else
		{
			if(v[nvnv].start<v[i].start && processing[nvnv]==1)
			return -1;
		}
	}
	visited[i]=1;
	processing[i]=0;
	v[i].end=s++;
	q.push(i);
	return 1;
}

int  do_DFS(vector<int> a[],int n)
{
	s=1;
	int visited[10005];
	int processing[10005];
	node v[10005];
	queue<int> emptyq;
	swap(q2,emptyq);
	stack<int> emptys;
	swap(q,emptys);
	int x=0;
	memset(visited,0,sizeof(visited));
	memset(processing,0,sizeof(processing));
	for(int i=1;i<=n;i++)
	{
		if(visited[i]==0)
		{
			x=DFS(a,i,visited,processing,v);
			if(x==-1)
			{
				printf("recheck hints\n");
				return -1;
			}
		}
	}
	return 1;
}
int main()
{
int t,i,j,n,h,u,v;
scanf("%d",&t);

for(i=0;i<t;i++)
	{
	scanf("%d %d",&n,&h);
	vector<int> a[10004];
//	int vett[n+10][n+10];
//	memset(vett,0,sizeof(vett));
	for(j=0;j<h;j++)
		{
		scanf("%d %d",&u,&v);
		a[u].push_back(v);
		//vett[u][v]=1;
		}
	int nbn=do_DFS(a,n);
	if(nbn==1)
	{
		int g=q.top();
	int y;
	q.pop();
	int set=1;
	while(!q.empty())
	{
		y=q.top();
		q.pop();
		while(a[g].size() && a[g].back()!=y)
		{
			a[g].pop_back();
		}
		if(a[g].size()==0)
		{
			printf("missing hints");
			set=0;
			break;
		}
		else
		{
			q2.push(g);
			g=y;
		}
	}
	q2.push(g);
	if(set)
		while(!q2.empty())
		{
			int cc=q2.front();
			printf("%d ",cc);
			q2.pop();
		}
		printf("\n");
	}
	}
return 0;
}
