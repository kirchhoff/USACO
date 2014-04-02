/*
  ID:twd30651
  PROG:gift1
  LANG:C++
*/
#include<iostream>
#include<fstream>
#include<string>
#include<map>
#include<vector>
using namespace std;
int main(int argc,char *argv[])
{
     freopen("gift1.in","r",stdin);
     freopen("gift1.out","w",stdout);
     int np;
     map<string,int>persons;
     string name;
     int init_money;
     int ps;
     cin >> np;
     vector<string>names;
     for(int i=0;i<np;++i)
     {
          cin>>name;
          persons[name]=0;
          names.push_back(name);
     }
     for(int i=0;i<np;++i)
     {
          cin>>name;
          cin>>init_money>>ps;
          persons[name]-=init_money;
          if(ps!=0)
          {
               persons[name]+=(init_money-init_money/ps*ps);
          }
          for(int j=0;j<ps;++j)
          {
               cin>>name;
               persons[name]+=init_money/ps;
          }
     }
     for(int i=0;i<names.size();++i)
     {
          cout<<names[i]<<" "<<persons[names[i]]<<endl;
     }
     return 0;
}

/*
Executing...
   Test 1: TEST OK [0.011 secs, 3516 KB]
   Test 2: TEST OK [0.011 secs, 3516 KB]
   Test 3: TEST OK [0.000 secs, 3516 KB]
   Test 4: TEST OK [0.011 secs, 3516 KB]
   Test 5: TEST OK [0.000 secs, 3516 KB]
   Test 6: TEST OK [0.011 secs, 3516 KB]
   Test 7: TEST OK [0.000 secs, 3516 KB]
   Test 8: TEST OK [0.000 secs, 3516 KB]
   Test 9: TEST OK [0.000 secs, 3516 KB]

All tests OK.
 */
