#include<iostream>
#include<string.h>
#include<stdlib.h>
using namespace std;
typedef struct xdeci{
    int pi;
    int ai;
}ddeci;
ddeci fa[6000];

int main(int argc, char *argv[])
{
    freopen("milk.in","r",stdin);
//    freopen("milk.out","w",stdout);
    int N;
    int M;
    cin>>N;
    cin>>M;
    int i;
    for(i=0;i<M;++i)
    {
        cin>>fa[i].pi;
        cin>>fa[i].ai;
    }
    for(i=0;i<M;++i)
    {
        cout<<fa[i].pi<<endl;
    }
    qs(fa , 0 , M-1);
    // hoare_quick_sort(a,0,4);
    for(i=0;i<M;++i)
    {
        cout<<fa[i].pi<<endl;
    }

       return 0;
}
