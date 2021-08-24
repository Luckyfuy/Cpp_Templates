/*
栈
一种LIFO（Last Input First Output，即后进先出）线性数据结构
*/

#include <bits/stdc++.h>

// 栈的最大空间
const int MAX_SIZE = 100000;

// 栈
template<class type>
class Stack
{
    private:
        // 元素
        type ele[MAX_SIZE];
        // 元素个数
        int tot;

    public:
        // 构造函数
        Stack();

        // 方法
        bool push(type e);
        bool pop();
        void print();
        bool empty();
        type top();
        int size();
};

// 初始化
template<class type>
Stack<type>::Stack()
{
    tot = 0;
}

// 把元素压入栈
template<class type>
bool Stack<type>::push(type e)
{
    if (tot == MAX_SIZE - 1)
        return false;
    ele[++tot] = e;
    return true;
}

// 把栈顶元素弹出
template<class type>
bool Stack<type>::pop()
{
    if (empty())
        return false;
    ele[tot--] = 0;
    return true;
}

// 输出栈内所有元素
template<class type>
void Stack<type>::print()
{
    for (int i = 1; i <= tot; ++i)
        std::cout << ele[i] << " ";
    puts("");
}

// 是否为空栈
template<class type>
bool Stack<type>::empty()
{
    return tot == 0;
}

// 返回栈顶元素
template<class type>
type Stack<type>::top()
{
    return ele[tot];
}

// 返回栈内元素个数
template<class type>
int Stack<type>::size()
{
    return tot;
}

// 测试
int main()
{
    Stack<int> st;
    int n;
    while (scanf("%d", &n))
        st.push(n);

    while (!st.empty())
    {
        st.print();
        printf("Top: %d\n", st.top());
        printf("Size: %d\n", st.size());
        st.pop();
    }

    setbuf(stdin, nullptr);
    getchar();
    return 0;
}