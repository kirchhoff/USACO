/*
  ID:twd30651
  PROG:milk2
  LANG:C++
*/
#include<iostream>
#include<fstream>
#include<vector>
#include<utility>
using namespace std;
int main(int argc,char *argv[])
{

     freopen("milk2.in","r",stdin);
     freopen("milk2.out","w",stdout);

     int beg=1000000,end=0;
     int n;
     int b,e;
     pair<int,int>time_segment;
     vector<pair<int,int> > times;
     cin>>n;
     while(cin>>b>>e)
     {
          time_segment=make_pair(b, e);
          times.push_back(time_segment);
          if(b<beg)
               beg=b;
          if(e>end)
               end=e;
     }
     int get_milk=0;
     int nont_milk=0;
     int max_get=0;
     int max_none=0;
     vector<pair<int,int> >::iterator iter;
     for(int i=beg;i<=end;++i){
          for(iter=times.begin();iter!=times.end();++iter)
          {
               if(iter->first <= i && i < iter->second)
               {
                    ++get_milk;
                    if(nont_milk > max_none)
                         max_none=nont_milk;
                    nont_milk=0;
               break;
               }
          }
          if (iter == times.end()) {
            ++nont_milk;
            if (get_milk > max_get)
                max_get = get_milk;
            get_milk = 0;
        }
     }
     cout<<max_get<<" "<<max_none<<endl;
     return 0;
}

/*
  Executing...
   Test 1: TEST OK [0.011 secs, 3512 KB]
   Test 2: TEST OK [0.000 secs, 3512 KB]
   Test 3: TEST OK [0.000 secs, 3512 KB]
   Test 4: TEST OK [0.000 secs, 3512 KB]
   Test 5: TEST OK [0.065 secs, 3512 KB]
   Test 6: TEST OK [0.000 secs, 3512 KB]
   Test 7: TEST OK [0.097 secs, 3512 KB]
   Test 8: TEST OK [0.140 secs, 3512 KB]

All tests OK.
 */
