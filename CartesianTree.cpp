#include<iostream>
#include<algorithm>
#include<vector>

#define MAX 10000;
using namespace std;


typedef struct node
{
	int val;
	int count;
	int left_size;
	int right_size;
	int size;
}node;


std::vector<node> tree;

node makeNode(int val)
{
	node t;
	t.val=val;
	return t;
}


 int buildTree(int s[], int as, int ae, int t)
 {
 	if(as>ae)
 	return 0;
 	else
 	{
 		int mid=(as+ae)/2;
  		node x=makeNode(s[mid]);
  		x.left_size=buildTree(s,as,mid-1,2*t);
  		x.right_size=buildTree(s,mid+1,ae,2*t+1);
  		x.count=1;
  		x.size=x.left_size+x.right_size+x.count;
  		tree[t]=x;
  		return x.size;
 	}
 }
  	
 int makeTree(int s[], int n)
  {
  	tree.resize(1000);
  	return(buildTree(s,0,n-1,1));
  }

int query(int k, int t)
 {
 	if(k<=tree[t].left_size)
 	{
 		return(query(k,2*t));
 	}
 	else if(k>(tree[t].left_size+tree[t].count))
 	{
 		return(query(k-tree[t].left_size-tree[t].count,2*t+1));
 	}
 	else
 	{
 		tree[t].count=0;
 		return tree[t].val;
 	}
 }
 
 int findKSmallest(int k)
 {
 	return query(k,1);
 }  
  
  int main()
  {
  	int s[]={1,2,3,4,5};
  	makeTree(s,5);
  	for(int i=1;i<=7;i++)
  	cout<<tree[i].size<<" ";
  	cout<<endl;
  	cout<<findKSmallest(1);
  	cout<<endl;
  	cout<<findKSmallest(1);
  	return 0;
  }
