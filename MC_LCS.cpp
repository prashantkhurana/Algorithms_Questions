#include<iostream>
#include<cstring>
#include<vector>
using namespace std;


#define max(a,b) a>b?a:b
std::string result[100];
int i=0;


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
	return lcs[n][m];
//	std::string s;
//	printlcs(a,b,lcs,n,m,s);
}

int main()
{
	std::string a,b;
	while(1)
	{
		cin>>a;
		if(a.compare("#")==0)
		break;
		cin>>b;
		int x=LCS(a,b);
		int y=((a.length()-x)*15)+((b.length()-x)*30);
		cout<<y<<endl;
	}
	return 1;
}
