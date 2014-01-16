#include<cstdio>
#include<cstring>
#include<vector>

#define MAX 100001

using namespace std ;

int binarySearch( vector<int> x , int key, int l , int r) 
{
	int k;
	if(key>x[r])
	return r+1;
	int m;
	while(r>=l)
	{
		m=(l+r)/2;
    	if(x[m]==key)
    	return m;
    	else
    	{
    		if(x[m]>key){
    		r=m-1;
    		//k=1;
    	}
    		else{
    		l=m+1;
    		//k=0;
    	}
    	}
	}
	return l;
	
}
	

int LIS( int a[] , int size ) 
{
    vector<int> x;
    int len , i ;
    x.push_back(-1);
    for( i = 0 ; i < size ; i++ ) 
	{
		if(a[i]<x[1])
		x[1]=a[i];
		else if(a[i]>x[x.size()-1])
		x.push_back(a[i]);
		else
		{
			int y=binarySearch(x,a[i],0,x.size()-1);
			x[y]=a[i];
		}
    }
    return x.size()-1;

    //delete[] tailTable ;

    //return len ;
}

int main( )
{
	int a[MAX] , b[MAX] , c[MAX] , t , n ;
	
	scanf("%d",&t) ;
	
	while(t--)
	{
		scanf("%d",&n) ;
		
		for( int i = 0 ; i < n ; i++ )
		{
			scanf("%d",&a[i]) ;
			c[a[i]] = i ;
		}
		
		for( int i = 0 ; i < n ; i++ )
		{
			scanf("%d",&a[i]) ;
			b[i] = c[a[i]] ;
		}
		
		printf("%d\n",LIS( b , n )) ;
	}
	
	return 0 ;
}
