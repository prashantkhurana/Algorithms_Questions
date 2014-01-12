#include<iostream>
#include<stack>
#include<cstring>
#include<stdlib.h>
#include<stdio.h>
#include<conio.h>
using namespace std;

char infix[100];
std::string postfix;

int preference(char s)
{
	switch (s)
	{
		case '*':	return 0;
					break;
		case '/':	return 0;
					break;
		case '+':	return 1;
					break;
		case '-':	return 1;
					break;
	}
}
void infixToPostfix()
{
	std::stack<char> s;
	for(int i=0;i<strlen(infix);i++)
	{
		if(isdigit(infix[i]))
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


int main()
{
	cin>>infix;
	infixToPostfix();
	cout<<postfix;
	getch();
	return 1;
}
