#include <cstdio>
#include <algorithm>



using namespace std;


int gcd(int a, int b)
{
	if(a%b==0)
	return b;
	else
	return gcd(b,a%b);
}


int main(){
    int N,x[100000];
    
    scanf("%d",&N);
    
    for(int i = 0;i < N;++i)
        scanf("%d",&x[i]);
    
    int g = x[1] - x[0];
    
    for(int i = 1;i + 1 < N;i++)
        g = gcd(g,x[i + 1] - x[i]);
    
    int ans = 0;
    
    ans=((x[N-1]-x[0])/g)+1-N;
    printf("%d\n",ans);
    
    return 0;
}

