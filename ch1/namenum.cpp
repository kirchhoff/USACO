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
     in>>num;  
     int len=num.size();  
     fstream dict_in("dict.txt");  
     vector<string> dict;  
     string tmp;  
     while(dict_in>>tmp){  
          if(tmp.size()==len)  
               dict.push_back(tmp);  
     }   
     return 0;
}
