/*
堆排序
利用堆的性质来排序
*/

#include <bits/stdc++.h>

// 堆的最大空间
const int MAX_SIZE = 100000;

// 大根堆
template<class type>
class Heap
{
    private:
        // 元素
        type ele[MAX_SIZE];
        // 末尾元素位置
        int tot;

        int le(int n);
        int rt(int n);
        int dad(int n);
    public:
        // 构造函数
        Heap();

        // 方法
        bool push(type e);
        bool pop();
        bool empty();
        type top();
        int size();
};

// 返回左子节点位置
template<class type>
int Heap<type>::le(int n)
{
    return n * 2;
}
// 返回右子节点位置
template<class type>
int Heap<type>::rt(int n)
{
    return n * 2 + 1;
}
// 返回父节点位置
template<class type>
int Heap<type>::dad(int n)
{
    return n / 2;
}

// 初始化
template<class type>
Heap<type>::Heap()
{
    tot = 0;
}

// 把元素压入堆
template<class type>
bool Heap<type>::push(type e)
{
    if (tot == MAX_SIZE - 1)
    {
        return false;
    }
    ele[++tot] = e;

    // 自下而上调整
    for (int i = tot; i != 1; i = dad(i))
    {
        if (ele[i] > ele[dad(i)])
        {
            std::swap(ele[i], ele[dad(i)]);
        }
        else
        {
            break;
        }
    }
    return true;
}

// 删除根节点元素
template<class type>
bool Heap<type>::pop()
{
    if (empty())
    {
        return false;
    }
    std::swap(ele[1], ele[tot]);
    ele[tot--] = 0;

    // 自上而下调整
    for (int i = 1; ; )
    {
        int tar = (ele[le(i)] > ele[rt(i)] ? le(i) : rt(i));
        if (ele[i] < ele[tar])
        {
            std::swap(ele[i], ele[tar]);
            i = tar;
        }
        else
        {
            break;
        }
    }
    return true;
}

// 是否为空堆
template<class type>
bool Heap<type>::empty()
{
    return tot == 0;
}

// 返回根节点元素
template<class type>
type Heap<type>::top()
{
    return ele[1];
}

// 返回节点个数
template<class type>
int Heap<type>::size()
{
    return tot;
}

// 堆排序
template<class type>
void HeapSort(std::vector<type> &num)
{
    Heap<type> hp;
    for (int i = 0; i < int(num.size()); ++i)
    {
        hp.push(num[i]);
    }

    for (int i = int(num.size()) - 1; i >= 0; --i)
    {
        num[i] = hp.top();
        hp.pop();
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

    HeapSort(num);

    for (int i = 0; i < int(num.size()); ++i)
    {
        printf("%d ", num[i]);
    }
    puts("");

    setbuf(stdin, nullptr);
    getchar();
    return 0;
}