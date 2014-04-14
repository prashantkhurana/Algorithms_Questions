#include<iostream>
#include<stdio.h>
using namespace std;


int f,c,r;

int visited[1000][1000];
char l[1000][1000];

struct node
{
	int x;
	int y;
	int d;
};

typedef struct node node;

node dfs(int fi, int fj, int r, int c)
{	
	visited[fi][fj]=1;
	node max;
	max.x=fi;
	max.y=fj;
	max.d=0;
	if(visited[fi+1][fj]==0 && l[fi+1][fj]=='.')
	{
		node x=dfs(fi+1,fj,r,c);
		x.d++;
		max=x;
	}
	if(visited[fi-1][fj]==0 && l[fi-1][fj]=='.')
	{
		node y=dfs(fi-1,fj,r,c);
		y.d++;
		if(max.d<y.d)
		max=y;
	}
	if(visited[fi][fj+1]==0 && l[fi][fj+1]=='.')
	{
		node y=dfs(fi,fj+1,r,c);
		y.d++;
		if(max.d<y.d)
		max=y;
	}
	if(visited[fi][fj-1]==0 && l[fi][fj-1]=='.')
	{
		node y=dfs(fi,fj-1,r,c);
		y.d++;
		if(max.d<y.d)
		max=y;
	}
	
	return max;
}

int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d %d\n" ,&c,&r);
		f=0;
		char b;
		int fi,fj;
		for(int i=0;i<r;i++)
		{
				scanf(" %[^\n]",l[i]);
			//	cout<<endl<<l[i]<<endl;
				for(int j=0;j<c;j++)
				if(l[i][j]=='.' && f==0)
				{
					fi=i;
					fj=j;
					f=1;
				}
		}
		for(int i=0;i<r;i++)
		{
			for(int j=0;j<c;j++)
			visited[i][j]=0;
		}
		
		node m=dfs(fi,fj,r,c);
				for(int i=0;i<r;i++)
		{
			for(int j=0;j<c;j++)
			visited[i][j]=0;
		}

		m=dfs(m.x,m.y,r,c);
		printf("Maximum rope length is %d.\n",m.d);
	}
}
