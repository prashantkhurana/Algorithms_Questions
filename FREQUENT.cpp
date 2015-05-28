#include<iostream>
#include<algorithm>
#include<string>
#include<list>
#include<map>
#include<stdio.h>
using namespace std;


struct node
{
	int left,right,max_freq,left_element_freq;
	int right_element_freq;
	
};

int n,q;
typedef struct node node;

const int MAX = 1<<17;

node SegTree[MAX<<1];
int a[MAX];

void buildTree(int i, int start, int end )
{
	if(start==end)
	{
		node x;
		x.left=start;
		x.right=end;
		x.max_freq=1;
	//	x.max_freq_element=a[start];	
	//	x.left_element=a[start];
		x.left_element_freq=1;
	//	x.right_element=a[start];
		x.right_element_freq=1;
		SegTree[i]=x;
		return;
	}
	int mid=(start+end)/2;
	buildTree(2*i, start, mid);
	buildTree(2*i+1, mid+1,end);
	
	node y;
	y.left=start;
	y.right=end;
//	y.left_element=SegTree[2*i].left_element;
//	y.right_element=SegTree[2*i+1].right_element;
	
	if(a[start]==a[mid+1])
	{
		y.left_element_freq=SegTree[2*i].left_element_freq+SegTree[2*i+1].left_element_freq;
	}
	else
	{
		y.left_element_freq=SegTree[2*i].left_element_freq;
	}
	
	if(a[mid]==a[end])
	{
		y.right_element_freq=SegTree[2*i].right_element_freq+SegTree[2*i+1].right_element_freq;
	}
	else
	{
		y.right_element_freq=SegTree[2*i+1].right_element_freq;
	}
	if(SegTree[2*i].max_freq>SegTree[2*i+1].max_freq)
	{
		y.max_freq=SegTree[2*i].max_freq;
		//y.max_freq_element=SegTree[2*i].max_freq_element;
	}
	else
	{
		y.max_freq=SegTree[2*i+1].max_freq;
		//y.max_freq_element=SegTree[2*i+1].max_freq_element;
	}
	int midc;
	if(a[mid]==a[mid+1])
	{
		midc=SegTree[2*i].right_element_freq+SegTree[2*i+1].left_element_freq;
		if(midc>y.max_freq)
		{
			y.max_freq=midc;
			//y.max_freq_element=SegTree[2*i+1].left_element;
		}
	}
	SegTree[i]=y;
}

node query1(int i, int start, int end, int qu1, int qu2)
{
	if(qu1<=start && qu2>=end)
	{
		return SegTree[i];
	}
	else
	{
		int mid=(start+end)/2;
		int lefts=0;
		int rights=0;
		node lef, righ;
		node y;
		if(qu1<=mid)
		{
			lef=query1(2*i,start,mid,qu1,qu2);
			lefts=1;
		}
		
		if(qu2>mid)
		{
			righ=query1(2*i+1,mid+1,end,qu1,qu2);
			rights=1;
		}
		
		if(lefts&&rights)
		{
			
			
			
			if(lef.max_freq>righ.max_freq)
			{
				y.max_freq=lef.max_freq;
				//y.max_freq_element=lef.max_freq_element;
			}
			else
			{
				y.max_freq=righ.max_freq;
				//y.max_freq_element=righ.max_freq_element;
			}
			int midc;
			if(a[mid]==a[mid+1])
			{
				midc=min(SegTree[2*i].right_element_freq,mid-qu1+1)+min(SegTree[2*i+1].left_element_freq,qu2-mid);
				if(midc>y.max_freq)
				{
					y.max_freq=midc;
					//y.max_freq_element=righ.left_element;
				}
			}
			
			
		}
		else if(lefts==1)
		y=lef;
		else
		y=righ;
		return y;
	}
}
int query(int i, int start, int end, int qu1, int qu2)
{
	node l=query1(1,1,n,qu1,qu2);
	return l.max_freq;
}

int main()
{
	
	while(1)
	{
		scanf("%d",&n);
		if(n==0)
		{
			return 0;
		}
		else
		{
			cin>>q;
			for(int i=1;i<=n;i++)
			{
				scanf("%d",&a[i]);
			}
			buildTree(1,1,n);
			int q1,q2;
			for(int i=0;i<q;i++)
			{
				scanf("%d %d",&q1,&q2);
				printf("%d\n",query(1,1,n,q1,q2));
			}
		}
	}
	return 0;
}
