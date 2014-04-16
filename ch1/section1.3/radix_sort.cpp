#include<iostream>
using namespace std;
int get(int a,int b)
{
    for(int i=0;i<b;++i)
    {
        a=a/10;
    }
    return a%10;
}
int k2[3];
int main(int argc, char *argv[])
{
    int a[]={23,16,12};
    int c[10];
    int b[7];
    int M=10;
    int k[3];
    for(int i=0;i<10;++i)c[i]=0;
    for(int i=0;i<3;++i)c[get(a[i],1)]++;
    for(int i=1;i<10;++i)c[i]=c[i-1]+c[i];
    for(int i=2;i>=0;--i){k[--c[get(a[i],1)]]=i;}
    for(int i=0;i<3;++i)
        cout<<" "<<k[i];
    cout<<endl;
    for(int i=0;i<10;++i)c[i]=0;
    for(int i=0;i<3;++i)c[get(a[i],0)]++;
    for(int i=1;i<10;++i)c[i]=c[i-1]+c[i];
    for(int i=2;i>=0;--i){k2[--c[get(a[i],0)]]=i;}
    for(int i=0;i<3;++i)
        cout<<" "<<k2[i];
    cout<<endl;

    for(int i=0;i<10;++i)c[i]=0;
    for(int i=0;i<3;++i)c[get(a[i],1)]++;
    for(int i=1;i<10;++i)c[i]=c[i-1]+c[i];
    for(int i=2;i>=0;--i){k[--c[get(a[k2[i]],1)]]=k2[i];}
    for(int i=0;i<3;++i)
        cout<<" "<<k[i];
    cout<<endl;

    return 0;
}
