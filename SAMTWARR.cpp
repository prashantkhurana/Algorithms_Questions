#include<iostream>
#include<algorithm>
#include<vector>

#define MAX 10000;
using namespace std;


typedef struct node
{
	int val;
	int sum;
	//int count;
	struct node *left;
	struct node *right;
}node;

typedef struct node *nodeptr;
nodeptr root1=NULL;
nodeptr root2=NULL;
//std::vector<node> tree;

nodeptr makeNode(int val)
{
	nodeptr  t=new node();
	t->val=val;
	t->sum=val;
	return t;
}
int getSum(nodeptr root)
{
	return root==NULL?0:root->sum;
}

 nodeptr buildTree(int as, int ae, int t)
 {
 	if(as>ae)
 	return NULL;
 	if(as==ae){
 		nodeptr x=makeNode(t);
 		x->left=NULL;
 		x->right=NULL;
 		return x;
 	}
 	else
 	{
 		int mid=(as+ae)/2;
  		nodeptr x=makeNode(t);
  		x->left=buildTree(as,mid-1,t);
  		x->right=buildTree(mid+1,ae,t);
  		x->sum+=getSum(x->left)+getSum(x->right);
  		//x.count=1;
  		//x.size=x.left_size+x.right_size+x.count;
  		//tree[t]=x;
  		return x;
 	}
 }
  	
int query(int s, int e, int as, int ae, nodeptr root)
 {
 	if(s>ae||e<as)
 	return 0;
 	if(as>ae)
 	return 0;
 	if(as==ae)
 	return root->val;
 	if(s<=as&&e>=ae)
 	return root->sum;
 	else
 	{
 		int mid=(as+ae)/2;
 		int ans=0;
 		if(mid>=s&&mid<=e)
 		ans=ans+root->val;
 		return (ans+query(s,e,as,mid-1,root->left)+query(s,e,mid+1,ae,root->right));
 	}
}

void update(nodeptr &root, int i, int v, int as, int ae)
{
	if(as>ae)
	return;
	else if(as<=ae)
	{
		int mid=(as+ae)/2;
		if(mid==i)
		{
		//	root->sum-=root->val;
			root->val=v;
			//root->sum+=v;
		}
	//	root->val=v;
		else if(mid>i)
		update(root->left,i,v,as,mid-1);
		else
		{
		//int mid=(as+ae)/2;
		
		update(root->right,i,v,mid+1,ae);
		}
		root->sum=root->val+getSum(root->left)+getSum(root->right);
	}
}

void swap(nodeptr &root1, nodeptr &root2, int l, int r,int as, int ae)
{
	if(as>ae)
	return;
	if(l>ae ||r<as)
	return;
	if(l<=as && r>=ae)
	{
		nodeptr x=root1;
		root1=root2;
		root2=x;
		return;
	}
	int mid=(as+ae)/2;
	if(mid>=l&&mid<=r)
	{
		int temp=root1->val;
		root1->val=root2->val;
		root2->val=temp;
	}
		swap(root1->left,root2->left,l,r,as,mid-1);
		swap(root1->right,root2->right,l,r,mid+1,ae);
		root1->sum=root1->val+getSum(root1->left)+getSum(root1->right);
		root2->sum=root2->val+getSum(root2->left)+getSum(root2->right);
}
  
  int main()
  {
  	
  	int n,m,p,cmd,q,l,r,v,a,in;
	scanf("%d %d",&n,&m);
		root1=buildTree(1,n,0);
		root2=buildTree(1,n,0);
	for(int i=1;i<=m;i++)
	{
		scanf("%d",&cmd);
		if(cmd==0)
		{
			scanf("%d %d %d",&a,&l,&r);
			if(a==0)
			printf("%d\n",query(l+1,r+1, 1, n,root1));
			else
			printf("%d\n",query(l+1,r+1,1,n,root2));
		}
		if(cmd==1)
		{
			scanf("%d %d %d",&a,&in,&v);
			if(a==0)
			{
				update(root1,in+1,v,1,n);
			}
			else
			{
				update(root2,in+1,v,1,n);
			}
	
		}
		if(cmd==2)
		{
			scanf("%d %d",&l,&r);
			swap(root1,root2,l+1,r+1,1,n);
		}
	}
	return 0;
  }
