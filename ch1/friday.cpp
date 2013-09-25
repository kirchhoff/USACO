/*
  ID:twd30651
  PROG:friday
  LANG:C++
*/
#include <iostream>
#include <fstream>
using namespace std;
bool isleapyear(int year)
{
     if(year%400==0||(year%100!=0&&year%4==0))return true;
     return false;
}
int years[12]={31,28,31,30,31,30,31,31,30,31,30,31};
int main(int argc, char *argv[])
{
     freopen("friday.in", "r", stdin);
     freopen("friday.out","w",stdout);
     int N;
     cin>>N;
     int week[7]={0};
     int n=13;
     week[n%7]++;
     for(int i=0;i<N;++i)
     {
          for(int j=0;j<12;++j)
          {
               int k=1900+i;
               if(isleapyear(k)&&j==1){
                    n+=29;
                    goto M;
               }
               n+=years[j];
          M:  week[n%7]++;
          }
     }
     week[n%7]--;
     cout<<week[6]<<' '<<week[0];
     for(int i=1;i<6;++i)
     {
          cout<<" "<<week[i];
     }
     cout<<endl;
     return 0;
}

/*
  Compiling...
Compile: OK

Executing...
   Test 1: TEST OK [0.000 secs, 3376 KB]
   Test 2: TEST OK [0.000 secs, 3376 KB]
   Test 3: TEST OK [0.000 secs, 3376 KB]
   Test 4: TEST OK [0.000 secs, 3376 KB]
   Test 5: TEST OK [0.000 secs, 3376 KB]
   Test 6: TEST OK [0.000 secs, 3376 KB]
   Test 7: TEST OK [0.000 secs, 3376 KB]
   Test 8: TEST OK [0.000 secs, 3376 KB]
 */
