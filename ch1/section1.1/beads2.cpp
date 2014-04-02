/*
  ID:twd30651
  PROG:beads
  LANG:C++
*/
#include<iostream>
#include<fstream>
#include<string>
using namespace std;
int main(int argc,char *argv[])
{
     freopen("beads.in","r",stdin);
     freopen("beads.out","w",stdout);
     string s;
     int N;
     cin>>N;
     cin>>s;
     s=s+s;
     int a=0;
     int b=0;
     int max=0;
     int w=0;
     char l = 0;
     for(int i=0;i<s.size();++i)
     {
          if(s[i] == 'w')
          {
               a++;
               w++;
          }
          else if(s[i] == l)
          {
               a++;
               w=0;
          }
          else
          {
              if(b+a>max)
                    max=a+b;
               b=a-w;
               a=w+1;
               w=0;
               l=s[i];
          }
     }
     if(b+a>max)
          max=a+b;
     if(max>N)
          max=N;
     cout<<max<<endl;
     return 0;
}
/*
  Executing...
   Test 1: TEST OK [0.000 secs, 3508 KB]
   Test 2: TEST OK [0.000 secs, 3508 KB]
   Test 3: TEST OK [0.000 secs, 3508 KB]
   Test 4: TEST OK [0.000 secs, 3508 KB]
   Test 5: TEST OK [0.000 secs, 3508 KB]
   Test 6: TEST OK [0.000 secs, 3508 KB]
   Test 7: TEST OK [0.011 secs, 3508 KB]
   Test 8: TEST OK [0.000 secs, 3508 KB]
   Test 9: TEST OK [0.000 secs, 3508 KB]

All tests OK.
 */
