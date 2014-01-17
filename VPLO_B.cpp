#include<cstdio>
#include<climits>
#include<cstring>
#include<algorithm>
#include<vector>
#include<map>
using namespace std ;

inline int numd( int n )
{
  	int c = 0 ;
	
	if( n == 0 )
		return 1 ;
	
	while( n )
	{
		n /= 10 ;
		c++ ;
	}

	return c ;
}

int main( )
{
	int t , s , n,u,d;
	int min=1000,max=0;
	s=1;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d %d",&n,&u) ;

		int a[n] ;
		map<int,vector<int> > m;
		min=1000;max=0;
		for( int i = 0; i < n ; i++ )
		{
			scanf("%d",&a[i]) ;
			min=(a[i]/u)<min?a[i]/u:min;
			max=(a[i]/u)>max?a[i]/u:max;
			if(m.find(a[i]/u)==m.end())
			{
				m.insert(std::pair<int,vector<int> >(a[i]/u,vector<int>(1,a[i]%u)));
				//vector<int> v=	m.find(a[i]/u)->second;
				//for(int j=0;j<v.size();j++)
				//printf("%d ",v[j]);
			}
			
			else
			{
				map<int,vector<int> >::iterator v=	m.find(a[i]/u);
				//for(int j=0;j<v.size();j++)
				//printf("%d ",v[j]);
				v->second.push_back(a[i]%u);
				//m.erase(m.find(a[i]/u));
				//m.insert(std::pair<int,vector<int> >(a[i]/u,v));
			}
			//m.find(a[i]/u)->second.insert(m.find(a[i]/u)->second.begin()+a[i]%u,a[i]%u);
		}
		printf("Scenario #%d:\n",s) ;
		s++;
		for( int i = min ; i <= max ; i++ )
		{
			if(m.find(i)!=m.end())
			{
				int dmax = numd( max ) ;
				int di=numd(i);
				for( int j = 1 ; j <= dmax - di ; j++ )
				printf(" ") ;
				printf("%d | ",i) ;
				vector<int> v=m.find(i)->second;
				
			//	for(int j=0;j<v.size();j++)
			//	printf("%d ",v[j]);
				
				sort(v.begin(),v.end());
				
				for(int j=0;j<v.size();j++)
				printf("%d ",v[j]);
					printf("\n") ;
			}
		
		}
	}

	return 0 ;
}
