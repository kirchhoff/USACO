#include<iostream>
using namespace std;
int b[50];
#define maxn 50
int wa[maxn],wb[maxn],wv[maxn],wd[maxn];
int cmp(int *r,int a,int b,int l)
{return r[a]==r[b]&&r[a+l]==r[b+l];}
void da(char *r,int *sa,int n,int m)
{
    int i,j,p,*x=wa,*y=wb,*t;
    for(i=0;i<m;i++) wd[i]=0;
    for(i=0;i<n;i++) wd[x[i]=r[i]]++;
    for(i=1;i<m;i++) wd[i]+=wd[i-1];
    for(i=n-1;i>=0;i--){ sa[--wd[x[i]]]=i;
        b[wd[x[i]]]=r[i];
    }

    for(int tt=0;tt<8;++tt)
    {
        cout<<" "<<sa[tt];
    }
    for(int tt=0;tt<8;++tt)
    {
        printf(" %c",b[tt]);
    }
    cout<<endl;


    for(j=1,p=1;p<n;j*=2,m=p)
    {
        for(p=0,i=n-j;i<n;i++) y[p++]=i;
        for(i=0;i<n;i++) if(sa[i]>=j) y[p++]=sa[i]-j;
for(int tt=0;tt<8;++tt)
    {
        cout<<" "<<y[tt];
    }
    cout<<endl;

        for(i=0;i<n;i++) wv[i]=x[y[i]];
for(int tt=0;tt<8;++tt)
    {
        printf(" %c",wv[tt]);
    }
    cout<<endl;

        for(i=0;i<m;i++) wd[i]=0;
        for(i=0;i<n;i++) wd[wv[i]]++;
        for(i=1;i<m;i++) wd[i]+=wd[i-1];
        for(i=n-1;i>=0;i--) sa[--wd[wv[i]]]=y[i];
        for(t=x,x=y,y=t,p=1,x[sa[0]]=0,i=1;i<n;i++)
            x[sa[i]]=cmp(y,sa[i-1],sa[i],j)?p-1:p++;
    }
    return;
}
int main(int argc, char *argv[])
{
    char r[]="aabaaaab";
    int sa[8];
    da(r,sa,8,128);
    for(int tt=0;tt<8;++tt)
    {
        cout<<" "<<sa[tt];
    }
    cout<<endl;

    return 0;
}
