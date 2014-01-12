#include<iostream>
#include<cstring>
#include<vector>
using namespace std;

#define max(a,b) a>b?a:b


void printlcs(std::string a, std::string b,std::vector<std::vector<int> > lcs, int n, int m)
{
	if(n==0 || m==0)
	cout<<"";
	else if(a[n-1]==b[m-1])
	{
		printlcs(a,b,lcs,n-1,m-1);
		cout<<a[n-1];
	}
	else
	{
		if(lcs[n][m-1]>lcs[n-1][m])
		printlcs(a,b,lcs,n,m-1);
		else
		printlcs(a,b,lcs,n-1,m);
	}
}


int LCS(std::string a, std::string b)
{
	int n=a.length();
	int m=b.length();
	
	std::vector<std::vector<int> > lcs;	
	lcs.resize(n+1);
	for(int i=0;i<=n;i++)
	lcs[i].resize(m+1);
	
	for(int i=0;i<=n;i++)
	for(int j=0;j<=m;j++)
	{	
		if(i==0 || j==0)
		lcs[i][j]=0;
		else if(a[i-1]==b[j-1])
			lcs[i][j]=1+lcs[i-1][j-1];
		else
		lcs[i][j]=max(lcs[i-1][j],lcs[i][j-1]);
	}
	cout<<lcs[n][m]<<endl;
	printlcs(a,b,lcs,n,m);
}

int main()
{
	std::string a,b;
	cin>>a>>b;
	LCS(a,b);
	return 1;
}
