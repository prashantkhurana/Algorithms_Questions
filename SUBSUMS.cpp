#include<iostream>
#include<vector>
#include<math.h>
#include<algorithm>
#include<stdio.h>
using namespace std;


int n, a, b;
int s[34];
int t[34];


vector<long long> subsets(int s[34],int start, int end)
{
	int c=pow(2,end-start);
	vector<long long> ans;
	for(int i=0;i<c;i++)
	{
		long long sum=0;
		for(int j=0;j<(end-start);j++)
		{
			if(i&(1<<j))
				sum+=s[j];
		}
		//cout<<"adding sum:"<<sum<<endl;
		ans.push_back(sum);
	}
	//cout<<"answer:";
	for(int i=0;i<c;i++)
		{
			//cout<<ans[i]<<endl;
		}
	return ans;
}
int main()
{
	long long ans=0;

	scanf("%d %d %d",&n,&a,&b);
	for(int i=0;i<n/2;i++)
	{
		scanf("%d",&s[i]);
	}
	for(int i=n/2;i<n;i++)
	{
		scanf("%d",&t[i-n/2]);
	}
	vector<long long> x=subsets(s,0,n/2);
	vector<long long> y=subsets(t,n/2,n);
	sort(y.begin(),y.end());

	int c=pow(2,n/2);
	for(int i=0;i<c;i++)
	{
		int f=x[i];
		//cout<<"f is"<<f<<endl;
		int g=a-f;
		//cout<<"g is"<<g<<endl;
		int h=b-f;
		//cout<<"h is"<<h<<endl;
		vector<long long>::iterator low=lower_bound(y.begin(),y.end(),g);
		long long n=low-y.begin();
		//cout<<"n is "<<n<<endl;
		vector<long long>::iterator upper=upper_bound(y.begin(),y.end(),h);
		long long m=upper-y.begin();
		//cout<<"m is"<<m<<endl;
		ans+=(m-n);
	}
	cout<<ans<<endl;
}
