/*
  ID:twd30651
  PROG:palsquare
  LANG:C++
*/
#include <iostream>
#include <fstream>
#include <string>
using namespace std;
char a[21]={'0','1','2','3','4','5','6','7','8','9','A','B','C','D','E','F','G','H','I','J','K'};
int main(int argc, char *argv[])
{
     freopen("palsquare.in","r",stdin);
     freopen("palsquare.out","w",stdout);
     int B;
     cin>>B;
     for(int i=1;i<300;++i)
     {
          string s;
          string is;
          int m=i*i;
          while(m!=0)
          {
               s=a[m%B]+s;
               m=m/B;
          } 
          // s=a[m%B]+s;
          bool flag=true;
          for (int j=0; j<s.size(); ++j)
          {
               if(s[j]!=s[s.size()-j-1]){
                    flag=false;
                    break;
               }
          }
          if(flag)
          {
               int tmp=i;
               while(tmp!=0)
               {
                    is=a[tmp%B]+is;
                    tmp=tmp/B;
               } 
               cout<<is<<" "<<s<<endl;
          }
     }
    return 0;
}
