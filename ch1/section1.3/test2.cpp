#include<cstdio>
using namespace std;
const int mo=1000000007;
int T,n,a,b,c;
typedef long long ll;
ll ans;
int main()
{
//    freopen("data2.txt", "r", stdin);
    scanf("%d",&T);
    for (int i=0;i<T;++i)
    {
        ans=0;
        scanf("%d",&n);
        for (a=1;a<=n;a++)
            for (b=1;b<=n;b++)
                for (c=1;c<=n;c++)
                {
                    if (a==b||a==c||b==c)
                    {
                        if(a!=b||a!=c||b!=c)continue;
                    }
                    ans=(ans+ ((n-a+1)%mo) * ((n-b+1)%mo) * ((n-c+1)%mo) % mo)%mo;
                }
        printf("Case %d: %d\n",i+1,ans);
    }
    return 0;
}
