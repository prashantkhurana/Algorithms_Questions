#include<iostream>
#include <stdio.h>
#include <string.h>
#include<map>

using namespace std;


map<int,string> m2;
	
	
string getnum(int n)
{
	string s;
	while(n)
	{
		int digit=n%10;
		std::map<int,string>::iterator it=m2.find(digit);
		s=it->second+s;
		n=n/10;
	}
//	string s2;
//	int j=0;
//	for(int i=s.length()-1;i>=0;i--)
//	{
//		s2[j++]=s[i];
//	}
//	s2[j]='\0';
	return s;
}

int main()
{
	int i, j, k, a, n[3];
	m2[0]="063";
	m2[1]="010";
	m2[2]="093";
	m2[3]="079";
	m2[4]="106";
	m2[5]="103";
	m2[6]="119";
	m2[7]="011";
	m2[8]="127";
	m2[9]="107";

	string s;
	string s1("BYE");
	
	map<string,int> m;
	m["010"]=1;
	m["063"]=0;
	m["093"]=2;
	m["079"]=3;
	m["106"]=4;
	m["103"]=5;
	m["119"]=6;
	m["011"]=7;
	m["127"]=8;
	m["107"]=9;
	while(1)
	{
		cin>>s;
		if(s.compare("BYE")==0)
		break;
		std::size_t pos = s.find("+");
		string s2=s.substr(pos+1);
		s1=s.substr(0,pos);
		int num=0,num2=0;
		for(int i=0;i<s1.length();i=i+3)
		{
			string s3=s1.substr(i,3);
			std::map<string,int>::iterator it=m.find(s3);
			num=num*10+it->second;
		}
		for(int i=0;i<s2.length()-1;i=i+3)
		{
			string s3=s2.substr(i,3);
			std::map<string,int>::iterator it=m.find(s3);
			num2=num2*10+it->second;
		}
		int res=num+num2;
		
		string b=getnum(res);
		cout<<s<<b<<endl;
	}
	return 0;
}

