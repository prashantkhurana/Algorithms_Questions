#include <iostream>
//#include<stdio.h>
#include<string.h>
#include<algorithm>
using namespace std;

const int MAX = 100005;
char a[MAX], b[MAX];
int dp_max[2][MAX], dp_min[2][MAX];

//
//inline int max(int i, int j)
//{
//	return i>j?i:j;
//}
//
//
//
//inline int min(int i, int j)
//{
//	return i<j?i:j;
//}

int findconsecutiveOnes(char a[])
{
	int i=0;
	while(i<strlen(a)&&a[i]=='1')
	i++;
	return i;
}
int findOnes(char a[])
{
	int i=0;
	int count=0;
	while(i<strlen(a))
	{
		if(a[i]=='1')
		count++;
		i++;
	}
	return count;
}

int findlastconsecutiveones(char a[])
{
	int i=strlen(a)-1;
	int count=0;
	while(i>0&&a[i]=='1')
	{
		count++;
		i--;
	}
	return count;
}

int findremainingones(int i, char a[])
{
	int count=0;
	i++;
	while(i<strlen(a))
	{
		if(a[i]=='1')
		count++;
		i++;
	}
	return count;
}


int main()
{
    int T;
    scanf("%d",&T);
    for (int ti = 0; ti < T; ++ti) {
        int n, m;
        scanf("%d%s%d%s", &n, a, &m, b);
        int consecutiveonesa=findconsecutiveOnes(a);
        int consecutiveonesb=findconsecutiveOnes(b);
        int allb=0;
        if(consecutiveonesb==strlen(b))
        {
        	allb=1;
        }
        int alla=0;
        if(consecutiveonesa==strlen(a))
        {
        	alla=1;
        }
        
        int small=consecutiveonesa<consecutiveonesb?consecutiveonesa:consecutiveonesb;
        int min=small;
		int lastconsecutiveonesa=findlastconsecutiveones(a);
		int lastconsecutiveonesb=findlastconsecutiveones(b);
		small=lastconsecutiveonesa<lastconsecutiveonesb?lastconsecutiveonesa:lastconsecutiveonesb;
		min=min+small;
		if(allb==1&&!alla)
		min=findOnes(a);
		if(!allb&&alla)
		min=findOnes(b);
		if(allb&&alla)
		min=findOnes(a)+findOnes(b)-1;
		
       // int remainingonesb=findremainingones(lastzerob,b);
        //int remainingonesa=findremainingones(lastzeroa,a);
       // if(lastzerob==0)
       // remainingonesb=strlen(b)-1;
       // if(lastzeroa==0)
        //remainingonesb=strlen(a)-1;
       // if(a[strlen(a)-1]!='0')
        //if(b[strlen(b)-1]=='0')
       // {
        	//if(lastzeroa)
        //	endcount=0;
       // }
       // else
//        {
//        	if(lastzerob==0)
//        	endcount=remainingonesa;
//        	if(lastzeroa==0)
//        	endcount=remainingonesb;
//        	else if(endcount!=remainingonesa)
//        	endcount=remainingonesb<remainingonesa?remainingonesb:remainingonesa;
//
//        }
//        min+=endcount;
        int numonesa=findOnes(a);
        int numonesb=findOnes(b);
        int max=(numonesb?1:0) *numonesa+(numonesa?1:0) *(numonesb?numonesb-1:0);
        printf("%d %d\n",max,min);
        }
    return 0;
}
