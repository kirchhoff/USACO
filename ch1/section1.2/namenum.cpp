/*
  ID:twd30651
  PROG:namenum
  LANG:C++
*/
#include<iostream>
#include<fstream>
#include<stdlib.h>
#include<string.h>
char a[100];
using namespace std;
int main(int argc,char *argv[])
{
    freopen("namenum.in","r",stdin);
    memset(a,0,sizeof(a));
    a['A']='2';
    a['B']='2';
    a['C']='2';
    a['D']='3';
    a['E']='3';
    a['F']='3';
    a['G']='4';
    a['H']='4';
    a['I']='4';
    a['J']='5';
    a['K']='5';
    a['L']='5';
    a['M']='6';
    a['N']='6';
    a['O']='6';
    a['P']='7';
    a['R']='7';
    a['S']='7';
    a['T']='8';
    a['U']='8';
    a['V']='8';
    a['W']='9';
    a['X']='9';
    a['Y']='9';
    freopen("namenum.out","w",stdout);
    FILE * p =fopen("dict.txt","r");
    char N[20];
    cin>>N;
    char tmp[20];
    int i=0;
int ok=0;
    while(fscanf(p,"%s",tmp)==1)
    {
        if(strlen(tmp)!=strlen(N))continue;
        for(i=0;i<strlen(N);++i)
        {
            if(a[tmp[i]]!=N[i])
                break;
        }
        if(i==strlen(N))
        {
ok=1;cout<<tmp<<endl;
}
}
if(ok!=1)
    cout<<"NONE"<<endl;
    return 0;
}
/*
Compiling...
Compile: OK

Executing...
   Test 1: TEST OK [0.000 secs, 3512 KB]
   Test 2: TEST OK [0.011 secs, 3512 KB]
   Test 3: TEST OK [0.011 secs, 3512 KB]
   Test 4: TEST OK [0.000 secs, 3512 KB]
   Test 5: TEST OK [0.011 secs, 3512 KB]
   Test 6: TEST OK [0.011 secs, 3512 KB]
   Test 7: TEST OK [0.011 secs, 3512 KB]
   Test 8: TEST OK [0.011 secs, 3512 KB]
   Test 9: TEST OK [0.011 secs, 3512 KB]
   Test 10: TEST OK [0.011 secs, 3512 KB]
   Test 11: TEST OK [0.011 secs, 3512 KB]
   Test 12: TEST OK [0.011 secs, 3512 KB]
   Test 13: TEST OK [0.011 secs, 3512 KB]
   Test 14: TEST OK [0.011 secs, 3512 KB]
   Test 15: TEST OK [0.000 secs, 3512 KB]

All tests OK.
 */
