#include<iostream>
#include<algorithm>
#include<stdlib.h>
#include<time.h>
using namespace std;

struct node
{
	int p,v;
	struct node *left,*right;
	int size;
	
	int max; //    extra
	
	int update; //extra
};


typedef struct node node;
typedef struct node *nodeptr;

nodeptr root=NULL;


int getSize(nodeptr x)
{
	return x==NULL?0:x->size;
}


// Extra 
int getMax(nodeptr x)
{
	return x==NULL?0:x->max;
}



void preorder(nodeptr root)
{
	if(root==NULL)
	{
		
	}
	else
	{
		printf("max:%d,value:%d,priority:%d    ",root->max,root->v,root->p);
		preorder(root->left);
		preorder(root->right);
	}
	
}


nodeptr buildTree(int p, int v, nodeptr left, nodeptr right)
{
	nodeptr x=new node();
	x->p=p;x->v=v;x->left=left;x->right=right;x->update=0;
	return x;
}


nodeptr update(nodeptr x)
{
	if(x==NULL)
	return x;
	else
	{
		{
			x->max+=x->update;
			x->v+=x->update;
			if(x->update!=0)
			{
				if(x->left!=NULL)
				x->left->update=x->update;
				if(x->right!=NULL)
				x->right->update=x->update;
				x->update=0;
			}
		}
		return x;
	}
}
nodeptr merge(nodeptr small, nodeptr big)
{
	small=update(small);
	big=update(big);
	if(small==NULL)
	return big;
	if(big==NULL)
	return small;
	if(big->p>small->p)
	{
		nodeptr x=merge(small,big->left);
		nodeptr y=buildTree(big->p,big->v,x,big->right);
		y->size=getSize(y->left)+getSize(y->right)+1;
		y->max=std::max(std::max(getMax(y->left),getMax(y->right)),y->v); //extra
		return y; 
	}
	else
	{
		nodeptr x=merge(small->right,big);
		nodeptr y=buildTree(small->p,small->v,small->left,x);
		y->size=getSize(y->left)+getSize(y->right)+1;
		y->max=std::max(std::max(getMax(y->left),getMax(y->right)),y->v);   // extra
		return y;
	}
}


nodeptr split(int pos, nodeptr root, nodeptr &left, nodeptr &right)
{
	if(root==NULL)
	{
		left=NULL;
		right=NULL;
	}
	else
	{
		update(root);
		int size=getSize(root->left)+1;
		if(pos<size)
		{
			nodeptr x,y;
			split(pos,root->left,x,y);
			nodeptr z=buildTree(root->p,root->v,y,root->right);
			z->size=getSize(z->left)+getSize(z->right)+1;
			z->max=std::max(std::max(getMax(z->left),getMax(z->right)),z->v);   // extra
			right=z;
			left=x;
		}
		else
		{
			nodeptr x,y,z;
			split(pos-size,root->right,x,y);
			z=buildTree(root->p,root->v,root->left,x);
			z->size=getSize(z->left)+getSize(z->right)+1;
			z->max=std::max(std::max(getMax(z->left),getMax(z->right)),z->v);   // extra
			right=y;
			left=z;
		}
	}
}


nodeptr insert(int pos,int p, int v)
{
	nodeptr x,y,z;
	split(pos,root,x,y);
	//printf("pre order of splitted x ::");
	//preorder(x);
	//printf("pre order of splitted y ::");
	//preorder(y);
	return merge(merge(x,buildTree(p,v,NULL,NULL)),y);
}

nodeptr remove(int pos)
{
	nodeptr x,y,z,t;
	split(pos,root,x,y);
	split(1,y,z,t);
	return merge(x,t);
}


int rangeQuery(int i, int j)
{
	nodeptr x,y,z,t;
	split(i,root,x,y);
	split(j-i+1,y,z,t);
	return z->max;
}


nodeptr rangeUpdate(int i, int j, int k)
{
	nodeptr x,y,z,t;
	split(i,root,x,y);
	split(j-i+1,y,z,t);
	z->max+=k;
	if(z->left!=NULL)
	z->left->update=k;
	if(z->right!=NULL)
	z->right->update=k;
	return merge(x,merge(z,t));
}
int main()
{
	int s[10]={2,3,4,5,6};
	srand(time(NULL));
	int p;
//	root=insert(0,5,2);
//	root=insert(1,6,3);
//	root=insert(2,10,4);
//	root=insert(3,8,5);
//	root=insert(4,9,6);

	for(int i=0;i<5;i++)
	{
		p=rand()%100;
		printf("p is :%d\n",p);
		root=insert(i,p,s[i]);
	//	printf("preorder of whole tree::::");
		preorder(root);
		printf("\n");
	}
	root=remove(3);
	preorder(root);
	printf("\n\n%d\n\n",rangeQuery(0,1));
	printf("\n\n%d\n\n",rangeQuery(0,3));
	root=rangeUpdate(0,3,2);
	preorder(root);
	printf("\n\n%d\n\n",rangeQuery(0,3));
	return 0;
}
