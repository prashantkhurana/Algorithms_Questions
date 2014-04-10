#include<iostream>
#include<stdio.h>
#include<string.h>

using namespace std;


int duval_no(char str[]){
	int i=0,j=1,k=0,N;
	char a,b;
			N=strlen(str);
			for(int i=N;i<2*N;i++)
			str[i]=str[i-N];
			str[2*N]='\0';
			N*=2;
			
			
	while(i+k < N && j+k < N){
		a= str[i+k];
		b= str[j+k];
		if(a==b)
		k++;
		else if(a > b){
			//i=i+k;
			//if(i <= j)
			i=j++;
			//j++;
			k=0;
		}
		else{
			j=j+k+1;
			//if(j<=i)
			//j=i+1;
			k=0;
		}
	}		
	return i;
}


int main(){
int t;
char str[200010];
scanf("%d",&t);
while(t--){
scanf("%s",str);
printf("%d\n",duval_no(str)+1);
}
return 0;
}
