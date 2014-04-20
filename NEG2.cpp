#include<iostream>
#include<stdio.h>
#include<stack>
#include<string>
using namespace std;

int getQ(int x, int y)
{
	int q=x/y;
	if(x-y*q>=0)
		return q;
	else
		return q+1;
}

void convert(int x)
{
	char s[1000];
	int i=0;
	int q;
	while(1)
	{
		q=getQ(x,-2);
		s[i]='0'+x-(-2*q);
		i++;
		if(q==0)
			break;
		x=q;
	}
	s[i]='\0';
	for(int j=i-1;j>=0;j--)
		printf("%c",s[j]);
}
int main()
{
	int x;
	scanf("%d",&x);
	convert(x);
	return 0;
}
