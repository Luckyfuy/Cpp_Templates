/*
队列
一种FIFO（Fast Input First Output，即先进先出）线性数据结构
*/

#include <bits/stdc++.h>

// 队列的最大空间
const int MAX_SIZE = 100000;

// 链式队列
template<class type>
class Queue
{
    private:
        // 元素
        type ele[MAX_SIZE];
        // 队首、队尾位置
        int fnt, end;

    public:
        // 构造函数
        Queue();

        // 方法
        bool push(type e);
        bool pop();
        void print();
        bool empty();
        type front();
        int size();
};

// 初始化
template<class type>
Queue<type>::Queue()
{
    fnt = end = 0;
}

// 让元素入队
template<class type>
bool Queue<type>::push(type e)
{
    if (end == MAX_SIZE - 1)
    {
        return false;
    }
    ele[++end] = e;
    return true;
}

// 让元素出队
template<class type>
bool Queue<type>::pop()
{
    if (empty())
    {
        return false;
    }
    ele[fnt++] = 0;
    return true;
}

// 输出队内所有元素
template<class type>
void Queue<type>::print()
{
    for (int i = fnt + 1; i <= end; ++i)
    {
        std::cout << ele[i] << " ";
    }
    puts("");
}

// 是否为空队列
template<class type>
bool Queue<type>::empty()
{
    return fnt == end;
}

// 返回队首元素
template<class type>
type Queue<type>::front()
{
    return ele[fnt + 1];
}

// 返回队内元素个数
template<class type>
int Queue<type>::size()
{
    return end - fnt;
}

// 测试
int main()
{
    Queue<int> cq;
    int n;
    while (scanf("%d", &n))
    {
        cq.push(n);
    }

    while (!cq.empty())
    {
        cq.print();
        printf("Front: %d\n", cq.front());
        printf("Size: %d\n", cq.size());
        cq.pop();
    }

    setbuf(stdin, nullptr);
    getchar();
    return 0;
}