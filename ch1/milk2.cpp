/*
  ID:twd30651
  PROG:milk2
  LANG:C++
*/
#include <iostream>
#include <fstream>
#include <string.h>
using namespace std;
int a[1000001];
int main(int argc, char *argv[])
{
     freopen("milk2.in","r",stdin);
     reopen("milk2.out","w",stdout);
     
     int N;
     cin>>N;
     memset(a, 0, sizeof(int)*1000001);
     int c,b;
     int k=0;
     int q=0;
     int p=1000001;
     while(k<N){
          cin>>c>>b;
          int tmp1=c>b?c:b;
          if(tmp1>q)q=tmp1;
          int tmp2=c<b?c:b;
          if(tmp2<p)p=tmp2; 
          for(int i=c;i<b;++i)
               a[i]=1;
          k++;
     }
     int max=0;
     int min=0;
     int tmp_max=0;
     int tmp_min=0; 
     //cout<<p<< ' '<<q<<endl;
     int tmp=a[p];
     for(int i=p+1;i<=q;++i)
     {
          if(a[i]==tmp&&tmp==1)
          {
               tmp_max++;
               if(tmp_max>max)max=tmp_max;
          }
          else if(a[i]==tmp&&tmp==0)
          {
               tmp_min++;
               if(tmp_min>min)min=tmp_min;
          }
          else if(a[i]!=tmp&&a[i]==0)
          
              tmp_max=0;
               tmp=a[i];
          }
          else if(a[i]!=tmp&&a[i]==1)
          {
               tmp_min=0;
               tmp=a[i];
          }
     }
     cout<<max+1<<" "<<min<<endl;     
     
     return 0;
}
