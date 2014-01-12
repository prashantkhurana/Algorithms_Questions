import java.util.*;
import java.lang.*;
import java.io.*;
class subArray
{
	public static void main (String[] args) throws java.lang.Exception
	{
		Scanner in = new Scanner(System.in); 
		int n = in.nextInt();
		int a[]=new int[n];
		for(int i=0;i<n;i++)
		a[i]=in.nextInt();  
		int k = in.nextInt();  
		Deque deque=new  ArrayDeque();
		int max=0;
		for(int i=1;i<k;i++)
		if(a[i]>a[max])
		max=i;
		deque.addFirst(max);
		System.out.print(a[(Integer)deque.peekLast()]+" ");
		for(int i=k;i<n;i++)
		{
				while(deque.peekFirst()!=null && a[i]>=a[(Integer)deque.peekFirst()])
				deque.removeFirst();
				deque.addFirst(i);
				while((Integer)deque.peekLast()<=(i-k))
				deque.removeLast();
			
			if(i!=n-1)
			System.out.print(a[(Integer)deque.peekLast()]+" ");
			if(i==(n-1))
			System.out.print(a[(Integer)deque.peekLast()]);
		}
		
	}
}