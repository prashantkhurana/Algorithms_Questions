#include<iostream>
using namespace std;


struct node
{
	int k,p;
	struct node *left,*right,*parent;
};

typedef struct node node;
typedef struct node *nodeptr;

nodeptr root=NULL;

nodeptr makeNode(int k,int p)
{
	nodeptr x=new node();
	x->k=k;x->p=p;x->left=NULL;x->right=NULL,x->parent=NULL;
	return x;
}

nodeptr insertbst(int key, int pri, nodeptr root)
{
	if(root==NULL)
	{
		root=makeNode(key,pri);
		return root;
	}
	else if(root->k<=key)
	{
		nodeptr x=insertbst(key,pri,root->right);
		if(root->right==NULL)
		{
			root->right=x;
			root->right->parent=root;
		}
		
		return x;
	}
	else
	{
		nodeptr x=insertbst(key,pri,root->left);
		if(root->left==NULL)
		{
			root->left=x;
			root->left->parent=root;
		}
		return x;
	}
}


nodeptr rightRotate(nodeptr x, nodeptr parent)
{
	 if(parent->parent==NULL)
	{
		root=x;
		x->parent=NULL;
		parent->right=x->left;
		x->left=parent;
		parent->parent=x;
	}
	else if(parent->parent->left==parent)
	{
		parent->parent->left=x;
		x->parent=parent->parent;
		parent->right=x->left;
		x->left=parent;
	}
	else if(parent->parent->right==parent)
	{
		parent->parent->right=x;
		x->parent=parent->parent;
		parent->right=x->left;
		x->left=parent;
		parent->parent=x;
	}
	return x;
}


nodeptr leftRotate(nodeptr x, nodeptr parent)
{
	if(parent->parent==NULL)
	{
		root=x;
		x->parent=NULL;
		parent->left=x->right;
		x->right=parent;
		parent->parent=x;
	}

	else if(parent->parent->left==parent)
	{
		parent->parent->left=x;
		x->parent=parent->parent;
		parent->left=x->right;
		x->right=parent;
		parent->parent=x;
	}
	else if(parent->parent->right==parent)
	{
		parent->parent->right=x;
		x->parent=parent->parent;
		parent->left=x->right;
		x->right=parent;
		parent->parent=x;
	}
		return x;
}


void insert(int key, int pri)
{
	if(root==NULL)
	root=insertbst(key,pri,root);
	else
	{
		nodeptr x=insertbst(key,pri,root);
		printf("\ninserted: %d\n",x->k);
		while(x->parent!=NULL&&x->p<x->parent->p)
		{
			if(x->parent->right==x)
			x=rightRotate(x,x->parent);
			else if(x->parent->left==x)
			x=leftRotate(x,x->parent);
		}
		printf("\nnew root:%d\n",root->k);
	}
}

int inorder(nodeptr root)
{
	if(root==NULL)
	return 0;
	else
	{
		
		inorder(root->left);
		printf("%d",root->k);
		inorder(root->right);
	}
}


int main()
{
	insert(1,17);
	insert(2,30);
	insert(3,47);
	insert(4,33);
	insert(5,11);
	inorder(root);
	return 0;
}
