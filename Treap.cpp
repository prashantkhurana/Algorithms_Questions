#include<iostream>
using namespace std;


typedef struct node
{
	int k,p;
}node;

const int maxval=30000;


node tree[maxval]={0,0};


int insertbst(int key, int pri, int root)
{
	if(tree[root].k==0)
	{
		tree[root].k=key;
		tree[root].p=pri;
		return root;
	}
	else if(tree[root].k<=key)
	return insert(key,pri,root*2+1);
	else
	return insert(key,pri,root*2);
}


void rightrotate()
{
	
}
void insert(int key, int pri,int root)
{
	int pos=insertbst(key,pri,root);
	while(tree[pos].p<tree[pos/2].p)
	rightrotate();
	
}




int main()
{
	insert(2,2,1);
	insert(1,4,1);
	insert(3,6,1);
	for(int i=0;i<100;i++)
	{
		cout<<tree[i].k;
	}
	return 0;
}
