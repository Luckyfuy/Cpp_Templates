/*
冒泡排序
通过交换相邻两个数字来排序
*/

#include <bits/stdc++.h>

// 冒泡排序
template<class type>
void bubbleSort(std::vector<type> &num)
{
    // 记录最后一次交换的位置
    int index = 0;
    // 无序数列的边界，每次比较到这里为止
    int border = num.size() - 1;

    for (int i = 0; i < int(num.size()); ++i)
    {
        // 有序标记，每轮初始化为true
        bool isSorted = true;

        for (int j = 0; j < border; ++j)
        {
            // 若数字比后一位数字大，则交换两个数字
            if (num[j] > num[j + 1])
            {
                std::swap(num[j], num[j + 1]);

                // 因为有元素交换，所以标记变为false
                isSorted = false;
                // 更新最后交换的位置
                index = j;
            }
        }

        // 更新无序数列的边界
        border = index;
        // 若已经有序，则停止排序
        if (isSorted)
        {
            return;
        }
    }
}

// 测试
int main()
{
    int n;
    std::vector<int> num;
    while (scanf("%d", &n))
    {
        num.push_back(n);
    }

    bubbleSort(num);

    for (int i = 0; i < int(num.size()); ++i)
    {
        printf("%d ", num[i]);
    }
    puts("");

    setbuf(stdin, nullptr);
    getchar();
    return 0;
}