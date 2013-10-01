/*
  ID:twd30651
  PROG:dualpal
  LANG:C++
*/
#include <iostream>
#include <fstream>
#include <string>
using namespace std;
int a[10]={'0','1','2','3','4','5','6','7','8','9'};
bool check(int num,int B)
{
     string s;
     while(num!=0)
     {
          s+=a[num%B];
          num=num/B;
     }
     for(int i=0;i<s.size();++i)
     {
          if(s[i]!=s[s.size()-i-1])return false;
     }
     return true;
}
int main(int argc, char *argv[])
{
     int N;
     int S;
     freopen("dualpal.in", "r", stdin);
     freopen("dualpal.out", "w", stdout);
     cin>>N>>S;
     int num=0;
     for(int j=S+1;;++j)
     {
          int tmp=0;
          for(int k=2;k<=10;++k)
          {
               if(tmp!=2&&check(j,k))
               {
                    tmp++;
               }
               if(tmp==2)
               {
                    cout<<j<<endl;
                    num++;
                    break;
               }
          }
          if(num==N)break;
     }
     return 0;
}
/*
  Compiling...
Compile: OK

Executing...
   Test 1: TEST OK [0.011 secs, 3508 KB]
   Test 2: TEST OK [0.000 secs, 3508 KB]
   Test 3: TEST OK [0.022 secs, 3508 KB]
   Test 4: TEST OK [0.011 secs, 3508 KB]
   Test 5: TEST OK [0.011 secs, 3508 KB]
   Test 6: TEST OK [0.032 secs, 3508 KB]
   Test 7: TEST OK [0.011 secs, 3508 KB]

   All tests OK.
 */
