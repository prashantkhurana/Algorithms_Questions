#include <iostream>
#include <stdio.h>
using namespace std;

int numbits(long long a){
	int c;
	for(c=0; a; c++)
		a &= a-1;
	return c;
}

int main() {
	
	int N, T;
	long long k;
	scanf("%d",&T);
	while(T--){
		scanf("%d",&N);
		scanf("%lld",&k);
		int c = numbits(k-1);
		if(c&1) cout<<"Female\n";
		else cout<<"Male\n";
	}
	
	return 0;
}
