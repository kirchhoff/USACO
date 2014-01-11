/*
  ID:twd30651
  PROG:namenum
  LANG:C++
*/
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
using namespace std;
int main(int argc, char *argv[])
{
     freopen("namenum.in", "r",stdin);
     freopen("namenum.out","w",stdout);
     int map[] = {2,2,2,3,3,3,4,4,4,5,5,5,6,6,6,7,-1,7,7,8,8,8,9,9,9,-1};  
     string num;  
     cin>>num;  
     int len=num.size();  
     fstream dict_in("dict.txt");  
     vector<string> dict;  
     string tmp;  
     while(dict_in>>tmp){  
          if(tmp.size()==len)  
               dict.push_back(tmp);  
     }   
     bool flag=false;
     for(int i=0;i<dict.size();++i)
     {
          int j=0;
          for(;j<len;++j)
          {
               if(map[dict[i][j]-'A']==num[j]-'0')continue;
               else
                    break;
          }
          if(j==len)
          {cout<<dict[i]<<endl;
               flag=true;
          }
     }
     if(flag==false)cout<<"NONE"<<endl;
     return 0;
}
/*
  Compiling...
Compile: OK

Executing...
   Test 1: TEST OK [0.011 secs, 3508 KB]
   Test 2: TEST OK [0.011 secs, 3508 KB]
   Test 3: TEST OK [0.011 secs, 3508 KB]
   Test 4: TEST OK [0.011 secs, 3508 KB]
   Test 5: TEST OK [0.011 secs, 3508 KB]
   Test 6: TEST OK [0.011 secs, 3508 KB]
   Test 7: TEST OK [0.011 secs, 3508 KB]
   Test 8: TEST OK [0.011 secs, 3508 KB]
   Test 9: TEST OK [0.011 secs, 3508 KB]
   Test 10: TEST OK [0.011 secs, 3508 KB]
   Test 11: TEST OK [0.011 secs, 3508 KB]
   Test 12: TEST OK [0.011 secs, 3508 KB]
   Test 13: TEST OK [0.011 secs, 3508 KB]
   Test 14: TEST OK [0.011 secs, 3508 KB]
   Test 15: TEST OK [0.011 secs, 3508 KB]

All tests OK.
 */
