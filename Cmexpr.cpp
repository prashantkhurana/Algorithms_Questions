//Giving TLE. I think because of heavy use of stl and also the approach is the naive approcah of converion to postfix, then expression tree and then solution.
// However all the test cases run perfectly.
// Any change suggestion is welcome.
#include<iostream>
#include<stack>
#include<cstring>
#include<stdlib.h>
#include<stdio.h>
#include<conio.h>
using namespace std;

std::string infix;
std::string postfix;
typedef struct node *nodeptr;
typedef struct node
{
	char c;
	struct node *left;
	struct node *right;
}node;

nodeptr root=NULL;
nodeptr newnode(char c)
{
	nodeptr x=new node();
	x->c=c;
	x->left=NULL;
	x->right=NULL;
	return x; 
}



int preference(char s)
{
	switch (s)
	{
		case '*':	return 1;
					break;
		case '/':	return 1;
					break;
		case '+':	return 2;
					break;
		case '-':	return 2;
					break;
		case '(':   return 3;
					break;
	}
}
void infixToPostfix()
{
	std::stack<char> s;
	for(int i=0;i<infix.size();i++)
	{
		if(isalpha(infix[i]))
		postfix.push_back(infix[i]);
		else
		{
			switch(infix[i])
			{
				case '(':	s.push(infix[i]);
							break;
				case ')':	while(s.top()!='(')
							{
								postfix.push_back(s.top());
								s.pop();
							}
							s.pop();
							break;
							
				default :	int p1,p2=10;
							do
							{
								p2=10;
								p1=preference(infix[i]);
								if(!s.empty())
								{
									p2=preference(s.top());
									if(p2<=p1)
									{
										postfix.push_back(s.top());
										s.pop();
									}
								}	
							
								
							}	while(p2<=p1);
							s.push(infix[i]);
								
				
							
			}
		}
		
	}
	while(!s.empty())
	{
		postfix.push_back(s.top());
		s.pop();
	}
	
}

nodeptr buildTree(std::string postfix )
{
	std::stack<nodeptr> s1;
	for(int i=0;i<postfix.length();i++)
	{
		if(isalpha(postfix[i]))
		{
			nodeptr x=newnode(postfix[i]);
			s1.push(x);
		}
		else
		{
			nodeptr tt1=NULL,tt2=NULL;
			tt1=s1.top();
			s1.pop();
			tt2=s1.top();
			s1.pop();
			nodeptr x=newnode(postfix[i]);
			x->left=tt2;
			x->right=tt1;
			s1.push(x);
		}
	}
	nodeptr q=s1.top();
	return q;
}

int cleanedexpr(nodeptr root)
{
	if(root==NULL)
	return 0;
	else
	if(isalpha(root->c))
	cout<<root->c;
	else 
	{
		nodeptr l=root->left;
		nodeptr r=root->right;
		int k=preference(root->c);
		if(l!=NULL)
		{
			if(isalpha(l->c))
			cleanedexpr(l);
			else{
			int i=preference(l->c);
			if(k<i)
			{
				cout<<"{";
				cleanedexpr(l);
				cout<<"}";
			}	
			else
			cleanedexpr(l);
		}
		}
		cout<<root->c;
		if(r!=NULL)
		{
			if(isalpha(r->c))
			cleanedexpr(r);
			else{
			int i=preference(r->c);
			if(k<i)
			{
				cout<<"{";
				cleanedexpr(r);
				cout<<"}";
			}
			else if(k==i&&(r->c=='+')&&(root->c=='-'))
			{
				cout<<"{";
				cleanedexpr(r);
				cout<<"}";
			}
			else if(k==i&&(r->c=='-')&&(root->c=='-'))
			{
				cout<<"{";
				cleanedexpr(r);
				cout<<"}";
			}
			else if(k==i&&(r->c=='*')&&(root->c=='/'))
			{
				cout<<"{";
				cleanedexpr(r);
				cout<<"}";
			}
			else if(k==i&&(r->c=='/')&&(root->c=='/'))
			{
				cout<<"{";
				cleanedexpr(r);
				cout<<"}";
			}


			else
			cleanedexpr(r);
		}
		}
	}
}

int main()
{
	int n;
	cin>>n;
	while(n--){
	cin>>infix;
	infixToPostfix();
	root=buildTree(postfix);
	int x=cleanedexpr(root);
	cout<<endl;
}
	getch();
	
	return 1;
}
