/*
链表
一种存储不连续的线性数据结构
*/

#include <bits/stdc++.h>

// 节点
template<class type>
struct Node
{
    // 数据
    type data;
    // 指向下一个节点的指针
    Node<type> *nxt;

    // 构造函数
    Node(type _data);
};

// 初始化
template<class type>
Node<type>::Node(type _data)
{
    data = _data;
    nxt = nullptr;
}

// 单链表
template<class type>
class LinkedList
{
    private:
        // 头节点
        Node<type> *head;

    public:
        // 构造函数
        LinkedList();

        // 方法
        Node<type>* getHead();
        Node<type>* getEnd();
        Node<type>* locate(int pos);
        void ins(type data);
        void ins(type data, int pos);
        void del();
        void del(int pos);
        int size();
        void print();
        bool empty();
};

// 初始化
template<class type>
LinkedList<type>::LinkedList()
{
    head = nullptr;
}

// 获取头节点
template<class type>
Node<type>* LinkedList<type>::getHead()
{
    return head;
}

// 获取尾节点
template<class type>
Node<type>* LinkedList<type>::getEnd()
{
    Node<type> *ptr = head;
    while (ptr -> nxt != nullptr)
    {
        ptr = ptr -> nxt;
    }
    return ptr;
}

// 获取第pos个节点
template<class type>
Node<type>* LinkedList<type>::locate(int pos)
{
    if (pos < 0 || pos > size())
    {
        return nullptr;
    }
    Node<type> *ptr = head;
    for (int i = 1; i <= pos; ++i)
    {
        ptr = ptr -> nxt;
    }
    return ptr;
}

// 插入节点到末尾
template<class type>
void LinkedList<type>::ins(type data)
{
    Node<type> *node = new Node<type>(data);
    if (head == nullptr)
    {
        head = node;
    }
    else
    {
        Node<type> *ptr = getEnd();
        ptr -> nxt = node;
    }
}

// 插入节点到位置pos
template<class type>
void LinkedList<type>::ins(type data, int pos)
{
    if (pos < 1 || pos > size())
    {
        return;
    }
    Node<type> *node = new Node<type>(data), *ptr = locate(pos - 1);
    node -> nxt = ptr -> nxt;
    ptr -> nxt = node;
}

// 删除末尾节点
template<class type>
void LinkedList<type>::del()
{
    if (head -> nxt == nullptr)
    {
        return;
    }
    Node<type> *ptr = head, *p = nullptr;
    while (ptr -> nxt != nullptr)
    {
        p = ptr;
        ptr = ptr -> nxt;
    }
    p -> nxt = nullptr;
    delete ptr;
}

// 删除第pos个节点
template<class type>
void LinkedList<type>::del(int pos)
{
    if (pos < 1 || pos > size())
    {
        return;
    }
    Node<type> *ptr = locate(pos - 1), *p = ptr -> nxt;
    ptr -> nxt = p -> nxt;
    delete p;
}

// 返回节点个数
template<class type>
int LinkedList<type>::size()
{
    int len = -1;
    Node<type> *ptr = head;
    while (ptr != nullptr)
    {
        ++len;
        ptr = ptr -> nxt;
    }
    return len;
}

// 遍历链表并输出每个节点的值
template<class type>
void LinkedList<type>::print()
{
    Node<type> *ptr = head;
    while (ptr -> nxt != nullptr)
    {
        ptr = ptr -> nxt;
        printf("%d ", ptr -> data);
    }
    puts("");
}

// 返回链表是否为空
template<class type>
bool LinkedList<type>::empty()
{
    return head == nullptr || head -> nxt == nullptr;
}

// 测试
int main()
{
    LinkedList<int> lst;
    int m, n;

    scanf("%d", &m);
    for (int i = 1; i <= m; ++i)
    {
        scanf("%d", &n);
        lst.ins(n);
        lst.print();
        printf("%d\n", lst.size());
    }

    // while (scanf("%d %d", &m, &n))
    // {
    //     lst.ins(n, m);
    //     lst.print();
    // }

    // while (lst.size() > 0)
    // {
    //     lst.del();
    //     lst.print();
    //     printf("%d\n", lst.size());
    // }

    // while (scanf("%d", &n))
    // {
    //     lst.del(n);
    //     lst.print();
    //     printf("%d\n", lst.size());
    // }

    setbuf(stdin, nullptr);
    getchar();
    return 0;
}