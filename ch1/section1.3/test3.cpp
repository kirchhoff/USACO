#include <iostream>

const int MAXN = 100000;
const int k = 1000; // range

int a[MAXN], c[MAXN], rank[MAXN];

int main()
{
    int n;

    std::cin >> n;
    for (int i = 0; i < n; ++i)
    {
        std::cin >> a[i];
        ++c[a[i]];
    }

    for (int i = 1; i < k; ++i) c[i] += c[i-1];
    for (int i = n-1; i >= 0; --i) rank[--c[a[i]]] = i;
    for (int i = 0; i < n; ++i) std::cout << a[rank[i]] << std::endl;

    return 0;
}
