/*
  ID:twd30651
  PROG:palsquare
  LANG:C++
*/
#include<iostream>
#include<fstream>
#include<string.h>
#include<stdlib.h>
using namespace std;
char a[100];
int i=0;
bool is_ok(int num,int B)
{
    i=0;
    memset(a,0,100);
    while(num/B)
    {
        a[i++]=num%B+'0';
        if(num%B>=10)
            a[i-1]='A'+num%B-10;
        num=num/B;
    }
    a[i++]=num%B+'0';
    if(num%B>=10)
        a[i-1]='A'+num%B-10;
    a[i]='\0';
    for(int j=0;j<=i/2;++j)
    {
        if(a[j]!=a[i-j-1])
            return 0;
    }
    return 1;
}
int main(int argc,char *argv[])
{
    freopen("palsquare.in","r",stdin);
    freopen("palsquare.out","w",stdout);
    int B;
    cin>>B;
    char b[100];
    int wi=0;
    for(int w=1;w<=300;++w)
    {
        if(is_ok(w*w,B))
        {
            int t=w;
            memset(b,0,100);
            wi=0;
            while(t/B)
            {
                b[wi++]=t%B+'0';
                if(t%B>=10)
                    b[wi-1]='A'+t%B-10;
                t=t/B;
            }
            b[wi++]=t%B+'0';
            if(t%B>=10)
                b[wi-1]='A'+t%B-10;
            for(int rr=wi-1;rr>=0;--rr)
            {
                cout<<b[rr];
            }
            cout<<" "<<a<<endl;
        }
    }

    return 0;
}

/*
  Compiling...
Compile: OK

Executing...
   Test 1: TEST OK [0.000 secs, 3376 KB]
   Test 2: TEST OK [0.011 secs, 3376 KB]
   Test 3: TEST OK [0.011 secs, 3376 KB]
   Test 4: TEST OK [0.011 secs, 3376 KB]
   Test 5: TEST OK [0.011 secs, 3376 KB]
   Test 6: TEST OK [0.011 secs, 3376 KB]
   Test 7: TEST OK [0.011 secs, 3376 KB]
   Test 8: TEST OK [0.011 secs, 3376 KB]

All tests OK.
 */
