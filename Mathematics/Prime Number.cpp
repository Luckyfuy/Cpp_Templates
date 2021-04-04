/*
质数
质数的判定及筛法
*/

#include <bits/stdc++.h>

// 快速幂
long long pow(long long x, long long y, long long z)
{
    x %= z;
    long long res = 1;
    while (y != 0)
    {
        if (y % 2 == 1)
            res = res * x % z;
        x = x * x % z;
        y /= 2;
    }
    return res;
}

// 测试次数
const int k = 10, MAX_SIZE = 100000;

// Miller-Rabin素性测试
bool millerRabin(long long n)
{
    if (n <= 2)
        return n == 2;
    long long u = n - 1, t = 0;
    while (u % 2 == 0)
    {
        ++t;
        u /= 2;
    }
    for (int i = 1, j; i <= k; ++i)
    {
        long long a = rand() % (n - 2) + 2, b = pow(a, u, n);
        if (b == 1 || b == n - 1)
        {
            continue;
        }
        for (j = 0; j < t; ++j)
        {
            b = b * b % n;
            if (b == n - 1)
            {
                break;
            }
        }
        if (j >= t)
        {
            return false;
        }
    }
    return true;
}

// 欧拉筛
int euler(long long n)
{
    int tot = 0, prime[MAX_SIZE];
    bool vis[MAX_SIZE] = {};
    for (int i = 2; i <= n; ++i)
    {
        if (!vis[i])
        {
            prime[++tot] = i;
        }
        for (int j = 1; j <= tot; ++j)
        {
            if (i * prime[j] > n)
            {
                break;
            }
            vis[i * prime[j]] = true;
            if (i % prime[j] == 0)
            {
                break;
            }
        }
    }
    for (int i = 1; i <= tot; ++i)
        printf("%d ", prime[i]);
    puts("");
    return tot;
}

// 测试
int main()
{
    long long n;
    scanf("%lld", &n);

    std::cout.setf(std::ios_base::boolalpha);
    std::cout << millerRabin(n) << std::endl;
    printf("%d\n", euler(n));

    setbuf(stdin, nullptr);
    getchar();
    return 0;
}