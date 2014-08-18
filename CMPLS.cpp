#include <iostream>
#include <vector>
using namespace std;
 
 
int temp[102][102];
 
 
int validate(int temp1[102],int level1,int s)
{
	for(int i=0;i<s-level1-1;i++)
	if(temp1[i]!=temp1[i+1])
	return 1;
	
	return 0;
} 
int MOD(int seq[102],int s,  int c){
     
    int i;
    for(i=0;i<s;i++){
        temp[0][i] = seq[i];
    }
     
    int order,idx;
    int flag=true;
    int level=1;
    while(flag)
    {
    	for(int i=0;i<s-level;i++)
    	temp[level][i]=temp[level-1][i+1]-temp[level-1][i];
    	flag=validate(temp[level],level,s);
    	if(flag)
    	level++;
    }
       
    
	for(int i=s-level;i<s-level+c;i++)
	{
		temp[level][i]=temp[level][i-1];
	}     
	
	for(int i=level-1;i>=0;i--)
	{
		for(int j=s-i;j<s-i+c;j++)
		{
			temp[i][j]=temp[i][j-1]+temp[i+1][j-1];
		}
	}   
}
 
int main(){
    int t,s,c;
    scanf("%d",&t);
     
    int e;
    for(int i=0;i<t;i++){
        scanf("%d %d",&s,&c);
        int seq[102];
        for(int j=0;j<s;j++){
            scanf("%d",&e);
            seq[j] = e;
        }
         
       MOD(seq,s, c);
         
        for(int j=s;j<s+c;j++){
            if(j!=s)printf(" ");
            printf("%d",temp[0][j]);
        }
         
        printf("\n");
    }
}
