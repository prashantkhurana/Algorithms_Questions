#include<iostream>
#include<stdio.h>
#include<math.h>


using namespace std;

#define M 1000000009


int modExp(long long  b, int e, long long m)
{

	int remainder;
	long long  x = 1;

	while (e != 0)
	{
		remainder = e % 2;
		e= e/2;

		if (remainder == 1)
			x = (x * b) % m;
		b= (b * b) % m; 
	}
	return (int)x;
}


int main()
{
    int t;
    
    scanf("%d",&t);
    
    while(t--)
    {
              int n;
              
              scanf("%d",&n);
              
              long long sum=0;
              int count=0;
              int num=1;
              int a;
              int max=-2147483648;
              int numz=0;
              
              for(int i=0;i<n;i++)
              {
              	scanf("%d",&a);
              	
              	if(a>max)
              	{
              		max=a;
              		num=1;
              	}
              	else if(a==max)
              	{
              		num++;
              	}
              	
              	if(!a)
              	numz++;
              	
              	if(a>0)
              	{
              		sum+=a;
              	}
              	
              }
              
              if(max<0)
              {
              	printf("%d %d\n",max,num);
              }
              else if (max==0)
              {
              	printf("0 %d\n",modExp(2,numz,1000000009)-1);
              }
              else
              	printf("%lld %d\n",sum,modExp(2,numz,1000000009));
    }
    return 0;
}
                      
                      
                      
                      
                      
                      
                      
                      

