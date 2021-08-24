/*
选择排序
通过查找最小值来排序
*/

#include <bits/stdc++.h>

// 选择排序
template<class type>
void selectionSort(std::vector<type> &num)
{
    // 循环n-1次
    for (int i = 0; i < int(num.size()) - 1; ++i)
    {
        // 寻找最小值
        int minNum = num[i];
        int index = i;
        for (int j = i; j < int(num.size()); ++j)
        {
            if (minNum != std::min(minNum, num[j]))
            {
                index = j;
                minNum = num[j];
            }
        }

        // 若最小值不为第1个元素，则交换第1个元素和最小值
        if (index != i)
        {
            num[index] = num[i];
            num[i] = minNum;
        }
    }
}

// 测试
int main()
{
    int n;
    std::vector<int> num;
    while (scanf("%d", &n))
        num.push_back(n);

    selectionSort(num);

    for (int i = 0; i < int(num.size()); ++i)
        printf("%d ", num[i]);
    puts("");

    setbuf(stdin, nullptr);
    getchar();
    return 0;
}