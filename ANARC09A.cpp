#include<iostream>
#include<stdio.h>
#include<stack>
#include<string>
using namespace std;

int getMin(string i)
{
	stack<char> s;
	for(int j=0;j<i.length();j++)
	{
		if(i.at(j)=='{')
			s.push('{');
		else if(!s.empty())
		{
			if(s.top()=='{')
				s.pop();
			else
				s.push('}');

		}
		else
			s.push('}');
	}
	int count=0;
	while(!s.empty())
	{
		char t=s.top();
		if(t=='{')
		{
			count++;
			s.pop();
			t=s.top();
			if(t=='{')
				s.pop();
			else
			{
				count++;
				s.pop();
			}
		}
		else if(t=='}')
				{
					s.pop();
					t=s.top();
					if(t=='{')
						s.pop();
					else
					{
						count++;
						s.pop();
					}
				}
	}

	return count;

}


int main()
{
	string i="d";
	int test=1;
	while(i[0]!='-')
	{
		cin>>i;
		printf("%d. %d\n",test,getMin(i));
	}

	return 0;
}
