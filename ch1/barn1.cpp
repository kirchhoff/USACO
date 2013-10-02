/*
  ID:twd30651
  PROG:barn1
  LANG:C++
*/
#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;
int main(int argc, char *argv[])
{
     freopen("barn1.in","r",stdin);
     freopen("barn1.out","w",stdout);
     int M,S,C;
     cin>>M>>S>>C;
     vector<int>cows;
     vector<int>length;
     for(int i=0;i<C;++i)
     {
          int tmp;
          cin>>tmp;
          cows.push_back(tmp);
     }
     int sum=cows[cows.size()-1]-cows[0]+1;
     for(int i=1;i<cows.size();++i)
     {
          length.push_back(cows[i]-cows[i-1]);
     }
     sort(length.begin(),length.end(),greater<int>());
     for(int i=0,j=0;i<length.size()&&j<M-1;++i,++j)
     {
               sum=sum-length[i]+1;
               //  cout<<"sum is "<<sum<<endl;
     }
     cout<<sum<<endl;
     return 0;
}
