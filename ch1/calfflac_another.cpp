/*
  ID:twd30651
  PROG:calfflac
  LANG:C++
*/
#include <iostream>
#include <fstream>
#include <string.h>
using namespace std;
#define maxn 22000
int main(int argc, char *argv[])
{
     freopen("calfflac.in","r",stdin);
     freopen("calfflac.out","w",stdout);
     char str[maxn], str1[maxn], str2[maxn<<1]; 
     int num[maxn];  
     int i, j;  
     i=j=0;  
     char c;  
     while (~scanf("%c",&c)){  
          str[i]=c;  
          if(isalpha(str[i])){
               str1[j]=tolower(str[i]);  
               num[j]=i;  
               j++;  
          }  
          i++;  
     }  
     str[i]='\0';  
     str1[j]='\0';  //短串
     //cout<<str<<endl;
     str2[0]='$';
     str2[1]='`';
     int w=2;
     for(int k=0;k<j;++k)
     {
          str2[w++]=str1[k];
          str2[w++]='`';
     }
     str2[w]='\0';
//     cout<<str2<<endl;
     int mx=0;
     int id=0;
     int *p=new int[w];
     memset(p,0,sizeof(int)*w);
     int max=0;
     int index;
     int st, ed; 
     for(int k=0;k<w;++k)
     {
          if(mx>k)p[k]=min(mx-k,p[2*id-k]);
          else
               p[k]=1;
          while(str2[k-p[k]]==str2[k+p[k]])++p[k];
          if(p[k]+k>mx)
          {
               mx=p[k]+k;
               id=k;
          }
          if(p[k]-1>max){  
               max=p[k]-1;  
               st=(k-max)/2;//str1中回文的起始  
               ed=(k+max)/2-1; //str1中回文的最后  
          }  
     }
         cout<<max<<endl;
     int s=num[st], e=num[ed];//  
     for(i=s; i<=e; i++) printf("%c",str[i]);  
     cout<<endl;
     
     //manacher  
     return 0;
}

/*
Compiling...
Compile: OK

Executing...
   Test 1: TEST OK [0.011 secs, 3552 KB]
   Test 2: TEST OK [0.011 secs, 3552 KB]
   Test 3: TEST OK [0.011 secs, 3564 KB]
   Test 4: TEST OK [0.011 secs, 3552 KB]
   Test 5: TEST OK [0.011 secs, 3564 KB]
   Test 6: TEST OK [0.011 secs, 3592 KB]
   Test 7: TEST OK [0.011 secs, 3576 KB]
   Test 8: TEST OK [0.022 secs, 3572 KB]

All tests OK.

 */
