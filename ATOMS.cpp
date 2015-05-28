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
	long long int   n,k,m; 
	int t;
	cin>>t;
	
	while(t--)
	{
	
	cin>>n>>k>>m;
	
	if(n>=m)
	{
		cout<<"0"<<endl;
	
	}
	else
	{
		float answer=log(m/n)/log(k);
	//cout<<m/n;
	cout<<(int)answer<<endl;
	}
	
}
		return 0;
}
