/*
  ID:twd30651
  PROG:gift1
  LANG:C++
*/
#include <iostream>
#include <fstream>
#include <map>
#include <vector>
using namespace std;
int main(int argc, char *argv[])
{
     freopen("gift1.in","r",stdin);
     freopen("gift1.out","w",stdout);
     int n;
     cin>>n;
     vector<string>givers;
     string name;
     for(int i=0;i<n;++i)
     {
          cin>>name;
          givers.push_back(name);
     }
     map<string,int>people;
     int money,gift,people_num;
     string giver,reciever;
     for(int i=0;i<n;++i)
     {
          cin>>giver>>money>>people_num;
          if(money==0||people_num==0)
               continue;

          gift=money/people_num;
          for(int j=0;j<people_num;++j)
          {
               cin>>reciever;
               people[reciever]+=gift;
          }
          people[giver]-=gift*people_num;
     }
     for(vector<string>::iterator iter=givers.begin();iter!=givers.end();++iter)
     {
          cout<<*iter<<" "<<people[*iter]<<endl;
     }

     
     return 0;
}

/*
  Executing...
   Test 1: TEST OK [0.011 secs, 3512 KB]
   Test 2: TEST OK [0.011 secs, 3512 KB]
   Test 3: TEST OK [0.011 secs, 3512 KB]
   Test 4: TEST OK [0.011 secs, 3512 KB]
   Test 5: TEST OK [0.011 secs, 3512 KB]
   Test 6: TEST OK [0.011 secs, 3512 KB]
   Test 7: TEST OK [0.011 secs, 3512 KB]
   Test 8: TEST OK [0.000 secs, 3512 KB]
   Test 9: TEST OK [0.000 secs, 3512 KB]

All tests OK.
 */
