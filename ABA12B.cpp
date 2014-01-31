#include<stdio.h>
#include<string.h>

int main()
{
int i,t,j,k,l,cl;
char s[100000];
int dist;
scanf("%d",&t);
while(t--)
{
	scanf("%s",s);
	int start=0,start_to=0;
	int end,end_to=0,count=0;
	end=1;dist=0;
	int last_end, last_start;
	int count_change=0;
	//,end_to=0;
	while((end+end_to)<strlen(s))
	{
		char x=s[start+start_to];
		char y=s[end+end_to];
		if(x!=y)
		{
			dist=end-start;
			end++;
			
		}
		else
		{
			start_to++;
			end_to++;
			while(s[start+start_to]==s[end+end_to]&&dist>0)
			{
				start_to++;
				end_to++;
				dist--;
			}
			if(dist==0)
			{
				count+=2;
				count_change=1;
				last_start=start;
				last_end=end+1;
				start=end+end_to;
				start_to=0;
				end=start+1;
				end_to=0;
				
			}
			
			else
			{
				count_change=0;
				dist++;
				start_to=0;
				end_to=0;
				end++;
			}
		}
		if(count_change==0 &&(end+end_to)>=strlen(s) )
		{
			end=last_end;
			count=count-2;
			start=last_start;
			end_to=0;
			start_to=0;
		}
	}
			printf("%d\n",count);

}
return 0;
}
