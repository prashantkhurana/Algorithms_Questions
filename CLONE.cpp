#include <iostream>
#include <string>
#include <map>
#include <vector>
 
using namespace std;
 
typedef map<string,int> msi;

 
int main()
{
  int n,k;
  
  std::map<string,int> m;
  
  while(1)
  {
    m.clear();
    scanf("%d %d",&n,&k);
   char s[k+4]; 
    if(n==0 && k==0)
      break;
    
    for(int i=0; i<n; i++)
    {
      scanf("%s",s);
     if(m.find(s) == m.end())
     m[s] = 1;
     else
     m[s]++;
    }
    
    vector<int> v(n+1,0);
    
     for(std::map<string,int>::iterator i = m.begin(); i!=m.end(); i++)
      v[i->second]++;
    
    for(int i=1; i<=n; i++)
      printf("%d\n",v[i]);
    
  }
  
  return 0;
}
