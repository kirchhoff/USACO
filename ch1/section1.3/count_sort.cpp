#include<iostream>
using namespace std;
int main(int argc, char *argv[])
{
    int a[]={2,5,3,0,2,3,0,3};
    int b[8];
    int c[6];
    for(int i=0;i<6;++i)
        c[i]=0;
    for(int i=0;i<8;++i)
        c[a[i]]++;
    for(int i=1;i<6;++i)
        c[i]=c[i-1]+c[i];
    for(int i=0;i<=7;++i)
    {
        b[--c[a[i]]]=a[i];
    }
    cout<<endl;
    for(int i=0;i<8;++i)
        cout<<" "<<b[i];
    cout<<endl;
    return 0;
}
