/*
  ID:twd30651
  PROG:milk2
  LANG:C++
*/
#include <iostream>
#include <fstream>
#include <string.h>
#define DEBUG

using namespace std;
int a[1000001];
int main(int argc, char *argv[])
{
     #ifdef DEBUG
      freopen("milk2.in","r",stdin);
     freopen("milk2.out","w",stdout);
     #endif
     
     int N;
     cin>>N;
     // cout<<"N is "<<N<<endl;
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
     int tmp=a[p];
     if(tmp==1)tmp_max=1;
     else
          tmp_min=1;
     // for(int i=p;i<q;++i)
     //    cout<<a[i]<<endl;
     for(int i=p+1;i<q;++i)
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
          {
               tmp_max=0;
               tmp=a[i];
               tmp_min=1;
               if(tmp_min>min)min=tmp_min;
          }
          else if(a[i]!=tmp&&a[i]==1)
          {
               tmp_min=0;
               tmp=a[i];
               tmp_max=1;
               if(tmp_max>max)max=tmp_max;
          }
     }
     //  if(tmp_min>min)min=tmp_min;
     //         if(tmp_max>max)max=tmp_max;
     cout<<max<<" "<<min<<endl;     
     
     return 0;
}
