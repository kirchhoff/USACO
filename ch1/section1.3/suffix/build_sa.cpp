#include<iostream>
using namespace std;
int sa[8];
int x[8];
int y[8];
int c[128];
int n;
int i;
int main(int argc, char *argv[])
{
char s[]="aabaaaab";
    for(i=0;i<128;++i)c[i]=0;
    for(i=0;i<strlen(s);++i) c[x[i] = s[i]]++;
    for(i=1;i<128;++i)c[i]=c[i-1]+c[i];
    for(i=strlen(s)-1;i>=0;i--)sa[--c[x[i]]]=i;
// 0 1 3 4 5 6 2 7

    int p=0;
    for(i=n-1;i<n;++i)y[p++]=i;
    return 0;
}
