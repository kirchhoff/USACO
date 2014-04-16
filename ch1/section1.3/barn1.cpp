/*
  ID:twd30651
  PROG:barn1
  LANG:C++
*/
#include<iostream>
#include<fstream>
int partition(int a[],int p,int r)
{
    int key=a[r];
    int i=p-1;
    int j=r+1;
    while(1)
    {
        do{
            i++;
        }while(a[i]>key);
        do{
            j--;
        }while(a[j]<key);
        if(i<j)
        {
            int tmp=a[i];
            a[i]=a[j];
            a[j]=tmp;
        }
        else
        {
            return i;
        }
    }
}
void quicksort(int a[],int p, int r)
{
    if(p<r)
    {
        int q=partition(a, p, r);
        quicksort(a, p, q-1);
        quicksort(a, q, r);
    }
}
using namespace std;
int cs[300];
int main(int argc,char *argv[])
{
    freopen("barn1.in","r",stdin);
    freopen("barn1.out","w",stdout);
    int M;
    int S;
    int C;
    cin>>M>>S>>C;
    int a;
    int b;
    cin>>a;
    int min=a;
    for(int i=0;i<C-1;++i)
    {
        cin>>b;
        cs[i]=b-a-1;
        a=b;
    }
    int max=b;
    int longest=max-min+1;
    quicksort(cs, 0, C-2);
    for(int i=0;i<M-1;++i)
    {
        longest-=cs[i];
    }
    cout<<longest<<endl;



    return 0;
}
