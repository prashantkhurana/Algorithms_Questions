#include <cstdio>
//#include <algorithm>

using namespace std;

int main() {
	int A, D, atac[11], def[11],min;

	while ( 1 ) {
		scanf( "%d%d", &A, &D );
		if ( A == 0 && D == 0 ) {
			break;
		}
		int i, j;
		for ( i = 0; i < A; ++i ) {
			scanf( "%d", &atac[i] );
			if(i==0)
			min=atac[i];
			else
			if(atac[i]<min)
			min=atac[i];
		}
		int count=0;
		for ( i = 0; i < D; ++i ) {
			scanf( "%d", def + i );
			if(def[i]<=min)
			count++;
		}
				if(count>=2)
				printf( "N\n" );
				else
				printf( "Y\n" );
		}

	return 0;
}
