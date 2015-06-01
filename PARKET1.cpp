#include<iostream>
#include<algorithm>
#include<string>
#include<list>
#include<queue>
#include<map>
#include<string.h>
#include<stdio.h>
#include<math.h>
using namespace std;

int main()
{
	int r,b;
	cin>>r>>b;
	
	int plus=(r+4)/2;
	int mul=b+2*plus-4;
	int min=sqrt(plus*plus-4*mul);
	
	int l=(plus+min)/2;
	int w=(plus-min)/2;
	
	if(l>w)
	cout<<l<<" "<<w;
	else cout<<w<<" "<<l;
	return 0;
}
