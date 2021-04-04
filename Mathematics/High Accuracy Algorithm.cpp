/*
高精度算法
可计算大整数的加减乘除及求余
*/

#include <bits/stdc++.h>

// 最大位数
const int MAX_DIGIT = 1000;
// 补齐0到最大位数
inline void zero(std::string &a)
{
    while (a.size() < MAX_DIGIT)
    {
        a = '0' + a;
    }
}

// 清除所有前导0
inline void clear(std::string &a)
{
    while (a.size() > 0 && a[0] == '0')
    {
        a.erase(0, 1);
    }
    if (a == "")
    {
        a = "0";
    }
}

// 判断a是否大于b
bool isBigger(std::string a, std::string b)
{
    clear(a);
    clear(b);

    if(a.size() > b.size())
    {
        return true;
    }
    else if(a.size() == b.size() && a >= b)
    {
        return true;
    }
    else
    {
        return false;
    }
}

// 加法，a+b
std::string add(std::string a, std::string b)
{
    zero(a);
    zero(b);

    // 按位相加
    for (int i = a.size() - 1; i >= 0; --i)
    {
        a[i] = a[i] + b[i] - '0';
        // 若结果大于9，则进位
        if (a[i] > '9')
        {
            a[i] -= 10;
            a[i - 1] += 1;
        }
    }

    clear(a);
    return a;
}

// 减法，a-b
std::string sub(std::string a, std::string b)
{
    zero(a);
    zero(b);

    // 若被减数小于减数，则交换被减数和减数
    bool aBigger = true;
    if (a < b)
    {
        aBigger = false;

        std::swap(a, b);
    }

    // 按位相减
    for (int i = a.size() - 1; i >= 0; --i)
    {
        if (a[i] >= b[i])
        {
            a[i] -= b[i] - '0';
        }
        // 若被减数的取位小于减数，则借位
        else
        {
            a[i] += 10;
            a[i - 1] -= 1;
            a[i] -= b[i] - '0';
        }
    }

    clear(a);
    // 若被减数小于减数，则添上负号
    if(!aBigger)
    {
        a = '-' + a;
    }
    return a;
}

// 乘法，a*b
// 依赖加法
std::string multi(std::string a, std::string b)
{
    std::string result = "0";

    // 若a的位数小于b，则交换a和b
    if (a.size() < b.size())
    {
        std::swap(a, b);
    }

    // 将乘法转换为加法
    for (int i = b.size() - 1; i >= 0; --i)
    {
        for (int j = 0; j < b[i] - '0'; ++j)
        {
            result = add(result, a);
        }
        a += '0';
    }

    clear(result);
    return result;
}

// 除法，a/b
// 依赖减法
std::string divide(std::string a, std::string b)
{
    clear(a);
    clear(b);

    // 若除数为0，则返回错误
    if (b == "0")
    {
        return "Error";
    }

    std::string result = "", remainder = "";

    // 从高位开始除
    for (int i = 0; i < int(a.size()); ++i)
    {
        remainder += a[i];
        result += '0';
        // 若取位不小于被除数，则用减法求商
        while (isBigger(remainder, b))
        {
            ++result[result.size() - 1];
            remainder = sub(remainder, b);
        }
    }

    clear(result);
    return result;
}

// 求余，a%b
// 依赖减法
// 算法同除法，但最后返回余数
std::string mod(std::string a, std::string b)
{
    clear(a);
    clear(b);

    if (b == "0")
    {
        return "Error";
    }

    std::string result = "", remainder = "";

    for (int i = 0; i < int(a.size()); ++i)
    {
        remainder += a[i];
        result += '0';
        while (isBigger(remainder, b))
        {
            ++result[result.size() - 1];
            remainder = sub(remainder, b);
        }
    }

    clear(remainder);
    return remainder;
}

// 测试
int main()
{
    std::string a, b;
    std::cin >> a >> b;

    printf("%s + %s = %s\n", a.c_str(), b.c_str(), add(a, b).c_str());
    printf("%s - %s = %s\n", a.c_str(), b.c_str(), sub(a, b).c_str());
    printf("%s * %s = %s\n", a.c_str(), b.c_str(), multi(a, b).c_str());
    printf("%s / %s = %s ...... %s\n", a.c_str(), b.c_str(), divide(a, b).c_str(), mod(a, b).c_str());

    setbuf(stdin, nullptr);
    getchar();
    return 0;
}