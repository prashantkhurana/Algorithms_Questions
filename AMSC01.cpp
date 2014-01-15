// AC, ALGO : Adhoc, Implementation.
#include<iostream>
#include <cstdio>
#include <string>
#include<string.h>
#include<stdlib.h>
#include<map>
using namespace std ;

int main( )
{
  	string key , text ;
	int i , j , k , l , key_length , text_length , var ;
	map<char,int> m;
	char key1[100];
	while(~scanf("%s",key1))
	{
		//cin>>key;
		key=key1; 
		cin>>text;
		map<char,int> m;
		if(key.length()==0)
		break;
		key_length = key.length();
		text_length = text.length();
		
		string plain[text_length/key_length+1][key_length] ;
		for(i=0;i<text_length/key_length+1;i++)
		{
			for(j=0;j<key_length;j++)
			plain[i][j]="\0";
		}
		for( i = 0 ; i < key_length ; i++ )
			{
				m.insert(std::pair<char,int>(key.at(i),i));	
			}
		l=0;
		int b=0;
		for( i=0;l<text_length ; i++ )
		{
			for(j=0;l<text_length&&j<key_length;j++)
			{
				if(j==0)
				b=i;
				if(b%2==0){
					if(l+2<=text_length)
				plain[i][j]=string(text.begin()+l,text.begin()+l+2);
				else
				plain[i][j]=string(text.begin()+l,text.begin()+l+1);
				//cout<<plain[i][j]<<"  ";
				l=l+2;
				b++;
			}
				else{
				plain[i][j]=string(text.begin()+l,text.begin()+l+1);
				//cout<<plain[i][j]<<"  ";
				l++;
				b++;
			}
		//	
				
			}
			//cout<<endl;
		}

		for( k = 1 ; k <= key_length ; k++ )
		{
			int q=m.find(k+'0')->second;
			for(int j=0;j<=i&&plain[j][q]!="\0";j++)
			cout<<plain[j][q];
		}
		printf("\n") ;
	}
	
	return 0 ;
}
