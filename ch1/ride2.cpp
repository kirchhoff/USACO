/*
ID:twd30651
PROG:ride
LANG:C++
*/
#include<iostream>
#include<string>
#include<fstream>
using namespace std;
int check(string a,string b)
{
     int num1=1;
     int num2=1;
     for(int i=0;i<a.size();++i)
     {
          num1*=(a[i]-'A'+1);
     }
     for(int i=0;i<b.size();++i)
     {
          num2*=(b[i]-'A'+1);
     }
     if(num1%47==num2%47)
          return 1;
     else
          return 0;
}
int main()
{
     freopen("ride.in","r",stdin);
     freopen("ride.out","w",stdout);
     string a,b;
     while(cin>>a>>b)
     {
          if(check(a,b))cout<<"GO"<<endl;
          else cout<<"STAY"<<endl;
     }
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
  Test 10: TEST OK [0.000 secs, 3512 KB]

  All tests OK.
*/
