/*
  ID:twd30651
  PROG:milk
  LANG:C++
*/
#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;
class farmer
{
public:
     int Pi;
     int Ai;
     bool operator<(const farmer&rhs)const   //升序排序时必须写的函数
          {   
               return Pi<rhs.Pi; 
          }
     bool operator>(const farmer&rhs)const   //升序排序时必须写的函数
          {   
               return Pi>rhs.Pi; 
          }
};
int main(int argc, char *argv[])
{
     freopen("milk.in","r",stdin);
     freopen("milk.out","w",stdout);
     int N;
     int M;
     cin>>N>>M;
     int k=0;
     vector<farmer>milk;
     for(;k<M;++k)
     {
          farmer x;
          cin>>x.Pi;
          cin>>x.Ai;
          milk.push_back(x); 
     }
     sort(milk.begin(), milk.end(), less<farmer>());
     /* for(int i=0;i<milk.size();++i)
        {
        cout<<milk[i].Pi<<endl;
        }*/
     int money=0;
     int num=0;
     for(int i=0;i<milk.size();++i)
     {
          if(milk[i].Ai+num<N)
          {
               money+=milk[i].Ai*milk[i].Pi;
               num+=milk[i].Ai;
               continue;
          }
          else
          {
               money+=milk[i].Pi*(N-num);
               break;
          }
     }
     cout<<money<<endl;
     return 0;

}

/*
  Compiling...
Compile: OK

Executing...
   Test 1: TEST OK [0.011 secs, 3508 KB]
   Test 2: TEST OK [0.011 secs, 3376 KB]
   Test 3: TEST OK [0.011 secs, 3508 KB]
   Test 4: TEST OK [0.011 secs, 3508 KB]
   Test 5: TEST OK [0.011 secs, 3508 KB]
   Test 6: TEST OK [0.043 secs, 3508 KB]
   Test 7: TEST OK [0.011 secs, 3508 KB]
   Test 8: TEST OK [0.032 secs, 3508 KB]

All tests OK.

 */
