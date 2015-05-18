#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;


bool cmp( pair< pair<int,int>, pair<int,int> > x, pair< pair<int,int>, pair<int,int> > y)
{
	return x.second.second<y.second.second;
}

bool cmp2( pair< pair<int,int>, pair<int,int> > x, pair< pair<int,int>, pair<int,int> > y)
{
	return x.first.first<y.first.first;
}
#define maxval 30005


int t[30005]; 

int lastpos[1000006];

int ans[200005];


void update(int index, int val)
{
	while(index<=maxval)
	{
		t[index]+=val;
		index+=(index & -index);
	}
}

int read(int index)
{
	int sum=0;
	while(index>0)
	{
		sum+=t[index];
		index-=(index &-index);
	}
	return sum;
}


int main()
{
	vector< pair< pair<int,int>, pair<int,int> > > num(30005);
	int n,q;
	scanf("%d",&n);
	int a[30005];
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
		//num.insert(pair<int,int>(a[i],i));
	}
	scanf("%d",&q);
	int g,h;
	for(int i=1;i<=q;i++)
	{
		scanf("%d %d",&g,&h);
		pair<int,int> u=pair<int,int>(i,0);
		pair<int,int> v=pair<int,int>(g,h);
		pair<pair<int,int> , pair<int, int> > w=make_pair(u,v);
		
		num.push_back(w);
	}
	
	sort(num.begin(),num.end(),cmp);
	
	int end=0;
	int total=0;
	for(int i=1;i<=n;i++)
	{
		if(lastpos[a[i]]==0)
		{
			lastpos[a[i]]=i;
			update(i,1);
			total++;
		}
		else
		{
			update(lastpos[a[i]],-1);
			update(i,1);
			lastpos[a[i]]=i;
		}
		while(num[end].second.second<=i && end<num.size())
		{
			int c=read(num[end].second.first-1);
			int d=total;
			num[end].first.second=d-c;
			ans[num[end].first.first]=d-c;
			end++;
		}
	}
	
	//sort(num.begin(),num.end(),cmp2);
	
	for(int i=1;i<=q;i++)
	{
		printf("%d\n",ans[i]);
	}
	return 0;
}
