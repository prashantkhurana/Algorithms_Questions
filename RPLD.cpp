// AC , ALGO : STL

/* 
	Helpful Link : http://www.cplusplus.com/reference/set/set/ 
*/

// For any clarifications, contact me at : osinha6792@gmail.com

#include<cstdio>
#include<set>
using namespace std ;

int main( )
{
  	int  t , n , r , i , r1 , r2 ,np;
	
	scanf("%d",&t) ;
	
	for( i = 1 ; i <= t ; i++ )
	{
		scanf("%d %d",&n,&r) ;
		np=0;
		set<pair<int,int> > s;
		bool status = true ;
		
		for( int j = 0 ; j < r ; j++ )
		{
			scanf("%d %d",&r1,&r2) ;
			if(s.count(pair<int,int>(r1,r2)))
			np=1;
			else
			s.insert( pair<int,int>(r1,r2) ) ;
		}
		if( np )
			printf("Scenario #%d: impossible\n",i) ;
		else
			printf("Scenario #%d: possible\n",i) ;
	}
	
	return 0 ;
}
