#include<iostream>
#include<cstring>

using namespace std;

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
		case '.':	return 4;
					break;
	}
}

int testifnecessary(char previousoperator,char minoperator,char nextoperator)
{
	int p1=preference(previousoperator);
	int p2=preference(minoperator);
	int p3=preference(nextoperator);
	if(p1==p3 && previousoperator=='.')
	return 0;
	else if (minoperator=='.')
	return 0;
	else
	if(p1<p2)
	return 1;
	else if(p1==p2 && previousoperator=='/' && minoperator=='*')
	return 1;
	else if(p1==p2 && previousoperator=='/' && minoperator=='/')
	return 1;
	else if(p1==p2 && previousoperator=='-' && minoperator=='+')
	return 1;
	else if(p1==p2 && previousoperator=='-' && minoperator=='-')
	return 1;
	else if(p3<p2)
	return 1;
	else 
	return 0;
}
void removeredundant(std::string s)
{

//	while(s[0]=='(' && s[s.length()-1]==')')
//	{
//		s.erase(0,1);
//		s.erase(s.length()-1,1);
//	}

	for(int i=0;i<s.length();i++)
	{
		if(s[i]=='(')
		{
			char previousoperator='.';
			char nextoperator='.';
			char minoperator='.';
			if(i!=0)
			previousoperator=s[i-1];
			int matchingparenthesis;
			int p=0;
			for(int j=i+1;j<s.length();j++)
			{
				if(s[j]==')'&&p==0)
				{
					matchingparenthesis=j;
					break;
				}
				else if(s[j]=='(')
				p++;
				else if(s[j]==')')
				p--;
				else if(!isalpha(s[j]) && p==0)
				{
					if(minoperator=='.')
					minoperator=s[j];
					else if(preference(minoperator)<preference(s[j]))
					minoperator=s[j];
				}
				
				
			}
			if(matchingparenthesis!=(s.length()-1))
			nextoperator=s[matchingparenthesis+1];
			if(!testifnecessary(previousoperator,minoperator,nextoperator))
			{
				s.erase(i,1);
				s.erase(matchingparenthesis-1,1);
				i--;
			}
			
		}
	}
	cout<<s;
		
}
int main()
{
	std::string s;
	int n;
	cin>>n;
	while(n--)
	{
	
	cin>>s;
	removeredundant(s);
	cout<<endl;
}}
