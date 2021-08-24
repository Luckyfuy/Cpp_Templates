/*
快速排序
通过分治法来排序
*/

#include <bits/stdc++.h>

// 快速排序
template<class type>
void quickSort(std::vector<type> &num, int left, int right)
{
    // 取中间数为基准
    int pivot = num[(left + right) / 2], i = left, j = right;
    do
    {
        // 查找左半部分比中间数大的数
        while (num[i] < pivot)
            ++i;
        // 查找左半部分比中间数小的数
        while (num[j] > pivot)
            --j;
        // 若左小右大，则交换2个数
        if (i <= j)
        {
            std::swap(num[i], num[j]);

            ++i;
            --j;
        }
    }
    while (i <= j);

    // 递归继续排序左右两部分
    if (left < j)
        quickSort(num, left, j);
    if (right > i)
        quickSort(num, i, right);
}

// 测试
int main()
{
    int n;
    std::vector<int> num;
    while (scanf("%d", &n))
        num.push_back(n);

    quickSort(num, 0, num.size() - 1);

    for (int i = 0; i < int(num.size()); ++i)
        printf("%d ", num[i]);
    puts("");

    setbuf(stdin, nullptr);
    getchar();
    return 0;
}