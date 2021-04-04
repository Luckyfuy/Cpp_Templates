/*
读入、输出优化
用getchar()和putchar()对读入、输出进行优化
*/

#include <bits/stdc++.h>

inline bool blank(char ch)
{
    return ch == ' ' || ch == '\n' || ch == '\r' || ch == '\t';
}

template<class type>
inline void read(type &n)
{
    int f = 1;
    n = 0;

    char ch = getchar();
    for (; !isdigit(ch); ch = getchar())
    {
        if (ch == '-')
        {
            f = -1;
        }
    }

    for (; isdigit(ch); ch = getchar())
    {
        n = n * 10 + ch - '0';
    }

    if (ch == '.')
    {
        type tmp = 1;
        for (ch = getchar(); isdigit(ch); ch = getchar())
        {
            tmp /= 10;
            n += tmp * (ch - '0');
        }
    }
    n *= f;
}
inline void read(char *str)
{
    char ch = getchar();
    for (; blank(ch); ch = getchar());
    for (; !blank(ch); ch = getchar())
    {
        *str++ = ch;
    }
    *str = 0;
}
inline void read(char &ch)
{
    for (ch = getchar(); blank(ch); ch = getchar());
}

template<class type>
inline void write(type n)
{
    if (n < 0)
    {
        putchar('-');
        n = -n;
    }
    type st[30];
    int top = 0;
    do
    {
        st[++top] = n % 10;
        n /= 10;
    }
    while (n);
    while (top)
    {
        putchar(st[top--] + '0');
    }
}
template<class type>
inline void write(type n, char ch)
{
    write(n);
    putchar(ch);
}

int main()
{
    while (true)
    {
        long long n;
        read<long long>(n);
        write<long long>(n, '\n');
    }

    setbuf(stdin, nullptr);
    getchar();
    return 0;
}