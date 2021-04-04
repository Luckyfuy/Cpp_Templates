/*
ST表
用于解决静态区间最值查询问题
*/

#include <bits/stdc++.h>

// ST表的最大空间
const int MAX_SIZE = 10000, MAX_LOG = 20;

// ST表
// 查询最小值
template<class type>
class MinST
{
    private:
        // 元素
        type f[MAX_SIZE][MAX_LOG];
        int lg[MAX_LOG];

    public:
        // 构造函数
        MinST(std::vector<int> num);

        // 方法
        type query(int l, int r);
};

// 初始化
template<class type>
MinST<type>::MinST(std::vector<int> num)
{
    for (int i = 1; i <= int(num.size()); ++i)
        f[i][0] = num[i - 1];
    for (int j = 1; j <= MAX_LOG; ++j)
        for (int i = 1; i + (1 << j) - 1 <= int(num.size()); ++i)
            f[i][j] = std::min(f[i][j - 1], f[i + (1 << (j - 1))][j - 1]);
    lg[1] = 0;
    for (int i = 2; i <= int(num.size()); ++i)
        lg[i] = lg[i / 2] + 1;
}

// 查询最小值
template<class type>
type MinST<type>::query(int l, int r)
{
    int len = lg[r - l + 1];
    return std::min(f[l][len], f[r - (1 << len) + 1][len]);
}

// ST表
// 查询最大值
template<class type>
class MaxST
{
    private:
        // 元素
        type f[MAX_SIZE][MAX_LOG];
        int lg[MAX_LOG];

    public:
        // 构造函数
        MaxST(std::vector<int> num);

        // 方法
        type query(int l, int r);
};

// 初始化
template<class type>
MaxST<type>::MaxST(std::vector<int> num)
{
    for (int i = 1; i <= int(num.size()); ++i)
        f[i][0] = num[i - 1];
    for (int j = 1; j <= MAX_LOG; ++j)
        for (int i = 1; i + (1 << j) - 1 <= int(num.size()); ++i)
            f[i][j] = std::max(f[i][j - 1], f[i + (1 << (j - 1))][j - 1]);
    lg[1] = 0;
    for (int i = 2; i <= int(num.size()); ++i)
        lg[i] = lg[i / 2] + 1;
}

// 查询最大值
template<class type>
type MaxST<type>::query(int l, int r)
{
    int len = lg[r - l + 1];
    return std::max(f[l][len], f[r - (1 << len) + 1][len]);
}

// 测试
int main()
{
    int n;
    std::vector<int> num;
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i)
    {
        int t;
        scanf("%d", &t);
        num.push_back(t);
    }
    MinST<int> minst(num);
    MaxST<int> maxst(num);

    scanf("%d", &n);
    for (int i = 1; i <= n; ++i)
    {
        int l, r;
        scanf("%d %d", &l, &r);
        printf("%d %d\n", minst.query(l, r), maxst.query(l, r));
    }

    setbuf(stdin, nullptr);
    getchar();
    return 0;
}