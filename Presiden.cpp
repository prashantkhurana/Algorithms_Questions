
#include <cstdio>
#include <cstring>
 
using namespace std ;
 
int main( )
{
        int t , c , v , i , j ;
        
        scanf("%d",&t) ;
        
        while( t-- )
        {
                scanf("%d %d",&c,&v) ;
                
                int p[v][c] , votes[c+1] , max1 , winner1 , max2 , winner2 ;
                //memset( votes , 0 , sizeof( pref ) ) ;
                
                for( i = 1 ; i <= c ; i++ )
                votes[i]=0;

                for( i = 0 ; i < v ; i++ )
                {
                        for( j = 0 ; j < c ; j++ )
                                scanf("%d",&p[i][j]) ;
                        votes[p[i][0]] += 1 ;
                }
                max1=0;max2=0;winner2=0;winner1=0;
                for( i = 1 ; i <= c ; i++ )
                {
                        if( max1 < votes[i] )
                        {
                                max2=max1;
                                winner2=winner1;
								max1 = votes[i] ;
                                winner1 = i ;
                                
                        }
                        else if(max2<votes[i])
                        {
                        	max2=votes[i];
                        	winner2=i;
                        }
                }
                
                if( ( ( double ) max1 ) / ( (double) v ) > 0.500000 )
                        printf("%d 1\n",winner1) ;
                else
                {
                        
                        for( i = 0 ; i < v ; i++ )
                        {
                               for(j=0;j<c;j++)
                               {
                               		if((p[i][j]==winner1) || (p[i][j]==winner2))
                               		{
                               			votes[p[i][j]]++;
                               			break;
                               		}
                               }
                        }
                        
                        if( votes[winner1] > votes[winner2] )
                                printf("%d 2\n",winner1) ;
                        else
                                printf("%d 2\n",winner2) ;
                }
        }
        
        return 0 ;
}
