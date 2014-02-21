#include<iostream>
using namespace std;


int main()
{
	int i=-1,numdeleted=0,left=0,mid_new=0,right=0;
	int max_heap_left[100000],min_heap_right[100000];
	int input,left_size=0,right_size=0,left_pointer=0,right_pointer=0,right_start=0;
	while(scanf("%d",&input)!=EOF)
	{
		if(input==-1)
		{
			if(left_size>=right_size)
			{
				printf("%d\n",max_heap_left[--left_pointer]);
				left_size--;
			}
			else
			{
				printf("%d\n",min_heap_right[right_start++]);
				right_size--;
			}
		}
	
		else if(input==0)
		{
			left_size=0;
			right_size=0;
			left_pointer=0;
			right_pointer=0;
			right_start=0;
			printf("\n");
		}
		else
		{
			if(left_size<=right_size)
			{
				if(right_pointer!=0)
				{
					max_heap_left[left_pointer++]=min_heap_right[right_start];
					right_start++;
					min_heap_right[right_pointer++]=input;
					left_size++;
				}
				else
				{
					max_heap_left[left_pointer++]=input;
					left_size++;
				}
			}
			else
			{
				min_heap_right[right_pointer++]=input;
				right_size++;
			}
		}
	}
	return 0;
}

