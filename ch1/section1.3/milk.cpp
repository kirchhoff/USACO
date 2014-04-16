/*
  ID:twd30651
  PROG:milk
  LANG:C++
*/
#include<iostream>
#include<fstream>
#include<string.h>
#include<stdlib.h>
using namespace std;
typedef struct xdeci{
    int pi;
    int ai;
}ddeci;
ddeci fa[6000];
int comp(ddeci a,ddeci b)
{
    if(a.pi>b.pi)
        return 1;
    else if(a.pi==b.pi)
        return 0;
    else
        return -1;
}
int ps(ddeci data[],int p,int r)
{
    ddeci key=data[r];
    int i=p-1;
    int j=r+1;
    while(1)
    {
        do
        {
            i++;
        } while (comp(data[i],key)<0);
        do
        {
            j--;
        } while (comp(data[j],key)>0);
        if(i<j)
        {
            ddeci tmp=data[i];
            data[i]=data[j];
            data[j]=tmp;
        }
        else
        {
            return i;
        }
    }
}
void qs(ddeci data[],int p,int r)
{
    if(p<r)
    {
        int q=ps(data,p,r);
        qs(data,p,q-1);
        qs(data,q,r);
    }
}
int hoare_partition(int A[], int p, int r)
{
    int x = A[p];
    int i = p - 1;
    int j = r + 1;

    while (1) {

        do j--;
        while (A[j] > x);

        do i++;
        while (A[i] < x);

        if (i < j)
        {
            int tmp=A[i];
            A[i]=A[j];
            A[j]=tmp;
        }
        else{

            //PrintArray(A);
            return j;
        }
    }
}

void hoare_quick_sort(int A[], int p, int r)
{
    if (p < r) {
        int q = hoare_partition(A, p, r);
        hoare_quick_sort(A, p, q);
        hoare_quick_sort(A, q + 1, r);
    }
}

//一趟快排之后，以枢纽为分隔，左边的<=枢纽, 右边的>=枢纽
int _Partition(int *arr, int beg, int end)
{
	int low = beg, high = end;
	//选定枢轴
	int sentinel = arr[beg];
	while(low < high)
	{
	    //printf("\n    定点取arr[%d]的值，设为 sentinel(%d)", low, sentinel );
	    //printf("\n    比sentinel(%d)大的都丢到右边", sentinel);
	    //比枢纽小的交换到低端
		while(low < high && arr[high]>=sentinel)
		{
            //printf("\n    arr[%d](%d) >= sentinel(%d)", high, arr[high], sentinel);
		    --high;
		    //printf(". high自减为%d, 此时 arr[high] 为 %d", high, arr[high]);
		}
		arr[low] = arr[high];
		//printf("\n    赋值-> arr[low](arr[%d]) = arr[high](arr[%d]) = %d", low, high, arr[low]);
		//printf("\n    比sentinel(%d)小的都丢到左边", sentinel);
		//比枢纽大的交换到高端
		while(low < high && arr[low]<=sentinel)
		{

		    //printf("\n    arr[%d](%d) <= sentinel(%d)", low, arr[low], sentinel);
		    ++low;
		    //printf(". low自增为%d, 此时 arr[low] 为 %d", low, arr[low]);
		}
		arr[high] = arr[low];
		//printf("\n    赋值-> arr[high](arr[%d]) = arr[low](arr[%d]) = %d", high, low, arr[high]);
	}
	arr[high] = sentinel;

	//printf("\n排序过程:");
	//PrintArray(arr);
	return low;
}

void _QuickSort(int *arr, int beg, int end)
{
	if(beg < end)
	{
		int pivot = _Partition(arr, beg, end);
		//分治思想，递归排序
		_QuickSort(arr, beg, pivot-1);
		_QuickSort(arr, pivot+1, end);
	}
}
int al_partition(int a[],int p,int r)
{
    int x= a[r];
    int i=p-1;
    int j=p;
    for(;j<=r-1;++j)
    {
        if(a[j]<x)
        {
            i++;
            int tmp=a[i];
            a[i]=a[j];
            a[j]=tmp;
        }
    }
    i++;
    int tmp=a[i];
    a[i]=a[j];
    a[j]=tmp;
    return i;
}
int al_quicksort(int a[],int p,int r)
{
    if(p<r)
    {
        int q=al_partition(a , p , r );
        al_quicksort(a , p , q-1);
        al_quicksort(a , q+1 , r);
    }
}
int issort(ddeci a[],int size)
{
    ddeci key;
    for(int j=1;j<size;++j)
    {
        key=a[j];
        int i;
        for(i=j-1;i>=0;--i)
        {
            if(comp(a[i],key))
                memcpy(&a[i+1],&a[i],sizeof(ddeci));
            else break;
        }
        memcpy(&a[i+1],&key,sizeof(ddeci));
    }
    return 0;
}
void swap(ddeci *a,ddeci *b)
{
    ddeci temp=*a;
    *a=*b;
    *b=temp;
}
int partition(ddeci data[],int lo,int hi)
{
    ddeci key=data[hi];  //以最后一个元素，data[hi]为主元
    int i=lo-1;
    for(int j=lo;j<hi;j++)   ///注，j从p指向的是r-1，不是r。
    {
        if(comp(data[j],key)<0)
        {
            i=i+1;
            swap(&data[i],&data[j]);
        }
    }
    swap(&data[i+1],&data[hi]);   //不能改为swap(&data[i+1],&key)
    return i+1;
}
void QuickSort(ddeci data[], int lo, int hi)
{
    if (lo<hi)
    {
        int k = partition(data, lo, hi);
        QuickSort(data, lo, k-1);
        QuickSort(data, k+1, hi);
    }
}
void PrintArray(int arr[])
{
    int i;
    for(i=0; i < 5; ++i)
    {
        printf("%d ", arr[i]);
    }
    cout<<endl;
}


int main(int argc,char *argv[])
{
    int sum=0;
    int money=0;
    freopen("milk.in","r",stdin);
    freopen("milk.out","w",stdout);
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
    qs(fa,0,M-1);
    //  QuickSort(fa,0,M-1);
    //qs(fa, 0, M-1);
    for(i=0;i<M;++i)
    {
        if(sum+fa[i].ai<=N)
        {
            money+=fa[i].ai*fa[i].pi;
            sum+=fa[i].ai;
        }
        else
        {
            money+=(N-sum)*fa[i].pi;
            break;
        }
    }
    cout<<money<<endl;
    return 0;
}

/*
  Compiling...
  Compile: OK

  Executing...
  Test 1: TEST OK [0.000 secs, 3420 KB]
  Test 2: TEST OK [0.000 secs, 3420 KB]
  Test 3: TEST OK [0.000 secs, 3420 KB]
  Test 4: TEST OK [0.000 secs, 3420 KB]
  Test 5: TEST OK [0.011 secs, 3420 KB]
  Test 6: TEST OK [0.054 secs, 3420 KB]
  Test 7: TEST OK [0.011 secs, 3420 KB]
  Test 8: TEST OK [0.032 secs, 3420 KB]

  All tests OK.
*/
