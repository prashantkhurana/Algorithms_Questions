#include<iostream>
#include<map>
#include<cstring>
#include<string.h>
using namespace std;

struct node
{
	std::string s;
	struct node *f;
	struct node *b;
	
};

typedef struct node node;
typedef struct node *nodeptr;

nodeptr createNode(std::string s)
{
	nodeptr x=new node();
	x->s=s;
	x->f=NULL;
	x->b=NULL;
	return x;
}

void merge(nodeptr &x, nodeptr &y)
{
	x->f=y;
	y->b=x;
}
nodeptr getFirst(nodeptr x)
{
	while(x->b!=NULL)
	x=x->b;
	return x;
}

int main()
{
	//std::map<std::string,nodeptr> m;
	std::map<std::string, int> m2;
	int x,y;
	nodeptr p1,p2;
	std::string p,q;
	int n,t;
	scanf("%d",&t);
	for(int i=1;i<=t;i++){
	scanf("%d",&n);
	std::map<std::string,nodeptr> m;
	while(--n)
	{
		cin>>p;
		cin>>q;
		map<std::string,nodeptr>::iterator it1=m.find(p);
		map<std::string,nodeptr>::iterator it2=m.find(q);
		if(it1==m.end())
		{
			p1=createNode(p);
			m[p]=p1;
			//m2[p]=1;
		}
		if(it2==m.end())
		{
			p2=createNode(q);
			m[q]=p2;
			//m2[q]=1;
		}
		p1=m.find(p)->second;
		p2=m.find(q)->second;
		merge(p1,p2);
	}
	nodeptr z=getFirst(p2);
	cout<<"Scenario #"<<i<<":"<<endl;
	while(z!=NULL)
	{
		cout<<z->s<<endl;
		z=z->f;
	}
}
return 0;
}

