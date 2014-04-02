/*
  ID:twd30651
  PROG:beads
  LANG:C++
*/
#include<iostream>
#include<fstream>
#include<string>
using namespace std;
int getmax(int a,int b)
{
     return a>b?a:b;
}
int main(int argc,char *argv[])
{
     freopen("beads.in","r",stdin);
     freopen("beads.out","w",stdout);
     int N;
     cin>>N;
     string s;
     cin>>s;
     s=s+s;
     int left[800][2];
     int right[800][2];
     left[0][0]=left[0][1]=0;
     for(int i=1;i<=N*2;++i)
     {
          if(s[i-1]=='r')
          {
               left[i][0]=left[i-1][0]+1;
               left[i][1]=0;
          }
          else if(s[i-1]=='b')
          {
               left[i][1]=left[i-1][1]+1;
               left[i][0]=0;
          }
          else
          {
               left[i][0]=left[i-1][0]+1;
               left[i][1]=left[i-1][1]+1;
          }
     }
     right[2*N][0]=right[2*N][1]=0;
     for(int i=N*2-1;i>=0;--i)
     {
          if(s[i]=='r')
          {
               right[i][0]=right[i+1][0]+1;
               right[i][1]=0;
          }
          else if(s[i]=='b')
          {
               right[i][1]=right[i+1][1]+1;
               right[i][0]=0;
          }
          else
          {
               right[i][0]=right[i+1][0]+1;
               right[i][1]=right[i+1][1]+1;
          }
     }
     int max=0;
     for(int i=0;i<N*2;++i)
     {
          if(getmax(left[i][0],left[i][1])+getmax(right[i][0],right[i][1])>max)
               max=getmax(left[i][0],left[i][1])+getmax(right[i][0],right[i][1]);
     }
     if(max > N)max=N;//很重要
     cout<<max<<endl;

     return 0;
}
/*
  Executing...
   Test 1: TEST OK [0.000 secs, 3512 KB]
   Test 2: TEST OK [0.000 secs, 3512 KB]
   Test 3: TEST OK [0.000 secs, 3512 KB]
   Test 4: TEST OK [0.000 secs, 3512 KB]
   Test 5: TEST OK [0.000 secs, 3512 KB]
   Test 6: TEST OK [0.000 secs, 3512 KB]
   Test 7: TEST OK [0.000 secs, 3512 KB]
   Test 8: TEST OK [0.000 secs, 3512 KB]
   Test 9: TEST OK [0.000 secs, 3512 KB]
All tests OK.
*/
