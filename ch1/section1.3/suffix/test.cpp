#include<algorithm>
#include<iostream>
using namespace std;
char t[11+1] = "mississippi";
int sa[11]; // t的後綴陣列

int cmp(const void* i, const void* j)
{
    return strcmp(t + *(int*)i, t + *(int*)j);
}

void suffix_array()
{
    for (int i=0; i<11; ++i) sa[i] = i;
    qsort(sa, 11, sizeof(int), cmp);
    /*
      qsort（即，quicksort）主要根据你给的比较条件给一个快速排序，主要是通过指针移动实现排序功能。排序之后的结果仍然放在原来数组中。
参数意义如下:
第一个参数 base 是 需要排序的目标数组名（或者也可以理解成开始排序的地址，因为可以写&s[i]这样的表达式）
第二个参数 num 是 参与排序的目标数组元素个数
第三个参数 width 是单个元素的大小（或者目标数组中每一个元素长度），推荐使用sizeof(s[0]）这样的表达式
第四个参数 compare 就是让很多人觉得非常困惑的比较函数啦。
     */
}
int main(int argc, char *argv[])
{
    suffix_array();
    for(int i=0;i<11;++i)
        cout<<" "<<sa[i];
    cout<<endl;
    return 0;
}
