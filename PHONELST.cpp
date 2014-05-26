#include<iostream>
#include<stdio.h>
#include<string.h>
using namespace std;


typedef struct trie trie;
typedef struct trie *trieptr;

struct trie
{
	int val;
	struct trie* child[10];
};


trieptr root=NULL;

void initialize()
{
	trieptr x=new trie();
	x->val=0;
	for(int i=0;i<10;i++)
	{
		x->child[i]=NULL;
	}
	root=x;
}


trieptr getTrie()
{
	trieptr x=new trie();
	x->val=0;
	for(int i=0;i<10;i++)
	{
		x->child[i]=NULL;
	}
	return x;
	
}

int add(trieptr root, char key[11])        //no number is the prefix of another.
{
	int len=strlen(key);
//	if(root->child[key[0]-'0']==NULL)
//	{
//		trieptr x=getTrie();
//		root->child[0]=x;
//	}
	
	//trieptr  x=root->child[key[0]-'0'];
	trieptr y=root;
	for(int i=0;i<len;i++)
	{
		if(y->val==1)
		return 0;
		if(y->child[key[i]-'0']==NULL)
		y->child[key[i]-'0']=getTrie();
		y=y->child[key[i]-'0'];
	}
	y->val=1;
	for(int i=0;i<10;i++)
	{
		if(y->child[i]!=NULL)
		return 0;
	}
	return 1;
}



int main()
{
	int t, n,b;
	char s[11];
	scanf("%d",&t);
	while(t--)
	{
		b=0;
		initialize();
		scanf("%d",&n);
		for(int i=0;i<n;i++)
		{
			scanf("%s",s);
			if(b==0)
			if(add(root,s)==0)
			{
				printf("NO\n");
				b=1;
			}
		}
		if(b==0)
		printf("YES\n");
	}
	return 0;
}


