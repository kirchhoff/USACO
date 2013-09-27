/*
  ID:twd30651
  PROG:beads
  LANG:C++
*/
#include <iostream>
#include <fstream>
#include <string>
using namespace std;
int N;
string s;
char S(int i)
{
     return s[i%N ];
}
 
int main(int argc, char *argv[])
{
     freopen("beads.in","r",stdin);
     freopen("beads.out","w",stdout);
     
     cin>>N;
     //char *tmpp="wwwbbrwrbrbrrbrbrwrwwrbwrwrrb";
     //s="wwwbbrwrbrbrrbrbrwrwwrbwrwrrb";
     cin>>s;
     char ch1,ch2;
     //memcpy(chain, tmpp, N);
     //cout<<s<<endl;
     int sum=0;
     for(int i=1;i<N;++i)
     {
          int left=i-1;
          int right=i;
          while(left>=-N&&S(left)=='w')--left;
          ch1=S(left);
          while(left>=-N&&(S(left-1)==ch1||S(left-1)=='w'))--left;
          int a=i-left;
          while(right<2*N&&S(right)=='w')++right;
          ch2=S(right);
          while(right<2*N&&(S(right+1)==ch2||S(right+1)=='w'))++right;
          int b=right-i+1;
          if(a+b>sum)sum=a+b;
     }
     if(sum>=N)sum=N;
     cout<<sum<<endl;

     return 0;   
}
