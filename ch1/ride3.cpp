/*
  ID:twd30651
  PROG:ride
  LANG:C++
*/
#include <iostream>
#include <fstream>
#include <string>
using namespace std;
int func(string s)
{
     int tmp=1;
     for(int i=0; i < s.size(); ++i)
     {
          tmp*=s[i]-'A'+1;
     }
     return tmp;
}
int main(int argc,char *argv[])
{
     freopen("ride.in","r",stdin);
     freopen("ride.out","w",stdout);
     string s;
     string t;
     while(cin>>s>>t){
          if(func(s) % 47 == func(t) % 47)
          {
               cout<<"GO"<<endl;
          }
          else{
               cout<<"STAY"<<endl;
          }

     }
     return 0;
}
/*
  Executing...
   Test 1: TEST OK [0.011 secs, 3512 KB]
   Test 2: TEST OK [0.000 secs, 3512 KB]
   Test 3: TEST OK [0.000 secs, 3512 KB]
   Test 4: TEST OK [0.000 secs, 3512 KB]
   Test 5: TEST OK [0.000 secs, 3512 KB]
   Test 6: TEST OK [0.000 secs, 3512 KB]
   Test 7: TEST OK [0.000 secs, 3512 KB]
   Test 8: TEST OK [0.011 secs, 3512 KB]
   Test 9: TEST OK [0.000 secs, 3512 KB]
   Test 10: TEST OK [0.000 secs, 3512 KB]

All tests OK.
 */
