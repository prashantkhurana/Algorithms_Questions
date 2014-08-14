#include<iostream>
#include<stdio.h>
using namespace std;

struct node
{
	int left_reqd;
	int right_reqd;
};

typedef struct node node;


node modify(node tree[], int l, int r, int k, int i)
{
		if(k<=r && k>=l)
		{
			if(l==r)
			{
				if(tree[i].right_reqd==1)
				{
					tree[i].left_reqd=1;
					tree[i].right_reqd=0;
				}
				else
				{
					tree[i].left_reqd=0;
					tree[i].right_reqd=1;
				}
				return tree[i];
			}
			int mid=(l+r)/2;
			tree[2*i]=modify(tree,l,mid,k,2*i);
			tree[2*i+1]=modify(tree,mid+1,r,k,2*i+1);
		tree[i].right_reqd=tree[2*i].right_reqd-tree[2*i+1].left_reqd ; //+tree[2*i+1].right_reqd;
//		printf("right %d",tree[i].right_reqd);
		if(tree[i].right_reqd<0)
		tree[i].right_reqd=0;
		tree[i].right_reqd+=+tree[2*i+1].right_reqd;
//		printf("right %d",tree[i].right_reqd);

		tree[i].left_reqd=tree[2*i+1].left_reqd-tree[2*i].right_reqd ; //+tree[2*i+1].left_reqd;
//				printf("left %d",tree[i].left_reqd);

		if(tree[i].left_reqd<0)
		tree[i].left_reqd=0;
		tree[i].left_reqd+=tree[2*i].left_reqd;	
//		printf("left %d",tree[i].left_reqd);

			}
		return tree[i];
}


node buildTree(char s[], int start, int end,int i, node tree[])
{
	if(start==end)
	{
		if(s[start]=='(')
		{
			tree[i].left_reqd=0;
			tree[i].right_reqd=1;
		}
		else
		{
			tree[i].left_reqd=1;
			tree[i].right_reqd=0;
			
		}
		return tree[i];
	}
	else
	{
		int mid=(start+end)/2;
		tree[2*i]=buildTree(s,start,mid,2*i,tree);
		tree[2*i+1]=buildTree(s,mid+1,end,2*i+1,tree);
		tree[i].right_reqd=tree[2*i].right_reqd-tree[2*i+1].left_reqd ; //+tree[2*i+1].right_reqd;
		if(tree[i].right_reqd<0)
		tree[i].right_reqd=0;
		tree[i].right_reqd+=+tree[2*i+1].right_reqd;
		tree[i].left_reqd=tree[2*i+1].left_reqd-tree[2*i].right_reqd ; //+tree[2*i+1].left_reqd;
		if(tree[i].left_reqd<0)
		tree[i].left_reqd=0;
		tree[i].left_reqd+=tree[2*i].left_reqd;
		//tree[i].sum=tree[2*i].sum+tree[2*i+1].sum;
//		if(tree[i].sum==0)
//		{
//			if(tree[2*i].sum>tree[2*i+1].sum) //&& tree[2*i].stable=='Y' && tree[2*i+1].stable=='Y') 
//			tree[i].stable='Y';
//			else if(tree[2*i].sum==0&& tree[2*i].stable=='Y' && tree[2*i+1].stable=='Y')
//			tree[i].stable='Y';
//			else
//			tree[i].stable='N';
//		}
//		else
//		{
//			tree[i].stable='N';
//		}
		return tree[i];
	}
}


node query(node tree[])
{
	if(tree[1].left_reqd!=0 || tree[1].right_reqd!=0)
	{
		printf("NO\n");
	}
	else
	{
		printf("YES\n");
	}
}


int main()
{
	for(int l=1;l<=10;l++)
	{
		int n;
		scanf("%d\n",&n);
		char s[n+1];
		node tree[4*n];
		for(int i=1;i<=n;i++)
			scanf("%c",&s[i]);
		node root=buildTree(s,1,n,1,tree);
		int m,k;
		scanf("%d",&m);
		printf("Test %d:\n",l);
		for(int i=0;i<m;i++)
		{
			scanf("%d",&k);
			if(k==0)
			query(tree);
			else
			root=modify(tree,1,n,k,1);
		}
	}
	return 0;
}
