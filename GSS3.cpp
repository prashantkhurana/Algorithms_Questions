#include<iostream>
#include<stdio.h>
using namespace std;

struct node
{
	int max_sum;
	int l_range;
	int r_range;
	int cum_sum;
	int end_sum;
	int start_sum;
	struct node *left;
	struct node *right;
};

typedef struct node node;

int max(int a, int b)
{
	if(a>=b)
		return a;
	else
		return b;
}
int max(int a,int b, int c)
{
	if(a>=b &&a>=c)
		return a;
	else if(b>=a&&b>=c)
		return b;
		return c;
}


node modify(node tree[], int i, int idx, int val)
{
	
		if(tree[i].l_range==tree[i].r_range)
		{
			tree[i].max_sum=val;
			tree[i].end_sum=val;
			tree[i].cum_sum=val;
			tree[i].start_sum=val;
			return tree[i];
		}
		else
		{
			int mid=(tree[i].l_range+tree[i].r_range)/2;
			if(idx<=mid)
			{
				node x=modify(tree,2*i,idx,val);
				tree[i].max_sum=max(x.max_sum,tree[2*i+1].max_sum,x.end_sum+tree[2*i+1].start_sum);
				tree[i].start_sum=max(x.start_sum,x.cum_sum+tree[2*i+1].start_sum);
				tree[i].end_sum=max(tree[2*i+1].end_sum,x.end_sum+tree[2*i+1].cum_sum);
				tree[i].cum_sum=x.cum_sum+tree[2*i+1].cum_sum;
				return tree[i];
			}
			if(idx>=mid+1)
			{
				node x=modify(tree,2*i+1,idx,val);
				tree[i].max_sum=max(x.max_sum,tree[2*i].max_sum,tree[2*i].end_sum+x.start_sum);
				tree[i].start_sum=max(tree[2*i].start_sum,tree[2*i].cum_sum+x.start_sum);
				tree[i].end_sum=max(x.end_sum,x.cum_sum+tree[2*i].end_sum);
				tree[i].cum_sum=x.cum_sum+tree[2*i].cum_sum;
				return tree[i];
			}
		}
}



node buildTree(int s[], int start, int end,int i, node tree[])
{
	if(start==end)
	{
		tree[i].max_sum=s[start];
		tree[i].l_range=start;
		tree[i].r_range=end;
		tree[i].end_sum=s[start];
		tree[i].cum_sum=s[start];
		tree[i].start_sum=s[start];
		return tree[i];
	}
	else
	{
		int mid=(start+end)/2;
		tree[2*i]=buildTree(s,start,mid,2*i,tree);
		tree[2*i+1]=buildTree(s,mid+1,end,2*i+1,tree);
		tree[i].l_range=start;
		tree[i].r_range=end;
		tree[i].max_sum=max(tree[2*i].max_sum,tree[2*i+1].max_sum,tree[2*i].end_sum+tree[2*i+1].start_sum);
		tree[i].start_sum=max(tree[2*i].start_sum,tree[2*i].cum_sum+tree[2*i+1].start_sum);
		tree[i].end_sum=max(tree[2*i+1].end_sum,tree[2*i].end_sum+tree[2*i+1].cum_sum);
		tree[i].cum_sum=tree[2*i].cum_sum+tree[2*i+1].cum_sum;
		return tree[i];
	}
}

node query(node tree[], int i, int start, int end)
{

	if(tree[i].l_range>=start && tree[i].r_range<=end)
		return tree[i];
	else
	{
		int mid=(tree[i].l_range+tree[i].r_range)/2;
		if(end<=mid)
		return query(tree,2*i,start,end);
		if(start>=(mid+1))
		return query(tree,2*i+1,start,end);
		else
		{
			node x;
			node a=query(tree,2*i,start,end);
			node b=query(tree,2*i+1,start,end);
			x.max_sum=max(a.max_sum,b.max_sum,a.end_sum+b.start_sum);
			x.start_sum=max(a.start_sum,a.cum_sum+b.start_sum);
			x.end_sum=max(b.end_sum,a.end_sum+b.cum_sum);
			x.cum_sum=a.cum_sum+b.cum_sum;
			return x;
		}
	}
}


int main()
{
	int n;
	scanf("%d",&n);
	int s[n+1];
	node tree[4*n+1];
	for(int i=1;i<=n;i++)
		scanf("%d",&s[i]);
	node root=buildTree(s,1,n,1,tree);
	int m,x,y,c;
	scanf("%d",&m);
	for(int i=0;i<m;i++)
	{
		scanf(" %d %d %d",&c,&x,&y);
		if(c==1)
		printf("%d\n",query(tree,1,x,y).max_sum);
		else
		modify(tree,1,x,y);
	}
	return 0;
}
