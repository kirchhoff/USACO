#include<iostream>
using namespace std;
char t[11+1] = "mississippi";
int sa[11];     // suffix array，各個名次對應的後綴。
int c[50000];   // 計數排序法的計數陣列
int temp[2][50000];
struct CMP
{
    int* rank, n, N;
    bool operator()(const int& i, const int& j)
    {
        // 先比前半段，再比後半段。
        if (rank[i] != rank[j])
            return rank[i] < rank[j];
        int a = (i+n<N) ? rank[i+n] : -1;
        int b = (j+n<N) ? rank[j+n] : -1;
        return a < b;
    }
};

void suffix_array()
{
    int N = 11; // 字串長度
    int* rank = temp[0];
    int* new_rank = temp[1];

    for (int i=0; i<N; i++)
    {
        // 各個名次對應的後綴
        // 隨便初始化一個順序，稍後會重新排序。
            sa[i] = i;
        // 各個後綴對應的名次
        // 偷懶取巧：直接把ASCII數值當作是名次。
        rank[i] = t[i];
    }

    // 鍵值長度逐步倍增
    for (int n=1; n<N; n*=2)
    {
        // 運用上一回合求得的名次，排序所有後綴。
        // 鍵值是每個後綴的前2*n個字元，
        // 先比前半段、再比後半段。
        CMP cmp = {rank, n, N};
        sort(sa, sa+N, cmp);

        // 重新整理名次。
        // 相異者、排在相異名次，相同者、排在相同名次。
        int r = 0;
        new_rank[sa[0]] = r;
        for (int i=1, r=0; i<N; i++)
        {
            if (cmp(sa[i-1], sa[i])) r++;
            new_rank[sa[i]] = r;
        }
        swap(rank, new_rank);

        // 如果名次皆相異，表示排序完畢，可以提早結束。
        if (r == N-1) break;
    }
}

void suffix_array2()
{
    int N = 11;             // 字串長度
    int A = 128;            // 計數排序法數值範圍
    int* rank = temp[0];    // 各個後綴對應的名次
    int* sa2 = temp[1];     // 各個名次對應的後綴後半段

    // 各個後綴第一個字元，實施計數排序法。
    // 然後累計次數，直接得到名次。
    // 從索引值最高的後綴開始處理，得到各個後綴對應的名次。
    // （偷懶取巧：直接把ASCII數值當作是名次。）
    for (int i=0; i<A; ++i) c[i] = 0;
    for (int i=0; i<N; ++i) c[rank[i] = t[i]]++;
    for (int i=1; i<A; ++i) c[i] += c[i-1];
    for (int i=N-1; i>=0; --i)
        sa[--c[rank[i]]] = i;
    // cout<<c[116]<<endl;

    // 鍵值長度逐步倍增
    for (int n=1; n<N; n*=2)
    {
        // sa 是各個名次對應的後綴前半段
        // sa2是各個名次對應的後綴後半段
        // rank是各個後綴前半段對應的名次

        // sa與rank在上一回合就計算好了，現在要計算sa2。
        // 最後n個後綴的後半段，肯定都是空字串，名次最高。
        // 各個空字串依照索引值由小到大進行排名。
        int r = 0;  // 名次
        for (int i=N-n; i<N; ++i)
            sa2[r++] = i;

        // 其它的後綴的後半段，運用sa求得。
        for (int i=0; i<N; ++i)
            // 位置大於等於k，實際上才有前半段。
            if (sa[i] >= n)
                sa2[r++] = sa[i] - n;
           cout<<"sa :";
        for(int i=0;i<N;++i)
            cout<<" "<<sa[i];
        cout<<endl;
        cout<<"sa2 :";
        for(int i=0;i<N;++i)
            cout<<" "<<sa2[i];
        cout<<endl;
        cout<<"rank :";
        for(int i=0;i<N;++i)
            cout<<" "<<rank[i];
            cout<<endl;

        // 使用各個後綴的名次，實施計數排序法。
        // 從名次最高的後綴後半段開始處理，得到正確名次。
        for (int i=0; i<A; ++i) c[i] = 0;
        for (int i=0; i<N; ++i) c[rank[i]]++;
        for (int i=1; i<A; ++i) c[i] += c[i-1];
        for (int i=N-1; i>=0; --i)
            sa[--c[rank[sa2[i]]]] = sa2[i];
        cout<<"2 sa :";
        for(int i=0;i<N;++i)
            cout<<" "<<sa[i];
        cout<<endl;
        cout<<endl;
        // 暫且以sa2來儲存本回合的rank，
        // 然後計算下一回合的rank。
        int*& new_rank = sa2;
        new_rank[sa[0]] = r = 0;
        for (int i=1; i<N; ++i)
        {
            // 相異者、排在相異名次，相同者、排在相同名次。
            // （偷懶取巧：因為最後n個後綴，
            // 上個回合就已經排序完畢，
            // 這些後綴長度不等、名次一定都相異，
            // 所以不會遇到sa[i-1]+n和sa[i]+n溢位。）
            if (!(rank[sa[i-1]] == rank[sa[i]] &&
                rank[sa[i-1]+n] == rank[sa[i]+n]))
                r++;
            new_rank[sa[i]] = r;
        }
        swap(rank, new_rank);
        cout<<"r is "<<r<<endl;

        // 如果名次皆相異，表示排序完畢，可以提早結束。
        if (r == N-1) break;
        // 修正一下計數排序法數值範圍
        A = r + 1;
    }
}
int main(int argc, char *argv[])
{
    suffix_array2();
    for(int i=0;i<11;++i)
    {
        cout<<" "<<sa[i];
    }
    cout<<endl;
    return 0;
}
