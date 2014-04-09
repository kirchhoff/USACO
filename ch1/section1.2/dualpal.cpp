/*
  ID:twd30651
  PROG:dualpal
  LANG:C++
*/
#include<iostream>
#include<fstream>
using namespace std;
char a[100];
char T(int n)
{
    if(n>=10)
    {
        return n-10+'A';
    }
    else
    {
        return n+'0';
    }
}
bool is_ok(int num,int B)
{
    int i=0;
    while(num/B)
    {
        a[i]=T(num%B);
        num=num/B;
        i++;
    }
    a[i]=T(num%B);
    for(int j=0;j<=i/2;++j)
    {
        if(a[j]!=a[i-j])
            return false;
    }
    return true;
}
int main(int argc,char *argv[])
{
    freopen("dualpal.in","r",stdin);
      freopen("dualpal.out","w",stdout);
    int N;
    int M;
    cin>>N;
    cin>>M;
    int i=0;
    int j=M+1;
    while(i<N)
    {
        int count=0;
        for(int t=2;t<=10;t++)
        {
            if(is_ok(j,t))
            {
                count++;
                if(count==2){
                    cout<<j<<endl;
                    i++;
                    break;
                }
            }
        }
        j++;
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
   Test 4: TEST OK [0.000 secs, 3376 KB]
   Test 5: TEST OK [0.011 secs, 3376 KB]
   Test 6: TEST OK [0.011 secs, 3376 KB]
   Test 7: TEST OK [0.011 secs, 3376 KB]

All tests OK.
 */
