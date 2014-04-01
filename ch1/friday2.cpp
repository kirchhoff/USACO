/*
  ID:twd30651
  PROG:friday
  LANG:C++
*/
#include<iostream>
#include<fstream>
#include<vector>
using namespace std;
int months[]={31,28,31,30,31,30,31,31,30,31,30,31};
int isleapyear(int year)
{
     if(year % 4 == 0 && year % 100 != 0 ||year % 400 ==0)
          return 1;
     else
          return 0;
}
int main(int argc,char *argv[])
{
     freopen("friday.in","r",stdin);
     freopen("friday.out","w",stdout);
     vector<int>y;
     int N;
     cin>>N;
     for(int i=0;i<7;++i)
          y.push_back(0);
     int w=0;
     int n=13;
     y[n%7]++;
     for(int i=1900;i<1900+N;++i)
     {
          for(int j=0;j<12;++j)
          {
               if(j == 1 && isleapyear(i))
                    months[1]=29;
               n+=months[j];
               y[n%7]++;
          }
          months[1]=28;
     }
     y[n%7]--;
     cout<<y[6]<<" "<<y[0];
     for(int i=1;i<=5;++i)
     {
          cout<<" "<<y[i];
     }
     cout<<endl;
     return 0;
}
/*
  Executing...
   Test 1: TEST OK [0.000 secs, 3512 KB]
   Test 2: TEST OK [0.011 secs, 3512 KB]
   Test 3: TEST OK [0.011 secs, 3512 KB]
   Test 4: TEST OK [0.000 secs, 3512 KB]
   Test 5: TEST OK [0.011 secs, 3512 KB]
   Test 6: TEST OK [0.011 secs, 3512 KB]
   Test 7: TEST OK [0.000 secs, 3512 KB]
   Test 8: TEST OK [0.000 secs, 3512 KB]

All tests OK.
 */
