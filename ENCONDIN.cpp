#include<cstdio>
#include<cstring>
#include<iostream>
#define MAX 1000000
using namespace std;
main() {
    string str;
    while(getline(cin,str)) {
        int len=str.length();
        int i;
        int flag=0;
        int ct=0;
        for(i=0;i<len;) {
            char ch=str[i];
            int j=i+1;
            ct=1;
            while(j<len&& str[j]==ch) {
                ++j;
                ++ct;
                if(ct==9) break;
            }
            i=j;
            if(!flag&&(ct==1)) {
                if(ch=='1')
                    printf("111");
                else
                    printf("1%c",ch);
                flag=1;
            }
            else if(flag && (ct==1))
            {
            	if(ch=='1')
                    printf("11");
                else
                    printf("%c",ch);
            }
            else if(flag&&(ct!=1)){
                printf("1%d%c",ct,ch);
                flag=0;
            }
            else if(!flag&&(ct!=1)){
                printf("%d%c",ct,ch);
            }
        
        }
        if(ct==1)
        printf("1");
        printf("\n");
    }
    return 0;
}
