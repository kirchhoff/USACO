/*
  ID:twd30651
  PROG:milk2
  LANG:C++
*/
#include<iostream>
#include<fstream>
#include<string.h>
using namespace std;
int a[1000001];
int main(int argc,char *argv[])
{
     freopen("milk2.in","r",stdin);
     freopen("milk2.out","w",stdout);
     int N;
     cin>>N;
     int b,e;
     int begin=1000000;
     int end=0;
     memset(a,0,sizeof(a));
     while(cin>>b>>e){
          if(begin>b)begin=b;
          if(end<e)end=e;
          for(int i=b+1;i<=e;++i)
               a[i]=1;
     }
     int max_milk=0;
     int max_none=0;
     int count_milk=0;
     int count_none=0;
     for(int i=begin+1;i<=end+1;++i)
     {
          if(a[i]==1)
          {
               count_milk++;
                 if(max_none<count_none)max_none=count_none;
               count_none=0;
          }
          else
          {
               if(max_milk<count_milk)max_milk=count_milk;
               count_milk=0;
               count_none++;
          }
     }
     cout<<max_milk<<" "<<max_none<<endl;

     return 0;
}
/*
  Executing...
   Test 1: TEST OK [0.011 secs, 7280 KB]
   Test 2: TEST OK [0.011 secs, 7280 KB]
   Test 3: TEST OK [0.011 secs, 7280 KB]
   Test 4: TEST OK [0.022 secs, 7280 KB]
   Test 5: TEST OK [0.032 secs, 7280 KB]
   Test 6: TEST OK [0.011 secs, 7280 KB]
   Test 7: TEST OK [0.022 secs, 7280 KB]
   Test 8: TEST OK [0.043 secs, 7280 KB]

All tests OK.
 */
