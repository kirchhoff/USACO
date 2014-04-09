/*
  ID:twd30651
  PROG:transform
  LANG:C++
*/
char a[11][11];
char b[11][11];
char tmp[11][11];
char tmp2[11][11];
int n;
#include<iostream>
#include<fstream>
#include<string.h>
#include<stdlib.h>
using namespace std;
void f1()
{
    for(int i=0;i<n;++i)
        for(int j=0;j<n;++j)
        {
            tmp[i][j]=a[n-1-j][i];
        }
}
void f2()
{
    for(int i=0;i<n;++i)
        for(int j=0;j<n;++j)
        {
            tmp[i][j]=a[n-1-i][n-1-j];
        }
}
void f3()
{
    for(int i=0;i<n;++i)
        for(int j=0;j<n;++j)
        {
            tmp[i][j]=a[j][n-1-i];
        }
}
void f44()
{
    for(int i=0;i<n;++i)
        for(int j=0;j<n;++j)
        {
            tmp[i][j]=a[i][n-1-j];
        }
}
void f51()
{
    for(int i=0;i<n;++i)
    {
        for(int j=0;j<n;++j)
        {
            tmp[i][j]=a[i][n-1-j];
        }
        strcpy(tmp2[i],tmp[i]);
    }
    for(int i=0;i<n;++i)
        for(int j=0;j<n;++j)
        {
            tmp[i][j]=tmp2[n-1-j][i];
        }
}
void f52()
{
    for(int i=0;i<n;++i)
    {
        for(int j=0;j<n;++j)
        {
            tmp[i][j]=a[i][n-1-j];
        }
        strcpy(tmp2[i],tmp[i]);
    }
    for(int i=0;i<n;++i)
        for(int j=0;j<n;++j)
        {
            tmp[i][j]=tmp2[n-1-i][n-1-j];
        }
}
void f53()
{
    for(int i=0;i<n;++i)
    {
        for(int j=0;j<n;++j)
        {
            tmp[i][j]=a[i][n-1-j];
        }
        strcpy(tmp2[i],tmp[i]);
    }
    for(int i=0;i<n;++i)
        for(int j=0;j<n;++j)
        {
            tmp[i][j]=tmp2[j][n-1-i];
        }
}
void print()
{
    cout<<"a is "<<endl;
    for(int i=0;i<n;++i)
    {
        cout<<a[i]<<endl;
    }
    cout<<endl;
    cout<<"tmp is "<<endl;
    for(int i=0;i<n;++i)
    {
        cout<<tmp[i]<<endl;
    }
}
int cmp()
{
    for(int i=0;i<n;++i)
    {
        if(strcmp(b[i],tmp[i]))
            return 0;
    }
    return 1;
}
int main(int argc,char *argv[])
{
    freopen("transform.in","r",stdin);
    freopen("transform.out","w",stdout);
    cin>>n;
    int i=0;
    while(i<n)
    {
        cin>>a[i];
        i++;
    }
    i=0;
    while(i<n)
    {
        cin>>b[i];
        i++;
    }
    f1();
    if(cmp())
    {
        cout<<"1"<<endl;
        return 0;
    }
    f2();
    if(cmp())
    {
        cout<<"2"<<endl;
        return 0;
    }
    f3();
    if(cmp())
    {
        cout<<"3"<<endl;
        return 0;
    }
    f44();
    if(cmp())
    {
        cout<<"4"<<endl;
        return 0;
    }
    f51();
    if(cmp())
    {
        cout<<"5"<<endl;
        return 0;
    }
    f52();
    if(cmp())
    {
        cout<<"5"<<endl;
        return 0;
    }
    f53();
    if(cmp())
    {
        cout<<"5"<<endl;
        return 0;
    }
    for(int i=0;i<n;++i)
    {
        if(strcmp(a[i],b[i]))
        {
            cout<<"7"<<endl;
            return 0;
        }
    }
    cout<<"6"<<endl;



    return 0;
}

/*
  Executing...
   Test 1: TEST OK [0.000 secs, 3380 KB]
   Test 2: TEST OK [0.000 secs, 3380 KB]
   Test 3: TEST OK [0.000 secs, 3380 KB]
   Test 4: TEST OK [0.000 secs, 3380 KB]
   Test 5: TEST OK [0.000 secs, 3380 KB]
   Test 6: TEST OK [0.000 secs, 3380 KB]
   Test 7: TEST OK [0.000 secs, 3380 KB]
   Test 8: TEST OK [0.000 secs, 3380 KB]

All tests OK.

 */
