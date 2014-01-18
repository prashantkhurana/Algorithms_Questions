#include <cstdio>

using namespace std ;

int main( )
{
	int t , n , q , i , j , k ,q1, q2, sum,c=1;;
	scanf("%d",&t) ;
	while(t--)
	{
		scanf("%d",&n) ;
		
		int d[n+1][n+1] ;

		for( i = 1 ; i <= n ; i++ )
		{
			for( j = 1 ; j <= n ; j++ )
				scanf("%d",&d[i][j]) ;
		}
		
		for( k = 1 ; k <= n ; k++ )
		{
			for( i = 1 ; i <= n ; i++ )
			{
				for( j = 1 ; j <= n ; j++ )
				{
					if( d[i][k] + d[k][j] < d[i][j] )
						d[i][j] = d[i][k] + d[k][j] ;
				}
			}
		}
				
		scanf("%d",&q) ;
		sum=0;
		for( k = 1 ; k <= q ; k++ )
		{
			scanf("%d %d",&q1,&q2) ;
			sum += d[q1][q2] ;
		}
		
		printf("Case #%d: %d\n",c,sum) ;
		c++;
	}
	
	return 0 ;
}
